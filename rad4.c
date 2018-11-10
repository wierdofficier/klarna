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
#include "system.h"
#define NUM_THREADS 5
float     vertexpoint_g_ventral[10000][3];
double mega_g_vertical;
double freq_vertical;
#include <stdbool.h>
struct state_vector       SPHERE_STATE_VECTOR(struct state_vector        next_state, float dt );
float fovy = 45.0;
float dNear = 100;
float dFar = 2000;
int DONE_WITH_THIS_0 = 0;
float cameraEye[3] = {0.0, 0.0, 1000.0};
float lightRotation[16] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
float cameraLookAt[4] = {0.0, 0.0, 0.0, 1.0};
float cameraUp[4] = {0.0, 1.0, 0.0};

float viewRotation[16] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
double POSX[100000];
double POSY[100000];
double VEL[100000];
float rotationX=0.0;
float rotationY=0.0;
double radius;
struct state_vector sphere_state;
void key(unsigned char key, int x, int y);

float prevX=0.0;
float prevY=0.0;
bool mouseDown=false;
void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        mouseDown = true;
        prevX = x - rotationY;
        prevY = y - rotationX;
    }else{
        mouseDown = false;
    }
}

void mouseMotion(int x, int y){
    if(mouseDown){
        rotationX = y - prevY;
        rotationY = x - prevX;
        glutPostRedisplay();
    }
}
float global_ambient[4] = {0.0, 0.0, 0.0, 0.0};
struct Light_ {
        float pos[4];
        float ambient[3];
        float difusse[3];
        float specular[3];

        void (*setPosition_light)(float,float,float);
	void (*setAmbient_light)(float,float,float);
 
        void (*setDifusse_light)(float,float,float);
	void (*setSpecular_light)(float,float,float);


};
void reshape(int w, int h){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fovy, (GLdouble)w/(GLdouble)h, dNear, dFar);
    glViewport(0, 0, w, h);
} 
int listplane; 
int listplane2;
typedef struct Light_ Light ;
struct Material_ {
        float ambient[4];
        float difusse[4];
        float specular[4];
        float shininess;

        void (*setAmbient_material)(float,float,float,float);
	void (*setDifusse_material)(float,float,float,float);
 
        void (*setSpecular_material)(float,float,float,float);
	void (*setShininess_material)(float);


};
typedef struct Material_ Material ; 

typedef struct _thread_data_t {
  int tid;
  double stuff;
} thread_data_t;
#include "system.h"
int working_on = 0;

#define EFIELD 300.0
#define PERMEABILITY 37000.0  
#define G 0.7296413

#define EFIELD 200.0
#define PERMEABILITY 25000.0 
#define G 4.818

#define EFIELD 1200.0
#define PERMEABILITY 37000.0  
#define G 9.8

//0.0004166 556.960
#define POWER  556.9609  *pow(10.0 ,2.0);
#define EFIELD 300.0
double EFIELD_ = 300.0;
#define PERMEABILITY 25000.0  
#define G 15.1
#define WATTTT 10297.0 

#define SIZE_BUFFER 10000000000.0
 


double freq  =  60;////1444939938.1067;
#define FREQUE 60
#define TIME_M 800000000000 *1*1
double TIME_M__ = TIME_M;
double stage_1_2 = 0;
double time_multplier = TIME_M;
int WORKWORK = 0;
double  *position1;
double  *energy;
double *time_;
int work =0;
int velonce = 0;
double relativ_permeability;
double accen;
double C;
int result_once = 0;
 double xradius_photon = 0;
double mega_g_below_and_under;
double attenuation;
#define RADAREA 0.374
struct state_vector photon_oscillate;
double dipolewattsystemh;
int one= 0;
double distance_in_material_2 = 0;
double distance_in_material = 0;

//double freq_ = 60.0;//  144493998538.1067;
 
double velocity= 894.43;
double wavelength = 14.9;
double new_U =EFIELD;
double new_W = WATTTT;
double WATT =   WATTTT;
double RESISTANCE;
double little_g;
double DISTANCE_;
double new_m ;
double NEWWU= EFIELD;
double DISTANCE__;
double mega_g;

double iron_atomic_mass_last;
double aluresistancewire;
double wirepower;
double wirevoltage = 0.1;
double wirefreq = 5e-6;
void wiregravity()
{

aluresistancewire = 2.65e-8*3.528/(0.005 * 3e-6);
wirepower = aluresistancewire*pow(wirevoltage,2.0);
//atomic_frequency_aluminium =    (1.02276e7* pow((pow(1.4e-10,2.0)*4*M_PI),1.0/6.0)* pow(velocity,2.0/3.0)* pow(new_W,1.0/6.0))/(pow(f[0],5.0/6.0)* NEWWU);
//little_g =  (how_many_photons_on_one_atom)*6.67e-11*(2.0/3.0*powf(radius__,2.0)*9.2732e-26*2*M_PI* (atomic_frequency))/(2*powf(299792458,2.0)*powf(radius__,3.0))*299792458.0/9.78
}

double GG = 0;
double atomic_frequency;
double *velocity1;
int K;
#define HAX 10000
int count ;
int megacount;
double mass_photon;
struct state_vector    state_result_photon;
int timeonce_ = 0;
double mega_radius = 0;
void rates_photon ( double *t, double *f, double result[]   )
{
start:
if(DONE_WITH_THIS_0 == 1)
	return;
/*
  Do some initial setup!
*/
if(one < 1)
{
	position1 =  malloc(SIZE_BUFFER);
        velocity1 =  malloc(SIZE_BUFFER);
	energy =     malloc(SIZE_BUFFER);
	time_ =      malloc(SIZE_BUFFER);
	distance_in_material_2 = 0;
	distance_in_material = 0;

	RESISTANCE =   new_W/(pow(NEWWU,2.0));  
        DISTANCE_ =1.0/(sqrt(M_PI*M_PI*4e-7*(25000)*1.03e7*freq)) *12; 

 
	relativ_permeability =  179751035759958240.0/(pow(f[3],2.0) + sqrt((pow(freq,2.0) + 323104348567777837056.0 *pow(1.03e7,2.0))/pow(freq,2.0)) *pow(f[3],2.0));// 179751035759958240.0/(pow(velocity,2.0) + sqrt((32310434856777778462720.0 + pow(freq,2.0))/pow(freq,2.0)) * pow(velocity,2.0));

	velocity =   1*299792458.0/(sqrt(1*relativ_permeability/2.0*(sqrt(1+pow((1.03e7/(2*M_PI*freq*8.854e-12)),2.0))+1))); 
freq=60;//1589836329275528111456256.0/sqrt(25276867888091238358551364825513984.0* pow(1.03e7,2.0) *pow(f[0],4.0)*pow(relativ_permeability,2.0) + 28123115323093299962657023983616.0* pow(f[0],2.0)* relativ_permeability);
	DISTANCE__ =DISTANCE_;//fabs(-(25 *log(300/pow(EFIELD,2.0)))/222804);
	/*Calculate mass*/
	new_m = (3.35677e-35)/(pow(NEWWU,2.0) *velocity);
	wavelength = sqrt(4*M_PI/(25000.0*M_PI*1.03e7*4e-7*freq));
 	//f[0] = wavelength;
	//f[3]=velocity;
one++;
}
else if(one > 0)
{


	attenuation = ( 1.00/WATT*(new_W/distance_in_material))/7874.0;
	//RESISTANCE =  new_W/(pow(NEWWU,2.0));  
	/*
   		This executes every loop.
	*/
	/* 
		  Calculate frequency
	*/
//f = 1589836329275528111456256/sqrt(25276867888091238358551364825513984 C^2 l^4 P^2 + 28123115323093299962657023983616 l^2 P)
	 //freq =   f[3]/f[0];//(((1.58882e10)* powf(f[3],2.0) *relativ_permeability)/sqrtf( 252425272283202775718997981659136.0 + 2808609933552555.0*powf(f[3],2.0)* 				relativ_permeability)); 
	position1[work] =   f[0]  ;
	velocity1[work] = f[3];
	 //f[0] =  sqrt(4*M_PI/(1.03e7*M_PI*relativ_permeability*4e-7*freq))-distance_in_material;//  sqrt(4*M_PI/(1.03e7*M_PI*relativ_permeability*4e-7*freq));
	/* 
		  Calculate relativ permeability for iron:
		  therefore the frequency must vary
	*/
	//  relativ_permeability = 179751035759958240.0/(pow(f[3],2.0) + sqrt((pow(freq,2.0) + 323104348567777837056.0 *pow(10.0,2.0))/pow(freq,2.0)) *pow(f[3],2.0));
	//  f[3] =  1*299792458.0/(sqrt(1*75.0/2.0*(sqrt(1+pow((10.0/(2*M_PI*freq*8.854e-12)),2.0))+1)));
	new_m = (3.35677e-35)/(pow(NEWWU,2.0) *1*(f[3])); 
 
	freq= (f[3])/f[0];// 1589836329275528111456256.0/sqrt(25276867888091238358551364825513984.0* pow(1.03e7,2.0) *pow(f[0],4.0)*pow(relativ_permeability,2.0) + 28123115323093299962657023983616.0* pow(f[0],2.0)* relativ_permeability);
//	 printf("freq = %.10f \n", freq);
 
	//printf("vel = %.10f \n", f[3]);
	// new_m = (3.35677e-35)/(pow(NEWWU,2.0) *f[3]);//(3.35677e-35)/(freq* (velocity/freq) *pow(NEWWU,2.0));
	//f[3] = 1*299792458.0/(sqrt(1*relativ_permeability/2.0*(sqrt(1+pow((1.03e7/(2*M_PI*freq*8.854e-12)),2.0))+1))); 
} 
double w;

if(result_once == 0)
{   
	w = 2*M_PI*freq;
	DISTANCE_ =1.0/(sqrt(M_PI*M_PI*4e-7*(relativ_permeability)*1.03e7*freq)) *6;
	energy[work] =  (pow(w,2)*new_m*pow(f[0],2.0));

	double Q = energy[work]/(energy[work-1]-energy[work])*2*M_PI;

	C = 1.0/(2.0*Q); 
 	distance_in_material =distance_in_material    +2.48e-10;   
 	distance_in_material_2 =distance_in_material_2+2.48e-10;
}
else if(result_once == 1){
 	w = 2*M_PI*freq;
	energy[work] = 0.5*(pow(w,2)*new_m*pow(distance_in_material,2.0));
	double Q = energy[work]/(energy[work-1]-energy[work])*2*M_PI;

	C = 1.0/(2.0*Q); 
	//if(f[3] < 0 || f[3] == 0)
	//	f[3] = velocity;
	energy[work] = 0.5*(pow(w,2)*new_m*pow((distance_in_material),2.0));
	 time_[work] = -1.0/(C*w);

	if(position1[work] <0)
		position1[work] = -position1[work];

if(time_[work] < 0 || time_[work-1] < 0   )
{
	time_[work] = -time_[work]; 
	time_[work-1] = -time_[work-1];
}
 
	double timechange = 0; 
	 
//	if(f[3] < 0 || f[3] == 0)
//		f[3] = velocity;
if(timeonce_ == 0)
{
 
	timeonce_ = 1;
}
else if(timeonce_ == 1)
{
	timechange =   ((position1[work]-position1[work-1])/(velocity1[work]));    
	//  printf("timechange =%.30f :: %.30f\n", 1/timechange,TIME_M*freq);
	 
timechange =   ((position1[work]-position1[work-1])/(velocity1[work]));    
	// printf("timechange =%.30f :: %.30f\n", 1/timechange,TIME_M*freq_);
	 if(timechange > 0)
	 {
	distance_in_material =distance_in_material    +((f[3]/distance_in_material)/(1.0/(timechange)*1*1))*1.0 ;   
distance_in_material_2 =distance_in_material_2+((f[3]/distance_in_material)/(1.0/(timechange)*1*1))*1.0 ;
}	 
}

}

double how_many_photons_on_one_atom = new_W/((6.626e-34*freq))  ; ///(distance_in_material));
//printf("megacount = %f :: how_many_photons_on_one_atom = %f\n", megacount,fabs(how_many_photons_on_one_atom));
//if(how_many_photons_on_one_atom < 0 || how_many_photons_on_one_atom == 0)
//how_many_photons_on_one_atom =  new_W/( 6.626e-34*freq);
double amplitude = (0.202642 *powf(velocity,2.0))/(pow(NEWWU,2.0)* powf(freq,2.0)* powf(distance_in_material,2.0));//(0.767495* NEWWU* freq *(velocity/freq))/pow(velocity,2.0);
double photonarea = M_PI*pow(amplitude,2.0);
double ironatomarea =  M_PI*pow(2.48e-10,2.0); 
double div = photonarea/ironatomarea;
 		
radius =   (0.0000508196* sqrt(new_m) *pow(1*(f[3]),(1.0/4.0))/((pow(NEWWU/299792458.0,1.0/4.0)) * pow(NEWWU,(1.0/4.0))));
 
double photon_mom_inertia = 2.0/3.0*2*new_m*pow(radius,2.0);
double mass_atom = 1.672e-27*26;
 
double frequency___atomic = 280474649406688306320629446517287519655646158909710794752.0 *freq* new_m *how_many_photons_on_one_atom* pow(radius,2.0);
accen = (-(pow(w,2)*1)*f[0] - (C*2*1*w)*f[3] )/1;
double atomic_frequency2 = (0.159155 *accen * photon_mom_inertia  + 1.3252e-33  *pow(freq,2.0) *radius)/(mass_atom* pow(1e-15,2.0));
double kinetic_mass = (1.3252e-33 *freq)/pow(f[3],2.0);
double ang_mom_g1 = 6.67e-11*(2.0/5.0*pow(radius,2.0)*(new_m)*2*M_PI*freq)/(2*pow(299792458.0,2.0)*(pow(radius,3.0))*1)*299792458.0/9.78 ;
double ang_mom_g = ((10000/(freq*6.626e-34)))*(ang_mom_g1) *pow(1.4e-10,2.0)*M_PI/0.374;
 
//ang_mom_g = 6.67e-11*( pow(radius,2.0)*(kinetic_mass)*2*M_PI*freq)/(2*pow(299792458.0,2.0)  *(pow(radius,3.0))*1)*299792458.0/(9.27e-26);
 
little_g  =   (ang_mom_g1* new_W)/(freq*6.626e-34)*1*((1) *sqrt(NEWWU/299792458.0))* 1*( sqrt(NEWWU)* sqrt(6.67e-11))/sqrt(1*(f[3]));
//little_g  =  1*( ang_mom_g1* new_W/(freq*6.626e-34)*1.25*((3162.28) *sqrt(NEWWU/299792458.0) *sqrt(NEWWU)* sqrt(6.67e-11))/sqrt(f[3])); 
mega_radius = mega_radius + radius;
//little_g  =  1*( 48.9/(radius*1.9e25) * ((3162.28) *sqrt(NEWWU/299792458.0) *sqrt(NEWWU)* sqrt(6.67e-11))/sqrt(f[3])); 
//little_g =   1*(little_g1  /*how_many_photons_on_one_atom*6.67e-11*(2.0/3.0*pow(radius,2.0)*new_m*2*M_PI*freq)/(2*pow(299792458.0,2.0)*(pow(radius,3.0))*1)*/) ;
/*					
 ...Calculate how much the electric field decreases in material after every iteration:
*/ 
if(attenuation < 0)
	attenuation = -attenuation;
double constant_atten =(( 11.931 )  )/DISTANCE__;
//printf("constant_atten = %f \n", constant_atten);
NEWWU    = exp(- 11550    *distance_in_material) *EFIELD_; 
new_W = pow(NEWWU  ,2.0)*RESISTANCE;
/*  
...Calculate the total gravity summation:
*/ 
if( (distance_in_material_2) > 2.48e-10)  
{	
	count =  (distance_in_material_2)/2.48e-10;
	//printf("count = %f \n", count);
	
	megacount = megacount + count;
	mega_g = mega_g + little_g*1;
	mega_g_below_and_under = mega_g;
	distance_in_material_2= 0;
}
double gravity_radius = radius*(new_W/(6.626e-34*freq))*0.0235744;
 
#include <stdio.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
if(K %  HAX == 0 )
{
printf(YEL "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n",RESET); 
	printf(RESET"");
	printf("frequency___atomic: ="CYN" %.10f"RESET" "WHT" seconds"RESET"\n", frequency___atomic);
	printf("Acceleration = "CYN"%.10f"RESET" "WHT" m/s²"RESET"\n", accen);
 	//printf("atomic_frequency = %.10f \n", atomic_frequency2);
 	printf("einstein g = "CYN"%.40f"RESET" "WHT" meter "RESET"\n", sqrt(NEWWU/299792458.0))* 1*( sqrt(NEWWU)* sqrt(6.67e-11))/sqrt(1*(f[3]));
        printf("ang_mom_g1 = "CYN"%.40f"RESET" "WHT" meter "RESET"\n", (ang_mom_g1* new_W)/(freq*6.626e-34));
	
 	//printf("div = %.10f \n", div);
	printf("Relativ permeability = "CYN"%.10f "RESET"\n", relativ_permeability); 
	printf("Watt change = "CYN"%.10f"RESET" "WHT" watts "RESET"\n",new_W);
	printf("Resistance = "CYN"%.10f"RESET" "WHT" ohm "RESET"\n",RESISTANCE);
	printf("Electric field = "CYN"%.10f"RESET" "WHT" volt/meter "RESET"\n",NEWWU);
	printf("Mass photon = "CYN"%.50f"RESET" "WHT" kg "RESET"\n",new_m);

	printf("Photon g = "CYN"%.10f"RESET" "WHT" m/s²"RESET"\n",little_g);
	printf("Frequeny of wave = "CYN"%.10f"RESET" "WHT" "RESET"\n",freq);
	printf("Wavelength = "CYN"%.10f"RESET" "WHT" meter "RESET"\n", f[0]);
	printf("Velocity of photons1  = "CYN"%.10f"RESET" "WHT" m/s² "RESET"\n",f[3]);
 	printf("Velocity of photons2  = "CYN"%.10f"RESET" "WHT" m/s² "RESET"\n",f[3]);
	printf("Total gravity recording = "CYN"%.40f"RESET" "WHT" m/s² "RESET"\n", mega_g  );
	printf("Distance traveled in medium by a photon = "CYN"%.20f"RESET" "WHT" meter "RESET"\n",distance_in_material);
	printf("Distance/atomic_spacing  = "CYN"%.10f"RESET" "WHT" meter"RESET"\n", ( distance_in_material)/( 2.48e-10   ) );
        printf("Torus mass  = "CYN"%.10f"RESET" "WHT" kg "RESET"\n", 697.0/20.0 - (3485.0* mega_g)/981.0); 
        printf("Distance needed  = "CYN"%.10f"RESET" "WHT" meter"RESET"\n", DISTANCE__ ); 
	printf("Total radius  = "CYN"%.50f"RESET" "WHT" meter"RESET" or "CYN"%.50f"RESET" "WHT" meter"RESET" or "CYN"%.50f"RESET" "WHT" meter"RESET"\n", mega_radius,radius*(new_W/(6.626e-34*freq))*pow(1.4e-10,2.0)*M_PI/0.374 ,(radius/freq)*sqrt(new_W/6.626e-34)); 
	printf("Total radius needed  = "CYN"%.10f"RESET" "WHT" meter"RESET"\n",299792458/freq );
	double totradius = radius*(new_W/(6.626e-34*freq))*0.0235744;
        /*x/(sqrt(1-(v)^2/(299792458^2))) = s solve x*/
	double seconds = 24.0*60.0*60.0*31.0;
	printf("Total time "CYN"%.10f"RESET" "WHT" days "RESET" needed for machine to get back "CYN"%f"RESET" "WHT" days"RESET"\n\n",(seconds *sqrt(89875517873681764.0 + 		pow(2.0*freq,2.0)))/299792458.0/(24.0*60.0*60.0),seconds/(24*60*60));
 
	printf("With vibration velocity  = "CYN"%.10f"RESET" "WHT" m/s  "RESET"\n",0.2*freq);
	printf("With vertical plates working at a initial value from:  "CYN"%.10f"RESET" "WHT" watt"RESET" @"CYN" %.10f"RESET" "WHT" Hz"RESET"\n",WATT,freq);
	double ironshieldmg = 0.000000006392*pow(0.778768,2.0)*7874;
	printf("Gravity between two equal plates  = "CYN"%.10f"RESET" "WHT" m/s  "RESET"\n",(6.67e-11*mega_g/(1e-12)*ironshieldmg)/pow((2.5/2),2.0));
 
  	//sleep(1);
printf(YEL "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n",RESET); 
    if(NEWWU < (pow(0.37,12.0)*EFIELD) ||(distance_in_material) > 0.0006)
  	{
 for(;;);
		stage_1_2++;
		if(stage_1_2 == 1)
		{
			double C =  73.2; // 4e-3 = dricksvatten
			double P = 1; //järn pulver är effektivt den drar våglängden utan att dra ner amplituden så mycket 
			//sqrt((4*pi)/(70.9*pi*1*4e-7*x)) = 12
		 	wavelength =  12;// sqrt((4*M_PI)/(C*M_PI*P*4e-7*156250000.0/9.0));// 1.0;
		
			freq  =  (1e7)/(C* pow(wavelength,2.0)* P);
			
			TIME_M__ =800000000000*1*1;
			//ersätt alla 25000 med 200000
			photon_oscillate.vel_new_x = 299792458.0/(sqrt(1*1.0/2.0*(sqrt(1+pow((73.2/(2*M_PI*freq*8.854e-12)),2.0))+1)));
			photon_oscillate.vel_new_y = 0;
			photon_oscillate.vel_new_z = 0;
			photon_oscillate.pos_new_x = photon_oscillate.vel_new_x/freq;
			photon_oscillate.pos_new_y =  0; 
			photon_oscillate.pos_new_z =  0;
			RESISTANCE =  pow(12,2.0)*sqrt((M_PI/9)*C*pow((M_PI*4e-7*P),3.0)*pow(freq,3.0));
			NEWWU =  300.0;
			new_U =  300.0;
			EFIELD_=   300.0;
			distance_in_material_2 = 0;
			distance_in_material = 0;
			new_W = pow((NEWWU*2*M_PI*freq*12 ),2.0)/(3*M_PI*8.854e-12*pow((2*M_PI*freq)/(2*M_PI/(pow((4*M_PI)/(freq*C*P*M_PI*4e-7),0.5))),3.0)*(pow((1+pow((C)/(2*M_PI*freq*8.854e-12),2.0)),0.5)+1)) ;;//426;
			mega_g_vertical = mega_g;
 
			freq_vertical = freq;
			mega_g = 0;
			timeonce_ = 0;
			result_once=0;
			one = 0;
       			task1();
	}
	DONE_WITH_THIS_0 = 1;	
	init_tasks(0,0);

}
}
 

if(result_once == 0)
{
	result[0] =             f[3]/1.0 ;
	result[1] =             f[4]/1.0  ;
	result[2] =             f[5]/1.0 ;
    
	result[3] = -(-2*C*w*result[0] - pow(w,2.0)*f[0])/(1);
	result[4] = -(-(pow(w,2)*1)*f[0] - (C*2*1*w)*f[4] )/1;
	result[5] = -(-(pow(w,2)*1)*f[0] - (C*2*1*w)*f[5] )/1;
	result_once = 1;
	accen = result[3];
}
else if(result_once == 1){
	result[0] =            f[3]/ 1.0;
	result[1] =             f[4]/1.0  ;
	result[2] =             f[5]/1.0  ;
	result[3] = -(-2*C*w*result[0] - pow(w,2.0)*f[0])/(1);
	result[4] = -(-(pow(w,2)*1)*f[0]- (C*2*1*w)*f[4] )/1;
	result[5] = -(-(pow(w,2)*1)*f[0]  - (C*2*1*w)*f[5] )/1;
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
 	rk45(rates_photon, t0, f0,f0_result, tf,z,6, 1*1000000000000  ); 
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
		photon_oscillate = get_photon_state_oscillate_task1(photon_oscillate,1,1);
}


void *thr_func(void *arg) {
  thread_data_t *data = (thread_data_t *)arg;
/* if(data->tid == 0)
	task0();*/
 if(data->tid == 0)
	task2();

  //pthread_exit(NULL);
}
int levitatecounter = 0;
int dowork = 0;
double g_multiplyer = 0.0001;
double frequency_ball= 0;
#define STAGE1 0.001
int speedcounter = 0;
#define STAGE2 0.001
double HEIGHT1 = 20;
int time____=0;
double HEIGHT2 = 20;
double height_amplitud;
void rates_sphere_g_acc(double *t, double *f, double result[] )
{
    result[0] =            f[3]/1.0;
    result[1] =            f[4]/1.0;
    result[2] =           f[3]/1.0;
     result[4] =             (    mega_g_below_and_under-9.8)/1.0;
    height_amplitud =1e-4;// radius*(new_W/(6.626e-34*freq))*0.0235744;

    //printf("position2: = %.20f\n", (f[1]*sin(2*M_PI*1.44494e12))/6.9207025897e-13);
    frequency_ball = f[3]/f[1];

if(levitatecounter < 1)
{
}
else
{
	if(f[1] >height_amplitud  )
	{
		 //printf("position1: = %.20f\n", f[1]);
		 //angående mega_g_below_and_under,acceleration kommer ochså underifrån och överifrån, fälten möts vid 0.25 meter, om deras effekt ligger runt 100 watt med en 			 //frekvens på 0.01 hz så kommer g ligga stabilt på 11.83
                 //för att fältet ska bli homogent så bör fältet ha styrkan 11.83 vid 0.25 meter det betyder att man behöver 7.86 plattor eller ~ 8 plattor för att uppfylla det 			   villkoret.
                 //mega_g_below_and_under ska vara så nära som jordens gravitation som möjligt vilket ger objektet i centrum fördelar.
	 	  result[4] = -mega_g_vertical+mega_g_below_and_under-9.8;  
 
		  result[1] =  (1e-6*cos(2*M_PI*299792455784151.5000))/((1.0/299792455784151.5000));  //hastigheten, då yled varierar upp o ned som fjäder, dvs plattan åker upp o ned, då 													accelerationen är 2.85476e-10 m/s^2
							   //den accelerationen kommer ifrån att fältet mellan vertikala plattorna har ett homogent fält mellan sig och deras fält
							   //möts vid mittpunkten vid 1 meter och därefter blir gravitationella fältlinjerna raka. men initialt sätt så kommer 
							   //gravitationen ifrån antennen som ligger bakom plattorna som avger ett fält på 0.000000045423181 m/s^2 med en frekvens på 								   //1.44494e12 hz som ger en periodtid på 6.9207025897e-13 sekunder, tar man denna tid gånger sträckan i yled som varierar 
							   //så får man hastigheten som man vill ska komma så nära ljuset som möjligt, vilket är 2.99792457991e8 m/s,dvs lite mindre 								   //än max, men tillräckligt för att resa tillbaka 16 år bakåt i tiden. Problemet är att lista ut hur lång sträcka f[1] får 				//inom sitt intervall, f[1] amplitud fås (men inte helt säker,men nästan) av 0.000000000000000000000293273826*(4.41066/(6.626e-34*1.44494e12))*0.0235744
	if(levitatecounter % HAX == 0 )
	{
	//	printf("velocity: = %.20f\n", result[1] );
 	//printf("position: = %.20f\n", result[4]); 
 	}
}
else if(f[1] <-height_amplitud )
{ 
	result[4] =  mega_g_vertical+mega_g_below_and_under-9.8;   ;//*cos(frequency_ball*time____) ;
	result[1] =  -(1e-6*cos(2*M_PI*299792455784151.5000))/((1.0/299792455784151.5000));
	 //printf("position2: = %.20f\n", f[1]);
if(levitatecounter % HAX == 0 )
{
 	//printf("velocity: = %.20f\n", result[1] );
 	//printf("position: = %.20f\n", result[4]); 
}
}
}
 
//printf("acceleration: = %.20f\n", result[4]);

time____++;
levitatecounter++;	 
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
sphere_state = SPHERE_STATE_VECTOR(sphere_state,1000 );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glMultMatrixf(lightRotation);
 

    glLoadIdentity();
    gluLookAt(cameraEye[0]+0, cameraEye[1]+253, cameraEye[2]-423, cameraLookAt[0], cameraLookAt[1], cameraLookAt[2], cameraUp[0], cameraUp[1], cameraUp[2]);

    glMultMatrixf(viewRotation);

    glRotatef(rotationX,1,0,0);
    glRotatef(rotationY+220,0,1,0);

    glMultMatrixf(lightRotation);
    glPushMatrix();
    glScalef( 50, 50, 50); 
    glCallList(listplane);
    glPopMatrix();	 

    glPushMatrix();
    glScalef( 50, 50, 50); 
    glCallList(listplane2);
    glPopMatrix();	 
    
// glPushMatrix();
//printf("POSX[WORKWORK]*100000000000 = %.120f \n", POSX[WORKWORK]*100000000000);
   //     glTranslatef(POSX[WORKWORK]*100000000000*9e-11-60, POSX[WORKWORK]*100000000000*9e-11 +70 ,POSX[WORKWORK]*100000000000*9e-11 +0);
 //   glPushMatrix();
      //  glTranslatef(0, POSY[WORKWORK]*10000 +40 ,0);

   // double x = 697.0/20.0 - (3485.0 *mega_g)/978.0;//-697.0000/980.0000*(5*(mega_g+mega_g_vert)*1-49);

 
 	//697/20 - (3485 y)/978 < 0.159*34.85 ||  697/20 - (3485 y)/978 > 0.159*34.85
  //  glutPostRedisplay();
  /*  if(x < 0.159*34.85 && x > -0.159*34.85/**1 < 34.85*0.159 && x*1 > -34.85*0.159*///)
  /*  {
 
    }
    else
    {*/
   
 //	 glutSolidSphere(4e22*radius,330,100  );
//glPopMatrix();
    glPushMatrix();
    WORKWORK += 10000;
    printf("WORKWORK = %d \n", WORKWORK);
   // glPushMatrix();
    glTranslatef(0, sphere_state.pos_new_y/1 +40 ,0);

    double x = 697.0/20.0 - (3485.0* mega_g)/978;//-697.0000/980.0000*(5*(mega_g+mega_g_vert)*1-49);

    //697/20 - (3485 y)/978 < 0.159*34.85 ||  697/20 - (3485 y)/978 > 0.159*34.85
     glutPostRedisplay();
    if(x < 0.159*34.85 && x > -0.159*34.85/**1 < 34.85*0.159 && x*1 > -34.85*0.159*/)
    {
 
    }
    else
    {
	   glutSolidSphere(24,330,100  );
    }
 glutSolidSphere(24,330,100  );
 display_mpeg();
 glutSwapBuffers();
}

Light *dirLight;
int mass_once_vert = 1;
Material *material;

void  setPosition_light(float x, float y, float z)
{
    dirLight->pos[0] = x;
    dirLight->pos[1] = y;
    dirLight->pos[2] = z;
    dirLight->pos[3] = 0.0f;
}

void  setAmbient_light(float x, float y, float z)
{
    dirLight->ambient[0] = x;
    dirLight->ambient[1] = y;
    dirLight->ambient[2] = z;
}

void  setDifusse_light(float x, float y, float z)
{
    dirLight->difusse[0] = x;
    dirLight->difusse[1] = y;
    dirLight->difusse[2] = z;
}

void  setSpecular_light(float x, float y, float z)
{
 
    dirLight->specular[0] = x;
    dirLight->specular[1] = y;
    dirLight->specular[2] = z;
}

 

void setAmbient_material(float x, float y, float z, float e)
{
    material->ambient[0] = x;
    material->ambient[1] = y;
    material->ambient[2] = z;
    material->ambient[3] = e;
}

void  setDifusse_material(float x, float y, float z, float e)
{
    material->difusse[0] = x;
    material->difusse[1] = y;
    material->difusse[2] = z;
    material->difusse[3] = e;
}

void  setSpecular_material(float x, float y, float z, float e)
{
    material->specular[0] = x;
    material->specular[1] = y;
    material->specular[2] = z;
    material->specular[3] = e;
}

void  setShininess_material(float shine)
{
    material->shininess = shine;
}

void init_tasks(int argc, char **argv)
{
   
    GLint glut_display;
    glutInitWindowSize (1000,1000);
    glutCreateWindow ("photon_encounter_teathers");

    int mainMenu;
    const GLubyte *str;
    str = glGetString (GL_EXTENSIONS);

    glEnable(GL_NORMALIZE);
 
    glEnable(GL_DEPTH_TEST);
 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    listplane =   loadOBJ("maskin4backup.obj");
     listplane2 =   loadOBJ("plane.obj");
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    dirLight = (Light*)malloc(sizeof(Light));
    dirLight->setPosition_light = setPosition_light;
    dirLight->setAmbient_light = setAmbient_light;
    dirLight->setDifusse_light = setDifusse_light;
    dirLight->setSpecular_light = setSpecular_light;
 
    dirLight->setPosition_light(100,100, 800);
    dirLight->setAmbient_light(0, 0, 0);
    dirLight->setDifusse_light(1, 1, 1);
    dirLight->setSpecular_light(0.7f, 0.1f, 0.88f);
 
    material =(Material*)malloc(sizeof(Material));
    material->setAmbient_material =setAmbient_material;
    material->setDifusse_material = setDifusse_material;
    material->setSpecular_material =setSpecular_material;
    material->setShininess_material = setShininess_material;
    material->setAmbient_material(0, 0, 1, 1);
    material->setDifusse_material(0.3f, 0.3f, 0.3f, 1.0f);
    material->setSpecular_material(0.01f, 0.01f, 0.01f, 1.0f);
    material->setShininess_material(128);
    glLightfv(GL_LIGHT0, GL_POSITION, dirLight->pos);
    glLightfv(GL_LIGHT0, GL_AMBIENT,   dirLight->ambient);
    glLightfv(GL_LIGHT0, GL_SPECULAR,  dirLight->specular);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,   dirLight->difusse);  


 
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);  
    glutDisplayFunc (display );
 
    glutReshapeFunc(reshape);
 
    glutMouseFunc(mouse);
    glutKeyboardFunc(key);
    init_mpgeg( );
 
    glutMotionFunc(mouseMotion);
//  multitasks( );
    glutMainLoop();

}
 
struct state_vector  state_result_sphere;
struct state_vector       SPHERE_STATE_VECTOR(struct state_vector        next_state, float dt )
{
	double f0[6];
	double f0_result[6];

	double z[6];
 	double t0[6] = {0,0,0,0,0,0};
 	double tburn = 1.0;
	double tf[6] = {tburn,tburn,tburn,tburn,tburn,tburn};

	z[0] =  next_state.pos_new_x;
	z[1] =  next_state.pos_new_y;
	z[2] = next_state.pos_new_z;
	z[3] =  next_state.vel_new_x;
	z[4] =  next_state.vel_new_y;
	z[5] = next_state.vel_new_z;

	f0[0] = next_state.pos_new_x;
	f0[1] =next_state.pos_new_y;
	f0[2] =next_state.pos_new_z;
	f0[3] =next_state.vel_new_x;
	f0[4] =next_state.vel_new_y;
	f0[5] = next_state.vel_new_z;
 
	rk45(rates_sphere_g_acc, t0, f0,f0_result, tf,z,6, 1000000      );

 
	state_result_sphere.pos_new_x = f0[0];
	state_result_sphere.pos_new_y = f0[1];
	state_result_sphere.pos_new_z = f0[2];

	state_result_sphere.vel_new_x = f0[3];
	state_result_sphere.vel_new_y = f0[4];
	state_result_sphere.vel_new_z = f0[5];
        printf("sphere_state.pos_new_y = %.30f \n", state_result_sphere.pos_new_y);
        printf("sphere_state.vel_new_y = %.30f  \n", state_result_sphere.vel_new_y);
	return  state_result_sphere;
}
void task2(void )
{
	while(1)
		sphere_state = SPHERE_STATE_VECTOR(sphere_state,1);
}
void key(unsigned char key, int x, int y)
{
 
   if(key == 'x') cameraEye[0]-= 50;
   if(key == 'X') cameraEye[0]+= 50;
   if(key == 'y') cameraEye[1]-= 50;
   if(key == 'Y') cameraEye[1]+= 50;
   if(key == 'z') cameraEye[2]-= 50;
   if(key == 'Z') cameraEye[2]+= 50;
 
   if(key == '+')
   {
      
           
        
   }
   if(key == '-')
   {        
   }

   glutPostRedisplay();
}
int first_run = 1;
int main (int argc, char **argv)
{ 
 if(first_run == 1)
{

	photon_oscillate.vel_new_x = 	   1*299792458.0/(sqrt(1*25000.0/2.0*(sqrt(1+pow((1.03e7/(2*M_PI*freq*8.854e-12)),2.0))+1))); 
	photon_oscillate.vel_new_y = 894.43;
	photon_oscillate.vel_new_z = 894.43;
	photon_oscillate.pos_new_x = photon_oscillate.vel_new_x/freq;
	photon_oscillate.pos_new_y =  0; 
	photon_oscillate.pos_new_z =  0;



	sphere_state.pos_new_x =   0;
	sphere_state.pos_new_y = 0.000000000000001; 
	sphere_state.pos_new_z =   2; 

	sphere_state.vel_new_x = 0.000;
	sphere_state.vel_new_y = (1e-6*cos(2*M_PI*299792455784151.5000))/((1.0/299792455784151.5000)) ;
	sphere_state.vel_new_z = 0.000;

	first_run = 0;
}
glutInit(&argc, argv);
  
task1();
  
  //init_tasks(argv,argv);

}
