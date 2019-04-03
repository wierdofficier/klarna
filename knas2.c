#include <math.h>
#include <complex.h>
#include <stdio.h>
int main()
{
double V = 0.1;

double f  =  1e-9 ;

double Z[500000]  ;

double o  = 3.5e7;
double p  = 2700;
double P  = 1;
double R  = 4.99;
double KKKK =1;
double v ;
double U ;
double Q;	
double M;
double XX;  
double r  ;
double zz;

double LL;
double YY;
 double A,B,C;

double coolZ[10000];

double ojk;
double photonmass ;


int count = 0;
 int once = 0;
double end;
int countme = 0;
double expo = -1.0;
FILE *out_file;
for(int i = 0; i < 1*10000 ; i++)
{ 
 
		v  = (4.23971e8)/sqrt((1.0 + sqrt(1.0 + 3.23118e20 *pow((o/f),2.0)))* P);
 		r = (615.728* 1)/(R* pow(((pow(o,3.0)* P* 1)/(pow(f,3.0)*pow(p,2.0) *pow(R,4.0))),1.0/4.0));
 		U  = sqrt((pow(o,3.0)* P *pow(V,4.0))/(pow(f,3.0)* pow(p,2.0)* pow(R,4.0)))/(1199169832000.0 *sqrt(10.0)*M_PI);

		photonmass = 1.428e-4 - (1-2*(sqrt(1+6.67e-14*pow(V,4.0)/pow(f,3.0))-1))*1.428e-4;
 		double acc =  9.81- 9.81*(1.428e-4-photonmass)/1.428e-4;
		double knas = 1.0 - (50.0* acc)/981.0  ; 

		ojk=(0.5* (photonmass)*1*pow(r,2.0)*pow((2*M_PI*f),2.0))/(U/pow(299792458,2.0)*(3.528*0.005*M_PI/2.0)*pow(v,2.0));

 
		double ZZ = (1.25509e-24 *acc)/(pow(f,(9.0/2.0))* U);
		double knas2 = (1.0023-1.0/(-0.723*pow(U,-1.11133)-1)-U);
		double acc2=(9.81-(knas2*9.81))*2;


		//double acc2 = (9.81-( knas2*9.81))*2 ;
			
V = V+ 0.01;
f =f*1.001;
 printf("%.7f\t%.7f\n",   acc,   acc2 );//ger  ( (-1.01329) + (-(-752136) - (-1.01329))/(1 + (U/3.3621e-7)^0.876795))*U where U =5.78

}
for(;;);

}
/*
Lösning:

***************
1.0023-1/(-0.73812*U^-1.11133-1)-U

som har formen:

1.0023 - 1/(b*x^a-1)-x = knas
***************

*/
