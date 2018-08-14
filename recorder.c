#include "GL/glut.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "system.h"
static double angle; 
static double delta_angle;
double view = 0;

#define PPM 0
#define LIBPNG 0
#define FFMPEG 1

#include <assert.h>
#include <stdio.h>
 
#define GL_GLEXT_PROTOTYPES 1
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glext.h>

#if LIBPNG
#include <png.h>
static png_byte *png_bytes = NULL;
static png_byte **png_rows = NULL;
#endif

#if FFMPEG
#include <libavcodec/avcodec.h>
#include <libavutil/imgutils.h>
#include <libavutil/opt.h>
#include <libswscale/swscale.h>
#endif
 
enum Constants { SCREENSHOT_MAX_FILENAME = 256 };
GLubyte *pixels = NULL;
static GLuint fbo;
static GLuint rbo_color;
static GLuint rbo_depth;
static const unsigned int HEIGHT = 1000;
static const unsigned int WIDTH = 1000;
static int offscreen = 1;
static unsigned int max_nframes = 100000; 
static unsigned int nframes = 0;
static unsigned int time0;
static AVCodecContext *c = NULL;
AVFrame *frame;
static AVPacket pkt;
static FILE *file;
static struct SwsContext *sws_context = NULL;
uint8_t *RGB_FFMPEG = NULL;

#define TOGGLE_ROTATE 1
 
#define TIMER  1
 
#define STEP_ROTATE 2
typedef int BOOL;
#define TRUE 1
#define FALSE 0
 
static int rotate, step;
#define VIEWING_DISTANCE_MIN  0.1
static GLfloat g_fViewDistance = 3 * VIEWING_DISTANCE_MIN;

void drawstr(int x, int y, char *string) {

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 1024, 0.0, 768);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, y);
	int i;
    int len = strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
}

void save_simulation( void )
{
    char extension[SCREENSHOT_MAX_FILENAME];
    char filename[SCREENSHOT_MAX_FILENAME];

    if (offscreen) {
       // glFlush();
    } else {
       // glutSwapBuffers();
    }
#if PPM
    snprintf(filename, SCREENSHOT_MAX_FILENAME, "tmp%d.ppm", nframes);
    screenshot_ppm(filename, WIDTH, HEIGHT, &pixels);
#endif
#if LIBPNG
    snprintf(filename, SCREENSHOT_MAX_FILENAME, "tmp%d.png", nframes);
    screenshot_png(filename, WIDTH, HEIGHT, &pixels, &png_bytes, &png_rows);
#endif
# if FFMPEG
    frame->pts = nframes;
    ffmpeg_encoder_glread_rgb(&RGB_FFMPEG, &pixels, WIDTH, HEIGHT);
    ffmpeg_encoder_encode_frame(RGB_FFMPEG);
#endif
    nframes++;
    if (model_finished())
        exit(EXIT_SUCCESS);
}
 
 
#if PPM
/*
Take screenshot with glReadPixels and save to a file in PPM format.
-   filename: file path to save to, without extension
-   width: screen width in pixels
-   height: screen height in pixels
-   pixels: intermediate buffer to avoid repeated mallocs across multiple calls.
    Contents of this buffer do not matter. May be NULL, in which case it is initialized.
    You must `free` it when you won't be calling this function anymore.
*/
static void screenshot_ppm(const char *filename, unsigned int width,
        unsigned int height, GLubyte **pixels) {
    size_t i, j, k, cur;
    const size_t format_nchannels = 3;
    FILE *f = fopen(filename, "w");
    fprintf(f, "P3\n%d %d\n%d\n", width, height, 255);
    *pixels = realloc(*pixels, format_nchannels * sizeof(GLubyte) * width * height);
    glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, *pixels);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            cur = format_nchannels * ((height - i - 1) * width + j);
            fprintf(f, "%3d %3d %3d ", (*pixels)[cur], (*pixels)[cur + 1], (*pixels)[cur + 2]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}
#endif

#if LIBPNG
/* Adapted from https://github.com/cirosantilli/cpp-cheat/blob/19044698f91fefa9cb75328c44f7a487d336b541/png/open_manipulate_write.c */
void screenshot_png(const char *filename, unsigned int width, unsigned int height,
        GLubyte **pixels, png_byte **png_bytes, png_byte ***png_rows) {
    size_t i, nvals;
    const size_t format_nchannels = 4;
    FILE *f = fopen(filename, "wb");
    nvals = format_nchannels * width * height;
    *pixels = realloc(*pixels, nvals * sizeof(GLubyte));
    *png_bytes = realloc(*png_bytes, nvals * sizeof(png_byte));
    *png_rows = realloc(*png_rows, height * sizeof(png_byte*));
    glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, *pixels);
    for (i = 0; i < nvals; i++)
        (*png_bytes)[i] = (*pixels)[i];
    for (i = 0; i < height; i++)
        (*png_rows)[height - i - 1] = &(*png_bytes)[i * width * format_nchannels];
    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) abort();
    png_infop info = png_create_info_struct(png);
    if (!info) abort();
    if (setjmp(png_jmpbuf(png))) abort();
    png_init_io(png, f);
    png_set_IHDR(
        png,
        info,
        width,
        height,
        8,
        PNG_COLOR_TYPE_RGBA,
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT
    );
    png_write_info(png, info);
    png_write_image(png, *png_rows);
    png_write_end(png, NULL);
    fclose(f);
}
#endif

#if FFMPEG
/* Adapted from: https://github.com/cirosantilli/cpp-cheat/blob/19044698f91fefa9cb75328c44f7a487d336b541/ffmpeg/encode.c */
static void ffmpeg_encoder_set_frame_yuv_from_rgb(uint8_t *rgb_m) {
    const int in_linesize[1] = { 4 * c->width };
    sws_context = sws_getCachedContext(sws_context,
            c->width, c->height, AV_PIX_FMT_BGR32 ,
            c->width, c->height, AV_PIX_FMT_YUV420P,
            SWS_FAST_BILINEAR, NULL, NULL, NULL);
    sws_scale(sws_context, (const uint8_t * const *)&rgb_m, in_linesize, 0,
            c->height, frame->data, frame->linesize);
}

AVFrame *avcodec_alloc_frame(void)
{
     AVFrame *frame = av_mallocz(sizeof(AVFrame));
     return frame; 
}

void ffmpeg_encoder_start(const char *filename, int codec_id, int fps, int width, int height) {
    AVCodec *codec;
    int ret;
    avcodec_register_all();
    codec = avcodec_find_encoder(codec_id);
    if (!codec) {
        fprintf(stderr, "Codec not found\n");
        exit(1);
    }
    c = avcodec_alloc_context3(codec);
    if (!c) {
        fprintf(stderr, "Could not allocate video codec context\n");
        exit(1);
    }
    c->bit_rate = 400000000;
    c->width = width;
    c->height = height;
    c->time_base.num = 1;
    c->time_base.den = fps;
    c->gop_size = 10;
    c->max_b_frames = 1;
    c->pix_fmt = AV_PIX_FMT_YUV420P;
    if (codec_id == AV_CODEC_ID_H264)
        av_opt_set(c->priv_data, "preset", "slow", 0);
    if (avcodec_open2(c, codec, NULL) < 0) {
        fprintf(stderr, "Could not open codec\n");
        exit(1);
    }
    file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open %s\n", filename);
        exit(1);
    }
    frame = avcodec_alloc_frame();
    if (!frame) {
        fprintf(stderr, "Could not allocate video frame\n");
        exit(1);
    }
    frame->format = c->pix_fmt;
    frame->width  = c->width;
    frame->height = c->height;
    ret = av_image_alloc(frame->data, frame->linesize, c->width, c->height, c->pix_fmt, 32);
    if (ret < 0) {
        fprintf(stderr, "Could not allocate raw picture buffer\n");
        exit(1);
    }
}

void ffmpeg_encoder_finish(void) {
    uint8_t endcode[] = { 0, 0, 1, 0xb7 };
    int got_output, ret;
    do {
        fflush(stdout);
        ret = avcodec_encode_video2(c, &pkt, NULL, &got_output);
        if (ret < 0) {
            fprintf(stderr, "Error encoding frame\n");
            exit(1);
        }
        if (got_output) {
            fwrite(pkt.data, 1, pkt.size, file);
            av_free_packet(&pkt);
        }
    } while (got_output);
    fwrite(endcode, 1, sizeof(endcode), file);
    fclose(file);
    avcodec_close(c);
    av_free(c);
    av_freep(&frame->data[0]);
    //avcodec_free_frame(&frame);
}

void ffmpeg_encoder_encode_frame(uint8_t *rgb_m) {
    int ret, got_output;
    ffmpeg_encoder_set_frame_yuv_from_rgb(rgb_m);
    av_init_packet(&pkt);
    pkt.data = NULL;
    pkt.size = 0;
    ret = avcodec_encode_video2(c, &pkt, frame, &got_output);
    if (ret < 0) {
        fprintf(stderr, "Error encoding frame\n");
        exit(1);
    }
    if (got_output) {
        fwrite(pkt.data, 1, pkt.size, file);
        av_free_packet(&pkt);
    }
}

void ffmpeg_encoder_glread_rgb(uint8_t **rgb_m, GLubyte **pixels, unsigned int width, unsigned int height) {
    size_t i, j, k, cur_gl, cur_rgb, nvals;
    const size_t format_nchannels = 4;
    nvals = format_nchannels * width * height;
    *pixels = realloc(*pixels, nvals * sizeof(GLubyte));
    *rgb_m = realloc(*rgb_m, nvals * sizeof(uint8_t));
    /* Get RGBA to align to 32 bits instead of just 24 for RGB. May be faster for FFmpeg. */
    glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, *pixels);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            cur_gl  = format_nchannels * (width * (height - i - 1) + j);
            cur_rgb = format_nchannels * (width * i + j);
            for (k = 0; k < format_nchannels; k++)
                (*rgb_m)[cur_rgb + k] = (*pixels)[cur_gl + k];
        }
    }
}
#endif

static int model_init(void) {
    angle = 0;
    delta_angle = 1;
}

static int model_update(void) {
    angle += delta_angle;
    return 0;
}

int model_finished(void) {
    return nframes >= max_nframes;
}
void INITIALIZE_RECORDER(void)  {
    int glget;

    if (offscreen) {
        /*  Framebuffer */
        glGenFramebuffers(1, &fbo);
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);

        /* Color renderbuffer. */
        glGenRenderbuffers(1, &rbo_color);
        glBindRenderbuffer(GL_RENDERBUFFER, rbo_color);
        /* Storage must be one of: */
        /* GL_RGBA4, GL_RGB565, GL_RGB5_A1, GL_DEPTH_COMPONENT16, GL_STENCIL_INDEX8. */
        glRenderbufferStorage(GL_RENDERBUFFER, GL_RGB565, WIDTH, HEIGHT);
        glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, rbo_color);

        /* Depth renderbuffer. */
        glGenRenderbuffers(1, &rbo_depth);
        glBindRenderbuffer(GL_RENDERBUFFER, rbo_depth);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, WIDTH, HEIGHT);
        glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rbo_depth);

        glReadBuffer(GL_COLOR_ATTACHMENT0);

        /* Sanity check. */
        //assert(glCheckFramebufferStatus(GL_FRAMEBUFFER));
        glGetIntegerv(1000000, &glget);
        printf("(WIDTH * HEIGHT = %d \n", (WIDTH * HEIGHT));
            printf("(glget = %d \n", (glget));
      //assert(WIDTH * HEIGHT < (unsigned int)glget);
    } else {
        glReadBuffer(GL_BACK);
    }

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glViewport(0, 0, WIDTH, HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    time0 = glutGet(GLUT_ELAPSED_TIME);
    model_init();
#if FFMPEG
    ffmpeg_encoder_start("sim.mpg",  1, 60, WIDTH, HEIGHT);
#endif
}

static void deinit(void)  {
    printf("FPS = %f\n", 1000.0 * nframes / (double)(glutGet(GLUT_ELAPSED_TIME) - time0));
    free(pixels);
#if LIBPNG
    free(png_bytes);
    free(png_rows);
#endif
#if FFMPEG
    ffmpeg_encoder_finish();
    free(RGB_FFMPEG);
#endif
    if (offscreen) {
        glDeleteFramebuffers(1, &fbo);
        glDeleteRenderbuffers(1, &rbo_color);
        glDeleteRenderbuffers(1, &rbo_depth);
    }
}
