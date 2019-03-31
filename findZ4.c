#include <math.h>
#include <complex.h>
int main()
{
double V = 0.1;
double VOLTA = 0.1;
double f  = 2.5e-6 ;
double Z[10000]  ;
double M__[10000]  ;
double XX__[10000]  ;
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
 double A,B,C;
double photonmass ;
double energy;
/*
2.0182784790 0.0000050000 0.2312339711 0.0000074344 16.8851911876
6.9255178473 0.0000050000 0.9249358845 0.0000074344 16.8851911876
11.1240451881 0.0000050000 2.0811057402 0.0000074344 16.8851911876

*/
/* show data, den är korrekt. */
int count = 0;
for(int i = 0; i < 1*20; i++)
{ 
 
				  f = -2.13163e-19 + 5e-6*KKKK;
		  v  = (4.23971e8)/sqrt((1.0 + sqrt(1.0 + 3.23118e20 *pow((o/f),2.0)))* P);
 		  r = (615.728* 1)/(R* pow(((pow(o,3.0)* P* 1)/(pow(f,3.0)*pow(p,2.0) *pow(R,4.0))),1.0/4.0));
  U  = sqrt((pow(o,3.0)* P *pow(V,4.0))/(pow(f,3.0)* pow(p,2.0)* pow(R,4.0)))/(1199169832000.0 *sqrt(10.0)*M_PI);
		  photonmass =  357.0 *(-1 + sqrt(1 + pow(U,2.0)))/1250000.0;
 		
		 A=(0.5* (photonmass)*1*pow(r,2.0)*pow((2*M_PI*f),2.0))/(U/pow(299792458,2.0)*(3.528*0.005*M_PI/2.0)*pow(v,2.0));
			


	 V += 0.1;
				  f = -2.13163e-19 + 5e-6*KKKK;
		  v  = (4.23971e8)/sqrt((1.0 + sqrt(1.0 + 3.23118e20 *pow((o/f),2.0)))* P);
		 		  r = (615.728* 1)/(R* pow(((pow(o,3.0)* P* 1)/(pow(f,3.0)*pow(p,2.0) *pow(R,4.0))),1.0/4.0));

	U  = sqrt((pow(o,3.0)* P *pow(V,4.0))/(pow(f,3.0)* pow(p,2.0)* pow(R,4.0)))/(1199169832000.0 *sqrt(10.0)*M_PI);
		  photonmass =  357.0 *(-1 + sqrt(1 + pow(U,2.0)))/1250000.0;
		  
		B=(0.5* (photonmass)*1*pow(r,2.0)*pow((2*M_PI*f),2.0))/(U/pow(299792458,2.0)*(3.528*0.005*M_PI/2.0)*pow(v,2.0));

	 V += 0.1;		
				  f = -2.13163e-19 + 5e-6*KKKK;
		  v  = (4.23971e8)/sqrt((1.0 + sqrt(1.0 + 3.23118e20 *pow((o/f),2.0)))* P);
 		  r = (615.728* 1)/(R* pow(((pow(o,3.0)* P* 1)/(pow(f,3.0)*pow(p,2.0) *pow(R,4.0))),1.0/4.0));

		  U  = sqrt((pow(o,3.0)* P *pow(V,4.0))/(pow(f,3.0)* pow(p,2.0)* pow(R,4.0)))/(1199169832000.0 *sqrt(10.0)*M_PI);
		  photonmass =  357.0 *(-1 + sqrt(1 + pow(U,2.0)))/1250000.0;

		C=(0.5* (photonmass)*1*pow(r,2.0)*pow((2*M_PI*f),2.0))/(U/pow(299792458,2.0)*(3.528*0.005*M_PI/2.0)*pow(v,2.0));
 		
 
		double D = 1.0/pow(((-5515540747304653959756513280.0 *A + 8466519923883659520034996224.0*B - 2951071217962757788006350848.0*C)/(32410546248787498094297088.0*A - 233546412144353310740054016.0*B + 201135865895565842710528000.0*C)),0.4482495853691335);


	double Y = -0.27069 *pow((1.0/D),(22309.0/10000.0)) *((4.69427* A)/pow((1.0/D),(22309.0/10000.0)) + 0.0275847* A - B/pow((1.0/D),(22309.0/10000.0)) - 0.0275847 *C);


 	 XX= (A + Y/(1 + 0.0275847 *pow((1.0/D),(22309.0/10000.0))))/(1 - 1.00/(1 + 0.0275847* pow((1.00/D),(22309.0/10000.0))));
VOLTA  += 0.1;
	double  newZ = ((( (XX) + (-Y - (XX))/(1.0 + pow((((VOLTA)*2)/(D)),2.2309)   )  )));
	//printf("XX = %.10f frequency = %.10f  volt = %.10f : %.10f %.10f %.10f  \n", XX,f, newZ,A,B,C);
	double rr = (615.728* 1)/(R* pow(((pow(o,3.0)* P* 1)/(pow(f,3.0)*pow(p,2.0) *pow(R,4.0))),1.0/4.0));
	//printf(" %.10f : %.10f  %.10f  %.10f   %.10f   \n",  XX,Y,D,f,newZ);
Q  = 0.02777;

   M  = (1.48679e-24* Q* pow(R,2.0) *U*pow(v,2.0)* sqrt((pow(o,3.0) *pow(V,4.0))/(pow(f,3.0)* pow(2700,2.0)* pow(R,4.0)))* newZ )/(pow(f,2.0)* pow(V,2.0));
 
	double volt = 0.1;
 
 Z[count] = newZ;
 M__[count] = M;
 XX__[count] = XX;
count++;
 KKKK = KKKK*1.018;
 V  = 0.1;
}
 
 
 

 
count = 0;
KKKK =1.0;
V = 0.2;
/* show solution with new data, den är korrekt,nästan. */
while(count <  20)
{
	 
	
	f = -2.13163e-19 + 5e-6*KKKK;
 
	double rr = (615.728* 1)/(R* pow(((pow(o,3.0)* P* 1)/(pow(f,3.0)*pow(p,2.0) *pow(R,4.0))),1.0/4.0)); 
	
 
 	XX  =   5.470555691e11*pow(rr,2.0) - 5450554.462*rr + 16.9583061;//38.6462 - 7.91894e-14* sqrt(401007909167331664725444395008.0 - 32528999126144027583106997439954944.0 *rr);
 
	 double y = 2.520717302e-11 *pow(XX,2.0) + 9.665025542e-9* XX + 3.657387124e-7;

	double L =  1.423972384e-4 *pow(XX,2.0) - 2.513206534e-2 *XX + 9.204275567e-1; //  -2.076158371e-4 *pow(XX,2.0) + 1.645080654e-2* XX + 1.509148955e-1; // //0.261458897;//   -5.367391155e-5 *pow(XX,2.0) + 1.045223119e-2 *XX + 1.634736817e-1;

	double D =  -2.076158371e-4 *pow(XX,2.0) + 1.645080654e-2 *XX + 1.509148955e-1;// 1.423972384e-4* pow(XX,2.0) - 2.513206534e-2* XX + 9.204275567e-1; // 4.693490519e-5* pow(XX,2.0) -  
	  
	 double  textZ   = ((( (XX) + (-L - (XX))/(1.0 + pow(((V*2)/(D)),2.2309)   )  )));;
	 //printf("%.10f %.10f %.10f\n", f,newZ,Z[count]   );

	double v  = (4.23971e8)/sqrt((1.0 + sqrt(1.0 + 3.23118e20 *pow((o/f),2.0)))* P);
	double Q  = 0.02777;

	U  = sqrt((pow(o,3.0)* P *pow(V,4.0))/(pow(f,3.0)* pow(p,2.0)* pow(R,4.0)))/(1199169832000.0 *sqrt(10.0)*M_PI);
	double  M  = (1.48679e-24* Q* pow(R,2.0) *U*pow(v,2.0)* sqrt((pow(o,3.0) *pow(V,4.0))/(pow(f,3.0)* pow(2700,2.0)* pow(R,4.0)))* textZ )/(pow(f,2.0)* pow(V,2.0));
	 	//  printf("%.10f %.10f %.10f  %.10f   %.10f   %.10f  mass = %.10f  \n",  f,L,D,XX, textZ,V , M  );
 printf("%.10f %.10f     mass = %.10f   ",  XX, textZ , M  );
M  = (1.48679e-24* Q* pow(R,2.0) *U*pow(v,2.0)* sqrt((pow(o,3.0) *pow(V,4.0))/(pow(f,3.0)* pow(2700,2.0)* pow(R,4.0)))*  Z[count] )/(pow(f,2.0)* pow(V,2.0));
 printf("%.10f %.10f     mass = %.10f \n",  XX__[count], Z[count]  ,M   );
	 
	 
  V += 0.1;
 KKKK = KKKK*1.018;
count++;	 
 
}
}
