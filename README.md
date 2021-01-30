# klarna

gcc oscillera.c integrator.c tinyexpr.c tinyexpr.h  -std=c99  -lm -lc -pthread -lglut  -lGLU -lGL -lSDL2 -ljpeg kdtree.c -DNO_ALLOCA -D__STDC_CONSTANT_MACROS -lavcodec -lavutil -lavformat  -lswscale  loadObj.c mpeg.c -o oscillera -lavcodec -lavutil -lswscale  -lm -lglut -lGL  `pkg-config --cflags --libs gtk+-3.0` catmull/*.c  -lGLU
