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
 
extern int KvvVENTAL ;
extern float *V;
extern int KvvVENTALA[600000*2]; 

struct state_vector *  springVector;
struct state_vector   springharmony_status_link[ 133333][33][1]; 
struct state_vector *** reall;
struct state_vector    springharmony_status_link_[ 133333][33][1];  

double changer = 1;
int once = 1;
void mesh_calc_bounds(const struct mesh *mesh, float *min, float *max)
{
	int i,j, nr;
	const float *vbuf;
 
	nr = mesh_vertex_buffer(mesh, &vbuf ) /100;
 	KvvVENTAL = nr;

 if(once == 1)
{
 springVector = malloc(nr*112);
 
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
for(kk = 0; kk <  10  ; kk++)
	{
	for(ll = 0; ll < nr  ; ll++)
	{
  printf(" index %d \n",  nr);
	  v= (Vec3 *)(V + 3*(KvvVENTALA[ll]-1));
         	  springharmony_status_link_[ll][0][kk].pos_new_x = v->x/(changer)  ;
 
 	          springharmony_status_link_[ll][0][kk].pos_new_y = v->y/(changer) ;
 		  springharmony_status_link_[ll][0][kk].pos_new_z = v->z/(changer)  ;
 
 	  	  springharmony_status_link_[ll][0][kk].vel_new_x = 1e-2*(kk+3) ;
 		  springharmony_status_link_[ll][0][kk].vel_new_y = 1e-3*(kk+3) ;
 		  springharmony_status_link_[ll][0][kk].vel_new_z =  6e-2*(kk+3)  ;
  printf("vector   %.10f  %.10f  %.10f  %d \n", v->x,v->y,v->z,ll);
	}
 
 
	for(ll = 0; ll < nr     ; ll++)
	{
 		findnearestpoint(nr  ,NULL,ll,0,kk );
	}
 changer = changer +0.2;
 
}
 
init_mpgeg();
once  = 0;
}

	vec_set(min, INFINITY, INFINITY, INFINITY);
	vec_neg(max, min);
	for (i = 0; i < nr; i++) {
		vec_min(min, min, vbuf + 3 * i);
		vec_max(max, max, vbuf + 3 * i);
	}
}
