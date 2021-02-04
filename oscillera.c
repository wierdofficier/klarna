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
 
int INDEX_NR1;
int INDEX_NR2;
int INDEX_NRmore;
extern int KvvVENTAL ;
float springlength =  0.04 ;
float dNear = 100;
float dFar = 2000;
double gravity[40] = {0,0 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 ,0,0 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
struct state_vector       worm_ventral(struct state_vector       next_state, int num );
#define HOW_MANY_FLUIDS 20
#define HOWMANY HOW_MANY_FLUIDS
double F_total[3][10000*2][HOW_MANY_FLUIDS][33] ;
int totalneigbours[10000*2][HOW_MANY_FLUIDS] ;
extern struct state_vector  *  springVector;
struct state_vector    springharmony_status_link[  133333][33][1]; 
struct state_vector *** reall;
struct state_vector     springharmony_status_link_[   133333][33][1]; 
int llll = 0;
 
int feather_once = 1;
int INDEX_NR = 0;
Light *dirLight;
Material *material;
 
float springConstant =   200.202f;

float frictionConstant =    0.2200000f;

float cameraEye[3] = {0.0, 0.0, 1000.0};
float lightRotation[16] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
float cameraLookAt[4] = {0.0, 0.0, 0.0, 1.0};
float cameraUp[4] = {0.0, 1.0, 0.0};

float viewRotation[16] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};

float rotationX=0.0;
float rotationY=0.0;
 
void rates_dorsal ( double *t, double *f, double result[]   );
void key(unsigned char key, int x, int y);
int findnearestpoint(int points,struct state_vector ** worm , int num,int howmany, int whantindex,double length) ;
 
double length (struct state_vector a,struct state_vector b ) { return sqrtf ( b.pos_new_x*a.pos_new_x + b.pos_new_y*a.pos_new_y + b.pos_new_z*a.pos_new_z); }
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
 
void springharmony( int kkkkkkkk, int xxx , int whatnet)
{
	 llll = kkkkkkkk;
	 k_flappers = xxx;
	 whatNET = whatnet;
	 int k = xxx;
 	
	 springConstant =   276.0 ;
	 frictionConstant =  32.2;

	 INDEX_NR =   springharmony_status_link[llll][k][whatnet].INDEX_NR ;
 
if(  INDEX_NR > 0  && INDEX_NR < KvvVENTAL && INDEX_NR != llll)
{
		 if( INDEX_NR > 0)
		{	
				 if(fabs(F_total[0][INDEX_NR][whatnet][k]) > 31.123123 )
	 				 	  F_total[0][INDEX_NR][whatnet][k] =0;
 
		 		 if(fabs(F_total[1][INDEX_NR][whatnet][k])  > 31.123123)
						F_total[1][INDEX_NR][whatnet][k] =0;

			 	 if(fabs(F_total[2][INDEX_NR][whatnet][k])  > 31.123123)
						F_total[2][INDEX_NR][whatnet][k] =0;
 			 
springVector->pos_new_x = springharmony_status_link_[INDEX_NR][k][whatnet].pos_new_x - springharmony_status_link_[llll][k][whatnet].pos_new_x;
springVector->pos_new_y = springharmony_status_link_[INDEX_NR][k][whatnet].pos_new_y - springharmony_status_link_[llll][k][whatnet].pos_new_y;
springVector->pos_new_z = springharmony_status_link_[INDEX_NR][k][whatnet].pos_new_z - springharmony_status_link_[llll][k][whatnet].pos_new_z;
 
				float r = length(springharmony_status_link_[INDEX_NR][k][whatnet],springharmony_status_link_[llll][k][whatnet]);

		if ( r != 0  &&    (r) < 50.152343433&&   (r) > -50.152343433)
		{	
springharmony_status_link_[INDEX_NR][k][whatnet].length = r ;
springharmony_status_link_[llll][k][whatnet].length = r ;
F_total[0][INDEX_NR][whatnet][k] +=( springVector->pos_new_x  /  r ) * ( r - springlength ) * ( -springConstant );
F_total[1][INDEX_NR][whatnet][k] += ( springVector->pos_new_y /  r ) * ( r - springlength ) * ( -springConstant );
F_total[2][INDEX_NR][whatnet][k] +=( springVector->pos_new_z  /  r ) * ( r - springlength ) * ( -springConstant );

F_total[0][llll][whatnet][k] +=( springVector->pos_new_x  / r ) * ( r - springlength ) * ( -springConstant );
F_total[1][llll][whatnet][k] += ( springVector->pos_new_y  / r ) * ( r - springlength) * ( -springConstant );
F_total[2][llll][whatnet][k] +=( springVector->pos_new_z  / r ) * ( r - springlength ) * ( -springConstant );

F_total[0][INDEX_NR][whatnet][k] +=-(  springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_x - springharmony_status_link_[llll][k][whatnet].vel_new_x ) * frictionConstant;
F_total[1][INDEX_NR][whatnet][k] += -( springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_y- springharmony_status_link_[llll][k][whatnet].vel_new_y ) * frictionConstant;
F_total[2][INDEX_NR][whatnet][k] += -(  springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_z - springharmony_status_link_[llll ][k][whatnet].vel_new_z ) * frictionConstant;


F_total[0][llll][whatnet][k] +=-(  springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_x - springharmony_status_link_[llll][k][whatnet].vel_new_x ) * frictionConstant;
F_total[1][llll][whatnet][k] += -( springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_y- springharmony_status_link_[llll][k][whatnet].vel_new_y ) * frictionConstant;
F_total[2][llll][whatnet][k] += -(  springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_z - springharmony_status_link_[llll ][k][whatnet].vel_new_z ) * frictionConstant;

springharmony_status_link_[llll][k][whatnet].vel_new_x = springharmony_status_link_[llll][k][whatnet].vel_new_x*0.95 ;
springharmony_status_link_[llll][k][whatnet].vel_new_y = springharmony_status_link_[llll][k][whatnet].vel_new_y*0.95 ;
springharmony_status_link_[llll][k][whatnet].vel_new_z = springharmony_status_link_[llll][k][whatnet].vel_new_z*0.95 ;
springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_x = springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_x*0.95 ;
springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_y = springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_y*0.95 ; 
springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_z= springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_z*0.95 ;
		}


		k_flappers = k;
	 	whatNET = whatnet;

		springharmony_status_link_[INDEX_NR][k][whatnet].force_sign =  -1;
		springharmony_status_link_[INDEX_NR][k][whatnet]    =  worm_ventral(   springharmony_status_link_[INDEX_NR][k][whatnet] ,1) ;

		springharmony_status_link_[llll][k][whatnet].force_sign =   1; ; 
		springharmony_status_link_[llll][k][whatnet]    =  worm_ventral(   springharmony_status_link_[llll][k][whatnet] ,1);

	for(int d = 0; d <= totalneigbours[llll][whatnet]; d++)
	{	 
		
		if(d == k  )
		  continue;
 
  		INDEX_NRmore = springharmony_status_link[llll][d][whatnet].INDEX_NR;
  if(  INDEX_NRmore > 0 && INDEX_NRmore != llll && INDEX_NRmore < KvvVENTAL)
{
		if(fabs(F_total[0][INDEX_NRmore][whatnet][k]) > 31.123123 )
	 				  F_total[0][INDEX_NRmore][whatnet][k] =0;
		if(fabs(F_total[1][INDEX_NRmore][whatnet][k])  > 31.123123)
					  F_total[1][INDEX_NRmore][whatnet][k] =0;
		if(fabs(F_total[2][INDEX_NRmore][whatnet][k])  > 31.123123)
					  F_total[2][INDEX_NRmore][whatnet][k] =0;
			

 		if(fabs(F_total[0][INDEX_NR][whatnet][k]) > 31.123123 )
	 				  F_total[0][INDEX_NR][whatnet][k] =0;
		if(fabs(F_total[1][INDEX_NR][whatnet][k])  > 31.123123)
					  F_total[1][INDEX_NR][whatnet][k] =0;
		if(fabs(F_total[2][INDEX_NR][whatnet][k])  > 31.123123)
					  F_total[2][INDEX_NR][whatnet][k] =0;
			
springVector->pos_new_x = springharmony_status_link_[INDEX_NR][k][whatnet].pos_new_x - springharmony_status_link_[INDEX_NRmore][k][whatnet].pos_new_x;
springVector->pos_new_y = springharmony_status_link_[INDEX_NR][k][whatnet].pos_new_y - springharmony_status_link_[INDEX_NRmore][k][whatnet].pos_new_y;
springVector->pos_new_z = springharmony_status_link_[INDEX_NR][k][whatnet].pos_new_z - springharmony_status_link_[INDEX_NRmore][k][whatnet].pos_new_z;
 			
		float r = length(springharmony_status_link_[INDEX_NR][k][whatnet],springharmony_status_link_[INDEX_NRmore][k][whatnet]);

		if ( r != 0  &&   (r) <  50.152343433 &&   (r) > -50.152343433)
		{	
 springharmony_status_link_[INDEX_NR][k][whatnet].length = r ;
springharmony_status_link_[INDEX_NRmore][k][whatnet].length = r ;
			F_total[0][INDEX_NR][whatnet][k] +=( springVector->pos_new_x  /  r ) * ( r - springlength ) * ( -springConstant );
			F_total[1][INDEX_NR][whatnet][k] += ( springVector->pos_new_y /  r ) * ( r - springlength ) * ( -springConstant );
			F_total[2][INDEX_NR][whatnet][k] +=( springVector->pos_new_z  /  r ) * ( r - springlength ) * ( -springConstant );

			F_total[0][INDEX_NRmore][whatnet][k] +=( springVector->pos_new_x  / r ) * ( r - springlength ) * ( -springConstant );
			F_total[1][INDEX_NRmore][whatnet][k] += ( springVector->pos_new_y  / r ) * ( r - springlength) * ( -springConstant );
			F_total[2][INDEX_NRmore][whatnet][k] +=( springVector->pos_new_z  / r ) * ( r - springlength ) * ( -springConstant );

			F_total[0][INDEX_NR][whatnet][k] +=-(  springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_x - springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x ) * frictionConstant;
 			F_total[1][INDEX_NR][whatnet][k] += -( springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_y- springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y ) * frictionConstant;
 			F_total[2][INDEX_NR][whatnet][k] += -(  springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_z - springharmony_status_link_[INDEX_NRmore ][k][whatnet].vel_new_z ) * frictionConstant;


			F_total[0][INDEX_NRmore][whatnet][k] +=-(  springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_x - springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x ) * frictionConstant;
 			F_total[1][INDEX_NRmore][whatnet][k] += -( springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_y- springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y ) * frictionConstant;
 			F_total[2][INDEX_NRmore][whatnet][k] += -(  springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_z - springharmony_status_link_[INDEX_NRmore ][k][whatnet].vel_new_z ) * frictionConstant;

		  springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x = springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x*0.95 ;
		
		springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y = springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y*0.95 ;
		springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_z = springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_z*0.95 ;
		springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_x = springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_x*0.95 ;
		
		springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_y = springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_y*0.95 ;
		springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_z = springharmony_status_link_[INDEX_NR][k][whatnet].vel_new_z*0.95 ;  
		}
		k_flappers = k;
		whatNET = whatnet;
		springharmony_status_link_[INDEX_NR][k][whatnet].force_sign =  -1;
		springharmony_status_link_[INDEX_NR][k][whatnet]    =  worm_ventral(   springharmony_status_link_[INDEX_NR][k][whatnet] ,1) ;

		springharmony_status_link_[INDEX_NRmore][k][whatnet].force_sign =   1; ; 
		springharmony_status_link_[INDEX_NRmore][k][whatnet]    =  worm_ventral(   springharmony_status_link_[INDEX_NRmore][k][whatnet] ,1);
 	} 		 
 	}	
	}	 
 	}		
				 if(fabs(F_total[0][llll][whatnet][k]) > 31.123123 )
	 				 F_total[0][llll][whatnet][k] =0;
		 		 if(fabs(F_total[1][llll][whatnet][k])  > 31.123123)
					 F_total[1][llll][whatnet][k] =0;
			 	 if(fabs(F_total[2][llll][whatnet][k])  > 31.123123)
					 F_total[2][llll][whatnet][k] =0;
}

void springharmony_netonnet( int kkkkkkkk, int xxx , int whatnet, int whatnet2)
{
	llll = kkkkkkkk;
 
	 k_flappers = xxx;
	 whatNET = whatnet;
	 int k = xxx;
	 int g = xxx;
  		
	 springConstant =   276.0 ;
	 frictionConstant =  32.2;
	if(k >= 0 && g >= 0)
{
 
	INDEX_NR1 =   springharmony_status_link[llll][k][whatnet].INDEX_NR ;
	INDEX_NR2 =   springharmony_status_link[llll][g][whatnet2].INDEX_NR ;

if(  INDEX_NR1 != INDEX_NR2)
{
if(  INDEX_NR1 >  0     && INDEX_NR1 < KvvVENTAL&& INDEX_NR1 != llll)
{
if(  INDEX_NR2 >  0    && INDEX_NR2 < KvvVENTAL && INDEX_NR2 != llll)
{
{
		{	
				 if(fabs(F_total[0][INDEX_NR1][whatnet][k]) > 31.123123 )
	 				 	  F_total[0][INDEX_NR1][whatnet][k] =0;
 
		 		 if(fabs(F_total[1][INDEX_NR1][whatnet][k])  > 31.123123)
						F_total[1][INDEX_NR1][whatnet][k] =0;

			 	 if(fabs(F_total[2][INDEX_NR1][whatnet][k])  > 31.123123)
						F_total[2][INDEX_NR1][whatnet][k] =0;



				 if(fabs(F_total[0][INDEX_NR2][whatnet2][g]) > 31.123123 )
	 				 	  F_total[0][INDEX_NR2][whatnet2][g] =0;
 
		 		 if(fabs(F_total[1][INDEX_NR2][whatnet2][g])  > 31.123123)
						F_total[1][INDEX_NR2][whatnet2][g] =0;

			 	 if(fabs(F_total[2][INDEX_NR2][whatnet2][g])  > 31.123123)
						F_total[2][INDEX_NR2][whatnet2][g] =0;
 			 
springVector->pos_new_x = springharmony_status_link_[INDEX_NR1][k][whatnet].pos_new_x - springharmony_status_link_[INDEX_NR2][g][whatnet2].pos_new_x;
springVector->pos_new_y = springharmony_status_link_[INDEX_NR1][k][whatnet].pos_new_y - springharmony_status_link_[INDEX_NR2][g][whatnet2].pos_new_y;
springVector->pos_new_z = springharmony_status_link_[INDEX_NR1][k][whatnet].pos_new_z - springharmony_status_link_[INDEX_NR2][g][whatnet2].pos_new_z;
 
float r = length(springharmony_status_link_[INDEX_NR1][k][whatnet],springharmony_status_link_[INDEX_NR2][g][whatnet2]);

if ( r != 0  &&    (r) < 50.152343433&&   (r) > -50.152343433)
{	
 springharmony_status_link_[INDEX_NR1][k][whatnet].length = r ;
springharmony_status_link_[INDEX_NR2][k][whatnet2].length = r ;
	F_total[0][INDEX_NR1][whatnet][k] +=( springVector->pos_new_x  /  r ) * ( r - springlength ) * ( -springConstant );
	F_total[1][INDEX_NR1][whatnet][k] += ( springVector->pos_new_y /  r ) * ( r - springlength ) * ( -springConstant );
	F_total[2][INDEX_NR1][whatnet][k] +=( springVector->pos_new_z  /  r ) * ( r - springlength ) * ( -springConstant );

	F_total[0][INDEX_NR2][whatnet2][g] +=( springVector->pos_new_x  / r ) * ( r - springlength ) * ( -springConstant );
	F_total[1][INDEX_NR2][whatnet2][g] += ( springVector->pos_new_y  / r ) * ( r - springlength) * ( -springConstant );
	F_total[2][INDEX_NR2][whatnet2][g] +=( springVector->pos_new_z  / r ) * ( r - springlength ) * ( -springConstant );

	F_total[0][INDEX_NR1][whatnet][k] +=-(  springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_x - springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_x ) * frictionConstant;
 	F_total[1][INDEX_NR1][whatnet][k] += -( springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_y- springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_y ) * frictionConstant;
 	F_total[2][INDEX_NR1][whatnet][k] += -(  springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_z - springharmony_status_link_[INDEX_NR2 ][k][whatnet2].vel_new_z ) * frictionConstant;


	F_total[0][INDEX_NR2][whatnet2][g] +=-(  springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_x - springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_x ) * frictionConstant;
 	F_total[1][INDEX_NR2][whatnet2][g] += -( springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_y- springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_y ) * frictionConstant;
 	F_total[2][INDEX_NR2][whatnet2][g] += -(  springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_z - springharmony_status_link_[INDEX_NR2 ][k][whatnet2].vel_new_z ) * frictionConstant;
springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_x = springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_x*0.95 ;		
springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_y = springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_y*0.95 ;
springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_z = springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_z*0.95 ;
springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_x = springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_x*0.95 ;
springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_y = springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_y*0.95 ; 
springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_z= springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_z*0.95 ; 
}
		 k_flappers = k;
		 whatNET = whatnet;

		springharmony_status_link_[INDEX_NR1][k][whatnet].force_sign =  -1;
		springharmony_status_link_[INDEX_NR1][k][whatnet]    =  worm_ventral(   springharmony_status_link_[INDEX_NR1][k][whatnet] ,1) ;


	 k_flappers = g;
whatNET = whatnet2;
		springharmony_status_link_[INDEX_NR2][g][whatnet2].force_sign =   1; ; 
		springharmony_status_link_[INDEX_NR2][g][whatnet2]    =  worm_ventral(   springharmony_status_link_[INDEX_NR2][g][whatnet2] ,1);
 
	for(int d = 0; d <= totalneigbours[INDEX_NR1][whatnet]; d++)
	{	 
		
		if(d == k  )
		  continue;
 
		INDEX_NRmore = springharmony_status_link[INDEX_NR1][d][whatnet].INDEX_NR;
    if(  INDEX_NRmore > 0 && INDEX_NRmore != INDEX_NR1 && INDEX_NRmore < KvvVENTAL)
{
		if(fabs(F_total[0][INDEX_NRmore][whatnet][k]) > 31.123123 )
	 				  F_total[0][INDEX_NRmore][whatnet][k] =0;
		if(fabs(F_total[1][INDEX_NRmore][whatnet][k])  > 31.123123)
					  F_total[1][INDEX_NRmore][whatnet][k] =0;
		if(fabs(F_total[2][INDEX_NRmore][whatnet][k])  > 31.123123)
					  F_total[2][INDEX_NRmore][whatnet][k] =0;
			

 		if(fabs(F_total[0][INDEX_NR2][whatnet][k]) > 31.123123 )
	 				  F_total[0][INDEX_NR2][whatnet][k] =0;
		if(fabs(F_total[1][INDEX_NR2][whatnet][k])  > 31.123123)
					  F_total[1][INDEX_NR2][whatnet][k] =0;
		if(fabs(F_total[2][INDEX_NR2][whatnet][k])  > 31.123123)
					  F_total[2][INDEX_NR2][whatnet][k] =0;
			
springVector->pos_new_x = springharmony_status_link_[INDEX_NR2][g][whatnet2].pos_new_x - springharmony_status_link_[INDEX_NRmore][k][whatnet].pos_new_x;
springVector->pos_new_y = springharmony_status_link_[INDEX_NR2][g][whatnet2].pos_new_y - springharmony_status_link_[INDEX_NRmore][k][whatnet].pos_new_y;
springVector->pos_new_z = springharmony_status_link_[INDEX_NR2][g][whatnet2].pos_new_z - springharmony_status_link_[INDEX_NRmore][k][whatnet].pos_new_z;
 			
float r = length(springharmony_status_link_[INDEX_NR2][g][whatnet2],springharmony_status_link_[INDEX_NRmore][k][whatnet]);

if ( r != 0  &&   (r) <  50.152343433 &&   (r) > -50.152343433 )
{	
 springharmony_status_link_[INDEX_NR2][k][whatnet2].length = r ;
springharmony_status_link_[INDEX_NRmore][k][whatnet].length = r ;
F_total[0][INDEX_NR2][whatnet2][g] +=( springVector->pos_new_x  /  r ) * ( r - springlength ) * ( -springConstant );
F_total[1][INDEX_NR2][whatnet2][g] += ( springVector->pos_new_y /  r ) * ( r - springlength ) * ( -springConstant );
F_total[2][INDEX_NR2][whatnet2][g] +=( springVector->pos_new_z  /  r ) * ( r - springlength ) * ( -springConstant );

F_total[0][INDEX_NRmore][whatnet][k] +=( springVector->pos_new_x  / r ) * ( r - springlength ) * ( -springConstant );
F_total[1][INDEX_NRmore][whatnet][k] += ( springVector->pos_new_y  / r ) * ( r - springlength) * ( -springConstant );
F_total[2][INDEX_NRmore][whatnet][k] +=( springVector->pos_new_z  / r ) * ( r - springlength ) * ( -springConstant );

F_total[0][INDEX_NR2][whatnet2][g] +=-(  springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_x - springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x ) * frictionConstant;
F_total[1][INDEX_NR2][whatnet2][g] += -( springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_y- springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y ) * frictionConstant;
F_total[2][INDEX_NR2][whatnet2][g] += -(  springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_z - springharmony_status_link_[INDEX_NRmore ][k][whatnet].vel_new_z ) * frictionConstant;


F_total[0][INDEX_NRmore][whatnet][k] +=-(  springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_x - springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x ) * frictionConstant;
F_total[1][INDEX_NRmore][whatnet][k] += -( springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_y- springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y ) * frictionConstant;
F_total[2][INDEX_NRmore][whatnet][k] += -(  springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_z - springharmony_status_link_[INDEX_NRmore ][k][whatnet].vel_new_z ) * frictionConstant;

springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x = springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x*0.95 ;	
springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y = springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y*0.95 ;
springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_z = springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_z*0.95 ;
springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_x = springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_x*0.95 ;	
springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_y = springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_y*0.95 ;
springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_z = springharmony_status_link_[INDEX_NR2][g][whatnet2].vel_new_z*0.95 ;  
		}
 	k_flappers = g;
	whatNET = whatnet2;
	
springharmony_status_link_[INDEX_NR2][g][whatnet2].force_sign =   1;
springharmony_status_link_[INDEX_NR2][g][whatnet2]   =  worm_ventral(   springharmony_status_link_[INDEX_NR2][g][whatnet2] ,1) ;
k_flappers = k;
whatNET = whatnet;
springharmony_status_link_[INDEX_NRmore][k][whatnet].force_sign =   1; ; 
springharmony_status_link_[INDEX_NRmore][k][whatnet]  =  worm_ventral(   springharmony_status_link_[INDEX_NRmore][k][whatnet] ,1);
  }
 	} 
for(int d = 0; d <= totalneigbours[INDEX_NR2][whatnet2]; d++)
	{	 	
		if(d == k  )
		  continue;
 
		INDEX_NRmore = springharmony_status_link[INDEX_NR2][d][whatnet2].INDEX_NR;
    if(  INDEX_NRmore > 0 && INDEX_NRmore != llll && INDEX_NR2 < KvvVENTAL)
{
		if(fabs(F_total[0][INDEX_NRmore][whatnet][k]) > 31.123123 )
	 				  F_total[0][INDEX_NRmore][whatnet][k] =0;
		if(fabs(F_total[1][INDEX_NRmore][whatnet][k])  > 31.123123)
					  F_total[1][INDEX_NRmore][whatnet][k] =0;
		if(fabs(F_total[2][INDEX_NRmore][whatnet][k])  > 31.123123)
					  F_total[2][INDEX_NRmore][whatnet][k] =0;
			

 		if(fabs(F_total[0][INDEX_NR1][whatnet][k]) > 31.123123 )
	 				  F_total[0][INDEX_NR][whatnet][k] =0;
		if(fabs(F_total[1][INDEX_NR1][whatnet][k])  > 31.123123)
					  F_total[1][INDEX_NR][whatnet][k] =0;
		if(fabs(F_total[2][INDEX_NR1][whatnet][k])  > 31.123123)
					  F_total[2][INDEX_NR][whatnet][k] =0;
			
springVector->pos_new_x = springharmony_status_link_[INDEX_NR1][k][whatnet].pos_new_x - springharmony_status_link_[INDEX_NRmore][k][whatnet].pos_new_x;
springVector->pos_new_y = springharmony_status_link_[INDEX_NR1][k][whatnet].pos_new_y - springharmony_status_link_[INDEX_NRmore][k][whatnet].pos_new_y;
springVector->pos_new_z = springharmony_status_link_[INDEX_NR1][k][whatnet].pos_new_z - springharmony_status_link_[INDEX_NRmore][k][whatnet].pos_new_z;
 		
		float r = length(springharmony_status_link_[INDEX_NR1][k][whatnet],springharmony_status_link_[INDEX_NRmore][k][whatnet]);



		if ( r != 0  &&   (r) <  50.152343433&&   (r) > -50.152343433 )
		{	
 springharmony_status_link_[INDEX_NR1][k][whatnet].length = r ;
springharmony_status_link_[INDEX_NRmore][k][whatnet].length = r ;
	F_total[0][INDEX_NR1][whatnet][k] +=( springVector->pos_new_x  /  r ) * ( r - springlength ) * ( -springConstant );
	F_total[1][INDEX_NR1][whatnet][k] += ( springVector->pos_new_y /  r ) * ( r - springlength ) * ( -springConstant );
	F_total[2][INDEX_NR1][whatnet][k] +=( springVector->pos_new_z  /  r ) * ( r - springlength ) * ( -springConstant );

	F_total[0][INDEX_NRmore][whatnet][k] +=( springVector->pos_new_x  / r ) * ( r - springlength ) * ( -springConstant );
	F_total[1][INDEX_NRmore][whatnet][k] += ( springVector->pos_new_y  / r ) * ( r - springlength) * ( -springConstant );
	F_total[2][INDEX_NRmore][whatnet][k] +=( springVector->pos_new_z  / r ) * ( r - springlength ) * ( -springConstant );

F_total[0][INDEX_NR1][whatnet][k] +=-(  springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_x - springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x ) * frictionConstant;
F_total[1][INDEX_NR1][whatnet][k] += -( springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_y- springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y ) * frictionConstant;
F_total[2][INDEX_NR1][whatnet][k] += -(  springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_z - springharmony_status_link_[INDEX_NRmore ][k][whatnet].vel_new_z ) * frictionConstant;


F_total[0][INDEX_NRmore][whatnet][k] +=-(  springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_x - springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x ) * frictionConstant;
F_total[1][INDEX_NRmore][whatnet][k] += -( springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_y- springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y ) * frictionConstant;
F_total[2][INDEX_NRmore][whatnet][k] += -(  springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_z - springharmony_status_link_[INDEX_NRmore ][k][whatnet].vel_new_z ) * frictionConstant;

springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x = springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_x*0.95 ;	
springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y = springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_y*0.95 ;
springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_z = springharmony_status_link_[INDEX_NRmore][k][whatnet].vel_new_z*0.95 ;
springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_x = springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_x*0.95 ;		
springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_y = springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_y*0.95 ;
springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_z = springharmony_status_link_[INDEX_NR1][k][whatnet].vel_new_z*0.95 ;  
		}


	k_flappers = k;
	whatNET = whatnet;
springharmony_status_link_[INDEX_NR1][k][whatnet].force_sign =  -1;
springharmony_status_link_[INDEX_NR1][k][whatnet]    =  worm_ventral(   springharmony_status_link_[INDEX_NR1][k][whatnet] ,1) ;

springharmony_status_link_[INDEX_NRmore][k][whatnet].force_sign =   1; ; 
springharmony_status_link_[INDEX_NRmore][k][whatnet]    =  worm_ventral(   springharmony_status_link_[INDEX_NRmore][k][whatnet] ,1);
 
 	} 		 
 	}	
 	}	 
 	}				 
 	}
	}
	}
	}
				 if(fabs(F_total[0][INDEX_NR1][whatnet][k]) > 31.123123 )
	 				 	  F_total[0][INDEX_NR1][whatnet][k] =0;
		 		 if(fabs(F_total[1][INDEX_NR1][whatnet][k])  > 31.123123)
						F_total[1][INDEX_NR1][whatnet][k] =0;
			 	 if(fabs(F_total[2][INDEX_NR1][whatnet][k])  > 31.123123)
						F_total[2][INDEX_NR1][whatnet][k] =0;

				 if(fabs(F_total[0][INDEX_NR2][whatnet2][g]) > 31.123123 )
	 				 	  F_total[0][INDEX_NR2][whatnet2][g] =0;
		 		 if(fabs(F_total[1][INDEX_NR2][whatnet2][g])  > 31.123123)
						F_total[1][INDEX_NR2][whatnet2][g] =0;
			 	 if(fabs(F_total[2][INDEX_NR2][whatnet2][g])  > 31.123123)
						F_total[2][INDEX_NR2][whatnet2][g] =0;
 
}
int find_index_____(int NUM, struct state_vector   real[ 133333][33][1],int num,int k,int what )
{
int ll = 0;
 	while(ll < NUM)
	{
	if(springharmony_status_link[num][k][what].pos_new_x ==real[ll][what]->pos_new_x && springharmony_status_link[num][k][what].pos_new_y ==real[ll][what]->pos_new_y && springharmony_status_link[num][k][what].pos_new_z ==real[ll][what]->pos_new_z)
		{
			//printf("found index_____ @ %d \n", ll);
			return ll;
		}
	ll++;
	}
}

void *ptree[100];
  
int ptreeonce[215] = {1,1 ,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 ,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 ,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int findnearestpoint(int points,struct state_vector ** worm , int num,int howmany, int whantindex,double length)  {
int i, num_pts = points;
int INDEX;
 
struct kdres *presults;
double pos[3], dist;
double pt[3] = { springharmony_status_link_[num][0][whantindex].pos_new_x,springharmony_status_link_[num][0][whantindex].pos_new_y, springharmony_status_link_[num][0][whantindex].pos_new_z };
double radius = length;
num_pts =points;
//srand( time(0) );

if(ptreeonce[whantindex]  == 1  )
{
	ptree[whantindex] = kd_create( 3 );
  	for( i=0; i<points; i++ ) {   
    		assert( 0 == kd_insert3( ptree[whantindex], springharmony_status_link_[i][0][whantindex].pos_new_x, springharmony_status_link_[i][0][whantindex].pos_new_y, springharmony_status_link_[i][0][whantindex].pos_new_z, NULL ) );
 	 }
}
ptreeonce[whantindex] = 0;

presults = kd_nearest_range( ptree[whantindex], pt, radius );
springharmony_status_link[num][0][whantindex].totaln = kd_res_size(presults) ;
int feather_count = 0;
   	totalneigbours[num][whantindex] = springharmony_status_link[num][0][whantindex].totaln;
while( !kd_res_end( presults ) ) {
	(char*)kd_res_item( presults, pos ); 
    	dist = sqrt( dist_sq( pt, pos, 3 ) );

 
	springharmony_status_link[num][feather_count][whantindex].pos_new_x = pos[0];
	springharmony_status_link[num][feather_count][whantindex].pos_new_y = pos[1];
	springharmony_status_link[num][feather_count][whantindex].pos_new_z = pos[2];
  	INDEX = find_index_____(KvvVENTAL,springharmony_status_link_,num,feather_count,whantindex);

  	springharmony_status_link[num][feather_count][whantindex].INDEX_NR = INDEX;
 	feather_count++;
   	kd_res_next( presults );
	if(num % 1000 ==0)
 		printf("num @ %d \n", num);
}
  feather_count = 0;
  kd_res_free( presults );
  //kd_free( ptree );
  return 0;
}
 
 
#include "catmull/gl.h"
#include "catmull/gl_util.h"
#include "catmull/mathx.h"
#include "catmull/mesh.h"
#include "catmull/meshrend.h"
#include "catmull/editor.h"
float  **V ; 
static struct editor *ed;
 
struct state_vector       worm_ventral(struct state_vector        next_state, int num )
{
	double f0[6];
	double f0_result[6];

	double z[6];
 	double t0[6] = {0.0,0.0,0.0,0.0,0.0,0.0};
 	double tburn =  1.0;
	double tf[6] = {tburn,tburn,tburn,tburn,tburn,tburn};

	z[0] =  next_state.pos_new_x;
	z[1] =  next_state.pos_new_y;
	z[2] = next_state.pos_new_z;
	z[3] =  next_state.vel_new_x;
	z[4] =  next_state.vel_new_y;
	z[5] = next_state.vel_new_z;

	f0[0] = next_state.pos_new_x;
	f0[1] =next_state.pos_new_y;
	f0[2] =next_state.pos_new_z;
	f0[3] =next_state.vel_new_x;
	f0[4] =next_state.vel_new_y;
	f0[5] = next_state.vel_new_z;
 
	rk45(rates_dorsal, t0, f0,f0_result, tf,z,6, 1  );

	next_state.pos_new_x = f0[0];
	next_state.pos_new_y = f0[1];
	next_state.pos_new_z = f0[2];

	next_state.vel_new_x = f0[3];
	next_state.vel_new_y = f0[4];
	next_state.vel_new_z = f0[5];

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
 
if(springharmony_status_link_[llll][k_flappers][whatNET].force_sign == 1)
{
    	result[0] =             f[3]/100.0;
    	result[1] =             f[4]/100.0;
    	result[2] =             f[5]/100.0;
  
	result[3] = (F_total[0][llll][whatNET][k_flappers])/(4000.0   );
	result[4] = (F_total[1][llll][whatNET][k_flappers] -gravity[whatNET]  )/(4000.0   );
	result[5] = (F_total[2][llll][whatNET][k_flappers] )/(4000.0); 
}
else if(springharmony_status_link_[INDEX_NR][k_flappers][whatNET].force_sign == -1)
{
    result[0] =             f[3]/100.0;
    result[1] =             f[4]/100.0;
    result[2] =             f[5]/100.0;
  
    result[3] = -(F_total[0][INDEX_NR][whatNET][k_flappers])/(4000.0  );
    result[4] = -(F_total[1][INDEX_NR][whatNET][k_flappers] -gravity[whatNET] ) /(4000.0) ;
    result[5] = -(F_total[2][INDEX_NR][whatNET][k_flappers] )/(4000.0  ); //522
 

}
else if(springharmony_status_link_[INDEX_NRmore][k_flappers][whatNET].force_sign == -1)
{
    	result[0] =             f[3]/100.0;
    	result[1] =             f[4]/100.0;
    	result[2] =             f[5]/100.0;
  
	result[3] = -(F_total[0][INDEX_NRmore][whatNET][k_flappers])/(4000.0   );
	result[4] = -(F_total[1][INDEX_NRmore][whatNET][k_flappers] -gravity[whatNET]  )/(4000.0   );
	result[5] = -(F_total[2][INDEX_NRmore][whatNET][k_flappers] )/(4000.0); 

 
}
else if(springharmony_status_link_[INDEX_NR1][k_flappers][whatNET].force_sign == -1)
{
    	result[0] =             f[3]/100.0;
    	result[1] =             f[4]/100.0;
    	result[2] =             f[5]/100.0;
  
	result[3] = -(F_total[0][INDEX_NR1][whatNET][k_flappers])/(4000.0   );
	result[4] = -(F_total[1][INDEX_NR1][whatNET][k_flappers] -gravity[whatNET] )/(4000.0   );
	result[5] = -(F_total[2][INDEX_NR1][whatNET][k_flappers] )/(4000.0); 

 
}
else if(springharmony_status_link_[INDEX_NR2][k_flappers][whatNET].force_sign ==  1)
{
    	result[0] =             f[3]/100.0;
    	result[1] =             f[4]/100.0;
    	result[2] =             f[5]/100.0;
  
	result[3] = -(F_total[0][INDEX_NR2][whatNET][k_flappers])/(4000.0   );
	result[4] = -(F_total[1][INDEX_NR2][whatNET][k_flappers]-gravity[whatNET]   )/(4000.0   );
	result[5] = -(F_total[2][INDEX_NR2][whatNET][k_flappers] )/(4000.0);
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

static struct editor *ed;

static vector center = { 0.0, 0.0, 0.0 };
static float focal_len = 5.0f;
static float y_rot = 0.0f, x_rot = 0.0f;

static float fovy  = 60.0f;
static float znear = 0.1f, zfar = 1960.0f;
static GLint width = 1366, height = 768;

static enum { NONE, ROTATING, PANNING, ZOOMING } cur_op = NONE;
static int last_x, last_y;

static void focus_camera(const struct mesh *mesh)
{
	vector min, max;
	/* FIXME */
	mesh_calc_bounds(mesh, min, max);
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
	ed_render(ed);
	//gl_draw_xyz();
 
	 gl_begin_2d();
	 gl_draw_fps(0.925f, 0.975f);
	 ed_render_overlay(ed);
	 gl_end_2d();
 
 for(int kk = 0; kk < HOW_MANY_FLUIDS ; kk++)
  {
 
 for(int ll = 0; ll <  KvvVENTAL; ll++)  
  { 
   // findnearestpoint( KvvVENTAL-1  ,NULL,ll,0,kk , springharmony_status_link_[ll][0][kk].length);	  
int lkl = 0; 
 //for(int lkl = 0; lkl <   totalneigbours[ll][kk]; lkl++)  
  { 

 INDEX_NR=    springharmony_status_link[ll][lkl][kk].INDEX_NR ; 	
 springharmony(ll,lkl,kk ); 
if(INDEX_NR > 0 && INDEX_NR < KvvVENTAL && INDEX_NR  != ll)
{
 //for(int kk = 0; kk <  HOW_MANY_FLUIDS; kk++)  
{
  for(int n = 1; n <=   HOW_MANY_FLUIDS-1; n++)  
{
 if(   kk != kk+n && kk+n <HOW_MANY_FLUIDS)
{

  springharmony_netonnet(ll,lkl,kk,kk+n );
 
}
 else if(  kk != kk+n && kk+n >= HOW_MANY_FLUIDS)
{

   springharmony_netonnet(ll,lkl,kk,kk -n);

}
else
{
 
}

}

}
}


 //for(int lkl = 0; lkl <   totalneigbours[ll][kk]; lkl++)  
  { 
 INDEX_NR=    springharmony_status_link[ll][lkl][kk].INDEX_NR ; 	
if(  INDEX_NR > 0  && INDEX_NR < KvvVENTAL && INDEX_NR != ll)
{
glPushMatrix();
  glTranslatef(springharmony_status_link_[INDEX_NR][lkl][kk].pos_new_x, springharmony_status_link_[INDEX_NR][lkl][kk].pos_new_y,springharmony_status_link_[INDEX_NR][lkl][kk].pos_new_z);

 
   glColor3f(springharmony_status_link_[INDEX_NR][lkl][kk].pos_new_x, springharmony_status_link_[INDEX_NR][lkl][kk].pos_new_y,springharmony_status_link_[INDEX_NR][lkl][kk].pos_new_z); 
 
 
glutWireSphere(0.05  ,11 +(kk+1),22+(kk+1)  );
 glPopMatrix();
}
}

}

	 }

} 

   display_mpeg();
 
	glutSwapBuffers();

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
			focus_camera(ed_cur_obj(ed));
			break;
		case 8:	case 127:	/* Backspace or Delete */
			ed_prev_obj(ed);
			focus_camera(ed_cur_obj(ed));
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
}

static void special(int key, int x, int y)
{
	if (ed_is_editing(ed))
		return;

	switch (key) {
	case GLUT_KEY_RIGHT:
		ed_next_obj(ed);
		focus_camera(ed_cur_obj(ed));
		break;
	case GLUT_KEY_LEFT:
		ed_prev_obj(ed);
		focus_camera(ed_cur_obj(ed));
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
	ed = ed_create();
 
	ed_add_obj(ed, "s.obj", 1);
	printf("done.\n");
 
	focus_camera(ed_cur_obj(ed));

	glutMainLoop();

	return 0;
}
