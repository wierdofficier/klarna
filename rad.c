#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <GL/glut.h>
#include <float.h>
#include <limits.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
#define NUM_THREADS 5
 
/* create thread argument struct for thr_func() */
typedef struct _thread_data_t {
  int tid;
  double stuff;
} thread_data_t;
#include "system.h"


#define EFIELD 150.0
#define PERMEABILITY 37000.0  
#define G 0.7296413




#define EFIELD 300.0
#define PERMEABILITY 25000.0 
#define G 4.818


#define EFIELD 200.0
#define PERMEABILITY 25000.0  
#define G 1.735
double  position1[1000000];
double  energy[1000000];
double time_[1000000];
int work =0;
int velonce = 0;
double relativ_permeability;
double accen;
double C;
int result_once = 0;

double attenuation;
#define RADAREA 0.374
struct state_vector photon_oscillate;
double dipolewattsystemh;
int one= 0;
double distance_in_material_2 = 0;
double distance_in_material = 0;
double freq = 60.0;
double velocity= 894.43;
double wavelength = 14.9;
double new_U =200.0;
double new_W = 4576;
double RESISTANCE;
double little_g;
double DISTANCE_;
double new_m ;
double NEWWU= 200.0;
double mega_g;
  double GG = 0;
  double atomic_frequency;
int K;
#define HAX 1000
struct state_vector    state_result_photon;
void rates_photon ( double *t, double *f, double result[]   )
{
/*
  Do some initial setup!
*/
if(one < 1)
{
distance_in_material_2 = 0;
distance_in_material = 0;

RESISTANCE =  new_W/(pow(EFIELD,2.0));  

DISTANCE_ =1.0/(sqrt(M_PI*M_PI*4e-7*(25000)*1.03e7*freq)) *5; 

relativ_permeability = 25000;
//velocity = 1*299792458.0/(sqrt(1*relativ_permeability/2.0*(sqrt(1+pow((1.03e7/(2*M_PI*freq*8.854e-12)),2.0))+1))); 
velocity = 1*299792458.0/(sqrt(1*25000.0/2.0*(sqrt(1+pow((10.0/(2*M_PI*60*8.854e-12)),2.0))+1))); 

relativ_permeability = 179751035759958240.0/(pow(velocity,2.0) + sqrt((32310434856777778462720.0 + pow(freq,2.0))/pow(freq,2.0)) * pow(velocity,2.0));
one++;
}
else
{
attenuation = ( 1.00/10296.7*(new_W/distance_in_material))/7874.0;

DISTANCE_ =1.0/(sqrt(M_PI*M_PI*4e-7*(relativ_permeability)*1.03e7*freq)) *5;
/*
   		This executes every loop.
*/
/* 
  Calculate relativ permeability for iron:
  therefore the frequency must vary
*/
velocity =  1*299792458.0/(sqrt(1*relativ_permeability/2.0*(sqrt(1+pow((1.03e7/(2*M_PI*freq*8.854e-12)),2.0))+1))); 
relativ_permeability = 179751035759958240.0/(pow(f[3],2.0) + sqrt((32310434856777778462720.0 + pow(freq,2.0))/pow(freq,2.0)) * pow(f[3],2.0));
/* 
  Calculate frequency
*/
freq =     (((1.58882e10)* powf(f[3],2.0) *relativ_permeability)/sqrtf( 252425272283202775718997981659136.0 + 2808609933552555.0*powf(f[3],2.0)* relativ_permeability));
/* 
  Calculate velocity
*/

/* 
  Calculate wavelength
*/
wavelength =   sqrt(4*M_PI/(1.03e7*M_PI*relativ_permeability*4e-7*freq));
/* 
  Calculate mass
*/
new_m = (3.35677e-35)/(freq* (velocity/freq) *pow(NEWWU,2.0));
position1[work] = 1*fabs(velocity/freq);

} 
 double w;
 
if(result_once == 0)
{   
 w = 2*M_PI*freq;

energy[work] = 0.5*(pow(w,2)*new_m*pow(wavelength,2.0));

double Q = energy[work]/(energy[work-1]-energy[work])*2*M_PI;

C = 1.0/(2.0*Q); 
 distance_in_material =distance_in_material    +2.52e-10;   
 distance_in_material_2 =distance_in_material_2+2.52e-10;
}
else if(result_once == 1){
 w = 2*M_PI*freq;

energy[work] = 0.5*(pow(w,2)*new_m*pow((velocity/freq),2.0));

double Q = energy[work]/(energy[work-1]-energy[work])*2*M_PI;

C = 1.0/(2.0*Q); 
 distance_in_material =distance_in_material    +  fabs(position1[work]-position1[work-1])/25.0;     
 distance_in_material_2 =distance_in_material+ fabs(position1[work]-position1[work-1])/25.0;     ; 
}
double A_atom = pow(1.26e-10 ,2.0)*M_PI*4;

/*
...Then how many photons strikes one atom:
*/

double how_many_photons_on_one_atom =   (((( new_W)/(6.626e-34* 1)) ) *pow(1.26e-10,2.0)*4*M_PI/0.374 );
 
/*
...Calculate the gravity of single atom:
*/ 
 
double amplitude = (0.202642 *powf(velocity,2.0))/(pow(NEWWU,2.0)* powf(freq,2.0)* powf(wavelength,2.0));//(0.767495* NEWWU* freq *(velocity/freq))/pow(velocity,2.0);
double photonarea = M_PI*pow(amplitude,2.0);
double ironatomarea =  M_PI*pow(1.26e-10,2.0); 
double div = photonarea/ironatomarea;
			 
  atomic_frequency =    (1.02276e7* pow((pow(1.26e-10,2.0)*4*M_PI/0.374),1.0/6.0)* pow(f[3],2.0/3.0)* pow(new_W,1.0/6.0))/(pow(wavelength,5.0/6.0)* NEWWU);//(7571.75  *pow(f[3],(2.0/3.0)) *pow(new_W,1.0/6.0))/(pow(f[0],5.0/6.0) *NEWWU);// (2703148515975084336218112 *freq* wavelength* new_W)/pow(velocity,4);
//little_g =1*div*1000000.0*how_many_photons_on_one_atom*(2.23897e-45)/((velocity/freq)*freq* pow(NEWWU,2.0)* pow(amplitude,2.0));
little_g =1*10000000*fabs(how_many_photons_on_one_atom)*6.67e-11*(2.0/3.0*powf(1.26e-10,2.0)*9.2732e-26*2*M_PI*fabs(atomic_frequency))/(2*powf(299792458,2.0)*powf(1.26e-10,3.0))*299792458.0/9.78;
//printf("little_g = %.100f \n", little_g);  
GG = GG +little_g;
//printf("GG = %.100Lf \n", GG);  
 /*
...Calculate the penetrating distance constant!
*/ 
  
double penetratingdistanceconstant = 5.0/(DISTANCE_);
/*
...Calculate how much the electric field decreases in material after every iteration:
*/ 

	NEWWU   = (exp(-(((distance_in_material ) )*penetratingdistanceconstant))*EFIELD );
	new_W = pow(NEWWU ,2.0)*RESISTANCE;
 

/*  
...Calculate the total gravity summation:
*/ 
if(distance_in_material_2 > 2.52e-10)  
{	
	double count = distance_in_material_2/2.52e-10;
	//printf("count = %f \n", count);
	

	mega_g = mega_g + little_g*1;
	distance_in_material_2= 0;
}


if(K % 1 == 0 )
{
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"); 
printf("attenuation = %.10f \n", attenuation);
 printf("div = %.10f \n", div);
printf("relativ permeability = %.10f \n", relativ_permeability); 
printf("new_W = %f \n",new_W);
printf("RESISTANCE = %.15f \n",RESISTANCE);
printf("new_U = %f \n",NEWWU);
 printf("atomic_frequency  = %f \n",fabs(atomic_frequency));
printf("amplitude = %.10f \n",amplitude);

printf("freq = %f \n",freq);
printf("Wavelength (x coordinate ) = %.10f meter \n", wavelength);
printf("Velocity of photons  = %.10f m/s^2 \n",velocity);
 
printf("Total gravity recording = %.100f m/s^2 \n", mega_g  );
 //sleep(1);
printf("Distance traveled in medium by a photon = %.40f meter \n",distance_in_material);
printf("distance/atomic_spacing  = %.10f \n", ( distance_in_material)/( 2.52e-10   ) );
 
printf("distance needed  = %.10f \n", DISTANCE_ ); 
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"); 
if(  mega_g > G ||  velocity < 0)
	for(;;);
}


time_[work] = -1.0/(C*w);
if(result_once == 0)
{
    result[0] =             velocity*1 ;
    result[1] =             f[4]*1  ;
    result[2] =             f[5]*1  ;
    
    result[3] = (-(pow(w,2)*new_m)*0 - (C*2*new_m*w)*velocity )/new_m;
    result[4] = (-(pow(w,2)*new_m)*0 - (C*2*new_m*w)*f[4] )/new_m;
    result[5] = (-(pow(w,2)*new_m)*0 - (C*2*new_m*w)*f[5] )/new_m;
    result_once = 1;

accen = result[3];
}
else if(result_once == 1){
    result[0] =             f[3]*1 ;
    result[1] =             f[4]*1  ;
    result[2] =             f[5]*1  ;
result[3] = (-(pow(w,2)*new_m)*wavelength - (C*2*new_m*w)*f[3] )/new_m;
result[4] = (-(pow(w,2)*new_m)*wavelength - (C*2*new_m*w)*f[4] )/new_m;
result[5] = (-(pow(w,2)*new_m)*wavelength  - (C*2*new_m*w)*f[5] )/new_m;

accen = result[3];
}
  result_once = 1;
K++;
work++;
}

struct state_vector  get_photon_state_oscillate_task1(struct state_vector next_state, float dt,int which )
{
	double f0[6];
	double f0_result[6];

	double z[6];
 	double t0[6] = {0,0,0,0,0,0};
 	double tburn = 1 ;  
	double tf[6] = {tburn,tburn,tburn,tburn,tburn,tburn};

	z[0] =  next_state.pos_new_x;
	z[1] =  next_state.pos_new_y;
	z[2] =  next_state.pos_new_z;
	z[3] =  next_state.vel_new_x;
	z[4] =  next_state.vel_new_y;
	z[5] =  next_state.vel_new_z;

	f0[0] =next_state.pos_new_x;
	f0[1] =next_state.pos_new_y;
	f0[2] =next_state.pos_new_z;
	f0[3] =next_state.vel_new_x;
	f0[4] =next_state.vel_new_y;
	f0[5] =next_state.vel_new_z;
 	 rk45(rates_photon, t0, f0,f0_result, tf,z,6, 10000000.0  );
//rates_photon();
	state_result_photon.pos_new_x = f0_result[0];
	state_result_photon.pos_new_y = f0_result[1];
	state_result_photon.pos_new_z = f0_result[2];

	state_result_photon.vel_new_x = f0_result[3];
	state_result_photon.vel_new_y = f0_result[4];
	state_result_photon.vel_new_z = f0_result[5];

	return  state_result_photon;
}

void task1(void )
{
 	while(1)
	{
		photon_oscillate = get_photon_state_oscillate_task1(photon_oscillate,1,1);
	//	printf("photon_oscillate position = %.10f \n", photon_oscillate.pos_new_x);
	//	printf("photon_oscillate velocity = %.10f \n", photon_oscillate.vel_new_x);
	}
}


void *thr_func(void *arg) {
  thread_data_t *data = (thread_data_t *)arg;
/* if(data->tid == 0)
	task0();*/
 if(data->tid == 0)
	task1();
 /*if(data->tid == 2)
	task2();*/
/* if(data->tid == 3)
	init_tasks();*/
  pthread_exit(NULL);
}

int multitasks( ) {
  pthread_t thr[NUM_THREADS];
  int i, rc;
  thread_data_t thr_data[NUM_THREADS];
 
  for (i = 0; i < NUM_THREADS; ++i) {
    thr_data[i].tid = i;
    if ((rc = pthread_create(&thr[i], NULL, thr_func, &thr_data[i]))) {
      fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
      return EXIT_FAILURE;
    }
  }
  for (i = 0; i < NUM_THREADS; ++i) {
    pthread_join(thr[i], NULL);
  }
 
  return EXIT_SUCCESS;
}

void display  (void){

}


int first_run = 1;
int main (int argc, char **argv)
{ 
  glutInit(&argc, argv);
  init_mpgeg( );
 if(first_run == 1)
{
	photon_oscillate.pos_new_x =  0;
	photon_oscillate.pos_new_y =  0; 
	photon_oscillate.pos_new_z =  0;

	photon_oscillate.vel_new_x = 894.43;
	photon_oscillate.vel_new_y = 894.43;
	photon_oscillate.vel_new_z = 894.43;

	first_run = 0;
}
 	multitasks(argc,argv);

}
