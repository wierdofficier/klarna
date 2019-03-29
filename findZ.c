#include <math.h>
int main()
{
double V = 0.1;
double f  = 5e-6 ;
double Z = 0;
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
double zz2;
double LL;
double YY;
double photonmass ;
/*
2.0182784790 0.0000050000 0.2312339711 0.0000074344 16.8851911876
6.9255178473 0.0000050000 0.9249358845 0.0000074344 16.8851911876
11.1240451881 0.0000050000 2.0811057402 0.0000074344 16.8851911876

*/

for(int i = 0; i < 3; i++)
{ 

	for(int j = 0; j < 3; j++)
	{ 	
		 
		  Q  = 0.028;
		  o  = 3.5e7;
		  p  = 2700;
		  P  = 1;
		  R  = 4.99;
		  f = -2.13163e-19 + 5e-6*KKKK;
		  v  = (4.23971e8)/sqrt((1.0 + sqrt(1.0 + 3.23118e20 *pow((o/f),2.0)))* P);
		  U  = sqrt((pow(o,3.0)* P *pow(V,4.0))/(pow(f,3.0)* pow(p,2.0)* pow(R,4.0)))/(1199169832000.0 *sqrt(10.0)*M_PI);
	

 		  r = (615.728* 1)/(R* pow(((pow(o,3.0)* P* 1)/(pow(f,3.0)*pow(p,2.0) *pow(R,4.0))),1.0/4.0));
		  photonmass =  357.0 *(-1 + sqrt(1 + pow(U,2.0)))/1250000.0;
  		


		// XX = -1.34779632e-12* pow(x,2.0) - 9.077023941e-4* x *r + 24733.49386* pow(r,2.0) + 1.769760539e-8* x + 4.929211372e-1 *r - 2.161999993e-7;

 		
		 Z=(0.5*photonmass*1*pow(r,2.0)*pow((2*M_PI*f),2.0))/(U/pow(299792458,2.0)*(3.528*0.005*M_PI/2.0)*pow(v,2.0));
 		


		M  = (1.48679e-24* Q* pow(R,2.0) *U*pow(v,2.0)* sqrt((pow(o,3.0) *pow(V,4.0))/(pow(f,3.0)* pow(p,2.0)* pow(R,4.0)))* Z)/(pow(f,2.0)* pow(V,2.0));
		V = V + 0.1;
		printf("%.10f %.10f %.10f %.10f %.10f\n", Z,f,U,r,XX);
	//	printf("%.10f\n", M);
	}

KKKK = KKKK+ 1;
V = 0.1;
}
double A = 4.0830011971 ;
double C=  32.8422571807;
double B=  15.943821610;

double D = 1.0/pow(((-5515540747304653959756513280.0 *A + 8466519923883659520034996224.0*B - 2951071217962757788006350848.0*C)/(32410546248787498094297088.0*A - 233546412144353310740054016.0*B + 201135865895565842710528000.0*C)),0.4482495853691335);


double Y = -0.27069 *pow((1/D),(22309.0/10000.0)) *((4.69427* A)/pow((1/D),(22309.0/10000.0)) + 0.0275847* A - B/pow((1/D),(22309.0/10000.0)) - 0.0275847 *C);


  XX= (A + Y/(1 + 0.0275847 *pow((1/D),(22309.0/10000.0))))/(1 - 1/(1 + 0.0275847* pow((1/D),(22309.0/10000.0))));
printf("%.10f  %.10f  %.10f\n", D,Y,XX);
printf("%f + i%f\n", creal(Y), cimag(Y));
}