#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <GL/glut.h>
#include <float.h>
#include <limits.h>
#include <float.h>
#include <limits.h>
#include "system.h"
int NUMEQ = 6;
double eps(x) {double d = nextafter(x,  DBL_MAX);   return  (d-x); }

void rk45(void f(double *, double [], double result[]  ), double *t, double *x,double y_n[], double *tf,double * export , int howmanyeq, double stepsize)
{

double h[NUMEQ];
double  te[NUMEQ];
double hmin;
int n = 0;
while(n <  NUMEQ)
{
	h[n]=(tf[n] - t[n])/stepsize; 
	//printf("h[n] = %f  : tf[n] = %f : stepsize  = %f \n", h[n],tf[n],stepsize);
	n++;
}
n = 0;

double tol =  0.0001;

double c20 = 0.25, c21 = 0.25;
double c30 = 0.375, c31 = 0.09375, c32 = 0.28125;
double c40,c41, c42,c43;
double c51, c52 = -8.0, c53, c54;
double c60 = 0.5, c61, c62 = 2, c63, c64;
double c65 = -0.275;
double a1, a2 = 0, a3, a4, a5 = -0.2;
double b1, b2 = 0, b3, b4, b5= -0.18, b6;
double F1[NUMEQ], F2[NUMEQ], F3[NUMEQ], F4[NUMEQ], F5[NUMEQ], F6[NUMEQ], x4;
double a6 = 0;
c40 = (double) 12/ (double) 13;
c41 = (double) 1932/(double) 2197;
c42 = (double) -7200/(double) 2197;
c43 = (double) 7296/(double) 2197;
c51 = (double) 439/ (double) 216;
c53 = (double) 3680/(double) 513;
c54 = (double) -845/(double) 4104;
c61 = (double) -8/(double) 27;
c63 = (double) -3544/(double) 2565;
c64 = (double) 1859/(double) 4104;
a1 =  (double) 25/(double) 216;
a3 =  (double) 1408/(double) 2565;
a4 =  (double) 2197/(double) 4104;
b1 =  (double) 16/(double) 135;
b3 =  (double) 6656/(double) 12825;
b4 =  (double) 28561/(double) 56430;
b6 =  (double) 2/(double) 55;
 
while (t[0] < tf[0])
{
	double   y_n_stable[100000];
	double  stable_value[100000];
	double time_pos[NUMEQ];
	double step_size[NUMEQ];
	double step_size_time[NUMEQ];
	while(n <  NUMEQ)
	{
		hmin = 16*eps(t[n]);
 		stable_value[n] = export[n];
		y_n_stable[n] = export[n];

		x[n] =stable_value[n];
		time_pos[n] = t[n];
		f(t, x, y_n);
		F1[n] =  y_n[n];
		step_size[n] = h[n]*c21;
	
		x[n] = stable_value[n] + step_size[n] * F1[n];
		time_pos[n] = t[n]+c20 * h[n] ;
		f(time_pos,  x, y_n );
		F2[n] =  y_n[n];
		x[n] = stable_value[n] + h[n]*(c31 * F1[n] + c32 * F2[n]);
		time_pos[n] = t[n] + c30 * h[n];
		f(time_pos, x, y_n );
		F3[n] = y_n[n];
		x[n] = stable_value[n] + h[n]*(c41 * F1[n] + c42 * F2[n] + c43 * F3[n]);
		time_pos[n] = t[n] + c40 * h[n];
		f(time_pos,  x, y_n );
		F4[n] = y_n[n];
		x[n] = stable_value[n] + h[n]*(c51 * F1[n] + c52 * F2[n] + c53 * F3[n] + c54 * F4[n] );
		time_pos[n] = t[n] + h[n];
		f(time_pos,  x, y_n );
		F5[n] =  y_n[n];
		x[n] = stable_value[n] + h[n]*(c61 * F1[n] + c62 * F2[n] + c63 * F3[n] + c64 * F4[n] + c65 * F5[n]);
		time_pos[n] = t[n]  + c60 * h[n];
		f(time_pos, x, y_n );
		F6[n] =  y_n[n];
 
		te[n] = h[n]*(F1[n]*(b1 - a1)+F2[n]*(b2 - a2)+F3[n]*(b3 - a3)+F4[n]*(b4 - a4)+F5[n]*(b5 - a5)+F6[n]*(b6 - a6));

		n++;
	}
 
	double te_max = 0;
	int k;
 
	for( k = 0;k < NUMEQ ; k++) {
		if (fabs (te[k]) > te_max) { te_max = te[k]; }
	}

	int v;
	double ymax = 0;
	for( v = 0; v < NUMEQ ; v++) {
		if (fabs (y_n[v]) > ymax) { ymax = y_n[v]; }
	}

	double te_allowed = tol*fmax(ymax,1.0);
	double delta = pow(te_allowed/(te_max + eps(1)), 1/5);
	//if (te_max <= te_allowed)
	//{
		n = 0;
		while(n <  NUMEQ)
		{
			h[n] = fmin(h[n], tf[n]-t[n]);
			t[n] = t[n] + h[n];
			n++;
		}
		n = 0;
		for(n = 0; n < NUMEQ; n++)
		{
			y_n[n]= y_n_stable[n] + h[n]*((F1[n]*b1)+(F2[n]*b2)+(F3[n]*b3)+(F4[n]*b4)+(F5[n]*b5)+(F6[n]*b6) );
			export[n] = y_n[n];
		}
		n = 0;
		while(n <  NUMEQ)
		{
			h[n] = fmin(delta*h[n], 4*h[n]);
		//	if (h[n] < hmin)
		//		printf("\n\n Warning: Step size fell below its minimum allowable value (%g) at time %g.\n\n",hmin, t);
			n++;
		}
		n = 0;
	//	free(y_n_stable);
		//free(stable_value);
	//}
	}
}
