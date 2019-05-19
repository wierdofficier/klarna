double PGAIN =0.00001005 ;
double IGAIN =0 ;
double DGAIN =0; 
double frequency__ = 6.95e-6  ; 
double o  = 3.5e7;
double p  = 2700;
double P  = 1;
double R  = 10;
double volt =1.653200000000001 ;


#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <GL/glut.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <pthread.h>
#include "system.h"
#include "kdtree.h"
#include <stdbool.h>
#include <math.h>
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "PID.h"
#include <sys/time.h>


#define NUM_THREADS 2

int stop_inc =1;
double human_radie = 2.0;
double object_age;
double acc12;
double U ;
double newvolt ;
double fieldnext ; 
double tk = 0;
float acc1;
double magneticfield;
int human;

double r ;
double integratenow  (double a, double b);
double PIDSOURCE();
double PIDOUTPUT(double state);
int multitasks( );

struct state_vector   *   mass_motion(struct state_vector     *  next_state, int num );
struct state_vector  ** mass_motion_state ;
struct state_vector  ** mass_motion_state_temp ;


//algoritm så att volten hålls jämn.
PIDController *createPIDController(double p, double i, double d, double (*pidSource)(void), void (*pidOutput)(double output),double target) {

	PIDController *controller = malloc(sizeof(PIDController));
	controller->p = p;
	controller->i = i;
	controller->d = d;
	controller->target = target ;//0;
	controller->output = 0;
	controller->enabled = 1;
	controller->currentFeedback = 0;
	controller->lastFeedback = 0;
	controller->lastError = 0;
	controller->currentTime = 0L;
	controller->lastTime = 0L;
	controller->integralCumulation = 0;
	controller->maxCumulation = 300000;
	controller->inputBounded = 0;
	controller->outputBounded = 0;
	controller->inputLowerBound = 0;
	controller->inputUpperBound = 0;
	controller->outputBounded = 0;
	controller->outputLowerBound = 0;
	controller->outputUpperBound = 0;
	controller->timeFunctionRegistered = 0;
	controller->pidSource = pidSource;
	controller->pidOutput = pidOutput;
	controller->getSystemTime = NULL;
	return controller;
}


void tick(PIDController *c,double input___) {
 
	if(c->enabled) {
		//Retrieve system feedback from user callback.
		c->currentFeedback = input___ ;

		//Apply input bounds if necessary.
		if(c->inputBounded) {
			if(c->currentFeedback > c->inputUpperBound) c->currentFeedback = c->inputUpperBound;
			if(c->currentFeedback < c->inputLowerBound) c->currentFeedback = c->inputLowerBound;
		}

		/*
		 * Feedback wrapping causes two distant numbers to appear adjacent to one
		 * another for the purpose of calculating the system's error.
		 */
		if(c->feedbackWrapped) {

			/*
			 * There are three ways to traverse from one point to another in this setup.
			 *
			 *		1)	Target --> Feedback
			 *
			 * The other two ways involve bridging a gap connected by the upper and
			 * lower bounds of the feedback wrap.
			 *
			 *		2)	Target --> Upper Bound == Lower Bound --> Feedback
			 *
			 *		3)	Target --> Lower Bound == Upper Bound --> Feedback
			 *
			 * Of these three paths, one should always be shorter than the other two,
			 * unless all three are equal, in which case it does not matter which path
			 * is taken.
			 */
			double regErr = c->target - c->currentFeedback;
			double altErr1 = (c->target - c->feedbackWrapLowerBound) + (c->feedbackWrapUpperBound - c->currentFeedback);
			double altErr2 = (c->feedbackWrapUpperBound - c->target) + (c->currentFeedback - c->feedbackWrapLowerBound);

			// Calculate the absolute values of each error.
			double regErrAbs = (regErr >= 0) ? regErr : -regErr;
			double altErr1Abs = (altErr1 >= 0) ? altErr1 : -altErr1;
			double altErr2Abs = (altErr2 >= 0) ? altErr2 : -altErr2;

			// Use the error with the smallest absolute value
			if(regErrAbs <= altErr1Abs && regErr <= altErr2Abs) {
				c->error = regErr;
			}
			else if(altErr1Abs < regErrAbs && altErr1Abs < altErr2Abs) {
				c->error = altErr1Abs;
			}
			else if(altErr2Abs < regErrAbs && altErr2Abs < altErr1Abs) {
				c->error = altErr2Abs;
			}
		}
		else {
			// Calculate the error between the feedback and the target.
			c->error = c->target - c->currentFeedback;
		}

		// If we have a registered way to retrieve the system time, use time in PID calculations.
		if(c->timeFunctionRegistered) {
			// Retrieve system time
			c->currentTime = c->getSystemTime();

			// Calculate time since last tick() cycle.
			long deltaTime = c->currentTime - c->lastTime;

			// Calculate the integral of the feedback data since last cycle.
			double cycleIntegral = (c->lastError + c->error / 2) * deltaTime;

			// Add this cycle's integral to the integral cumulation.
			c->integralCumulation += cycleIntegral;

			// Calculate the slope of the line with data from the current and last cycles.
			c->cycleDerivative = (c->error - c->lastError) / deltaTime;

			// Save time data for next iteration.
			c->lastTime = c->currentTime;
		}
		// If we have no way to retrieve system time, estimate calculations.
		else {
			c->integralCumulation += c->error;
			c->cycleDerivative = (c->error - c->lastError);
		}

		// Prevent the integral cumulation from becoming overwhelmingly huge.
		if(c->integralCumulation > c->maxCumulation) c->integralCumulation = c->maxCumulation;
		if(c->integralCumulation < -c->maxCumulation) c->integralCumulation = -c->maxCumulation;

		// Calculate the system output based on data and PID gains.
		c->output = (double) ((c->error * c->p) + (c->integralCumulation * c->i) + (c->cycleDerivative * c->d));

		// Save a record of this iteration's data.
		c->lastFeedback = c->currentFeedback;
		c->lastError = c->error;

		// Trim the output to the bounds if needed.
		if(c->outputBounded) {
			if(c->output > c->outputUpperBound) c->output = c->outputUpperBound;
			if(c->output < c->outputLowerBound) c->output = c->outputLowerBound;
		}
	 	//printf("c->output : %.10f \n",  c->output);
	
		c->pidOutput(c->output);
	}
}


void setEnabled(PIDController *controller, uint8_t enabled) {

	// If the PIDController was enabled and is being disabled.
	if(!enabled && controller->enabled) {
		controller->output = 0;
		controller->integralCumulation = 0;
	}
	controller->enabled = enabled;
}


double getProportionalComponent(PIDController *controller) {
	return (controller->error * controller->p);
}

double getIntegralComponent(PIDController *controller) {
	return (controller->integralCumulation * controller->i);
}


double getDerivativeComponent(PIDController *controller) {
	return (controller->cycleDerivative * controller->d);
}


void setMaxIntegralCumulation(PIDController *controller, double max) {

	// If the new max value is less than 0, invert to make positive.
	if(max < 0) {
		max = -max;
	}

	// If the new max is not more than 1 then the cumulation is useless.
	if(max > 1) {
		controller->maxCumulation = max;
	}
}


void setInputBounds(PIDController *controller, double lower, double upper) {

	if(upper > lower) {
		controller->inputBounded = 1;
		controller->inputUpperBound = upper;
		controller->inputLowerBound = lower;
	}
}


void setOutputBounds(PIDController *controller, double lower, double upper) {

	if(upper > lower) {
		controller->outputBounded = 1;
		controller->outputLowerBound = lower;
		controller->outputUpperBound = upper;
	}
}


void setFeedbackWrapBounds(PIDController *controller, double lower, double upper) {

	// Make sure no value outside this circular range is ever input.
	setInputBounds(controller, lower, upper);

	controller->feedbackWrapped = 1;
	controller->feedbackWrapLowerBound = lower;
	controller->feedbackWrapUpperBound = upper;
}

double freq;
double motion_acc;
double w_0;
double k;
double v ;
double Q;	
double M; 
double zz;
double LL;
double A,B,C;
double photonmass ;
int count = 0;
int once = 0;
double end;
int INDEX_NRmore = 0;

#define SIZE_OBJECT 507904 //126976
#define FIRST 1
#define WORK 0

float fovy = 45.0;
float dNear = 100;
float dFar = 2000;
int i; 
 
int INDEX_NR = 0;
Light *dirLight;
Material *material;
 

float cameraEye[3] = {0.0, 0.0, 1000.0};
float lightRotation[16] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
float cameraLookAt[4] = {0.0, 0.0, 0.0, 1.0};
float cameraUp[4] = {0.0, 1.0, 0.0};

float viewRotation[16] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};

float rotationX=0.0;
float rotationY=0.0;

 typedef struct {
	float x, y, z;
} Vec3;

void rates_dorsal ( double *t, double *f, double result[]   );
void key(unsigned char key, int x, int y);
 
void display  (void);

 
 
double accen[1000];
float global_ambient[4] = {0.0, 0.0, 0.0, 0.0};
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
 

void reshape(int w, int h){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fovy, (GLdouble)w/(GLdouble)h, dNear, dFar);
    glViewport(0, 0, w, h);
} 

int initonce =1;
 
  
 
int argc_;
char **argv_;
int main (int argc, char **argv)
{ 
argc_=argc;
argv_=argv;

  
multitasks();	
}

void task2( )
{
//allokering
	int i,j,k;
	mass_motion_state =(struct state_vector*)malloc(sizeof(struct state_vector*)*SIZE_OBJECT*32);


	for(int i=0; i<SIZE_OBJECT*1; i++)
		mass_motion_state[i] = (struct state_vector*)malloc(sizeof(struct state_vector)*32);
 
 
	if(initonce==1)
	{
		int ll;
		for(ll = 0; ll < SIZE_OBJECT  ; ll++)
		{
	 
         	 	 mass_motion_state[ll]->pos_new_x = 0.0 ;
 	          	 mass_motion_state[ll]->pos_new_y = 0 ;
 		 	 mass_motion_state[ll]->pos_new_z = 0 ;
 
 	  	 	 mass_motion_state[ll]->vel_new_x =   0.0 ;
 		  	 mass_motion_state[ll]->vel_new_y =   0 ;
 		  	 mass_motion_state[ll]->vel_new_z =   0 ;
		}
		initonce = 0;
}


	glutInit(&argc_, argv_);
	init_mpgeg();

	GLint glut_display;

	glutInitWindowSize (1080,1920);
	glutCreateWindow ("gchange");

	int mainMenu;
	const GLubyte *str;
	str = glGetString (GL_EXTENSIONS);

	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glEnable(GL_NORMALIZE);
	//glEnable(GL_COLOR_MATERIAL);
	 human = loadOBJ__("FinalBaseMesh.obj"); 
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	dirLight = (Light*)malloc(sizeof(Light));
	dirLight->setPosition_light = setPosition_light;
	dirLight->setAmbient_light = setAmbient_light;
	dirLight->setDifusse_light = setDifusse_light;
	dirLight->setSpecular_light = setSpecular_light;
	 
	dirLight->setPosition_light(100,100, 800);
	dirLight->setAmbient_light(0, 0, 0);
	dirLight->setDifusse_light(1, 1, 1);
	dirLight->setSpecular_light(0.995f, 0.1f, 0.88f);
	 
	material =(Material*)malloc(sizeof(Material));
	material->setAmbient_material =setAmbient_material;
	material->setDifusse_material = setDifusse_material;
	material->setSpecular_material =setSpecular_material;
	material->setShininess_material = setShininess_material;
	material->setAmbient_material(0, 0, 1, 1);
	material->setDifusse_material(0.5f, 0.1f, 0.995f, 1.0f/450.0f);
	material->setSpecular_material(0.01f, 0.01f, 0.01f, 1.0f/450.0f);
	material->setShininess_material(128);
	 
	glutDisplayFunc (display );
	 
	glutReshapeFunc(reshape);
	 
	glutMouseFunc(mouse);
	glutKeyboardFunc(key);
	  	

	glutMotionFunc(mouseMotion);
	glutMainLoop();
}

struct state_vector   *   mass_motion(struct state_vector     *  next_state, int num )
{
	double f0[6];
	double f0_result[6];

	double z[6];
 	double t0[6] = {0,0,0,0,0,0};
 	double tburn =  .1;
	double tf[6] = {tburn,tburn,tburn,tburn,tburn,tburn};

	z[0] =  next_state->pos_new_x;
	z[1] =  next_state->pos_new_y;
	z[2] = next_state->pos_new_z;
	z[3] =  next_state->vel_new_x;
	z[4] =  next_state->vel_new_y;
	z[5] = next_state->vel_new_z;

	f0[0] = next_state->pos_new_x;
	f0[1] =next_state->pos_new_y;
	f0[2] =next_state->pos_new_z;
	f0[3] =next_state->vel_new_x;
	f0[4] =next_state->vel_new_y;
	f0[5] = next_state->vel_new_z;
 	//integrera 
	rk45(rates_dorsal, t0, f0,f0_result, tf,z,6, 1);

	next_state->pos_new_x = f0[0];
	next_state->pos_new_y = f0[1];
	next_state->pos_new_z = f0[2];

	next_state->vel_new_x = f0[3];
	next_state->vel_new_y = f0[4];
	next_state->vel_new_z = f0[5];

	return   next_state ;
}

 
double total_time = 0;
double total_distance = 0;
double osc_freq = 0;
double total_period_time = 0;
double vel[1000000];
double pos[1000000];
double difftime1[1000000];

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
 
double dif;
int sect;
double gmass;

typedef struct {
    float r;
    float g;
    float b;
} RGB;

int timerseccounter = 0;
void RenderString(float x, float y, void *font, const char* string )
{  
	  char *c;
	  RGB rgb;
	  glRasterPos2f(x, y);

	  glutBitmapString(font, string);
}


int cccc = 0;
int clocksec[100000];

double PIDSOURCE()
{
	return mass_motion_state[0]->pos_new_y;
}
 

double PIDOUTPUT(double state)
{
	newvolt = state;
	//printf("y height fix: %.10f \n",newvolt);
 
return state;
}
void display  (void){
	 
	    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	    glEnable(GL_TEXTURE_2D);
	    glEnable(GL_COLOR_MATERIAL);
	    glMatrixMode(GL_MODELVIEW);
	    glLoadIdentity();

	    glMultMatrixf(lightRotation);
	    glLoadIdentity();
	    gluLookAt(cameraEye[0]+0, cameraEye[1]+253, cameraEye[2]-423, cameraLookAt[0], cameraLookAt[1], cameraLookAt[2], cameraUp[0], cameraUp[1], cameraUp[2]);

	    glMultMatrixf(viewRotation);
	    glRotatef(rotationX+320,1,0,0);
	    glMultMatrixf(lightRotation);

	    //ge position och hastighet för kroppen
	    mass_motion_state[INDEX_NRmore] = mass_motion( mass_motion_state[INDEX_NRmore] ,1);	

	    if(mass_motion_state[0]->pos_new_y < 0   )
		{
			 mass_motion_state[0]->vel_new_y =0;
			 mass_motion_state[0]->pos_new_y = 0;
		}
	 
	    if(gmass < 0.159*0.02 && gmass > -0.159*0.02 )
	    {
	 	// glutSolidSphere(24,330,100  ); 
	    }
	    else
	    {
		 
	    } 
	 
	    time_t now;
	    struct tm *tm;

	    now = time(0);
	    if ((tm = localtime (&now)) == NULL) {
		printf ("Error extracting time stuff\n");
		return 1;
	    }
	 
	    cccc++;
	    clocksec[cccc] = tm->tm_sec;

	    if(r < 10000 && mass_motion_state[0]->pos_new_y > 0.09 )
	    {
		if(( abs(clocksec[cccc])  - abs(clocksec[cccc-1] )) != 0 && (abs(clocksec[cccc])  - abs(clocksec[cccc-1] )) > 0)  
			sect =sect+ ( abs(clocksec[cccc])  - abs(clocksec[cccc-1] ));
	    }
	    else
	      sect = 0;

 
	char  buf[1000];
	sprintf(buf,"height(y): %f m \n velocity(y): %f m/s \n time over ground: %d\n gravity: %f m/s^2 \n signal freq: %f Hz\n mass sphere: %f kg\n EBfield radius: %f\n voltage: %f\n EBfield reduce factor: %f\n motionfreq: %f\n energy density %f\n object_age %f\n body_linear_velocity %f\n",mass_motion_state[0]->pos_new_y,mass_motion_state[0]->vel_new_y,sect,acc1,frequency__,gmass,r,volt,tk,fabs(mass_motion_state[0]->vel_new_y/mass_motion_state[0]->pos_new_y),U,object_age,mass_motion_state[0]->vel_new_x*r);
	  
	 glColor3f(1, 1,1); 
	 glPushMatrix();
	 glScalef(11,11,11);
	 glTranslatef(0,   mass_motion_state[0]->pos_new_y*1 -0  , 0 );
	 //glutWireSphere(24,330,100  ); 
	 glRotatef( mass_motion_state[0]->pos_new_y/human_radie,0,1,0);
	 glCallList(human);
	 glPopMatrix();
	 RenderString( 105.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24, buf);

	 glPopMatrix();
	 glutPostRedisplay();
	 glutSwapBuffers();
	 
	 display_mpeg();

	if(newvolt < 0)
	{
		newvolt = -newvolt;
		volt = volt*1.00150050000000000000000000000000000000000000000000000000000000001;
	}
	else
	 volt =newvolt;

	 //v  = (4.23971e8)/sqrt((1.0 + sqrt(1.0 + 3.23118e20 *pow((o/frequency__),2.0)))* P);
	 r = (615.728* 1)/(R* pow(((pow(o,3.0)* P* 1)/(pow(frequency__,3.0)*pow(p,2.0) *pow(R,4.0))),1.0/4.0));
	 tk =  fabs( (integratenow(r ,  mass_motion_state[0]->pos_new_y)));

	//modifiera frekvensen så att energidensitetens radie hålls konstant. 
	if(fabs(mass_motion_state[0]->vel_new_y) > 0)
	 {
		frequency__ =6.95e-3;
	 	for(int whatfreq = 0; whatfreq < 10000000; whatfreq++)
		{
			
			 //vilken frekvens gör så att radien tillsammans med massdistansen blir en konstant, men vilken konstant? kanske 1 ?
			 r = (615.728* 1)/(R* pow(((pow(o,3.0)* P* 1)/(pow(frequency__,3.0)*pow(p,2.0) *pow(R,4.0))),1.0/4.0));
	 		 tk =  fabs( (integratenow(r ,  (mass_motion_state[0]->pos_new_y))));

	 		 frequency__ = frequency__*1.02;
	 
		         if( tk > 0.975 )
			 {
				printf("DONE: frequency = %.10f tk = %.10f \n", frequency__,tk);
	 			break;
			 } 
		}
	}

	if(volt > 0 && r > 0)
		magneticfield = ( (volt/R))/(2*M_PI*r);

	if(tk > 1 )
	{
		fieldnext =magneticfield;
	 	U = ((8.85e-12/2.0*pow((fieldnext*299792458),2.0) +1.0/(2*M_PI*4e-7)*(pow((fieldnext),2.0)))); 

	}
	else if(tk > 0  && tk < 1) 
	{
		magneticfield = ( (volt/R))/(2*M_PI*r);
		fieldnext=magneticfield*tk; 

	 	U = ((8.85e-12/2.0*pow((fieldnext*299792458),2.0) +1.0/(2*M_PI*4e-7)*(pow((fieldnext),2.0)))); 
		//printf("U = %.10f %.10f %.10f %.10f %.10f %.10f   \n",  U,volt,r,fieldnext,tk,magneticfield);
	}


	if(fabs(mass_motion_state[0]->vel_new_y) > 0)
	{ 
		for(int whatvolt = 0; whatvolt < 400000000 ; whatvolt++)
		{
	  		 magneticfield = ( (volt/R))/(2*M_PI*r);

			 fieldnext=magneticfield*tk; 
	 		 U = ((8.85e-12/2.0*pow((fieldnext*299792458),2.0) +1.0/(2*M_PI*4e-7)*(pow((fieldnext),2.0)))); 
	  
			 volt = volt +0.0000088;
 
			 acc1= 9.81-(3 - 2 *sqrt(1 + pow(U,2.0)))*9.81;  
			 //torque accelerationen som ger kroppen spin eftersom massan ändras
	  		 acc12 =  -(2*pow(mass_motion_state[0]->pos_new_y,2.0)*mass_motion_state[0]->vel_new_y)/(pow(2.0,3.0)-2*mass_motion_state[0]->pos_new_y);

			 if(acc1 > 9.8100000001 && (mass_motion_state[0]->vel_new_x*r) < 299792458)
			 {
			        printf("angular velocity*E_radius  %f ::acc12 =%.20f ::acc12  %f :: light speed in medium %f :: %f \n", mass_motion_state[0]->vel_new_x*r,acc1,acc12,v,mass_motion_state[0]->vel_new_y  );
				printf("DONE: volt, U = %.10f %.10f %.10f %.10f %.10f %.10f   \n",  U,volt,acc1,fieldnext,tk,magneticfield);
	 				break;
			 }
	                 else
	 		{
			if(stop_inc == 1)
			{
				frequency__ = frequency__/1.005;

			}
		}
	}



	object_age= 1.0 /(1.0 -pow(mass_motion_state[0]->vel_new_x*r,2.0)/pow(299792458,2.0));
	if((mass_motion_state[0]->vel_new_x*r) > 299192458)
	{
		 printf("object_age = %f velocity = %f \n", object_age,mass_motion_state[0]->vel_new_x*r);
		 stop_inc =0;
		for(;;);
	}
} 


	  gmass = 1.428e-4-(acc1/9.81)*1.428e-4; 
	  tick(createPIDController(PGAIN,IGAIN,DGAIN,PIDSOURCE,PIDOUTPUT,0.2),mass_motion_state[0]->vel_new_y);
	  printf("U = %.10f %.10f %.10f %.10f %.10f %.10f %.10f   %.10f \n",  U,volt,r, mass_motion_state[0]->pos_new_y,fieldnext,tk,acc1,mass_motion_state[0]->vel_new_x*r);

}

//integrate( ( a^2-x^2)dx)/(a^2+b^2-2*b*x)^(3/2)) ) from -a to  a
double fun_experiment1(double x,double inc_funx,double inc_funy)
{
	 double x2 = 1.0/(pow((pow((inc_funx+x),2.0) + pow(2.0/*(0.275/2.0)*/+inc_funy,2.0)),(1.0/2.0))) -pow((inc_funx+ x),2.0)*pow((pow((inc_funx+x),2.0) + (pow(2.0/*(0.275/2.0)*/+inc_funy,2.0))), -(3.0/2.0) );
 
	return x2;
}
double fun_impulse_disk_experiment2(double x,double inc_fun)
{
	 double x2 = 1.0/(pow((pow((0+x),2.0) + pow((0.1/2.0),2.0)),(1.0/2.0))) -pow((0+ x),2.0)*pow((pow((0+x),2.0) + (pow((0.1/2.0),2.0))), -(3.0/2.0) );
 
	return x2;
}
 
double fun_experiment3(double x,double Bradius, double Mdistance )
{
	double a= Bradius;
	double b= Mdistance;
 
	double  x2= (( (pow(Bradius,2.0)-pow(x,2.0) ))/pow((  pow(Bradius,2.0)+pow(Mdistance,2.0)-2*Mdistance*x),(3.0/2.0)))    ;
 
	 return x2;
}
 
double sum_integral(double lowbound, int n_total, double dx,double Bradius, double Mdistance)
{
	int n;
	double sum = 0;
	for(n = 0; n < n_total; n++)
	{
		double xi = lowbound+n*dx;
		double x = fun_experiment3(xi,Bradius,Mdistance);
		double rect_area = x*dx;
		sum += rect_area;	
	}
	return sum;

}
double integrating(double z_inc,double y_inc);
double sum_integral_double(double lowbound,double lowbound2, int n_total, double dy )
{

	int j;
	double sum_big = 0;
	for(j = 0; j < n_total; j++)
	{
		double ji = lowbound+j*dy;
		double dx =  (double)(ji - lowbound)/n_total;
		double sum_small = 0;
		 int n;
		for(n = 0; n < n_total; n++)
		{
			double xi = lowbound+dx*n;
			double x = fun_impulse_disk_experiment2(xi,0);
			double rect_area = x*dx;
			sum_small += rect_area;	
		}
		double second_rect_area = sum_small*dy;
		sum_big += second_rect_area;	
	}
	return sum_big*2;

}

double sum_integral_triple(double lowbound,double lowbound2, int n_total, double dy,double inc_funx,double inc_funy  )
{
int t = 0;
double sum_triple_big = 0;
for(t = 0; t < n_total; t++)
	{
		double ti = lowbound+t*dy;
		double dt =  (double)(ti - lowbound)/n_total;
		 
		
	int j;
	double sum_big = 0;
	for(j = 0; j < n_total; j++)
	{
		double ji = lowbound+j*dy;
		double dx =  (double)(ji - lowbound)/n_total;
		double sum_small = 0;
		 int n;
		for(n = 0; n < n_total; n++)
		{
			double xi = lowbound+dx*n;
				double x = fun_experiment1(xi,inc_funx,inc_funy);
			double rect_area = x*dx;
			sum_small += rect_area;	
		}
		double second_rect_area = sum_small*ti;
		sum_big += second_rect_area;	
	}
	
	
	double third_rect_area =   sum_big*2*dy;
	sum_triple_big += third_rect_area;	
}
	
return sum_triple_big*2;
} 

double integratenow  (double a, double b)
{
	double n = 3.0;

	double lowbound =  a;
	double hibound = - a;
	double dx =  (hibound - lowbound)/n;
	// printf("[integral dx] = [%.10f] \n",pow(a,-1.5));
	double result = sum_integral(lowbound,n, dx,a,b);

	
	//  printf("[integral result] = [%.30f] \n",result);
	return result;
	result = sum_integral_double(lowbound,hibound,n, dx);
 
	//result = sum_integral_triple(lowbound,hibound,n, dx,0);
	printf("[integral result] = [%.10f] \n",result);
	int n_inc = 0;
	while(n_inc < 100)
	{
	//	result = integrating(n_inc);
		printf("[integral result] = [%.10f] \n",result);
		n_inc++;
	}
}

void rates_dorsal ( double *t, double *f, double result[]   )
{
    result[0] =             f[3]/1.0;
    result[1] =             f[4]/1.0;
    result[2] =             f[5]/1.0;
  
    result[3] =  acc12;
    result[4] =  -9.81 +acc1;
    result[5] =  0;
}	

 
 typedef struct _thread_data_t {
  int tid;
  double stuff;
} thread_data_t;


void *thr_func(void *arg) {
  thread_data_t *data = (thread_data_t *)arg;
 
 if(data->tid == 0)
	task2();

 //if(data->tid ==1)
 //	task1();

  //pthread_exit(NULL);
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
 
