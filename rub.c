#include "tinyexpr.h"
#include <stdlib.h>
#include <stdio.h> 
#include <stdlib.h> 
#include<time.h> 
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <complex.h>
#include <stdio.h>
#include "beamfreq.h"
#include "afgan2.h"
#include <GL/gl.h>
#include <GL/glut.h>
extern int main_cube(int argc, char **argv);
#define NUMEQ  6 
#define MAXALLOCSIZE 10000
#define LINENUMBERSTOTAL 600000000
#define NUMVAR 8
#define MAXBUFLEN 44*20000000
#define NUM_THREADS 3
#define MAX_PAIRS   16
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m" 
char search[1000][1000] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q"};
double solutionkk[] ={160.72,79.99,110.35,337.10,13.21,0.44};
double solution2[] = {30.0,10.0,20.0,60.0,1.0,25.0};
double solution3[] = {2, 1  ,  3,1.5,4.2,1.4 };
double solutiong[] = {9.8,3.7,8.89,24.79,0.62,8.69};
double solution66[] = {2.0,9.0,1.0,5.0,5.0,8.0,9.0,1.0,1.0,1.0,8.0,5.0,4.0,5.0,7.0,6.0,8.0,2.0,3.0,1.0,6.0,6.0,6.0 ,5.0,1.0,7.0 };
double solutionk[] = {1,4,27};
double solutionm[] = {9,9,6,6,8,6,9,5};
double solution[] = {13,14 ,10,13,12 ,12};
double a[NUMEQ+1];
#define AMP 10 
int bufcnt = 0;
char BIGBUF[1000][1000][3];
char BIGBUF2[1000][1000][3];
char BIGBUF3[1000][1000][3];
double _count = 0;
int iterator =  0;
int isbreaked = 0;
void task1()
{
	char e[] = "abcdef"; 
        permute_number(e, 0, NUMVAR-1,NULL);
}

void task2()
{
	char e[] = "+-*/^+-*/^+"; 
        permute_sign(e, 0, 10,NULL);
}


void task3()
{
while(1)
    matching_parenthesis_pairs(0, 0);

}
typedef struct _thread_data_t {
  int tid;
  double stuff;
} thread_data_t;


void *thr_func(void *arg) {
  thread_data_t *data = (thread_data_t *)arg;
 
 if(data->tid == 0)
	task1();	
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

typedef enum _PARENTHESIS {                   
    NONE,
    LEFT,
    RIGHT
} PARENTHESIS;

int n;
PARENTHESIS stack[MAX_PAIRS * 2 + 1] = {NONE, }; 
int ind;                                         
FILE * fp;
 
int onceopen = 1;
int kk = 0;
char equation_[1000];
char eq_[1000];
 
 void print_stack_(char *a,char *var)
{
	if(onceopen == 1)
	{	     
	   fp = fopen ("data6.txt","w");
	   onceopen =0;
	}
  
        int i;
        for (i = 1; i <= n * 2; i++) {
 
        	if (stack[i] == LEFT) {
             
			 if(i < 33  )
			{
			    //printf("%c(%c",a[kk],var[kk]);
			    sprintf(equation_,"%c(%c",a[kk],var[kk]);
 
			    strcpy(eq_,equation_);
			    if(i == 1)
			       fprintf (fp, "%s", (char*)(eq_+1));
			    else
			       fprintf (fp, "%s", eq_);				 
			}
		        else
			{
			   //printf("(");
			   char C = '(';
			   sprintf(eq_,"%c",C);
			   if(i == 1)
				fprintf (fp, "%s", (char*)(eq_+1));
			   else
			     	fprintf (fp, "%s", eq_);					
			}		 
        }
        	else if (stack[i] == RIGHT) {		 
			//printf(")%c%c",a[kk],var[kk]);
			sprintf(equation_,")%c%c",a[kk],var[kk]);
			fprintf (fp, "%s", equation_);		 	  
       		 }
		else {
		    //printf("ERROR!!!!\n");
		    // exit(-1);
		}
	kk++;
	if(kk >(NUMVAR-1))
	{
		kk  = 0; 
	}
    }
 
    //printf("\n");
    fprintf (fp, "\n");
}

 
void matching_parenthesis_pairs(int left_in_stack, int right_in_stack,char *a,char *var)
{
    if (left_in_stack < right_in_stack) {
        return;
    }
 
    if (ind == n * 2 + 1)
    {
        print_stack_(a,var);
        return;
    }

    if (left_in_stack < n) {
        stack[ind++] = LEFT;
        matching_parenthesis_pairs(left_in_stack + 1, right_in_stack,a,var);
        ind--;
    }
    if (right_in_stack < left_in_stack) {
        stack[ind++]= RIGHT;
        matching_parenthesis_pairs(left_in_stack, right_in_stack + 1,a,var);
        ind--;
    }
}
 
 
void swap_num (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swap_sign (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute_number(char *a, int i, int n,char *var)
{
   int j;
   if (i == n) 
	{
 	 //printf("%c%c%c%c%c%c%c%c%c%c\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
	 char e[] = "+-*/^+"; 
	 permute_sign(e, 0, NUMVAR-1,a);
 
	}
  
   else
   {
        for (j = i; j <= n; j++)
       {
          swap_num((a+i), (a+j));
          permute_number(a, i+1, n,var);
          swap_num((a+i), (a+j)); 
       }
   }
}
 char  bufff1[1000];
 char  bufff2[1000];
 char  bufff3[1000];
 char  bufff4[1000];
 char  bufff5[1000];
 char  bufff6[1000];
char * permute_number_rubics(char *a, int i, int n,char *var, int what)
{
   int j;
   if (i == n) 
	{
 	 // printf("%s\n",a );
	 //char *buf = malloc(100);
	if(what == 0)
	 memcpy(bufff1,a,strlen(a));
	if(what == 1)
	memcpy(bufff2,a,strlen(a));	
	if(what == 2)
	memcpy(bufff3,a,strlen(a));
	if(what == 3)
	memcpy(bufff4,a,strlen(a));
	if(what == 4)
	memcpy(bufff5,a,strlen(a));
	if(what == 5)
	memcpy(bufff6,a,strlen(a));
	return;
	// return bufff;
 
	}
  
   else
   {
        for (j = i; j <= n; j++)
       {
          swap_num((a+i), (a+j));
          permute_number_rubics(a, i+1, n,var,what);
          swap_num((a+i), (a+j)); 
       }
   }
}


void permute_sign(char *a, int i, int n,char *var)
{
   int j;
   if (i == n) 
	{
 	  //printf("%c%c%c%c%c%c%c%c%c%c\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
 	  matching_parenthesis_pairs(0, 0,a,var);
	}
   else
   {
        for (j = i; j <= n; j++)
       {
          swap_sign((a+i), (a+j));
          permute_sign(a, i+1, n,var);
          swap_sign((a+i), (a+j));  
       }
   }
}
// fork from https://github.com/irl/la-cucina/blob/master/str_replace.c
char* str_replace(char* string, const char* substr, const char* replacement) {
	char* tok = NULL;
	char* newstr = NULL;
	char* oldstr = NULL;
	int   oldstr_len = 0;
	int   substr_len = 0;
	int   replacement_len = 0;

	newstr = strdup(string);
	substr_len = strlen(substr);
	replacement_len = strlen(replacement);

	if (substr == NULL || replacement == NULL) {
		return newstr;
	}

	while ((tok = strstr(newstr, substr))) {
		oldstr = newstr;
		oldstr_len = strlen(oldstr);
		newstr = (char*)malloc(sizeof(char) * (oldstr_len - substr_len + replacement_len + 1));

		if (newstr == NULL) {
			free(oldstr);
			return NULL;
		}

		memcpy(newstr, oldstr, tok - oldstr);
		memcpy(newstr + (tok - oldstr), replacement, replacement_len);
		memcpy(newstr + (tok - oldstr) + replacement_len, tok + substr_len, oldstr_len - substr_len - (tok - oldstr));
		memset(newstr + oldstr_len - substr_len + replacement_len, 0, 1);

		free(oldstr);
	}
	//free(string);
	return newstr;
}
double f = 0;
int c = 0;
char   **new_str;
char   *strnew;
int newloop = 0;

char * fill_equation(char * line_buf, double ** data , int lll ,char *str, char *str2 )
{

	strcpy(str, line_buf);
	char buf1[1000];

	for(int ll = 0; ll < 8; ll++)
	{			 			
		char * ptr = strstr(str, search[ll]);
		if (ptr != NULL) /* Substring found */
		{
			//printf("%s contains '%s'\n", new_str, search[ll]);												 
			sprintf(buf1,"%f" ,data[lll][ll]  );							 
			str2= str_replace(str,search[ll],buf1);	 
			strcpy(str,str2); 	
			free(str2);		 
		}
	} 
return str ;
}

int randme;
double   **result ;
int newloopnew = 0;
int eqline;
extern GLfloat angle, fAspect, cube_size;
extern  GLint rot_x, rot_y, crement, x_0, x_k, y_0, y_k, z_0, z_k, gap, gap_crement;

 int once_perm = 0;
// draw function
void draw_func(void)
{


        printf("Number of parenthesis pairs (max %d): ", MAX_PAIRS);
        scanf("%d", &n);
	ind = 1;
        srand(time(NULL));
	// multitasks();

	// for(;;);
	FILE *fp5;	
        char* filename = "data8.txt";
        fp5 = fopen(filename, "r");
	ind = 1;
        if (fp5 == NULL  ){
        	printf("Could not open file %s",filename);
        	return 1;
        }

	strnew = malloc(20000);
	 new_str = malloc(20000);

 	char * line_buf = NULL;
 	size_t line_buf_size = 0;
	int line_count = 0;
	ssize_t * line_size;

	line_size = malloc(   MAXBUFLEN );	 
	iterator = 0;
   
 	double **VARA1;
	VARA1 = malloc( MAXALLOCSIZE*100);
	 
	for(int iiiii=0; iiiii<20000*1; iiiii++)
		VARA1[iiiii] =  malloc(MAXALLOCSIZE*100);


	char **NEWSTR = malloc( MAXALLOCSIZE*100);
	 
	for(int iiiii=0; iiiii<20000*1; iiiii++)
		NEWSTR[iiiii] =  malloc(MAXALLOCSIZE*100);

	printf("done\n");
 	double  **earth_i ;
	earth_i = malloc( MAXALLOCSIZE*100);
		printf("done\n"); 
	for(int iiiii=0; iiiii<20000*1; iiiii++)
		earth_i[iiiii] =  malloc(MAXALLOCSIZE*100);
	printf("done\n");
	result = malloc( MAXALLOCSIZE*100);
		printf("done\n"); 
	for(int iiiii=0; iiiii<MAXALLOCSIZE*10; iiiii++)
		result[iiiii] =  malloc(MAXALLOCSIZE*100);
	printf("done\n");
	for(int aa = 0; aa < NUMEQ; aa++)
	{
	for(int bb = 0; bb < NUMEQ; bb++)
	{
	 	if(bb != aa)
			earth_i[aa][bb] = solution[aa]/solution[bb];
	//printf("aa =%d \n", aa);	
	} 
	}
/* double a1[] =   {2,1,2,1,1,2,2,2}; 
double a2[] =   {2,2,2,2,2,1,2,1};  
double a3[] =   {1,1,1,1,2,2,1,1}; 
double a4[] =  {2,2,1,2,2,2,1,1}; 
double a5[] =  {1,2,1,0,2,2,2,2}; 
double a6[] =  {1,2,2,1,1,2,2,1}; */



 char a1[] =   "21211222"; 
char a2[] =    "22222121";  
char a3[] =    "11112211"; 
char a4[] =    "22122211"; 
char a5[] =    "12102222"; 
char a6[] =    "12211221"; 
  	printf("done\n");
	double inc  = 0;
	int counter = 0;
	while(line_size >= 0 && line_count < LINENUMBERSTOTAL)
	{
//printf("done\n");
 	/* 
	double a1[]  =  {6371000.0 ,  6371000.0 ,     6371000,   6371000.0 ,     6371000,   6371000.0,     6371000.0 ,  6371000.0,  6371000.0 ,     6371000,   6371000.0,     6371000.0 ,  6371000.0,  6371000.0 ,     6371000.0 ,  6371000.0,   };
	double a2[] =   {3389500.0 ,  3389500.0 ,     3389500,   3389500.0,       3389500,    3389500,   3389500.0,   3389500.0 ,  3389500.0 ,       3389500,    3389500,   3389500.0,   3389500.0 ,  3389500.0 ,   3389500.0,   3389500.0  };	 
	double a3[]  =  {6051800.0 ,  6051800.0 ,    6051800,   6051800.0,       6051800 ,   6051800.0,     6051800.0 ,  6051800.0, 6051800.0  ,      6051800 ,   6051800.0,     6051800.0 ,  6051800.0, 6051800.0 ,     6051800.0 ,  6051800.0     };
	double a6[] =   {2439700.0 ,  2439700,     2439700,   2439700.0,       2439700.0,   2439700.0,     2439700.0,   2439700.0 , 2439700.0 ,       2439700.0,  2439700.0,     2439700.0,   2439700.0 , 1.0,     2439700.0,   2439700.0  };	 
	double a4[]  =  {25362000.0 ,25362000,    25362000,   25362000.0 ,     25362000.0,    25362000.0 ,    25362000.0 ,  25362000.0,   25362000.0 ,   25362000.0,   25362000.0 ,    25362000.0 ,  25362000.0,   25362000.0,    25362000.0 ,  25362000.0   };
	double a5[] =   {1188300.0 ,  1188300 ,     1188300,   1188300.0,       1188300.0,   1188300.0,     1188300.0,   1188300.0 ,  1188300.0 ,       1188300.0,   1188300.0,     1188300.0,   1188300.0 ,  1188300.0 ,     1188300.0,   1188300.0  };	*/
//             dt,lt,ht,d1,d2,lt1,lt2,lt3,ht1,ht2,h3
//printf("done\n");
/*double a1[] = {1,2,2,1,1,2,2,2};  
double a2[] = {1,2,2,2,2,2,2,0};
double a3[] = {2,2,2,1,1,2,2,1};
double a4[] = {1,1,1,2,1,1,1,1};
double a5[] = {2,1,2,2,1,2,2,1};
double a6[] = {2,2,1,1,1,2,2,2};*/
/*
double a1[] =  {2,1,2,0,2,1,2,1};  
double a2[] =  {2,2,2,1,2,2,1,2};
double a3[] =  {1,2,2,2,2,2,2,2};
double a4[] =  {2,2,2,2,1,2,1,2};
double a5[] =  {1,2,1,1,2,2,1,2};
double a6[] =  {2,2,2,1,1,1,1,2};
*/





	newloopnew = 0;
	line_size[line_count] = getline(  &line_buf  , &line_buf_size, fp5);	
if(line_count > 0)
{
	 
	eqline = 0;
	int xxxc = -1;
       	for(int llll = 0; llll < 1         ; llll++)
	{ 
		//char * BUFF;
		if(once_perm == 0)
		{
       			permute_number_rubics(a1, 0, NUMVAR-1,NULL,0);
			permute_number_rubics(a2, 0, NUMVAR-1,NULL,1);
			permute_number_rubics(a3, 0, NUMVAR-1,NULL,2);
			permute_number_rubics(a4, 0, NUMVAR-1,NULL,3);
			permute_number_rubics(a5, 0, NUMVAR-1,NULL,4);
			permute_number_rubics(a6, 0, NUMVAR-1,NULL,5);
			once_perm = 1;
		}
		else
		{
		        permute_number_rubics(a1, 0, NUMVAR-1,NULL,0);
			permute_number_rubics(a2, 0, NUMVAR-1,NULL,1);
			permute_number_rubics(a3, 0, NUMVAR-1,NULL,2);
			permute_number_rubics(a4, 0, NUMVAR-1,NULL,3);
			permute_number_rubics(a5, 0, NUMVAR-1,NULL,4);
			permute_number_rubics(a6, 0, NUMVAR-1,NULL,5);
		}
 
		a[0] = 0.000001;
		for(int kkk = 0; kkk < NUMVAR; kkk++)
		{ 
		   
		  int slump1 =  kkk;		
		  VARA1[0][kkk] =51-bufff1[kkk]-'\0';
		  a1[kkk] = 51 - VARA1[0][kkk] - '\0';
	 		
		 VARA1[1][kkk] =51-bufff2[kkk]-'\0';
		  a2[kkk] = 51 - VARA1[1][kkk] - '\0';

		 VARA1[2][kkk] =51-bufff3[kkk]-'\0';
		  a3[kkk] = 51 - VARA1[2][kkk] - '\0';

		 VARA1[3][kkk] =51-bufff4[kkk]-'\0';
		  a4[kkk] = 51 - VARA1[3][kkk] - '\0';

		 VARA1[4][kkk] =51-bufff5[kkk]-'\0';
		  a5[kkk] = 51 - VARA1[4][kkk] - '\0';

		 VARA1[5][kkk] =51-bufff6[kkk]-'\0';
		  a6[kkk] = 51 - VARA1[5][kkk] - '\0';

		 //printf("%f", VARA1[3][kkk]);
		/* VARA1[7][kkk] =a7[slump1];
		 VARA1[8][kkk] =a8[slump1];
		 VARA1[9][kkk] =a9[slump1];
		 VARA1[10][kkk] =a10[slump1]; 
 		 VARA1[11][kkk] =a11[slump1];
		 VARA1[12][kkk] =a12[slump1]; */
		}
	 //	printf("\n");
		if(newloopnew == 1)
		break;			 
		for(int kkk = 0; kkk < NUMVAR; kkk++)
		{ 
		for(int oooo = 0; oooo < NUMEQ; oooo++)
		{
		a[oooo] =  a[oooo] + 0.000001;		
		VARA1[oooo][kkk] += a[oooo]; 
		new_str  = fill_equation(line_buf,VARA1 ,oooo,new_str,strnew);
		strcpy(NEWSTR[oooo],new_str);
		
		result[oooo][kkk] = te_interp(NEWSTR[oooo] , 0);

		xxxc++;

		/*if(kkk != xxxc)
		{							
		int cc = 0;
 
			for(int llllll = 0; llllll < NUMEQ; llllll++)
			{ 
			if(llllll != oooo)
			{
				double diff = result[oooo][kkk]/result[llllll][kkk-1];
					 
				double ratio = earth_i[oooo][cc];
				//printf("ratio = %f diff = %f \n", ratio,diff);		 		
				if(diff > (ratio))	
				{
					VARA1[llllll][kkk]  += a[oooo];	
						
				}
				else
				{
					VARA1[llllll][kkk]  -= a[oooo];
					 									
				}					
			}
			cc++;		
			}				 
			 cc = 0;
		}*/



		if(newloop == 0  || isnan(result[oooo][kkk]) == 0  &&  (result[oooo][kkk] < 16.0) && result[oooo][kkk] > -1.0 && result[oooo][kkk] != INFINITY && result[oooo][kkk] != NAN && result[oooo][kkk] != -NAN)
		{
		if(isnan(result[oooo][kkk]) == 0) 
		{
		if(result[oooo][kkk] != INFINITY && result[oooo][kkk] > -1.0 && result[oooo][kkk])
		{
			if(result[oooo][kkk] < 16.0)
				check_eq(oooo,kkk,NEWSTR ,eqline);
			else
			{
			newloopnew = 1;
			break;
			}			
		}
		else
		{
		newloopnew = 1;
		break;
		}
		}
		else
		{
		newloopnew = 1;
		break;
		}
		}
		else
		{
		newloopnew = 1;
		break;
		}
		
		if(newloopnew == 1)
				break;	
	if(xxxc >NUMVAR)
		xxxc = -1;		
	 } 
}
 if(newloopnew == 1)
		break;	

}
 }	
line_count++;	 
iterator++;
isbreaked = 0;	
randme = iterator;





}

int mainold(int argc, char **argv)
{
main_cube(argc,argv);
							
}
	for(int i = 0; i < 25; i++)
	{
		printf("eq[%d] %s = %f\n",i,BIGBUF[i][0],te_interp(BIGBUF[i][0], 0));
		//printf("%s\n", BIGBUF2[i][1]);
		//printf("%s\n", BIGBUF3[i][2]);
	}
  //fclose(fp5);

    return 0;
}

void check_eq(int oooo,int kkk, char **resultstr,int eqline_)
{	

for(int oooo = 0; oooo < NUMEQ; oooo++)
printf("\neqline: %d eq: ="CYN" %s"RESET" "WHT" solution: "YEL" %f"RESET" "WHT" EQ linenr: "CYN" %d"RESET" "WHT" "RESET"",eqline,resultstr[oooo] , result[oooo][kkk],randme);	
 	  if((result[0][kkk]) < solution[0]*1.001&& ((result[0][kkk])) > solution[0]*0.999)  
	 if((result[1][kkk]) < solution[1]*1.001&& ((result[1][kkk])) > solution[1]*0.999)
	 if((result[2][kkk]) < solution[2]*1.001&& ((result[2][kkk])) > solution[2]*0.999)    
{
eqline++;
   int x = -cube_size, y = -cube_size, z = -cube_size;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // reset transformations
  glLoadIdentity();

  // set camera position
  set_camera();

  // apply visualization transformations
  glRotatef(rot_x, 1.0, 0.0, 0.0); // rotate in y axis
  glRotatef(rot_y, 0.0, 1.0, 0.0); // rotate in x axis

  for(int i = 0; i < 3; ++i) // step through x axis
    for(int j = 0; j < 3; ++j) // step through y axis
      for(int k = 0; k < 3; ++k) { // step through z axis

	// draw a single cube
	draw_cube(i, j, k);

      }

  // flush opengl commands
  glutSwapBuffers();	
	printf("\n\n");
for(int oooo = 0; oooo < NUMEQ; oooo++)
	 printf("\neqline: %d eq: ="CYN" %s"RESET" "WHT" solution: "YEL" %f"RESET" "WHT" EQ linenr: "CYN" %d"RESET" "WHT" "RESET"",eqline,resultstr[oooo] , result[oooo][kkk],randme);							 
	}
}
