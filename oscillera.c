#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <GL/glut.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include "system.h"
#include "kdtree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>
double length__ =0;
/* Some <math.h> files do not define M_PI... */
#ifndef M_PI
#define M_PI 3.14159216358979323846
#endif

#define TWO_PI  (2*M_PI)

typedef struct lightRec {
  float amb[4];
  float diff[4];
  float spec[4];
  float pos[4];
  float spotDir[3];
  float spotExp;
  float spotCutoff;
  float atten[3];

  float trans[3];
  float rot[3];
  float swing[3];
  float arc[3];
  float arcIncr[3];
} Light;

static int useSAME_AMB_SPEC = 1;
/* *INDENT-OFF* */
static float modelAmb[4] = {0.2, 0.2, 0.2, 1.0};

static float matAmb[4] = {0.2, 0.2, 0.2, 1.0};
static float matDiff[4] = {0.8, 0.8, 0.8, 1.0};
static float matSpec[4] = {0.4, 0.4, 0.4, 1.0};
static float matEmission[4] = {0.0, 0.0, 0.0, 1.0};
/* *INDENT-ON* */

#define NUM_LIGHTS 3
static Light spots[] =
{
  {
    {0.2, 0.0, 0.0, 1.0},  /* ambient */
    {0.8, 0.0, 0.0, 1.0},  /* diffuse */
    {0.4, 0.0, 0.0, 1.0},  /* specular */
    {0.0, 0.0, 0.0, 1.0},  /* position */
    {0.0, -1.0, 0.0},   /* direction */
    20.0,
    60.0,               /* exponent, cutoff */
    {1.0, 0.0, 0.0},    /* attenuation */
    {0.0, 1.25, 0.0},   /* translation */
    {0.0, 0.0, 0.0},    /* rotation */
    {20.0, 0.0, 40.0},  /* swing */
    {0.0, 0.0, 0.0},    /* arc */
    {TWO_PI / 70.0, 0.0, TWO_PI / 140.0}  /* arc increment */
  },
  {
    {0.0, 0.2, 0.0, 1.0},  /* ambient */
    {0.0, 0.8, 0.0, 1.0},  /* diffuse */
    {0.0, 0.4, 0.0, 1.0},  /* specular */
    {0.0, 0.0, 0.0, 1.0},  /* position */
    {0.0, -1.0, 0.0},   /* direction */
    20.0,
    60.0,               /* exponent, cutoff */
    {1.0, 0.0, 0.0},    /* attenuation */
    {0.0, 1.25, 0.0},   /* translation */
    {0.0, 0.0, 0.0},    /* rotation */
    {20.0, 0.0, 40.0},  /* swing */
    {0.0, 0.0, 0.0},    /* arc */
    {TWO_PI / 120.0, 0.0, TWO_PI / 60.0}  /* arc increment */
  },
  {
    {0.0, 0.0, 0.2, 1.0},  /* ambient */
    {0.0, 0.0, 0.8, 1.0},  /* diffuse */
    {0.0, 0.0, 0.4, 1.0},  /* specular */
    {0.0, 0.0, 0.0, 1.0},  /* position */
    {0.0, -1.0, 0.0},   /* direction */
    20.0,
    60.0,               /* exponent, cutoff */
    {1.0, 0.0, 0.0},    /* attenuation */
    {0.0, 1.25, 0.0},   /* translation */
    {0.0, 0.0, 0.0},    /* rotation */
    {20.0, 0.0, 40.0},  /* swing */
    {0.0, 0.0, 0.0},    /* arc */
    {TWO_PI / 50.0, 0.0, TWO_PI / 100.0}  /* arc increment */
  }
};

static void
initLights(void)
{
  int k;

  for (k = 0; k < NUM_LIGHTS; ++k) {
    int lt = GL_LIGHT0 + k;
    Light *light = &spots[k];

    glEnable(lt);
    glLightfv(lt, GL_AMBIENT, light->amb);
    glLightfv(lt, GL_DIFFUSE, light->diff);

    if (useSAME_AMB_SPEC)
      glLightfv(lt, GL_SPECULAR, light->amb);
    else
      glLightfv(lt, GL_SPECULAR, light->spec);

    glLightf(lt, GL_SPOT_EXPONENT, light->spotExp);
    glLightf(lt, GL_SPOT_CUTOFF, light->spotCutoff);
    glLightf(lt, GL_CONSTANT_ATTENUATION, light->atten[0]);
    glLightf(lt, GL_LINEAR_ATTENUATION, light->atten[1]);
    glLightf(lt, GL_QUADRATIC_ATTENUATION, light->atten[2]);
  }
}

static void
aimLights(void)
{
  int k;

  for (k = 0; k < NUM_LIGHTS; ++k) {
    Light *light = &spots[k];

    light->rot[0] = light->swing[0] * sin(light->arc[0]);
    light->arc[0] += light->arcIncr[0];
    if (light->arc[0] > TWO_PI)
      light->arc[0] -= TWO_PI;

    light->rot[1] = light->swing[1] * sin(light->arc[1]);
    light->arc[1] += light->arcIncr[1];
    if (light->arc[1] > TWO_PI)
      light->arc[1] -= TWO_PI;

    light->rot[2] = light->swing[2] * sin(light->arc[2]);
    light->arc[2] += light->arcIncr[2];
    if (light->arc[2] > TWO_PI)
      light->arc[2] -= TWO_PI;
  }
}

static void
setLights(void)
{
  int k;

  for (k = 0; k < NUM_LIGHTS; ++k) {
    int lt = GL_LIGHT0 + k;
    Light *light = &spots[k];

    glPushMatrix();
    glTranslatef(light->trans[0], light->trans[1], light->trans[2]);
    glRotatef(light->rot[0], 1, 0, 0);
    glRotatef(light->rot[1], 0, 1, 0);
    glRotatef(light->rot[2], 0, 0, 1);
    glLightfv(lt, GL_POSITION, light->pos);
    glLightfv(lt, GL_SPOT_DIRECTION, light->spotDir);
    glPopMatrix();
  }
}

static void
drawLights(void)
{
  int k;

  glDisable(GL_LIGHTING);
  for (k = 0; k < NUM_LIGHTS; ++k) {
    Light *light = &spots[k];

    glColor4fv(light->diff);

    glPushMatrix();
    glTranslatef(light->trans[0], light->trans[1], light->trans[2]);
    glRotatef(light->rot[0], 1, 0, 0);
    glRotatef(light->rot[1], 0, 1, 0);
    glRotatef(light->rot[2], 0, 0, 1);
    glBegin(GL_LINES);
    glVertex3f(light->pos[0], light->pos[1], light->pos[2]);
    glVertex3f(light->spotDir[0], light->spotDir[1], light->spotDir[2]);
    glEnd();
    glPopMatrix();
  }
  glEnable(GL_LIGHTING);
}

int INDEX_NR1;
int INDEX_NR2;
int INDEX_NRmore;
int playsound(double length);
 double length_______ =0;
float springlength =  0.004 ;
float dNear = 100;
float dFar = 2000;
double gravity[40] = { 9.8,9.8,9.8,9.8,9.8,9.8,9.8,9.8,9.8,9.8,9.8,9.8 ,9.8,9.8,9.8,9.8,9.8,9.8,9.8,9.8};
struct state_vector       worm_ventral(struct state_vector       next_state, int num,int kkkk );
#define HOW_MANY_FLUIDS 12
#define HOWMANY HOW_MANY_FLUIDS
double F_total[3][  7936][7][55][3] ;
int totalneigbours[  7936][7][3] ;
  struct state_vector  *  springVector;
struct state_vector    ***  springharmony_status_link    ; 
 
struct state_vector    ***   springharmony_status_link_   ; 
int llll = 0;
 
int feather_once = 1;
int INDEX_NR = 0;
 
Material *material;

float cameraEye[3] = {0.0, 0.0, 1000.0};
float lightRotation[16] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
float cameraLookAt[4] = {0.0, 0.0, 0.0, 1.0};
float cameraUp[4] = {0.0, 1.0, 0.0};

float viewRotation[16] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};

float rotationX=0.0;
float rotationY=0.0;
 
void rates_dorsal ( double *t, double *f, double result[]   );
void key(unsigned char key, int x, int y);
int findnearestpoint(int points,struct state_vector ** worm , int num,int howmany, int whantindex,double length,int kkkk) ;
  //double length (struct state_vector a,struct state_vector b ,int kkkk,int nnnn) { return sqrtf ( b.pos_new_x[nnnn]*a.pos_new_x[kkkk] + b.pos_new_y[nnnn]*a.pos_new_y[kkkk] + b.pos_new_z[nnnn]*a.pos_new_z[kkkk]); }
   double length(struct state_vector a,struct state_vector b,int kkkk,int nnnn ) {double rr =  sqrtf( pow(a.pos_new_x[kkkk]-b.pos_new_x[nnnn],2.0) +  pow(a.pos_new_y[kkkk]-b.pos_new_y[nnnn],2.0) +  pow(a.pos_new_z[kkkk]-b.pos_new_z[nnnn],2.0)); return rr;}
static double dist_sq( double *a1, double *a2, int dims ) {
  double dist_sq = 0, diff;
  while( --dims >= 0 ) {
    diff = (a1[dims] - a2[dims]);
    dist_sq += diff*diff;
  }
  return dist_sq;
}
float global_ambient[4] = {0.0, 0.0, 0.0, 0.0};
 
float prevX=0.0;
float prevY=0.0;
bool mouseDown=false;
 
void mouseMotion(int x, int y){
    if(mouseDown){
        rotationX = y - prevY;
        rotationY = x - prevX;
        glutPostRedisplay();
    }
}
 
int k_flappers = 0;
int whatNET = 0;
int kkkk_ = 0;
void springharmony( int kkkkkkkk, int xxx , int whatnet, int kkkk)
{
	 llll = kkkkkkkk;
	 k_flappers = xxx;
	 whatNET = whatnet;
	 int k = xxx;
 	kkkk_ = kkkk;
	 INDEX_NR =   springharmony_status_link[llll][k][whatnet].INDEX_NR[kkkk] ;
  
 
				 if(fabs(F_total[0][INDEX_NR][whatnet][k][kkkk]) > 61.1233 )
	 				 	  F_total[0][INDEX_NR][whatnet][k][kkkk] =0;
		 		 if(fabs(F_total[1][INDEX_NR][whatnet][k][kkkk])  > 61.1233)
						F_total[1][INDEX_NR][whatnet][k][kkkk] =0;
			 	 if(fabs(F_total[2][INDEX_NR][whatnet][k][kkkk])  > 61.1233)
						F_total[2][INDEX_NR][whatnet][k][kkkk] =0;
 			 
 			 
 			 	 if(fabs(F_total[0][llll][whatnet][k][kkkk]) > 61.1233 )
	 				 F_total[0][llll][whatnet][k][kkkk] =0;
		 		 if(fabs(F_total[1][llll][whatnet][k][kkkk])  > 61.1233)
					 F_total[1][llll][whatnet][k][kkkk] =0;
			 	 if(fabs(F_total[2][llll][whatnet][k][kkkk])  > 61.1233)
					 F_total[2][llll][whatnet][k][kkkk] =0;
					 
					 
springVector->pos_new_x[kkkk] = springharmony_status_link_[INDEX_NR][k][whatnet].pos_new_x[kkkk] - springharmony_status_link_[llll][k][whatnet].pos_new_x[kkkk];
springVector->pos_new_y[kkkk] = springharmony_status_link_[INDEX_NR][k][whatnet].pos_new_y[kkkk] - springharmony_status_link_[llll][k][whatnet].pos_new_y[kkkk];
springVector->pos_new_z[kkkk] = springharmony_status_link_[INDEX_NR][k][whatnet].pos_new_z[kkkk] - springharmony_status_link_[llll][k][whatnet].pos_new_z[kkkk];
 
				float r = length(springharmony_status_link_[INDEX_NR][k][whatnet],springharmony_status_link_[llll][k][whatnet],kkkk,kkkk);
// printf("r=%f \n", r);
springharmony_status_link_[INDEX_NR][k][whatnet].length = r ;
springharmony_status_link_[llll][k][whatnet].length = r ;
		if ( r != 0  &&    (r) < 3.323333&&   (r) > -3.323333  )
		{	
length_______ = r;
F_total[0][INDEX_NR][whatnet][k][kkkk] +=( springVector->pos_new_x[kkkk]  /  r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );
F_total[1][INDEX_NR][whatnet][k][kkkk] += ( springVector->pos_new_y[kkkk] /  r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );
F_total[2][INDEX_NR][whatnet][k][kkkk] +=( springVector->pos_new_z[kkkk]  /  r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );

F_total[0][llll][whatnet][k][kkkk] +=( springVector->pos_new_x[kkkk]  / r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );
F_total[1][llll][whatnet][k][kkkk] += ( springVector->pos_new_y[kkkk]  / r ) * ( r - springlength) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );
F_total[2][llll][whatnet][k][kkkk] +=( springVector->pos_new_z[kkkk]  / r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );

F_total[0][INDEX_NR][whatnet][k][kkkk] +=-(  springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_x[kkkk] - springharmony_status_link_[llll][k][whatnet].vel_new_x[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];
F_total[1][INDEX_NR][whatnet][k][kkkk] += -( springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_y[kkkk]- springharmony_status_link_[llll][k][whatnet].vel_new_y[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];
F_total[2][INDEX_NR][whatnet][k][kkkk] += -(  springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_z[kkkk] - springharmony_status_link_[llll ][k][whatnet].vel_new_z[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];


F_total[0][llll][whatnet][k][kkkk] +=-(  springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_x[kkkk] - springharmony_status_link_[llll][k][whatnet].vel_new_x[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];
F_total[1][llll][whatnet][k][kkkk] += -( springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_y[kkkk]- springharmony_status_link_[llll][k][whatnet].vel_new_y[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];
F_total[2][llll][whatnet][k][kkkk] += -(  springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_z[kkkk] - springharmony_status_link_[llll ][k][whatnet].vel_new_z[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];

springharmony_status_link_[llll][k][whatnet].vel_new_x[kkkk] = springharmony_status_link_[llll][k][whatnet].vel_new_x[kkkk]*0.995 ;
springharmony_status_link_[llll][k][whatnet].vel_new_y[kkkk] = springharmony_status_link_[llll][k][whatnet].vel_new_y[kkkk]*0.995 ;
springharmony_status_link_[llll][k][whatnet].vel_new_z[kkkk] = springharmony_status_link_[llll][k][whatnet].vel_new_z[kkkk]*0.995 ;
springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_x[kkkk]= springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_x[kkkk]*0.995 ;
springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_y[kkkk] = springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_y[kkkk]*0.995 ; 
springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_z[kkkk]= springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_z[kkkk]*0.995 ;
		}

		k_flappers = k;
	 	whatNET = whatnet;

		springharmony_status_link_[INDEX_NR][k][whatnet].force_sign[kkkk] =  -1;
		springharmony_status_link_[INDEX_NR][k][whatnet]    =  worm_ventral(   springharmony_status_link_[INDEX_NR][k][whatnet] ,1,kkkk) ;
springharmony_status_link_[INDEX_NR][k][whatnet].force_sign[kkkk] =  97;

 
		springharmony_status_link_[llll][k][whatnet].force_sign[kkkk] =   1;   
		springharmony_status_link_[llll][k][whatnet]    =  worm_ventral(   springharmony_status_link_[llll][k][whatnet] ,1,kkkk);
  
	for(int d = 0; d < totalneigbours[llll][whatnet][kkkk]; d++)
	{	 
	 
 
  		INDEX_NRmore = springharmony_status_link[llll][d][whatnet].INDEX_NR[kkkk];
  
		if(fabs(F_total[0][INDEX_NRmore][whatnet][k][kkkk]) > 61.1233 )
	 				  F_total[0][INDEX_NRmore][whatnet][k][kkkk] =0;
		if(fabs(F_total[1][INDEX_NRmore][whatnet][k][kkkk])  > 61.1233)
					  F_total[1][INDEX_NRmore][whatnet][k][kkkk] =0;
		if(fabs(F_total[2][INDEX_NRmore][whatnet][k][kkkk])  > 61.1233)
					  F_total[2][INDEX_NRmore][whatnet][k][kkkk] =0;
			

 		if(fabs(F_total[0][INDEX_NR][whatnet][k][kkkk]) > 61.1233 )
	 				  F_total[0][INDEX_NR][whatnet][k][kkkk] =0;
		if(fabs(F_total[1][INDEX_NR][whatnet][k][kkkk])  > 61.1233)
					  F_total[1][INDEX_NR][whatnet][k][kkkk] =0;
		if(fabs(F_total[2][INDEX_NR][whatnet][k][kkkk])  > 61.1233)
					  F_total[2][INDEX_NR][whatnet][k][kkkk] =0;
			
springVector->pos_new_x[kkkk] = springharmony_status_link_[INDEX_NR][k][whatnet].pos_new_x[kkkk]- springharmony_status_link_[INDEX_NRmore][k][whatnet].pos_new_x[kkkk];
springVector->pos_new_y[kkkk] = springharmony_status_link_[INDEX_NR][k][whatnet].pos_new_y[kkkk] - springharmony_status_link_[INDEX_NRmore][k][whatnet].pos_new_y[kkkk];
springVector->pos_new_z[kkkk] = springharmony_status_link_[INDEX_NR][k][whatnet].pos_new_z[kkkk] - springharmony_status_link_[INDEX_NRmore][k][whatnet].pos_new_z[kkkk];
 			
		float r = length(springharmony_status_link_[INDEX_NR][k][whatnet],springharmony_status_link_[INDEX_NRmore][k][whatnet],kkkk,kkkk);
 springharmony_status_link_[INDEX_NR][k][whatnet].length = r ;
springharmony_status_link_[INDEX_NRmore][k][whatnet].length = r ;
		if ( r != 0  &&   (r) <  3.323333 &&   (r) > -3.323333)
		{	

			F_total[0][INDEX_NR][whatnet][k][kkkk]+=( springVector->pos_new_x[kkkk]  /  r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );
			F_total[1][INDEX_NR][whatnet][k][kkkk]+= ( springVector->pos_new_y[kkkk] /  r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );
			F_total[2][INDEX_NR][whatnet][k][kkkk]+=( springVector->pos_new_z[kkkk]  /  r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );

			F_total[0][INDEX_NRmore][whatnet][k][kkkk]+=( springVector->pos_new_x[kkkk]  / r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );
			F_total[1][INDEX_NRmore][whatnet][k][kkkk]+= ( springVector->pos_new_y[kkkk]  / r ) * ( r - springlength) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );
			F_total[2][INDEX_NRmore][whatnet][k][kkkk]+=( springVector->pos_new_z[kkkk]  / r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );

			F_total[0][INDEX_NR][whatnet][k][kkkk]+=-(  springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_x[kkkk] - springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x[kkkk]) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];
 			F_total[1][INDEX_NR][whatnet][k][kkkk]+= -( springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_y[kkkk]- springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];
 			F_total[2][INDEX_NR][whatnet][k][kkkk]+= -(  springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_z[kkkk] - springharmony_status_link_[INDEX_NRmore ][k][whatnet].vel_new_z[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];


			F_total[0][INDEX_NRmore][whatnet][k][kkkk]+=-(  springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_x[kkkk] - springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];
 			F_total[1][INDEX_NRmore][whatnet][k][kkkk]+= -( springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_y[kkkk]- springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];
 			F_total[2][INDEX_NRmore][whatnet][k][kkkk]+= -(  springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_z[kkkk] - springharmony_status_link_[INDEX_NRmore ][k][whatnet].vel_new_z[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];

		  springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x[kkkk] = springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x[kkkk]*0.995 ;
		
		springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y[kkkk] = springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y[kkkk]*0.995 ;
		springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_z[kkkk] = springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_z[kkkk]*0.995 ;
		springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_x[kkkk] = springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_x[kkkk]*0.995 ;
		
		springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_y[kkkk] = springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_y[kkkk]*0.995 ;
		springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_z[kkkk] = springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_z[kkkk]*0.995 ;  
		}
		k_flappers = k;
		whatNET = whatnet;
		springharmony_status_link_[INDEX_NR][k][whatnet].force_sign[kkkk] =  -1;
		springharmony_status_link_[INDEX_NR][k][whatnet]    =  worm_ventral(   springharmony_status_link_[INDEX_NR][k][whatnet] ,1,kkkk) ;
springharmony_status_link_[INDEX_NR][k][whatnet].force_sign[kkkk] =  99;

 
		springharmony_status_link_[INDEX_NRmore][k][whatnet].force_sign[kkkk]=   -1;  
		springharmony_status_link_[INDEX_NRmore][k][whatnet]    =  worm_ventral(   springharmony_status_link_[INDEX_NRmore][k][whatnet] ,1,kkkk);
		springharmony_status_link_[INDEX_NRmore][k][whatnet].force_sign[kkkk] =   98;   
	 	
	}	 		
}

void springharmony_netonnet( int kkkkkkkk, int xxx , int whatnet, int whatnet2,int kkkk)
{
	llll = kkkkkkkk;
  	kkkk_ = kkkk;
	 k_flappers = xxx;
	 whatNET = whatnet;
	 int k = xxx;
	 int g = xxx;
  		
   for(int nnnn =0; nnnn < 2 ; nnnn++)
  {
	INDEX_NR1 =   springharmony_status_link[llll][k][whatnet].INDEX_NR[kkkk] ;
	INDEX_NR2 =   springharmony_status_link[llll][g][whatnet2].INDEX_NR[nnnn] ;

 	
				 if(fabs(F_total[0][INDEX_NR1][whatnet][k][kkkk]) > 61.1233 )
	 				 	  F_total[0][INDEX_NR1][whatnet][k][kkkk]=0;
 
		 		 if(fabs(F_total[1][INDEX_NR1][whatnet][k][kkkk])  > 61.1233)
						F_total[1][INDEX_NR1][whatnet][k][kkkk]=0;

			 	 if(fabs(F_total[2][INDEX_NR1][whatnet][k][kkkk])  > 61.1233)
						F_total[2][INDEX_NR1][whatnet][k][kkkk]=0;



				 if(fabs(F_total[0][INDEX_NR2][whatnet2][g][nnnn]) > 61.1233 )
	 				 	  F_total[0][INDEX_NR2][whatnet2][g][nnnn]=0;
 
		 		 if(fabs(F_total[1][INDEX_NR2][whatnet2][g][nnnn])  > 61.1233)
						F_total[1][INDEX_NR2][whatnet2][g][nnnn]=0;

			 	 if(fabs(F_total[2][INDEX_NR2][whatnet2][g][nnnn])  > 61.1233)
						F_total[2][INDEX_NR2][whatnet2][g][nnnn]=0;
 			 
springVector->pos_new_x[kkkk] = springharmony_status_link_[INDEX_NR1][k][whatnet].pos_new_x[kkkk]- springharmony_status_link_[INDEX_NR2][g][whatnet2].pos_new_x[nnnn];
springVector->pos_new_y[kkkk] = springharmony_status_link_[INDEX_NR1][k][whatnet].pos_new_y[kkkk] - springharmony_status_link_[INDEX_NR2][g][whatnet2].pos_new_y[nnnn];
springVector->pos_new_z[kkkk] = springharmony_status_link_[INDEX_NR1][k][whatnet].pos_new_z[kkkk] - springharmony_status_link_[INDEX_NR2][g][whatnet2].pos_new_z[nnnn];
 
float r = length(springharmony_status_link_[INDEX_NR1][k][whatnet],springharmony_status_link_[INDEX_NR2][g][whatnet2],kkkk,nnnn);
 springharmony_status_link_[INDEX_NR1][k][whatnet].length = r ;
springharmony_status_link_[INDEX_NR2][k][whatnet2].length = r ;
if ( r != 0  &&    (r) < 3.323333&&   (r) > -3.323333 )
{	

	F_total[0][INDEX_NR1][whatnet][k][kkkk]+=( springVector->pos_new_x[kkkk]  /  r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );
	F_total[1][INDEX_NR1][whatnet][k][kkkk]+= ( springVector->pos_new_y[kkkk] /  r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );
	F_total[2][INDEX_NR1][whatnet][k][kkkk]+=( springVector->pos_new_z[kkkk]  /  r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );

	F_total[0][INDEX_NR2][whatnet2][g][nnnn]+=( springVector->pos_new_x[kkkk]  / r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );
	F_total[1][INDEX_NR2][whatnet2][g][nnnn]+= ( springVector->pos_new_y[kkkk]  / r ) * ( r - springlength) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );
	F_total[2][INDEX_NR2][whatnet2][g][nnnn]+=( springVector->pos_new_z[kkkk]  / r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );

	F_total[0][INDEX_NR1][whatnet][k][kkkk]+=-(  springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_x[kkkk] - springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_x[nnnn] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];
 	F_total[1][INDEX_NR1][whatnet][k][kkkk]+= -( springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_y[kkkk]- springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_y[nnnn] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];
 	F_total[2][INDEX_NR1][whatnet][k][kkkk]+= -(  springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_z[kkkk] - springharmony_status_link_[INDEX_NR2 ][k][whatnet2].vel_new_z[nnnn] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];


	F_total[0][INDEX_NR2][whatnet2][g][nnnn]+=-(  springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_x[kkkk] - springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_x[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];
 	F_total[1][INDEX_NR2][whatnet2][g][nnnn]+= -( springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_y[kkkk]- springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_y[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];
 	F_total[2][INDEX_NR2][whatnet2][g][nnnn]+= -(  springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_z[kkkk] - springharmony_status_link_[INDEX_NR2 ][k][whatnet2].vel_new_z[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];
springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_x[nnnn] = springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_x[nnnn]*0.995 ;		
springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_y[nnnn] = springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_y[nnnn]*0.995 ;
springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_z[nnnn] = springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_z[nnnn]*0.995 ;
springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_x[kkkk] = springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_x[kkkk]*0.995 ;
springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_y[kkkk] = springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_y[kkkk]*0.995 ; 
springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_z[kkkk]= springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_z[kkkk]*0.995 ; 
}
		 k_flappers = k;
		 whatNET = whatnet;
kkkk_ = kkkk;
		springharmony_status_link_[INDEX_NR1][k][whatnet].force_sign[kkkk] =  -1;
		springharmony_status_link_[INDEX_NR1][k][whatnet]    =  worm_ventral(   springharmony_status_link_[INDEX_NR1][k][whatnet] ,1,kkkk) ;
springharmony_status_link_[INDEX_NR1][k][whatnet].force_sign[kkkk] =  9911;

 
kkkk_ = nnnn;
	 k_flappers = g;
whatNET = whatnet2;
		springharmony_status_link_[INDEX_NR2][g][whatnet2].force_sign[nnnn] =   1;  
		springharmony_status_link_[INDEX_NR2][g][whatnet2]    =  worm_ventral(   springharmony_status_link_[INDEX_NR2][g][whatnet2] ,1,nnnn);
 springharmony_status_link_[INDEX_NR2][k][whatnet].force_sign[nnnn] =  1234;
 
 
	for(int d = 0; d < totalneigbours[INDEX_NR1][whatnet][kkkk]; d++)
	{	 
		
 
 
		INDEX_NRmore = springharmony_status_link[INDEX_NR1][d][whatnet].INDEX_NR[kkkk];
 
		if(fabs(F_total[0][INDEX_NRmore][whatnet][k][kkkk]) > 61.1233 )
	 				  F_total[0][INDEX_NRmore][whatnet][k][kkkk]=0;
		if(fabs(F_total[1][INDEX_NRmore][whatnet][k][kkkk])  > 61.1233)
					  F_total[1][INDEX_NRmore][whatnet][k][kkkk]=0;
		if(fabs(F_total[2][INDEX_NRmore][whatnet][k][kkkk])  > 61.1233)
					  F_total[2][INDEX_NRmore][whatnet][k][kkkk]=0;
			

 		if(fabs(F_total[0][INDEX_NR2][whatnet][k][nnnn]) > 61.1233 )
	 				  F_total[0][INDEX_NR2][whatnet][k][nnnn]=0;
		if(fabs(F_total[1][INDEX_NR2][whatnet][k][nnnn])  > 61.1233)
					  F_total[1][INDEX_NR2][whatnet][k][nnnn]=0;
		if(fabs(F_total[2][INDEX_NR2][whatnet][k][nnnn])  > 61.1233)
					  F_total[2][INDEX_NR2][whatnet][k][nnnn]=0;
			
springVector->pos_new_x[kkkk] = springharmony_status_link_[INDEX_NR2][g][whatnet2].pos_new_x[nnnn] - springharmony_status_link_[INDEX_NRmore][k][whatnet].pos_new_x[kkkk];
springVector->pos_new_y[kkkk] = springharmony_status_link_[INDEX_NR2][g][whatnet2].pos_new_y[nnnn] - springharmony_status_link_[INDEX_NRmore][k][whatnet].pos_new_y[kkkk];
springVector->pos_new_z[kkkk] = springharmony_status_link_[INDEX_NR2][g][whatnet2].pos_new_z[nnnn] - springharmony_status_link_[INDEX_NRmore][k][whatnet].pos_new_z[kkkk];
 			
float r = length(springharmony_status_link_[INDEX_NR2][g][whatnet2],springharmony_status_link_[INDEX_NRmore][k][whatnet],kkkk,nnnn);
 springharmony_status_link_[INDEX_NR2][k][whatnet2].length = r ;
springharmony_status_link_[INDEX_NRmore][k][whatnet].length = r ;
if ( r != 0  &&   (r) <  3.323333 &&   (r) > -3.323333 )
{	

F_total[0][INDEX_NR2][whatnet2][g][nnnn]+=( springVector->pos_new_x[kkkk]  /  r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );
F_total[1][INDEX_NR2][whatnet2][g][nnnn]+= ( springVector->pos_new_y[kkkk] /  r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );
F_total[2][INDEX_NR2][whatnet2][g][nnnn]+=( springVector->pos_new_z[kkkk]  /  r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );

F_total[0][INDEX_NRmore][whatnet][k][kkkk]+=( springVector->pos_new_x[kkkk]  / r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );
F_total[1][INDEX_NRmore][whatnet][k][kkkk]+= ( springVector->pos_new_y[kkkk]  / r ) * ( r - springlength) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );
F_total[2][INDEX_NRmore][whatnet][k][kkkk]+=( springVector->pos_new_z[kkkk]  / r ) * ( r - springlength ) * ( -springharmony_status_link_[llll][0][whatnet].springConstant[kkkk] );

F_total[0][INDEX_NR2][whatnet2][g][nnnn]+=-(  springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_x[nnnn] - springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];
F_total[1][INDEX_NR2][whatnet2][g][nnnn]+= -( springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_y[nnnn]- springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];
F_total[2][INDEX_NR2][whatnet2][g][nnnn]+= -(  springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_z[nnnn] - springharmony_status_link_[INDEX_NRmore ][k][whatnet].vel_new_z[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];


F_total[0][INDEX_NRmore][whatnet][k][kkkk]+=-(  springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_x[nnnn] - springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];
F_total[1][INDEX_NRmore][whatnet][k][kkkk]+= -( springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_y[nnnn]- springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];
F_total[2][INDEX_NRmore][whatnet][k][kkkk]+= -(  springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_z[nnnn] - springharmony_status_link_[INDEX_NRmore ][k][whatnet].vel_new_z[kkkk] ) * springharmony_status_link_[llll][0][whatnet].frictionConstant[kkkk];

springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x[kkkk] = springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x[kkkk]*0.995 ;	
springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y[kkkk] = springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y[kkkk]*0.995 ;
springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_z[kkkk] = springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_z[kkkk]*0.995 ;
springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_x[nnnn] = springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_x[nnnn]*0.995 ;	
springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_y[nnnn] = springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_y[nnnn]*0.995 ;
springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_z[nnnn] = springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_z[nnnn]*0.995 ;  
		}
 	k_flappers = g;
	whatNET = whatnet2;
	kkkk_ = nnnn;
springharmony_status_link_[INDEX_NR2][g][whatnet2].force_sign[nnnn] =   1;
springharmony_status_link_[INDEX_NR2][g][whatnet2]   =  worm_ventral(   springharmony_status_link_[INDEX_NR2][g][whatnet2] ,1,nnnn) ;
 springharmony_status_link_[INDEX_NR2][k][whatnet].force_sign[nnnn] =  1234;
 
  
k_flappers = k;
whatNET = whatnet;
kkkk_ = kkkk;
springharmony_status_link_[INDEX_NRmore][k][whatnet].force_sign[kkkk] =   -1;  
springharmony_status_link_[INDEX_NRmore][k][whatnet]  =  worm_ventral(   springharmony_status_link_[INDEX_NRmore][k][whatnet] ,1,kkkk);
 springharmony_status_link_[INDEX_NRmore][k][whatnet].force_sign[kkkk] =  4321;
 

  }
				 if(fabs(F_total[0][INDEX_NR1][whatnet][k][kkkk]) > 61.1233 )
	 				 	  F_total[0][INDEX_NR1][whatnet][k][kkkk]=0;
		 		 if(fabs(F_total[1][INDEX_NR1][whatnet][k][kkkk])  > 61.1233)
						F_total[1][INDEX_NR1][whatnet][k][kkkk]=0;
			 	 if(fabs(F_total[2][INDEX_NR1][whatnet][k][kkkk])  > 61.1233)
						F_total[2][INDEX_NR1][whatnet][k][kkkk]=0;

				 if(fabs(F_total[0][INDEX_NR2][whatnet2][g][nnnn]) > 61.1233 )
	 				 	  F_total[0][INDEX_NR2][whatnet2][g][nnnn]=0;
		 		 if(fabs(F_total[1][INDEX_NR2][whatnet2][g][nnnn])  > 61.1233)
						F_total[1][INDEX_NR2][whatnet2][g][nnnn]=0;
			 	 if(fabs(F_total[2][INDEX_NR2][whatnet2][g][nnnn])  > 61.1233)
						F_total[2][INDEX_NR2][whatnet2][g][nnnn]=0;
						
						}
}
int num_pts =0;
int allround2 = 3840;
int find_index_____(int NUM, struct state_vector     ***real,int num,int k,int what,int kkkk )
{
int i = 0;
  allround2 = springharmony_status_link_[0][0][0].totnumpoints[kkkk];
	  while(allround2 > 0)
  {	

  	if(num > allround2 && num < num_pts -allround2)
  	{
 
  	for( i=num-allround2; i<num+allround2; i++ ) { 
  	
  	if(springharmony_status_link[num][k][what].pos_new_x[kkkk] ==real[i][k][what].pos_new_x[kkkk] && springharmony_status_link[num][k][what].pos_new_y[kkkk] ==           real[i][k][what].pos_new_y[kkkk] && springharmony_status_link[num][k][what].pos_new_z[kkkk] ==real[i][k][what].pos_new_z[kkkk])
		{
			// printf("found index_____ @ %d \n", ll);
			return i;
		}  
 	 }
 break;
 }
 else if(num <  allround2)
 {
 
  	for( i=0; i<allround2; i++ ) {
  	if(springharmony_status_link[num][k][what].pos_new_x[kkkk] ==real[i][k][what].pos_new_x[kkkk] && springharmony_status_link[num][k][what].pos_new_y[kkkk] ==           real[i][k][what].pos_new_y[kkkk] && springharmony_status_link[num][k][what].pos_new_z[kkkk] ==real[i][k][what].pos_new_z[kkkk])
		{
			// printf("found index_____ @ %d \n", ll);
			return i;
		}    
 	 }

break;
 }
 else
 {
 
 
  allround2--;
 
 }
	
}	
}
int allround = 3840;

int ptreeonce[215][25] = {1,1 ,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 ,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 ,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int findnearestpoint(int points,struct state_vector ** worm , int num,int howmany, int whantindex,double length,int kkkk)  {
allround = springharmony_status_link_[0][0][0].totnumpoints[kkkk];
int i = points;
 void *ptree ;
int INDEX;
num_pts = points;
struct kdres *presults;
double pos[3], dist;
double pt[3] = { springharmony_status_link_[num][0][whantindex].pos_new_x[kkkk],springharmony_status_link_[num][0][whantindex].pos_new_y[kkkk], springharmony_status_link_[num][0][whantindex].pos_new_z[kkkk] };
double radius = length;
  while(allround >= 0)
  {	

  	if(num > allround && num < points -allround)
  	{
  	ptree= kd_create( 3 );
  	for( i=num-allround; i<num+allround; i++ ) {   
    		assert( 0 == kd_insert3( ptree, springharmony_status_link_[i][0][whantindex].pos_new_x[kkkk], springharmony_status_link_[i][0][whantindex].pos_new_y[kkkk], springharmony_status_link_[i][0][whantindex].pos_new_z[kkkk], NULL ) );
 	 }
 	 presults = kd_nearest_range( ptree, pt, radius );
 break;
 }
 else if(num <=  allround)
 {
  	ptree = kd_create( 3 );
  	for( i=0; i<allround; i++ ) {   
    		assert( 0 == kd_insert3( ptree, springharmony_status_link_[i][0][whantindex].pos_new_x[kkkk], springharmony_status_link_[i][0][whantindex].pos_new_y[kkkk], springharmony_status_link_[i][0][whantindex].pos_new_z[kkkk], NULL ) );
 	 }
presults = kd_nearest_range( ptree, pt, radius );
break;
 }
 else
 {
 
  allround--;
 
 }
 
 }
 
springharmony_status_link[num][0][whantindex].totaln = kd_res_size(presults) ;
int feather_count = 0;
   	totalneigbours[num][whantindex][kkkk] = springharmony_status_link[num][0][whantindex].totaln;
while( !kd_res_end( presults ) ) {
	(char*)kd_res_item( presults, pos ); 

	springharmony_status_link[num][feather_count][whantindex].pos_new_x[kkkk] = pos[0];
	springharmony_status_link[num][feather_count][whantindex].pos_new_y[kkkk] = pos[1];
	springharmony_status_link[num][feather_count][whantindex].pos_new_z[kkkk] = pos[2];



 	feather_count++;
   	kd_res_next( presults );
	if(num % 1000 ==0)
 		printf("num @ %d \n", num);
}
  kd_res_free( presults );
int k = 0;
while(     k < feather_count )  
{
  INDEX = find_index_____(springharmony_status_link_[0][0][0].totnumpoints[kkkk],springharmony_status_link,num,k,whantindex,kkkk);
  	springharmony_status_link[num][k][whantindex].INDEX_NR[kkkk] = INDEX;
 
  	k++;
  	}
  feather_count = 0;
allround = springharmony_status_link_[0][0][0].totnumpoints[kkkk];
 kd_free( ptree );
  return 0;
}
 
 
#include "catmull/gl.h"
#include "catmull/gl_util.h"
#include "catmull/mathx.h"
#include "catmull/mesh.h"
#include "catmull/meshrend.h"
#include "catmull/editor.h"
extern float  **V ; 
 
 
struct state_vector       worm_ventral(struct state_vector        next_state, int num,int kkkk )
{
	double f0[6];
	double f0_result[6];

	double z[6];
 	double t0[6] = {0.0,0.0,0.0,0.0,0.0,0.0};
 	double tburn =  1.0;
	double tf[6] = {tburn,tburn,tburn,tburn,tburn,tburn};

	z[0] =  next_state.pos_new_x[kkkk];
	z[1] =  next_state.pos_new_y[kkkk];
	z[2] = next_state.pos_new_z[kkkk];
	z[3] =  next_state.vel_new_x[kkkk];
	z[4] =  next_state.vel_new_y[kkkk];
	z[5] = next_state.vel_new_z[kkkk];

	f0[0] = next_state.pos_new_x[kkkk];
	f0[1] =next_state.pos_new_y[kkkk];
	f0[2] =next_state.pos_new_z[kkkk];
	f0[3] =next_state.vel_new_x[kkkk];
	f0[4] =next_state.vel_new_y[kkkk];
	f0[5] = next_state.vel_new_z[kkkk];
 
	rk45(rates_dorsal, t0, f0,f0_result, tf,z,6, 1  );

	next_state.pos_new_x[kkkk] = f0[0];
	next_state.pos_new_y[kkkk] = f0[1];
	next_state.pos_new_z[kkkk] = f0[2];

	next_state.vel_new_x[kkkk] = f0[3];
	next_state.vel_new_y[kkkk] = f0[4];
	next_state.vel_new_z[kkkk] = f0[5];

	return   next_state ;
}
 
void key(unsigned char key, int x, int y)
{
 
   if(key == 'x') cameraEye[0]-= 50;
   if(key == 'X') cameraEye[0]+= 50;
   if(key == 'y') cameraEye[1]-= 50;
   if(key == 'Y') cameraEye[1]+= 50;
   if(key == 'z') cameraEye[2]-= 50;
   if(key == 'Z') cameraEye[2]+= 50;
 
   if(key == '+')
   {
      
      
   }
   if(key == '-')
   {        
   }

   glutPostRedisplay();
}
 
void rates_dorsal ( double *t, double *f, double result[]   )
{
 
if(springharmony_status_link_[llll][k_flappers][whatNET].force_sign[kkkk_] == 1)
{
    	result[0] =             f[3]/1.00000123;
    	result[1] =             f[4]/1.00000123;
    	result[2] =             f[5]/1.00000123;
  
	result[3] = (F_total[0][llll][whatNET][k_flappers][kkkk_])/(230000000*springharmony_status_link_[llll][k_flappers][kkkk_].mass[kkkk_]  );
	result[4] = (F_total[1][llll][whatNET][k_flappers][kkkk_] -gravity[whatNET]  )/(230000000.0123 *springharmony_status_link_[llll][k_flappers][kkkk_].mass[kkkk_]   );
	result[5] = (F_total[2][llll][whatNET][k_flappers][kkkk_] )/(230000000.0123 *springharmony_status_link_[llll][k_flappers][kkkk_].mass[kkkk_]); 
}
else if(springharmony_status_link_[INDEX_NR][k_flappers][whatNET].force_sign[kkkk_] == -1)
{
    result[0] =             f[3]/1.00000123;
    result[1] =             f[4]/1.00000123;
    result[2] =             f[5]/1.00000123;
  
    result[3] = -(F_total[0][INDEX_NR][whatNET][k_flappers][kkkk_])/(230000000.0123 *springharmony_status_link_[INDEX_NR][k_flappers][kkkk_].mass[kkkk_] );
    result[4] = -(F_total[1][INDEX_NR][whatNET][k_flappers][kkkk_] -gravity[whatNET] ) /(230000000.0123 *springharmony_status_link_[INDEX_NR][k_flappers][kkkk_].mass[kkkk_]) ;
    result[5] = -(F_total[2][INDEX_NR][whatNET][k_flappers][kkkk_] )/(230000000.0123 *springharmony_status_link_[INDEX_NR][k_flappers][kkkk_].mass[kkkk_] ); //522


}
else if(springharmony_status_link_[INDEX_NRmore][k_flappers][whatNET].force_sign[kkkk_]== -1)
{
    	result[0] =             f[3]/1.00000123;
    	result[1] =             f[4]/1.00000123;
    	result[2] =             f[5]/1.00000123;
  
	result[3] = -(F_total[0][INDEX_NRmore][whatNET][k_flappers][kkkk_])/(230000000.0123*springharmony_status_link_[INDEX_NRmore][k_flappers][kkkk_].mass[kkkk_]   );
	result[4] = -(F_total[1][INDEX_NRmore][whatNET][k_flappers][kkkk_] -gravity[whatNET]  )/(230000000.0123*springharmony_status_link_[INDEX_NRmore][k_flappers][kkkk_].mass[kkkk_]   );
	result[5] = -(F_total[2][INDEX_NRmore][whatNET][k_flappers][kkkk_] )/(230000000.0123 *springharmony_status_link_[INDEX_NRmore][k_flappers][kkkk_].mass[kkkk_] ); 

 
}
else if(springharmony_status_link_[INDEX_NR1][k_flappers][whatNET].force_sign[kkkk_] == -1)
{
    	result[0] =             f[3]/1.00000123;
    	result[1] =             f[4]/1.00000123;
    	result[2] =             f[5]/1.00000123;
  
	result[3] = -(F_total[0][INDEX_NR1][whatNET][k_flappers][kkkk_])/(230000000.0123*springharmony_status_link_[INDEX_NR1][k_flappers][kkkk_].mass[kkkk_]  );
	result[4] = -(F_total[1][INDEX_NR1][whatNET][k_flappers][kkkk_] -gravity[whatNET] )/(230000000.0123*springharmony_status_link_[INDEX_NR1][k_flappers][kkkk_].mass[kkkk_]  );
	result[5] = -(F_total[2][INDEX_NR1][whatNET][k_flappers][kkkk_] )/(230000000.0123 *springharmony_status_link_[INDEX_NR1][k_flappers][kkkk_].mass[kkkk_]); 

 
}
else if(springharmony_status_link_[INDEX_NR2][k_flappers][whatNET].force_sign[kkkk_] ==  1)
{
    	result[0] =             f[3]/1.00000123;
    	result[1] =             f[4]/1.00000123;
    	result[2] =             f[5]/1.00000123;
  
	result[3] = -(F_total[0][INDEX_NR2][whatNET][k_flappers][kkkk_])/(230000000.0123 *springharmony_status_link_[INDEX_NR2][k_flappers][kkkk_].mass[kkkk_]   );
	result[4] = -(F_total[1][INDEX_NR2][whatNET][k_flappers][kkkk_]-gravity[whatNET]   )/(230000000.0123*springharmony_status_link_[INDEX_NR2][k_flappers][kkkk_].mass[kkkk_]  );
	result[5] = -(F_total[2][INDEX_NR2][whatNET][k_flappers][kkkk_] )/(230000000.0123 *springharmony_status_link_[INDEX_NR2][k_flappers][kkkk_].mass[kkkk_] );
}
  
}
 
#include <stdio.h>
#include <stdlib.h>
#include "catmull/gl.h"
#include "catmull/gl_util.h"
#include "catmull/mathx.h"
#include "catmull/mesh.h"
#include "catmull/meshrend.h"
#include "catmull/editor.h"

static struct editor *ed[2000];
static struct editor *ed2;
static struct editor *ed3;

static struct editor *ed4;
static vector center = { 0.0, 0.0, 0.0 };
static float focal_len = 5.0f;
static float y_rot = 0.0f, x_rot = 0.0f;

static float fovy  = 60.0f;
static float znear = 0.1f, zfar = 1960.0f;
static GLint width = 1920, height = 1080;

static enum { NONE, ROTATING, PANNING, ZOOMING } cur_op = NONE;
static int last_x, last_y;

static void focus_camera(const struct mesh *mesh, int nr)
{
	vector min, max;
	/* FIXME */
	mesh_calc_bounds(mesh, min, max,nr-1);
	vec_add(center, min, max);
	vec_mul(center, 0.5f, center);
	focal_len = 2.0f * max[1];
}

static void get_camera_frame(vector x, vector y, vector z)
{
	matrix m;

	vec_set(x, 1.0f, 0.0f, 0.0f);
	vec_set(y, 0.0f, 1.0f, 0.0f);
	vec_set(z, 0.0f, 0.0f, 1.0f);

	mat_rotate(m, y, y_rot);
	mat_mul_vector(x, m, x);
	mat_mul_vector(z, m, z);

	mat_rotate(m, x, x_rot);
	mat_mul_vector(y, m, y);
	mat_mul_vector(z, m, z);
}

static void get_camera(vector eye, vector at, vector up)
{
	vector x, y, z;

	get_camera_frame(x, y, z);
	vec_copy(at, center);
	vec_copy(eye, center);
	vec_mad(eye, focal_len, z);
	vec_copy(up, y);
}

int show_perm(int *x_, int len)
{
 
}

/* next lexicographical permutation */
int next_lex_perm(int *a, int n) {
#	define swap(i, j) {t = a[i]; a[i] = a[j]; a[j] = t;}
	int k, l, t;
	for (k = n - 1; k && a[k - 1] >= a[k]; k--);
	if (!k--) return 0;
	for (l = n - 1; a[l] <= a[k]; l--);
	swap(k, l);
	for (k++, l = n - 1; l > k; l--, k++)
		swap(k, l);
	return 1;
#	undef swap
}
void perm1(int *x, int n, int callback(int *, int))
{
	do {
		if (callback) callback(x, n);
	} while (next_lex_perm(x, n));
}
 

  void display(void)
{

	matrix m;
	vector eye, at, up;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
        glEnable(GL_COLOR_MATERIAL);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	mat_persp(m, fovy, (double) width / height, znear, zfar);
	glLoadMatrixf(m);
	glMatrixMode(GL_MODELVIEW);
	get_camera(eye, at, up);
	mat_lookat(m, eye, at, up);
	glLoadMatrixf(m);
   	  
   // for(int kkk = 0; kkk < springharmony_status_link_[0][0][0].tot_layer[0] ; kkk++)
  {
 
 ////for(int lll = 0; lll <  springharmony_status_link_[0][0][0].totnumpoints[0]; lll++)  
  { 	  
  //INDEX_NR=    springharmony_status_link[lll][0][kkk].INDEX_NR[0] ; 	
 // glTranslatef(springharmony_status_link_[INDEX_NR][0][kkk].pos_new_x[0], springharmony_status_link_[INDEX_NR][0][kkk].pos_new_y[0],springharmony_status_link_[INDEX_NR][0][kkk].pos_new_z[0]);
 
 // for(int kkk = 0; kkk < springharmony_status_link_[0][0][0].tot_layer[0] ; kkk++)
  {
 
 //for(int lll = 0; lll <  springharmony_status_link_[0][0][0].totnumpoints[0]; lll++)  
  { 
 
   //INDEX_NR=    springharmony_status_link[lll][0][kkk].INDEX_NR[0] ; 	
   // 	  glPushMatrix();
    	  
  //  glTranslatef(springharmony_status_link_[INDEX_NR][0][kkk].pos_new_x[0], springharmony_status_link_[INDEX_NR][0][kkk].pos_new_y[0],springharmony_status_link_[INDEX_NR][0][kkk].pos_new_z[0]);
   // 	glutPostRedisplay();
 for(int kkkk =0; kkkk < 2 ; kkkk++)
  {
 for(int kk = 0; kk < springharmony_status_link_[0][0][0].tot_layer[kkkk] ; kk++)
  {
 for(int ll = 0; ll <  springharmony_status_link_[0][0][0].totnumpoints[kkkk]; ll++)  
  { 
   // glScalef(0.2,0.2,0.2);
   // findnearestpoint( KvvVENTAL-1  ,NULL,ll,0,kk , springharmony_status_link_[ll][0][kk].length);	  
  int lkl = 0; 
 //for(int lkl = 0; lkl <   totalneigbours[ll][kk][kkkk]; lkl++)  
  { 
   INDEX_NR=    springharmony_status_link[ll][0][kk].INDEX_NR[kkkk] ; 	

 //playsound(springharmony_status_link_[ll][0][kk].length);
   springharmony(ll,lkl,kk ,kkkk); 
  for(int nnn = 0; nnn < springharmony_status_link_[0][0][0].tot_layer[kkkk] ; nnn++)
  {

  springharmony_netonnet(ll,lkl,kk,nnn,kkkk );
}
 	  glPushMatrix();
  glTranslatef(springharmony_status_link_[INDEX_NR][lkl][kk].pos_new_x[kkkk], springharmony_status_link_[INDEX_NR][lkl][kk].pos_new_y[kkkk],springharmony_status_link_[INDEX_NR][lkl][kk].pos_new_z[kkkk]);

 
   glColor3f(springharmony_status_link_[INDEX_NR][lkl][kk].pos_new_x[kkkk]*2, springharmony_status_link_[INDEX_NR][lkl][kk].pos_new_y[kkkk]*2,springharmony_status_link_[INDEX_NR][lkl][kk].pos_new_z[kkkk]*2); 
  
length__  = springharmony_status_link_[INDEX_NR][lkl][kk].length;

//printf("pos=%f %f %f \n", springharmony_status_link_[INDEX_NR][lkl][kk].pos_new_x[kkkk], springharmony_status_link_[INDEX_NR][lkl][kk].pos_new_y[kkkk],springharmony_status_link_[INDEX_NR][lkl][kk].pos_new_z[kkkk]);
 if(length__ < 3.5 && kkkk == 0)
glutSolidSphere(length__/40  ,19,19  );


 if(length__ < 3.5 && kkkk == 1)
glutWireSphere(length__/290  ,19,19  );


 if(length__ < 3.5 && kkkk == 2)
glutWireSphere(length__/30  ,19,19  );
 printf("length__ =%f \n", length__);
	//glutPostRedisplay();
 glPopMatrix();
  // drawLights();
 //for(int lkl = 0; lkl <   totalneigbours[ll][kk][kkkk] ; lkl++)  
  { 
 INDEX_NR=    springharmony_status_link[ll][lkl][kk].INDEX_NR[kkkk] ; 	
//if(  INDEX_NR > 0  && INDEX_NR < springharmony_status_link_[0][0][0].totnumpoints[kkkk] && INDEX_NR != ll)
{

}
}

}
 }
}
} 
}
}
 //glPopMatrix();
   display_mpeg();
 
	glutSwapBuffers();
}
}
 //glPopMatrix();


}

static void reshape(int w, int h)
{
	width = w > 1 ? w : 1;
	height = h > 1 ? h : 1;
	glViewport(0, 0, width, height);
	glClearDepth(1.0);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
}

static void keyboard(unsigned char key, int x, int y)
{
#if 0
	switch (key) {
	case 27: case 17:	/* Esc or Ctrl-Q */
		exit(0);
		break;
	case 'w': case 'W':

	for(int ll = 0; ll < KvvVENTAL  ; ll++)
	{
	if(ll % 100 == 0)
 		 printf(" index %d \n",  KvvVENTAL);
 
 	         springharmony_status_link_[ll][0][1].pos_new_y += 0.05;
	}
		//focus_camera(ed_cur_obj(ed));
		break;
	case 's': case 'S':
	for(int ll = 0; ll < KvvVENTAL  ; ll++)
	{
	if(ll % 100 == 0)
 		 printf(" index %d \n",  KvvVENTAL);
 	         springharmony_status_link_[ll][0][1].pos_new_y-= 0.05;
 
	}	
		//ed_toggle_editing(ed);
		break;

	case 'd': case 'D':
	for(int ll = 0; ll < KvvVENTAL  ; ll++)
	{
	if(ll % 100 == 0)
 		 printf(" index %d \n",  KvvVENTAL);
 
 	          springharmony_status_link_[ll][0][1].pos_new_x+= 0.05;
	}
		//ed_toggle_editing(ed);
		break;

	case 'a': case 'A':
	for(int ll = 0; ll < KvvVENTAL  ; ll++)
	{
	if(ll % 100 == 0)
 		 printf(" index %d \n",  KvvVENTAL);
 
 	          springharmony_status_link_[ll][0][1].pos_new_x-= 0.05;
 		//  springharmony_status_link_[ll][0][3].pos_new_z = v->z/(changer)  ;
}

		//ed_toggle_editing(ed);
		break;
	}

	if (!ed_is_editing(ed)) {
		switch (key) {
		case ' ':
			ed_next_obj(ed);
			//focus_camera(ed_cur_obj(ed));
			break;
		case 8:	case 127:	/* Backspace or Delete */
			ed_prev_obj(ed);
			//focus_camera(ed_cur_obj(ed));
			break;
		//case 'w': case 'W':
		//	ed_toggle_wireframe(ed);
		//	break;
		case '=': case '+':
			ed_next_level(ed);
			break;
		case '-': case '_':
			ed_prev_level(ed);
			break;
		}
	}
	#endif
}

static void special(int key, int x, int y)
{
	if (ed_is_editing(ed))
		return;

	switch (key) {
	case GLUT_KEY_RIGHT:
		ed_next_obj(ed);
		//focus_camera(ed_cur_obj(ed));
		break;
	case GLUT_KEY_LEFT:
		ed_prev_obj(ed);
		//focus_camera(ed_cur_obj(ed));
		break;
	case GLUT_KEY_UP:
		ed_next_level(ed);
		break;
	case GLUT_KEY_DOWN:
		ed_prev_level(ed);
		break;
	}
}

static void mouse(int button, int state, int x, int y)
{
	int mods;
	static const int cursor[] = {
		GLUT_CURSOR_RIGHT_ARROW,		/* NONE */
		GLUT_CURSOR_CYCLE,			/* ROTATING */
		GLUT_CURSOR_CROSSHAIR,			/* PANNING */
		GLUT_CURSOR_UP_DOWN			/* ZOOMING */
	};

	mods = glutGetModifiers();
	if (state == GLUT_DOWN) {
		if (button == GLUT_LEFT_BUTTON)
			cur_op = (mods & GLUT_ACTIVE_CTRL) ? PANNING : ROTATING;
		else if (button == GLUT_RIGHT_BUTTON)
			cur_op = ZOOMING;
		else if (button == GLUT_MIDDLE_BUTTON)
			cur_op = PANNING;
	} else {
		cur_op = NONE;
	}

	glutSetCursor(cursor[cur_op]);

	last_x = x;
	last_y = y;
}

static void motion(int x, int y)
{
	float dx, dy;

	dx = (float) (x - last_x) / width;
	dy = (float) (y - last_y) / height;

	if (cur_op == ROTATING) {
		y_rot -= dx * 360.0f;
		x_rot -= dy * 360.0f;
	} else if (cur_op == PANNING) {
		float lx, ly;
		vector x, y, z;

		ly = 2.0f * focal_len * tanf(radians(fovy / 2.0f));
		lx = ly * width / height;

		get_camera_frame(x, y, z);
		vec_mad(center, -dx * lx, x);
		vec_mad(center,  dy * ly, y);
	} else if (cur_op == ZOOMING) {
		focal_len *= (1.0f - dy) - dx;
	}

	last_x = x;
	last_y = y;
}

static void idle(void)
{
	glutPostRedisplay();
}

int main (int argc, char **argv)
{
 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(width, height);
	glutCreateWindow("catmull-clark");
  	springVector = malloc( 11121);
	 glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutIdleFunc(idle);
	  glEnable (GL_DEPTH_TEST);
	  glEnable (GL_BLEND);
	  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	  glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	printf("Loading... "); fflush(stdout);
	
	 for(int kkkk =0; kkkk < 1 ; kkkk++)
         {
	  ed[kkkk] = ed_create();
   
	  ed_add_obj(ed[kkkk], "ico4.obj", 1+kkkk,kkkk);
 
	  printf("done.\n");
 
	  focus_camera(ed_cur_obj(ed[kkkk]),1+kkkk);
 
	 }
	 	 for(int kkkk =1; kkkk < 2 ; kkkk++)
         {
	  ed[kkkk] = ed_create();
   
	  ed_add_obj(ed[kkkk], "s3.obj", 1+kkkk,kkkk);
 
	  printf("done.\n");
 
	  focus_camera(ed_cur_obj(ed[kkkk]),1+kkkk);
 
	 }
	 
	 
 	 initLights();
	init_mpgeg();
	glutMainLoop();

	return 0;
}



#include <SDL2/SDL.h>

#define MUS_PATH "Alesis-Fusion-Fretless-Bass-C3.wav"

// prototype for our audio callback
// see the implementation for more information
void my_audio_callback(void *userdata, Uint8 *stream, int len);

// variable declarations
static Uint8 *audio_pos; // global pointer to the audio buffer to be played
static Uint32 audio_len; // remaining length of the sample we have to play

int one=1;
/*
** PLAYING A SOUND IS MUCH MORE COMPLICATED THAN IT SHOULD BE
*/
	static Uint32 wav_length; // length of our sample
	static Uint8 *wav_buffer; // buffer containing our audio file
	static SDL_AudioSpec wav_spec; // the specs of our piece of music
int playsound(double length){
if(one == 1)
{
	// Initialize SDL.
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
			return 1;

	// local variables

	
	
	/* Load the WAV */
	// the specs, length and buffer of our wav are filled
	if( SDL_LoadWAV(MUS_PATH, &wav_spec, &wav_buffer, &wav_length) == NULL ){
	  return 1;
	}
	// set the callback function
	wav_spec.callback = my_audio_callback;
	wav_spec.userdata = NULL;
	// set our global static variables
	audio_pos = wav_buffer; // copy sound buffer
	audio_len = wav_length; // copy file length
	
	/* Open the audio device */
	if ( SDL_OpenAudio(&wav_spec, NULL) < 0 ){
	  fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
	  exit(-1);
	}
one = 0;
	}


	/* Start playing */
	SDL_PauseAudio(0);	
	// shut everything down
	//SDL_CloseAudio();
	//SDL_FreeWAV(wav_buffer);

}

// audio callback function
// here you have to copy the data of your audio buffer into the
// requesting audio buffer (stream)
// you should only copy as much as the requested length (len)
void my_audio_callback(void *userdata, Uint8 *stream, int len) {
	
	if (audio_len ==0)
		return;
	
	len = ( len > audio_len ? audio_len : len );
	//SDL_memcpy (stream, audio_pos, len); 					// simply copy from one buffer into the other
	SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);// mix from one buffer into another
	
	audio_pos += (int)length__*10;
	audio_len -= (int)length__*10;;
}
