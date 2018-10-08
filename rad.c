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
double POSX[10000000];
double POSY[10000000];
double VEL[10000000];
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

#define EFIELD 850.0
#define PERMEABILITY 25000.0  
#define G 15.1
#define WATTTT 92673.0 

#define SIZE_BUFFER 10000000000.0
#define TIME_M 1111191000000.0
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
double attenuation;
#define RADAREA 0.374
struct state_vector photon_oscillate;
double dipolewattsystemh;
int one= 0;
double distance_in_material_2 = 0;
double distance_in_material = 0;
double freq = 1.44494e8 ;
double freq_ = 1.44494e6;
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
int K;
#define HAX 100000
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
	position1 =  malloc(SIZE_BUFFER);
	energy =     malloc(SIZE_BUFFER);
	time_ =      malloc(SIZE_BUFFER);
	distance_in_material_2 = 0;
	distance_in_material = 0;

	RESISTANCE =  new_W/(pow(EFIELD,2.0));  
	//DISTANCE_ =1.0/(sqrt(M_PI*M_PI*4e-7*(25000)*1.03e7*freq)) *5; 

	velocity =  1*299792458.0/(sqrt(1*25000.0/2.0*(sqrt(1+pow((10.0/(2*M_PI*freq*8.854e-12)),2.0))+1))); 
	relativ_permeability =  179751035759958240.0/(pow(velocity,2.0) + sqrt((32310434856777778462720.0 + pow(freq,2.0))/pow(freq,2.0)) * pow(velocity,2.0));

	DISTANCE__ =fabs(-(25 *log(300/pow(EFIELD,2.0)))/222804);
	/*Calculate mass*/
	new_m = (3.35677e-35)/(pow(NEWWU,2.0) *299792458);
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
  Calculate frequency
*/
 //freq =     (((1.58882e10)* powf(f[3],2.0) *relativ_permeability)/sqrtf( 252425272283202775718997981659136.0 + 2808609933552555.0*powf(f[3],2.0)* relativ_permeability));

/* 
  Calculate velocity
*/
	velocity =  1*299792458.0/(sqrt(1*relativ_permeability/2.0*(sqrt(1+pow((1.03e7/(2*M_PI*freq*8.854e-12)),2.0))+1))); 

	position1[work] = 1* (f[0]);
	f[0] =   sqrt(4*M_PI/(1.03e7*M_PI*relativ_permeability*4e-7*freq));
/* 
  Calculate relativ permeability for iron:
  therefore the frequency must vary
*/
	relativ_permeability = 179751035759958240.0/(pow(f[3],2.0) + sqrt((32310434856777778462720.0 + pow(freq,2.0))/pow(freq,2.0)) * pow(f[3],2.0));
// new_m = (3.35677e-35)/(pow(NEWWU,2.0) *f[3]);//(3.35677e-35)/(freq* (velocity/freq) *pow(NEWWU,2.0));
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
	if(f[3] < 0 || f[3] == 0)
		f[3] = velocity;
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
//printf("time_[work] = %.100f \n", time_[work]);  
if(time_[work] < 0.0009 || time_[work-1] < 0.0009)
{
	timechange = 0.8;
}
else
	timechange = fabs(time_[work]-time_[work-1]);

	distance_in_material =distance_in_material    +((velocity/0.0006)/(TIME_M*freq_)) ;   
	distance_in_material_2 =distance_in_material_2+((velocity/0.0006)/(TIME_M*freq_)) ;     
}
/*
...Then how many photons strikes one atom:
*/
double how_many_photons_on_one_atom = new_W/((6.626e-34*freq))  ; ///(distance_in_material));
//printf("megacount = %f :: how_many_photons_on_one_atom = %f\n", megacount,fabs(how_many_photons_on_one_atom));
//if(how_many_photons_on_one_atom < 0 || how_many_photons_on_one_atom == 0)
//how_many_photons_on_one_atom =  new_W/( 6.626e-34*freq);
double amplitude = (0.202642 *powf(velocity,2.0))/(pow(NEWWU,2.0)* powf(freq,2.0)* powf(distance_in_material,2.0));//(0.767495* NEWWU* freq *(velocity/freq))/pow(velocity,2.0);
double photonarea = M_PI*pow(amplitude,2.0);
double ironatomarea =  M_PI*pow(2.48e-10,2.0); 
double div = photonarea/ironatomarea;
 		
radius =   (0.0000508196* sqrt(new_m) *pow(f[3],(1.0/4.0))/((pow(NEWWU/299792458.0,1.0/4.0)) * pow(NEWWU,(1.0/4.0))));
 
double photon_mom_inertia = 2.0/3.0*2*new_m*pow(radius,2.0);
double mass_atom = 1.672e-27*26;
 
double frequency___atomic = 280474649406688306320629446517287519655646158909710794752.0 *freq* new_m *how_many_photons_on_one_atom* pow(radius,2.0);
accen = (-(pow(w,2)*1)*distance_in_material - (C*2*1*w)*f[3] )/1;
double atomic_frequency2 = (0.159155 *accen * photon_mom_inertia  + 1.3252e-33  *pow(freq,2.0) *radius)/(mass_atom* pow(1e-15,2.0));


little_g  = (1.0)/(radius*1.9e25*18.6638)*((3162.28) *sqrt(NEWWU/299792458.0) *sqrt(NEWWU)* sqrt(6.67e-11))/sqrt(f[3]); 
//little_g =   1*(little_g1  /*how_many_photons_on_one_atom*6.67e-11*(2.0/3.0*pow(radius,2.0)*new_m*2*M_PI*freq)/(2*pow(299792458.0,2.0)*(pow(radius,3.0))*1)*/) ;
/*					
 ...Calculate how much the electric field decreases in material after every iteration:
*/ 
if(attenuation < 0)
	attenuation = -attenuation;

NEWWU    =1*exp(-7809.88 *distance_in_material) *EFIELD;// fabs((exp(-(((distance_in_material ) )*9506.30412))*EFIELD  ));
new_W = pow(NEWWU  ,2.0)*RESISTANCE;
/*  
...Calculate the total gravity summation:
*/ 
if( (distance_in_material_2) > 2.48e-10)  
{	
	count =  (distance_in_material_2)/2.48e-10;
	//printf("count = %f \n", count);
	
	megacount = megacount + count;
	mega_g = mega_g + little_g*count;
	distance_in_material_2= 0;
}
 
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
	printf("Time since start: ="CYN" %.10f"RESET" "WHT" seconds"RESET"\n", time_[work]);
	printf("Acceleration = "CYN"%.10f"RESET" "WHT" m/s²"RESET"\n", accen);
 	//printf("atomic_frequency = %.10f \n", atomic_frequency2);
 	printf("Photon radius = "CYN"%.40f"RESET" "WHT" meter "RESET"\n", radius);
 	//printf("div = %.10f \n", div);
	printf("Relativ permeability = "CYN"%.10f "RESET"\n", relativ_permeability); 
	printf("Watt change = "CYN"%.10f"RESET" "WHT" watts "RESET"\n",new_W);
	printf("Resistance = "CYN"%.10f"RESET" "WHT" ohm "RESET"\n",RESISTANCE);
	printf("Electric field = "CYN"%.10f"RESET" "WHT" volt/meter "RESET"\n",NEWWU);
	printf("Mass photon = "CYN"%.50f"RESET" "WHT" kg "RESET"\n",new_m);

	printf("Photon g = "CYN"%.10f"RESET" "WHT" m/s²"RESET"\n",little_g);
	printf("Frequeny of wave = "CYN"%.10f"RESET" "WHT" "RESET"\n",freq);
	printf("Wavelength = "CYN"%.10f"RESET" "WHT" meter "RESET"\n", f[0]);
	printf("Velocity of photons  = "CYN"%.10f"RESET" "WHT" m/s² "RESET"\n",velocity);
 
	printf("Total gravity recording = "CYN"%.20f"RESET" "WHT" m/s² "RESET"\n", mega_g  );
	printf("Distance traveled in medium by a photon = "CYN"%.20f"RESET" "WHT" meter "RESET"\n",distance_in_material);
	printf("Distance/atomic_spacing  = "CYN"%.10f"RESET" "WHT" meter"RESET"\n", ( distance_in_material)/( 2.48e-10   ) );
        printf("Torus mass  = "CYN"%.10f"RESET" "WHT" kg "RESET"\n", 697.0/20.0 - (2905.0 *mega_g)/978.0 ); 
        printf("Distance needed  = "CYN"%.10f"RESET" "WHT" meter"RESET"\n", DISTANCE__ ); 
// sleep(1);
printf(YEL "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n",RESET); 
 //if(NEWWU < (pow(0.37,5.0)*EFIELD))
 //	for(;;);
}
if(  (distance_in_material) > 0.0006 /* || mega_g > G ||  velocity < 0 || new_U < (3.0 )*/)
{
        //for(;;);
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
	result[4] = (-(pow(w,2)*1)*distance_in_material- (C*2*1*w)*f[4] )/1;
	result[5] = (-(pow(w,2)*1)*distance_in_material  - (C*2*1*w)*f[5] )/1;
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
 	rk45(rates_photon, t0, f0,f0_result, tf,z,6, TIME_M*freq_  ); 
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
void rates_sphere_g_acc(double *t, double *f, double result[] )
{

    result[0] =            f[3]/1.0;
    result[1] =            f[4]/1.0;
    result[2] =           f[3]/1.0;
    //result[4] =             (    10.0   -9.78)/1.0;
 
levitatecounter++;
 
frequency_ball = f[3]/f[1];

if(levitatecounter > 1)
{

if(f[1] >0.5  )
{
	result[4] =    -4.13719; 
	result[1] =            - (0.5)/8.33910237995380123938941e-10;  
}
else if(f[1] <-0.5 )
{
	result[4] =   4.13719 ;//*cos(frequency_ball*time____) ;
	result[1] =            (0.5)/8.33910237995380123938941e-10;
}

    result[0] =             result[1] ;
    result[1] =             result[1]  ;
    result[2] =             result[1]  ;
    
    result[3] = result[4];
    result[4] = result[4];
    result[5] = result[4];

 
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
//printf("POSX[WORKWORK]*10000000000000000 = %.120f \n", POSX[WORKWORK]*10000000000000000);
   //     glTranslatef(POSX[WORKWORK]*10000000000000000*9e-11-60, POSX[WORKWORK]*10000000000000000*9e-11 +70 ,POSX[WORKWORK]*10000000000000000*9e-11 +0);
 //   glPushMatrix();
      //  glTranslatef(0, POSY[WORKWORK]*1000000 +40 ,0);

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

    double x = 697.0/20.0 - (3485.0 *0.02797532)/978.0;//-697.0000/980.0000*(5*(mega_g+mega_g_vert)*1-49);

 
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
 
	rk45(rates_sphere_g_acc, t0, f0,f0_result, tf,z,6, 10000    );
        printf("sphere_state.pos_new_y = %f \n", sphere_state.pos_new_y);
        printf("sphere_state.vel_new_y = %f \n", sphere_state.vel_new_y);
 
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

	photon_oscillate.vel_new_x = 299792458.0/(sqrt(1*75/2.0*(sqrt(1+pow((10.0/(2*M_PI*freq*8.854e-12)),2.0))+1)));
	photon_oscillate.vel_new_y = 894.43;
	photon_oscillate.vel_new_z = 894.43;

	sphere_state.pos_new_x =   14.9;
	sphere_state.pos_new_y =   0;  
	sphere_state.pos_new_z =   2; 

	sphere_state.vel_new_x = 0.000;
	sphere_state.vel_new_y = 2e-4/6.671281903e-13;
	sphere_state.vel_new_z = 0.000;

	first_run = 0;
}
glutInit(&argc, argv);
  
task1();
  
  //init_tasks(argv,argv);

}
