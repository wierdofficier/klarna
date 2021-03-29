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
extern float *V[100];
 
void free_data(struct state_vector ***data, size_t xlen, size_t ylen)
{
    size_t i, j;

    for (i=0; i < xlen; ++i) {
        if (data[i] != NULL) {
            for (j=0; j < ylen; ++j)
                free(data[i][j]);
            free(data[i]);
        }
    }
    free(data);
}
 extern int veclist[8840 ][100];
extern struct state_vector   ***  springharmony_status_link  ; 
extern struct state_vector *** reall;
extern struct state_vector    ***  springharmony_status_link_    ;  
int ***alloc_data(size_t xlen, size_t ylen, size_t zlen)
{
    struct state_vector ***p;
    size_t i, j;

    if ((p = malloc(xlen * sizeof *p)) == NULL) {
        perror("malloc 1");
        return NULL;
    }

    for (i=0; i < xlen; ++i)
        p[i] = NULL;

    for (i=0; i < xlen; ++i)
        if ((p[i] = malloc(ylen * sizeof *p[i])) == NULL) {
            perror("malloc 2");
            free_data(p, xlen, ylen);
            return NULL;
        }

    for (i=0; i < xlen; ++i)
        for (j=0; j < ylen; ++j)
            p[i][j] = NULL;

    for (i=0; i < xlen; ++i)
        for (j=0; j < ylen; ++j)
            if ((p[i][j] = malloc(zlen * sizeof *p[i][j])) == NULL) {
                perror("malloc 3");
                free_data(p, xlen, ylen);
                return NULL;
            }

    return p;
}
 
int nr = 0;
int once__ = 1;
 
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
	int i,j;
		int ll = 0;
	const float *vbuf;
	nr = mesh_vertex_buffer(mesh, &vbuf )  /1;
	if(once__ == 1)
	{
         springharmony_status_link_=alloc_data(7936,55,7);
        springharmony_status_link=alloc_data(7936,55,7);
 
	
	for(  ll = 0; ll < 2 ; ll++)
	{
	springharmony_status_link_[0][0][0].tot_layer[ll] = 7;

	}  	
	once__ = 0;
	}
	

  	springharmony_status_link_[0][0][0].totnumpoints[jj] = nr/1;
 
 	int kk = 0; 
  Vec3 * v;

	ll = 0;
 
for(kk = 0; kk < springharmony_status_link_[0][0][0].tot_layer[jj]; kk++)
	{
	for(ll = 0; ll < springharmony_status_link_[0][0][0].totnumpoints[jj]  ; ll++)
	{
 
	  v= (Vec3 *)(V[jj] + 3*(veclist[ll][jj]-1));
	  
 
{
double vel1=  ((float)rand()/(float)(RAND_MAX))  ;
double vel2=  ((float)rand()/(float)(RAND_MAX)) ;
double vel3=  ((float)rand()/(float)(RAND_MAX)) ;

double mass=  ((float)rand()/(float)(RAND_MAX)) ;
if(yup == 0)
{
         	  springharmony_status_link_[ll][0][kk].pos_new_x[jj]  = v->x/(changer1) +yup ;
 
 	          springharmony_status_link_[ll][0][kk].pos_new_y[jj]  = v->y/(changer2)+yup ;
 		  springharmony_status_link_[ll][0][kk].pos_new_z[jj]  = v->z/(changer3) +yup ;

 		   centroidx +=v->x;
		   centroidy +=v->y;
		   centroidz +=v->z;
		 
 		  }
 		  else if(yup == 1)
 		  {
 		 
 		 springharmony_status_link_[ll][0][kk].pos_new_x[jj]  = (    (v->x - cx) )/changer1 + cx ;
 
 	          springharmony_status_link_[ll][0][kk].pos_new_y[jj]  =   v->y/(changer1);
 		  springharmony_status_link_[ll][0][kk].pos_new_z[jj]  = ( (v->z - cz) )/changer3 + cz;
 		  springharmony_status_link_[ll][0][kk].springConstant[jj] =   300.1233/changer3 ;
 		  springharmony_status_link_[ll][0][kk].frictionConstant[jj] =   3.21233*changer3 ;
 		   		  
 		  }
 		  springharmony_status_link_[ll][0][kk].mass[jj] = 1;
 
 	  	  springharmony_status_link_[ll][0][kk].vel_new_x[jj]  = 1*1e-11;
 		  springharmony_status_link_[ll][0][kk].vel_new_y[jj]  = 1*1e-11;
 		  springharmony_status_link_[ll][0][kk].vel_new_z[jj]  =1*1e-11;

		}
	}

	 for(ll = 0; ll < springharmony_status_link_[0][0][0].totnumpoints[jj]     ; ll++)
	{
 	 	 findnearestpoint(springharmony_status_link_[0][0][0].totnumpoints[jj]  ,NULL,ll,0,kk ,0.004,jj);
	}

  changer1 = changer1 +0.005;
  changer2 = changer2 +0.015;
  changer3 = changer3 +0.825 ;
  cx = centroidx/springharmony_status_link_[0][0][0].totnumpoints[jj];
  cy = centroidy/springharmony_status_link_[0][0][0].totnumpoints[jj];
  cz = centroidz/springharmony_status_link_[0][0][0].totnumpoints[jj];
printf("pos {%f,%f,%f}\n", cx,cy,cz);

 
  yup = 1;
}
 
 
  KvvVENTAL = 0;
	vec_set(min, INFINITY, INFINITY, INFINITY);
	vec_neg(max, min);
	for (i = 0; i < springharmony_status_link_[0][0][0].totnumpoints[jj]; i++) {
		vec_min(min, min, vbuf + 3 * i);
		vec_max(max, max, vbuf + 3 * i);
	}
}
