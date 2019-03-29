#include <math.h>
int main()
{
double V = 0.1;
double f  = 2.5e-6 ;
double Z = 0;
double o  = 3.5e7;
double p  = 2700;
double P  = 1;
double R  = 4.99;

double v ;
double U ;
	

double r  ;
double photonmass ;
for(int i = 0; i < 3; i++)
{ 

	for(int j = 0; j < 3; j++)
	{ 	
		  o  = 3.5e7;
		  p  = 2700;
		  P  = 1;
		  R  = 4.99;

		  v  = (4.23971e8)/sqrt((1.0 + sqrt(1.0 + 3.23118e20 *pow((o/f),2.0)))* P);
		  U  = sqrt((pow(o,3.0)* P *pow(V,4.0))/(pow(f,3.0)* pow(p,2.0)* pow(R,4.0)))/(1199169832000.0 *sqrt(10.0)*M_PI);
	

 		  r = (615.728* 1)/(R* pow(((pow(o,3.0)* P* 1)/(pow(f,3.0)*pow(p,2.0) *pow(R,4.0))),1.0/4.0));
		  photonmass = 1.428e-4 - ( ((2*(sqrt(1+6.67e-14*  pow(V,4.0)/pow(f,3.0)))) -3))*1.428e-4;
  
		Z=(0.5*photonmass*1*pow(r,2.0)*pow((2*M_PI*f),2.0))/(U/pow(299792458,2.0)*(3.528*0.005*M_PI/2.0)*pow(v,2.0));
 	
		V = V + 0.1;
		printf("%.10f %.10f %.10f %.10f %.10f   \n", Z,v,U,r,photonmass);
	}

f = f/2.0;
V = 0.1;
}


}
