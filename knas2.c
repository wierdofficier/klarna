#include <math.h>
#include <complex.h>
#include <stdio.h>
int main()
{
double V = 0.00000001;

double f  =  5e-6 ;

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
for(int i = 0; i < 1*500; i++)
{ 
 
		v  = (4.23971e8)/sqrt((1.0 + sqrt(1.0 + 3.23118e20 *pow((o/f),2.0)))* P);
 		r = (615.728* 1)/(R* pow(((pow(o,3.0)* P* 1)/(pow(f,3.0)*pow(p,2.0) *pow(R,4.0))),1.0/4.0));
 		U  = sqrt((pow(o,3.0)* P *pow(V,4.0))/(pow(f,3.0)* pow(p,2.0)* pow(R,4.0)))/(1199169832000.0 *sqrt(10.0)*M_PI);

		photonmass =  357.0 *(-1 + sqrt(1 + pow(U,2.0)))/1250000.0;
 		double acc =  9.81- 9.81*(1.428e-4-photonmass)/1.428e-4;
		double knas = 1.0 - (50.0* acc)/981.0  ; 

		ojk=(0.5* (photonmass)*1*pow(r,2.0)*pow((2*M_PI*f),2.0))/(U/pow(299792458,2.0)*(3.528*0.005*M_PI/2.0)*pow(v,2.0));

 
		double ZZ = (1.25509e-24 *acc)/(pow(f,(9.0/2.0))* U);
			
V = V+ 0.01;
f = f / 1.00028;
printf("%.7f\t%.7f\n",796755611151391638159360.0*pow(f,(9.0/2.0))* U,ZZ );
}
for(;;);

}
/*
Lösning:

m*U^2= (x^2*4.99)*V^4*Z solve Z
Z =(100 m U^2)/(499 V^4 x^2)

m = (357.0 *(-1 + sqrt(1 + pow(U,2.0)))/1250000.0)
x = (V/4.99)
(100 (357.0 *(-1 + sqrt(1 + pow(U,2.0)))/1250000.0) U^2)/(499 V^4 (V/4.99)^2) = Z
=(0.00142514 U^2 (sqrt(U^2 + 1) - 1))/V^6 = Z

9.81-(3-2*X)*9.81 = g solve X
X= 1 + (50 g)/981

(0.00142514 U^2 (sqrt(U^2 + 1) - 1))/V^6 = Z, där sqrt(U^2 + 1) = X

(0.00142514 U^2 ((1 + (50 g)/981) - 1))/V^6 = Z

(13767.1 (-1966.74 f^(3/4) sqrt(U))^6 Z)/U^2

7.96754×10^23 f^(9/2) U Z=g solve Z

Z=(1.25509×10^-24 g)/(f^(9/2) U)

z = (1.25509e-24 *a)/(pow(f,(9.0/2.0))* U) solve a

796755611151391638159360 f^(9/2) U z


printf("%.7f\t%.7f\n",796755611151391638159360.0*pow(f,(9.0/2.0))* U,ZZ );

( k + (-L - k)/(1 + (x1/D)^p)) = y , en symmetrisk sigmoidal formel alltså.

multiplicera med x1 så får man lösningen:

( k + (-L - k)/(1 + (x1/D)^p))*x1 = y

k = 0.0296648
L = -11.8322
D = 1.64016
p = 0.988836



( 0.0296648 + (-( -11.8322) - 0.0296648)/(1 + (U/1.64016)^0.988836))*U =Z 

*/
