/*

(2*pi*freq)/t = a 


torque_photon  = I*acc + 2*radius*freq*6.626e-34*(2*M_PI*freq)



torque_photon*timechange = L

torque_photon*timechange = 1.672e-27*26*pow(1.26e-10,2.0)*2*M_PI*freq

angularmom_photon = angularmom_atom


I*acc + 2*radius*freq*6.626e-34*(2*M_PI*freq)  = 1.672e-27*26*pow(1.26e-10,2.0)*2*M_PI*freq




I*a + 2*r*f*6.626e-34*(2*pi*f)  = 1.672e-27*26*pow(1.26e-10,2.0)*2*pi*X



X = (0.159155 *a *M + 1.3252×10^-33 f^2 r)/(m R^2)






 ((3162.28) sqrt(B) sqrt(D) sqrt(6.67e-11))/sqrt(v)  = 6.67e-11*m/x^2 solve x
x ger
x =  ((0.0000359349 - 0.0000359349 i) sqrt(m) v^(1/4))/(B^(1/4) D^(1/4))
som är fotonens radius

radius = ((0.0000359349 - 0.0000359349) *sqrt(m)* pow(f[3],(1.0/4.0))/(pow((NEWWU/(299792458),(1.0/4.0)) * pow(NEWWU,(1/4)));
double photon_mom_inertia = 2.0/3.0*2*new_m*pow(radius,2.0)
double mass_atom = 1.672e-27*26;
atomic_frequency = (0.159155 *acc *(photon_mom_inertia) + 1.3252e-33 *pow(freq,2.0) *radius)/(mass_atom* pow(1.4e-10,2.0));


*/
//torque_photon/radius = angular momentum
//a*mom_of_inertia = torque
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

float rotationX=0.0;
float rotationY=0.0;
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

#define EFIELD 150.0
#define PERMEABILITY 37000.0  
#define G 0.7296413

#define EFIELD 200.0
#define PERMEABILITY 25000.0 
#define G 4.818

#define EFIELD 1200.0
#define PERMEABILITY 37000.0  
#define G 9.8

#define EFIELD 250.0
#define PERMEABILITY 25000.0  
#define G 15.1
#define WATTTT 7151.0
double  position1[1000000];
double  energy[1000000];
double time_[1000000];
int work =0;
int velonce = 0;
double relativ_permeability;
double accen;
double C;
int result_once = 0;
 double xradius_photon = 0;
double attenuation;
#define RADAREA 0.374
struct state_vector photon_oscillate;
double dipolewattsystemh;
int one= 0;
double distance_in_material_2 = 0;
double distance_in_material = 0;
double freq =60.0 ;
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
int K;
#define HAX 1000
int count ;
int megacount;
double mass_photon;
struct state_vector    state_result_photon;
void rates_photon ( double *t, double *f, double result[]   )
{
if(DONE_WITH_THIS_0 == 1)
	return;
/*
  Do some initial setup!
*/
if(one < 1)
{
distance_in_material_2 = 0;
distance_in_material = 0;

RESISTANCE =  new_W/(pow(EFIELD,2.0));  

DISTANCE_ =1.0/(sqrt(M_PI*M_PI*4e-7*(25000)*1.03e7*freq)) *5; 

//velocity = 1*299792458.0/(sqrt(1*relativ_permeability/2.0*(sqrt(1+pow((1.03e7/(2*M_PI*freq*8.854e-12)),2.0))+1))); 
velocity =  1*299792458.0/(sqrt(1*25000.0/2.0*(sqrt(1+pow((10.0/(2*M_PI*freq*8.854e-12)),2.0))+1))); 

relativ_permeability =  179751035759958240.0/(pow(velocity,2.0) + sqrt((32310434856777778462720.0 + pow(freq,2.0))/pow(freq,2.0)) * pow(velocity,2.0));
//DISTANCE__ =-(25.0 *log(2.0/new_U))/195728.0;
DISTANCE__ =fabs(-(25 *log(300/pow(EFIELD,2.0)))/222804);
 
one++;
}
else
{
 attenuation = ( 1.00/WATT*(new_W/distance_in_material))/7874.0;
 RESISTANCE =  new_W/(pow(NEWWU,2.0));  

/*
   		This executes every loop.

*/
/* 
  Calculate relativ permeability for iron:
  therefore the frequency must vary
*/
/* 
  Calculate frequency
*/


/* 
  Calculate velocity
*/
freq =     (((1.58882e10)* powf(f[3],2.0) *relativ_permeability)/sqrtf( 252425272283202775718997981659136.0 + 2808609933552555.0*powf(f[3],2.0)* relativ_permeability));
velocity =  1*299792458.0/(sqrt(1*relativ_permeability/2.0*(sqrt(1+pow((1.03e7/(2*M_PI*freq*8.854e-12)),2.0))+1))); 

position1[work] = 1*fabs(f[0]);
f[0] =  sqrt(4*M_PI/(1.03e7*M_PI*relativ_permeability*4e-7*freq));
 relativ_permeability = 179751035759958240.0/(pow(f[3],2.0) + sqrt((32310434856777778462720.0 + pow(freq,2.0))/pow(freq,2.0)) * pow(f[3],2.0));
/* 
  Calculate mass
0.5*(A^2*l^2*(m/l)*(2*pi*f)^2)= f*6.626e-34 solve m
*/
 new_m = (3.35677e-35)/(pow(NEWWU,2.0) *freq* f[0]);//(3.35677e-35)/(freq* (velocity/freq) *pow(NEWWU,2.0));


} 
 double w;
 
if(result_once == 0)
{   
 w = 2*M_PI*freq;
DISTANCE_ =1.0/(sqrt(M_PI*M_PI*4e-7*(relativ_permeability)*1.03e7*freq)) *5;
energy[work] =  (pow(w,2)*new_m*pow(distance_in_material,2.0));

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
energy[work] = 0.5*(pow(w,2)*new_m*pow((velocity/freq),2.0));
time_[work] = -1.0/(C*w);

if(position1[work] <0)
position1[work] = -position1[work];

 //distance_in_material =distance_in_material    +   (position1[work]-position1[work-1])/23.0;     
 //distance_in_material_2 =distance_in_material+  (position1[work]-position1[work-1])/ 23.0;     ;
if(time_[work] < 0 || time_[work-1] < 0)
{
time_[work] = -time_[work]; 
time_[work-1] = -time_[work-1];
}

 
 
//printf("time_[work] = %.100f \n", time_[work]);  
distance_in_material =distance_in_material    +   1* ((position1[work])- (position1[work-1]) );     
 distance_in_material_2 =distance_in_material_2+  1* ((position1[work])- (position1[work-1]));      
 
 
}
 

/*
...Then how many photons strikes one atom:
*/
double how_many_photons_on_one_atom = new_W/((6.626e-34*1))  ; ///(distance_in_material));
//printf("megacount = %f :: how_many_photons_on_one_atom = %f\n", megacount,fabs(how_many_photons_on_one_atom));
// if(how_many_photons_on_one_atom < 0 || how_many_photons_on_one_atom == 0)
	//how_many_photons_on_one_atom =  new_W/( 6.626e-34*freq);
/*
...Calculate the gravity of single atom:
*/ 
 
double amplitude = (0.202642 *powf(velocity,2.0))/(pow(NEWWU,2.0)* powf(freq,2.0)* powf(distance_in_material,2.0));//(0.767495* NEWWU* freq *(velocity/freq))/pow(velocity,2.0);
double photonarea = M_PI*pow(amplitude,2.0);
double ironatomarea =  M_PI*pow(2.48e-10,2.0); 
double div = photonarea/ironatomarea;
 		 
//atomic_frequency =    (1.02276e7* pow((pow(1.4e-10,2.0)*1*M_PI),1.0/6.0)* pow(velocity,2.0/3.0)* pow(new_W,1.0/6.0))/(pow(distance_in_material,5.0/6.0)* NEWWU);//(7571.75  *pow(f[3], 
/*

8.85e-12*(integrate( integrate( integrate (x*((U*U/299792458)) ))))*x

1.23002×10^-21 U^2 x^5
1.23002×10^-21 y^2 x^5 = 2/3*m*(x)^2*2*pi*f solve x
*/
double radius__ =  (7.5225e6*pow(freq,1.0/3.0)* pow( (3.35677e-35)/(pow(NEWWU,2.0) *freq* f[0]),(1.0/3.0))/pow(NEWWU,(2.0/3.0)));
 //printf("radius__ = %.20f \n", radius__);
//g via ang mom
 //little_g =((5.53948e-15 )* pow(299792458.0,2.0) *sqrt(6.67e-11) *sqrt(162941829212697647530584535681990656.0* pow(NEWWU/f[3],2.0) *f[0] + 1812933896770298880.0*pow(NEWWU,2.0)* f[0] + 1404334755935659.0 *f[3]))/sqrt( f[0]* (pow(299792458.0,4.0) + pow(f[3],4.0)));
if(  xradius_photon == 0)
	xradius_photon = 1e-6;

 if(mass_photon != 0)
 new_m =mass_photon; 
else
mass_photon  = new_m;
 double little_g1 = 1*((3162.28) *sqrt(NEWWU/(299792458.0)) *sqrt(NEWWU)* sqrt(6.67e-11))/sqrt(f[3]) ;//1*6.67e-11*(2.0/3.0*powf(xradius_photon,2.0)*mass_photon*2*M_PI* (freq))/(2*powf(299792458,2.0)*powf(xradius_photon,3.0))*299792458.0/9.78;
// printf("  little_g = %.200f kg \n", little_g1);
  /// xradius_photon = (2.85875e-18 *(2*6.626e-34*freq)/pow(f[3],2.0))/little_g1;//fabs(-(0.0795778 *(-pow(little_g1,2.0) + 4.99998e6 *pow(NEWWU/f[3],2.0) *6.67e-11))/6.67e-11);

//if(little_g == 0)
//little_g = little_g1;
   //mass_photon = 1.49925e10* little_g1 *pow(xradius_photon,2.0);
 //printf("total mass_photon = %.200f kg \n", mass_photon);
// //printf("total radius__ = %.200f kg \n", radius__);
// atomic_frequency =(0.0825453 *pow(new_W,3.0))/pow(little_g1,2.0);// 8.29607e8 *pow(new_W,3.0); //(4.2264e-14 *pow(freq,3.0)* pow(distance_in_material,3.0)* pow(new_W,3.0))/(pow(little_g1,2.0)* pow(1.4e-10,2.0)* pow(f[3],9));;


//double photon_mom_inertia = 2.0/3.0*2*new_m*pow(radius,2.0)
//double mass_atom = 1.672e-27*26;
//atomic_frequency = (0.159155 *acc *(photon_mom_inertia) + 1.3252e-33 *pow(freq,2.0) *radius)/(mass_atom* pow(1.4e-10,2.0));



/*
 c*((1/(c^2))*((c^2/(4*pi*G))*g*((v*g)/c^2))) +(1/(pi*4e-7)*D*B)/c = 1/(4*pi*c)*D*B solve g 

 beräkna radius av fotonen genom
 ((3162.28) sqrt(B) sqrt(D) sqrt(6.67e-11))/sqrt(v)  = 6.67e-11*m/x^2 solve x 
 andra ledet har massa, fotonens massa, om 6.67e-11*m/x^2 använder beräknade radius x, så får dem samma resultat utan att vänster led använder massan!
 så fotoner har massa!

sen kan man eftersom fotoner har säkerligen massa och massan kommer ifrån, m = (3.35677×10^-35)/(A^2 f l) :
6.67e-11*((3.35677×10^-35)/(A^2 f l) )/(x^2) = ((3162.28) *sqrt(U/299792458.0) *sqrt(U)* sqrt(6.67e-11))/sqrt(v) solve x



sen kan man efter att löst ut x beräkna gravitation som en foton har:
6.67e-11*((3.35677×10^-35)/(U^2 f l))/((3.87434×10^-20 v^(1/4))/(sqrt(f) sqrt(l) U^(3/2)) )^2 = g

vilket blir förenklat:
(1.4916×10^-6 U)/sqrt(v) =g

*/

double radius =   (0.0000508196* sqrt(new_m) *pow(f[3],(1.0/4.0))/((pow(NEWWU/299792458.0,1.0/4.0)) * pow(NEWWU,(1.0/4.0))));
double radius_amplitud = radius*1;
double amplitud_per_atomdistance = radius_amplitud/(2.48e-10);

double photon_mom_inertia = 2.0/3.0*2*new_m*pow(radius,2.0);
double mass_atom = 1.672e-27*26;
/*

Beräkna atomens nya frekvens genom:
M*a + 2*r*f*6.626e-34*(2*pi*f)  = m*pow(R,2.0)*2*pi*X solve X

(0.159155 a M + 1.3252×10^-33 f^2 r)/(m R^2)


*/
accen = (-(pow(w,2)*1)*f[0] - (C*2*1*w)*f[3] )/1;
double atomic_frequency2 = (0.159155 *accen * photon_mom_inertia  + 1.3252e-33 *pow(freq,2.0) *radius)/(mass_atom* pow(1.26e-10,2.0));
/*
Beräkna atomens enskilda gravitation genom enbart dess nya spin ( gravitomagnetism)
*/
little_g1 =  1/(radius*1.9e25*10)*((3162.28) *sqrt(NEWWU/299792458.0) *sqrt(NEWWU)* sqrt(6.67e-11))/sqrt(f[3]); //denna ger samma som little_g1 = 1*((3162.28) *sqrt(NEWWU/(299792458.0)) *sqrt(NEWWU)* sqrt(6.67e-11))/sqrt(f[3])  6.7e-11*new_m/(pow(radius,2.0))
little_g =little_g1;//0+how_many_photons_on_one_atom*  1/amplitud_per_atomdistance*6.67e-11*(2.0/3.0*pow(1.26e-10,2.0)*9.2732e-26*2*M_PI*atomic_frequency2)/(2*pow(299792458.0,2.0)*(pow(1.26e-10,3.0))*299792458.0/9.78);
/*					
...Calculate how much the electric field decreases in material after every iteration:
*/ 

 //little_g = little_g1;
if(attenuation < 0)
attenuation = -attenuation;

	  NEWWU    =1*exp(-7809.88 *distance_in_material) *EFIELD;// fabs((exp(-(((distance_in_material ) )*9506.30412))*EFIELD  ));
	  new_W = pow(NEWWU  ,2.0)*RESISTANCE;
/*  
...Calculate the total gravity summation:
*/ 
if(fabs(distance_in_material_2) > 2.48e-10)  
{	
	count = fabs(distance_in_material_2)/2.48e-10;
	//printf("count = %f \n", count);
	
	megacount = megacount + count;
	mega_g = mega_g + little_g*count;
	distance_in_material_2= 0;
}


if(K % 1 == 0 )
{
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"); 
printf("attenuation = %.10f \n", attenuation);
printf("radius_amplitud = %.10f \n", radius_amplitud);

printf("little g from photon = %.10f \n", little_g1);
printf("acc = %.10f \n", accen);
 printf("atomic_frequency = %.10f \n", atomic_frequency2);
 printf("radius = %.100f \n", radius);
 printf("div = %.10f \n", div);
printf("relativ permeability = %.10f \n", relativ_permeability); 
printf("new_W = %f \n",new_W);
printf("RESISTANCE = %.15f \n",RESISTANCE);
printf("new_U = %f \n",NEWWU);
printf("new_m = %.100f \n",new_m);

printf("amplitude = %.10f \n",amplitude);

printf("freq = %f \n",freq);
printf("f[0] (x coordinate ) = %.10f meter \n", f[0]);
printf("Velocity of photons  = %.10f m/s^2 \n",velocity);
 
printf("Total gravity recording = %.100f m/s^2 \n", mega_g  );
 //sleep(1);
printf("Distance traveled in medium by a photon = %.40f meter \n",distance_in_material);
printf("distance/atomic_spacing  = %.10f \n", ( distance_in_material)/( 2.48e-10   ) );
 printf("torus mass  = %.10f kg \n", 697.0/20.0 - (2905.0 *mega_g)/978.0 ); 
printf("distance needed  = %.10f \n", DISTANCE__ ); 
// sleep(1);
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"); 
 if(NEWWU < (pow(0.37,5.0)*EFIELD))
 	for(;;);
}
if( fabs(distance_in_material) > 0.011 /* || mega_g > G ||  velocity < 0 || new_U < (3.0 )*/)
 {
 for(;;);
	DONE_WITH_THIS_0 = 1;	
	init_tasks(0,0);
}
 
time_[work] = -1.0/(C*w);
if(result_once == 0)
{
    result[0] =             velocity*1 ;
    result[1] =             f[4]*1  ;
    result[2] =             f[5]*1  ;
    
    result[3] = (-(pow(w,2)*1)*f[0] - (C*2*1*w)*velocity )/1;
    result[4] = (-(pow(w,2)*1)*f[0] - (C*2*1*w)*f[4] )/1;
    result[5] = (-(pow(w,2)*1)*f[0] - (C*2*1*w)*f[5] )/1;
    result_once = 1;

accen = result[3];
}
else if(result_once == 1){
    result[0] =             f[3]*1 ;
    result[1] =             f[4]*1  ;
    result[2] =             f[5]*1  ;
result[3] = (-(pow(w,2)*new_m)*f[0] - (C*2*new_m*w)*f[3] )/new_m;
result[4] = (-(pow(w,2)*new_m)*f[0]- (C*2*new_m*w)*f[4] )/new_m;
result[5] = (-(pow(w,2)*new_m)*f[0]  - (C*2*new_m*w)*f[5] )/new_m;

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
 	 rk45(rates_photon, t0, f0,f0_result, tf,z,6, 4100000232.0  );
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
 	//while(1)
	//{
		photon_oscillate = get_photon_state_oscillate_task1(photon_oscillate,1,1);

	//	printf("photon_oscillate position = %.10f \n", photon_oscillate.pos_new_x);
	//	printf("photon_oscillate velocity = %.10f \n", photon_oscillate.vel_new_x);
	//}
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
void rates_sphere_g_acc(double *t, double *f, double result[] )
{

    result[0] =            f[3]/1.0;
    result[1] =            f[4]/1.0;
    result[2] =           f[3]/1.0;
 




 result[4] =             (    10.0   -9.78)/1.0;
 
levitatecounter++;
 

if(f[1] >31.0 && dowork ==0  )
{

 
	 
// result[4] =             ( - mega_g   -9.78);
dowork = 1;
}
  frequency_ball = f[3]/f[1];

if(levitatecounter > 100000)
{

if(f[1] > 30.0   )
{
 //printf("sphere_state.vel_new_y1 = %f \n", sphere_state.vel_new_y);
 result[4] =   -4;//*cos(frequency_ball*time____); 
    result[1] =            f[4]/1.0;
}
else if(f[1] < 30.0   )
{

 result[4] =    4;//*cos(frequency_ball*time____) ;
  //printf("sphere_state.vel_new_y2 = %f \n", sphere_state.vel_new_y);
    result[1] =            f[4]/1.0;
}
else if (dowork == 1)
{

 
}
if(speedcounter > 60*4)
	speedcounter = 0;
speedcounter++;
g_multiplyer =g_multiplyer +0.01;



 
}
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
sphere_state = SPHERE_STATE_VECTOR(sphere_state,1);
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
    

    glPushMatrix();
 
 
 
 
    glTranslatef(0, sphere_state.pos_new_y/1 +40 ,0);

    double x = 697.0/20.0 - (3485.0 *mega_g)/978.0;//-697.0000/980.0000*(5*(mega_g+mega_g_vert)*1-49);

 
 	//697/20 - (3485 y)/978 < 0.159*34.85 ||  697/20 - (3485 y)/978 > 0.159*34.85
    glutPostRedisplay();
    if(x < 0.159*34.85 && x > -0.159*34.85/**1 < 34.85*0.159 && x*1 > -34.85*0.159*/)
    {
 
    }
    else
    {
   
 	glutSolidSphere(24,330,100  );
}
glutSwapBuffers();
}


Light *dirLight;
int mass_once_vert = 1;
Material *material;
double findMod(double a, double b)
{
    // Handling negative values
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
 
    // Finding mod by repeated subtraction
    double mod = a;
    while (mod >= b)
        mod = mod - b;
 
    // Sign of result typically depends
    // on sign of a.
    if (a < 0)
        return -mod;
 
    return mod;
}
 
 
void  setPosition_light(float x, float y, float z)
{
////////////////////////////printf("light1\n");
    dirLight->pos[0] = x;
    dirLight->pos[1] = y;
    dirLight->pos[2] = z;
    dirLight->pos[3] = 0.0f;
}

void  setAmbient_light(float x, float y, float z)
{
////////////////////////////printf("light2\n");
    dirLight->ambient[0] = x;
    dirLight->ambient[1] = y;
    dirLight->ambient[2] = z;
}

void  setDifusse_light(float x, float y, float z)
{
////////////////////////////printf("light3\n");
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
 
	rk45(rates_sphere_g_acc, t0, f0,f0_result, tf,z,6, 1000 );
  printf("sphere_state.pos_new_y = %f \n", sphere_state.pos_new_y);
 printf("sphere_state.vel_new_y = %f \n", sphere_state.vel_new_y);
 printf("frequency_ball = %f \n", frequency_ball);
	state_result_sphere.pos_new_x = f0[0];
	state_result_sphere.pos_new_y = f0[1];
	state_result_sphere.pos_new_z = f0[2];

	state_result_sphere.vel_new_x = f0[3];
	state_result_sphere.vel_new_y = f0[4];
	state_result_sphere.vel_new_z = f0[5];

	return  state_result_sphere;
}
void task2(void )
{
printf("TASK  \n");
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
	photon_oscillate.pos_new_x =  0;
	photon_oscillate.pos_new_y =  0; 
	photon_oscillate.pos_new_z =  0;

	photon_oscillate.vel_new_x = 894.43;
	photon_oscillate.vel_new_y = 894.43;
	photon_oscillate.vel_new_z = 894.43;

	sphere_state.pos_new_x =   2;
	sphere_state.pos_new_y =   2;  
	sphere_state.pos_new_z =   2; 

	sphere_state.vel_new_x = 0.000;
	sphere_state.vel_new_y = 0.000;
	sphere_state.vel_new_z = 0.000;

	first_run = 0;
}
  glutInit(&argc, argv);
  init_mpgeg( );
task1();
  
  //init_tasks(argv,argv);


 	

}
