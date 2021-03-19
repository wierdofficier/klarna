#include <math.h>
#include <stdlib.h>
#include "gl.h"
#include "mesh.h"
#include "mathx.h"

void mesh_render(const struct mesh *mesh)
{
	int i, nr_faces;

	nr_faces = mesh_face_count(mesh);
	for (i = 0; i < nr_faces; i++) {
		int j, nr_verts;

		nr_verts = mesh_face_vertex_count(mesh, i);
		glBegin(GL_POLYGON);
		for (j = 0; j < nr_verts; j++) {
			const float *v;

			v = mesh_get_normal(mesh, i, j);
			if (v)
				glNormal3fv(v);

			v = mesh_get_vertex(mesh, i, j);
			glVertex3fv(v);
		}
		glEnd();
	}
}

void mesh_compile_list(const struct mesh *mesh, GLuint list)
{
	glNewList(list, GL_COMPILE);
	mesh_render(mesh);
	glEndList();
}
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
#include "../system.h"
#include "../kdtree.h"
 typedef struct {
	float x, y, z;
} Vec3;
#define NUM_THREADS 5
#include <stdbool.h>
 int nomoreindex = 1;
extern int KvvVENTAL ;
extern float *V[10];
extern int KvvVENTALA[600000*2]; 

 extern int veclist[600000 ][2];
extern struct state_vector   springharmony_status_link[  8333][32][1]; 
extern struct state_vector *** reall;
extern struct state_vector    springharmony_status_link_[  8333][32][1];  


void mesh_calc_bounds(const struct mesh *mesh, float *min, float *max,int jj)
{


double changer1 = 1;
double changer2 = 1;
double changer3 = 1;
double yup = 0;
int once = 1;
int counnn =0;
double centroidx = 0;
double centroidy = 0;
double centroidz = 0;
double cx= 0;
double cy= 0;
double cz= 0;
	int i,j, nr;
	const float *vbuf;
 
	nr = mesh_vertex_buffer(mesh, &vbuf )  /1;
 	springharmony_status_link_[0][0][0].totnumpoints[jj] = nr;
 	

 
/*
state_result_worm_ventral= (struct state_vector ***) malloc(sizeof(struct state_vector**) * nr*3); //FIX 1
for(i = 0; i < nr*2; i++){
 
  state_result_worm_ventral[i] = (struct state_vector **) malloc(sizeof(struct state_vector*) * nr*3);  // FIX 2
  for(j = 0; j < 33; j++){
 
        state_result_worm_ventral[i][j] = (struct state_vector *) malloc(sizeof(struct state_vector) * 3);
  }
}

 

state_result_worm_ventral_feather= (struct state_vector ***) malloc(sizeof(struct state_vector**) * nr*3); //FIX 1
for(i = 0; i < nr*2; i++){
 
  state_result_worm_ventral_feather[i] = (struct state_vector **) malloc(sizeof(struct state_vector*) * nr*3);  // FIX 2
  for(j = 0; j < 33; j++){
 
        state_result_worm_ventral_feather[i][j] = (struct state_vector *) malloc(sizeof(struct state_vector) * 3);
  }
}
*/

 	int kk = 0; 
  Vec3 * v;
	int ll;
	
 
for(kk = 0; kk < 4; kk++)
	{
	for(ll = 0; ll < nr  ; ll++)
	{
  printf(" index %d \n",  nr);
	  v= (Vec3 *)(V[jj] + 3*(veclist[ll][jj]-1));
//if(v->x != 0 && v->y != 0 && v->z != 0)
{
double vel1=  ((float)rand()/(float)(RAND_MAX))  ;
double vel2=  ((float)rand()/(float)(RAND_MAX)) ;
double vel3=  ((float)rand()/(float)(RAND_MAX)) ;

double mass=  ((float)rand()/(float)(RAND_MAX)) ;
if(yup == 0)
{
         	  springharmony_status_link_[ll][0][kk].pos_new_x[jj]  = v->x/(changer1) +yup ;
 printf("vel1 =%f \n", vel1);
 	          springharmony_status_link_[ll][0][kk].pos_new_y[jj]  = v->y/(changer2)+yup ;
 		  springharmony_status_link_[ll][0][kk].pos_new_z[jj]  = v->z/(changer3) +yup ;
 		  
 		   centroidx +=v->x;
		   centroidy +=v->y;
		   centroidz +=v->z;
 		  }
 		  else if(yup == 1)
 		  {
 		 
 		 springharmony_status_link_[ll][0][kk].pos_new_x[jj]  = (    (v->x - cx) )/changer1 + cx ;
 printf("vel1 =%f \n", vel1);
 	          springharmony_status_link_[ll][0][kk].pos_new_y[jj]  =   v->y/(changer1);
 		  springharmony_status_link_[ll][0][kk].pos_new_z[jj]  = ( (v->z - cz) )/changer3 + cz;
 		  
 		  
 		  }
 		  springharmony_status_link_[ll][0][kk].mass = 1.0;
 
 	  	  springharmony_status_link_[ll][0][kk].vel_new_x[jj]  = 1*1e-11;
 		  springharmony_status_link_[ll][0][kk].vel_new_y[jj]  = 1*1e-11;
 		  springharmony_status_link_[ll][0][kk].vel_new_z[jj]  =1*1e-11;

}
  printf("vector   %.10f  %.10f  %.10f  %d \n", v->x,v->y,v->z,ll);
	}
 

printf("counnn =%d\n", ll);
	 for(ll = 0; ll < nr     ; ll++)
	{
 	 	 findnearestpoint(nr  ,NULL,ll,0,kk ,0.004,jj);
	}

  changer1 = changer1 +0.015;
  changer2 = changer2 +0.025;
  changer3 = changer3 +0.2;
  cx = centroidx/nr;
  cy = centroidy/nr;
  cz = centroidz/nr;
printf("pos {%f,%f,%f}\n", cx,cy,cz);

 
  yup = 1;
}
 
  nomoreindex = 0;
  KvvVENTAL = 0;
	vec_set(min, INFINITY, INFINITY, INFINITY);
	vec_neg(max, min);
	for (i = 0; i < nr; i++) {
		vec_min(min, min, vbuf + 3 * i);
		vec_max(max, max, vbuf + 3 * i);
	}
}
