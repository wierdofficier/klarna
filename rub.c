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
int show(int *x, int len);
#define NUMEQ  6 
#define N 8
#define MAXALLOCSIZE 10000
#define LINENUMBERSTOTAL 600000000
#define NUMVAR 16
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
double solution[] = {9.8,3.7,8.89,24.79,0.62,3.7};
double solution66[] = {2.0,9.0,1.0,5.0,5.0,8.0,9.0,1.0,1.0,1.0,8.0,5.0,4.0,5.0,7.0,6.0,8.0,2.0,3.0,1.0,6.0,6.0,6.0 ,5.0,1.0,7.0 };
double solutionk[] = {1,4,27};
double solutionm[] = {9,9,6,6,8,6,9,5};
double solutiont[] = {1,1 ,1,1,1 ,1};
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
 
}

void task2()
{
	 
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
	task3();	
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
	   fp = fopen ("data16ny.txt","w");
	   onceopen =0;
	}
 	 int i; 
	 int x[N];	
	 char array[] =  { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h','i', 'j', 'k', 'l', 'm', 'n', 'o', 'p' }; 
	 for (i = 0; i < N; i++) x[i] = array[i];
 
	 /* three different methods */
	 //perm1(x, N, show);
	 perm1(x, N, show,NULL);    
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
int counter_num = 0;
 
 int  bufff1[1000];
 int  bufff2[1000];
 int  bufff3[1000];
 int  bufff4[1000];
 int  bufff5[1000];
 int  bufff6[1000];
 
 

#include <stdio.h>
#include <stdlib.h>
 int show2(int *x, int len,int *e)
{
	int i;
	 //for (i = 0; i < len; i++)
	 //	printf("%c%c", x[i], i == len - 1 ? '\n' : ' ');
        for (i = 1; i <= n * 2; i++) {
 
        	if (stack[i] == LEFT) {
            	 
			 if(i < 33  )
			{
			    //printf("%c(%c",x[kk],e[kk]);
			    sprintf(equation_,"%c(%c",x[kk],e[kk]);
			    strcpy(eq_,equation_);
			    if(i == 1)
			       fprintf (fp, "%s", (char*)(eq_+1));
			    else
			       fprintf (fp, "%s", eq_);				 
			}
		        else
			{
			//   printf("(");
			   char C = '(';
			   sprintf(eq_,"%c",C);
			   if(i == 1)
				fprintf (fp, "%s", (char*)(eq_+1));
			   else
			     	fprintf (fp, "%s", eq_);					
			}		 
        }
        	else if (stack[i] == RIGHT) {		 
		//	 printf(")%c%c",x[kk],e[kk]);
			sprintf(equation_,")%c%c",x[kk],e[kk]);
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
 
    // printf("\n");
    fprintf (fp, "\n");
}
/* print a list of ints */
int show(int *x, int len)
{
	counter_num++;
	int i;
	//for (i = 0; i < len; i++)
	//	printf("%d%c", x[i], i == len - 1 ? '\n' : ' ');

	int e[N];	
	char array[] =  { '+', '-', '*', '/', '^', '+', '-', '*', '/', '^', '+', '-', '*' , '/', '^','+' }; 
	for (i = 0; i < N; i++) e[i] = array[i];
  
	perm1(e, N, show2,x);
	//printf("count = %d \n", counter_num);
	return 1;
}
 
 
/* Boothroyd method; exactly N! swaps, about as fast as it gets */
void boothroyd(int *x, int n, int nn, int callback(int *, int))
{
	int c = 0, i, t;
	while (1) {
		if (n > 2) boothroyd(x, n - 1, nn, callback);
		if (c >= n - 1) return;
 
		i = (n & 1) ? 0 : c;
		c++;
		t = x[n - 1], x[n - 1] = x[i], x[i] = t;
		if (callback) callback(x, nn);
	}
}
 
/* entry for Boothroyd method */
void perm2(int *x, int n, int callback(int*, int))
{
	if (callback) callback(x, n);
	boothroyd(x, n, n, callback);
}
 
 /* next lexicographical permutation */
int next_lex_perm(int *a, int n) {
#	define swap(i, j) {t = a[i]; a[i] = a[j]; a[j] = t;}
	int k, l, t;
 
	/* 1. Find the largest index k such that a[k] < a[k + 1]. If no such
	      index exists, the permutation is the last permutation. */
	for (k = n - 1; k && a[k - 1] >= a[k]; k--);
	if (!k--) return 0;
 
	/* 2. Find the largest index l such that a[k] < a[l]. Since k + 1 is
	   such an index, l is well defined */
	for (l = n - 1; a[l] <= a[k]; l--);
 
	/* 3. Swap a[k] with a[l] */
	swap(k, l);
 
	/* 4. Reverse the sequence from a[k + 1] to the end */
	for (k++, l = n - 1; l > k; l--, k++)
		swap(k, l);
	return 1;
#	undef swap
}
 
void perm1(int *x, int n, int callback(int *, int, int *),int *e )
{
	do {
		if (callback) callback(x, n,e);
	} while (next_lex_perm(x, n));
}

int showrubics(int *a, int len,int *e, int what)
{
	counter_num++;
	int i;
	//  for (i = 0; i < len; i++)
	 //	printf("%d%c", a[i], i == len - 1 ? '\n' : ' ');
 	
	if(what == 0)
	{
	for (i = 0; i < len; i++)
		 bufff1[i] = a[i];
	}
	if(what == 1)
	{
	for (i = 0; i < len; i++)
		 bufff2[i] = a[i];
	}
	if(what == 2)
	{
	for (i = 0; i < len; i++)
		 bufff3[i] = a[i];
	}
	if(what == 3)
	{
	for (i = 0; i < len; i++)
		 bufff4[i] = a[i];
	}
	if(what == 4)
	{
	for (i = 0; i < len; i++)
		 bufff5[i] = a[i];
	}
	if(what == 5)
	{
	for (i = 0; i < len; i++)
		 bufff6[i] = a[i];
	}
	return;
	//printf("count = %d \n", counter_num);
	return 1;
}



int perm1_rubics(int *x, int n, int callback(int *, int, int *,int),int *e, int what )
{
	  next_lex_perm(x, n) ;
		if (callback) callback(x, n,e,what);	
}

int test()
{
	int i; 
	int x[N];	
	char array[] =  { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' }; 
	 for (i = 0; i < N; i++) x[i] = array[i];
 
	/* three different methods */
	//perm1(x, N, show);
	perm1(x, N, show ,NULL);
	//perm3(x, N, show);
 
	return 0;
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
int countperm = 0;
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
        char* filename = "data8ny.txt";
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
/*
	char a1[] =    "11122222"; 
	char a2[] =    "11222222";  
	char a3[] =    "11111122"; 
	char a4[] =    "11122222"; 
	char a5[] =    "01122222"; 
	char a6[] =    "11112222"; */
  	printf("done\n");
	double inc  = 0;
	int counter = 0;
	while(line_size >= 0 && line_count < LINENUMBERSTOTAL)
	{
//printf("done\n");
  
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
	once_perm = 0;
	line_count++;	 
	iterator++;
	isbreaked = 0;	
	randme = iterator;
if(line_count > 0)
{
	eqline = 0;
	int xxxc = -1;
       	for(int llll = 0; llll < 3360          ; llll++)
	{ 
 countperm++;
if(once_perm == 0)
{
		 	int i; 
			int x[N];	
	        	/*int a1[] =   {1,1,1,2,2,2,2,2}; 
			int a2[] =   {1,1,2,2,2,2,2,2};  
			int a3[] =   {1,1,1,1,1,1,2,2}; 
			int a4[] =  {1,1,1,2,2,2,2,2}; 
			int a5[] =  {0,1,1,2,2,2,2,2}; 
			int a6[] =  {1,1,1,1,2,2,2,2}; */
 
	/*int a1[]  =  {1 ,  1 ,1 ,  2 ,    3,   4, 5, 6,  7 ,      8,          9 ,  6371000 ,      6371000,          6371000 , abs(pow(6371000/1000,2)),abs(pow(6371000/1000,2))  };
	int a2[] =   {1 ,  1 ,1 ,  2 ,    3,   4, 5, 6,  7 ,      8,          9 ,  3389500 ,      3389500,          3389500 , abs(pow(3389500/1000,2)),abs(pow(3389500/1000,2))  };
	int a3[]  =   {1 ,  1 ,1 ,  2 ,    3,   4, 5, 6,  7 ,      8,          9 ,  6048800 ,      6048800,          6048800 , abs(pow(6048800/1000,2)),abs(pow(6048800/1000,2))  };
	int a4[] =  {1 ,  1 ,1 ,  2 ,    3,   4, 5, 6,  7 ,      8,          9 ,  25362000 ,      25362000,          25362000 , abs(pow(25362000/1000,2)),abs(pow(25362000/1000,2))  }; 
	int a5[]  =   {1 ,  1 ,1 ,  2 ,    3,   4, 5, 6,  7 ,      8,          9 ,  1188300 ,      1188300,          1188300 , abs(pow(1188300/1000,2)),abs(pow(1188300/1000,2))  };
	int a6[] =   {1 ,  1 ,1 ,  2 ,    3,   4, 5, 6,  7 ,      8,          9 ,  2439700 ,      2439700,          2439700 , abs(pow(2439700/1000,2)),abs(pow(2439700/1000,2))  };
*/

	int a1[]  =  {1 ,  1 ,   2,  abs(sqrt(6371000)),   6371000 ,      6371000,          6371000 ,   abs(pow(6371000/1000,2))   };
	int a2[] =   {1 ,  1 ,   2,  abs(sqrt(3389500)),   3389500,       3389500,         3389500,     abs(pow(3389500/1000,2))   };	 
	int a3[]  =  {1 ,  1 ,   2,  abs(sqrt(6048800)),   6048800,       6048800 ,         6048800,    abs(pow(6048800/1000,2))   };
	int a6[] =   {1 ,  1,    2, abs(sqrt(25362000)),  25362000,     25362000,        25362000,     abs(pow(25362000/1000,2))  };	 
	int a4[]  =  {1 ,  1,    2,  abs(sqrt(1188300)),   1188300 ,      1188300,        1188300 ,   abs(pow(1188300/1000,2))   };
	int a5[] =   {1 ,  1 ,   2,  abs(sqrt(2439700)),   2439700,       2439700,       2439700,     abs(pow(2439700/1000,2))   };
			for (i = 0; i < N; i++) x[i] = a1[i];
		        perm1_rubics(x, N, showrubics,NULL,0);
			for (i = 0; i < N; i++) x[i] = a2[i];
			 perm1_rubics(a2, N, showrubics,NULL,1);
			for (i = 0; i < N; i++) x[i] = a3[i];
		        perm1_rubics(a3, N, showrubics,NULL,2);
			for (i = 0; i < N; i++) x[i] = a4[i];
			perm1_rubics(a4, N, showrubics,NULL,3);
			for (i = 0; i < N; i++) x[i] = a5[i];
		        perm1_rubics(a5, N, showrubics,NULL,4);
			for (i = 0; i < N; i++) x[i] = a6[i];
			perm1_rubics(a6, N, showrubics,NULL,5); 
once_perm = 1;
}	 
else
{
			int i; 
			int x[N];
			for (i = 0; i < N; i++) x[i] = bufff1[i];
		        perm1_rubics(x, N, showrubics,NULL,0);
			for (i = 0; i < N; i++) x[i] = bufff2[i];
			 perm1_rubics(x, N, showrubics,NULL,1);
			for (i = 0; i < N; i++) x[i] = bufff3[i];
		        perm1_rubics(x, N, showrubics,NULL,2);
			for (i = 0; i < N; i++) x[i] = bufff4[i];
			perm1_rubics(x, N, showrubics,NULL,3);
			for (i = 0; i < N; i++) x[i] = bufff5[i];
		        perm1_rubics(x, N, showrubics,NULL,4);
			for (i = 0; i < N; i++) x[i] = bufff6[i];
			perm1_rubics(x, N, showrubics,NULL,5); 

}		 
 		 double slump1  = 0.00001 ;	
		 a[0] = 0.000001;
		for(int kkk = 0; kkk < NUMVAR; kkk++)
		{ 
		  VARA1[0][kkk] =(double)bufff1[kkk] ;
		  VARA1[0][kkk] = VARA1[0][kkk] + slump1;	
		  	 		
		  VARA1[1][kkk] = bufff2[kkk]  ;
		  VARA1[1][kkk] = VARA1[1][kkk] + slump1;	
		  
		  VARA1[2][kkk] = bufff3[kkk]  ;
		  VARA1[2][kkk] = VARA1[2][kkk] + slump1;

		  VARA1[3][kkk] = bufff4[kkk]  ;
		  VARA1[3][kkk] = VARA1[3][kkk] + slump1;

		  VARA1[4][kkk] = bufff5[kkk] ;
		  VARA1[4][kkk] = VARA1[4][kkk] + slump1;

		  VARA1[5][kkk] = bufff6[kkk];
		  VARA1[5][kkk] = VARA1[5][kkk] + slump1;	
		  slump1 = slump1 - 0.00001;
		// printf("%d", bufff1[kkk]);
		/* VARA1[7][kkk] =a7[slump1];
		 VARA1[8][kkk] =a8[slump1];
		 VARA1[9][kkk] =a9[slump1];
		 VARA1[10][kkk] =a10[slump1]; 
 		 VARA1[11][kkk] =a11[slump1];
		 VARA1[12][kkk] =a12[slump1]; */
		}
 
	 	//printf("\n");
		//if(newloopnew == 1)
		//break;
newloopnew = 0;
for(int xxxx = 0; xxxx < 1000          ; xxxx++)
	{ 			 
	 	 for(int kkk = 0; kkk < NUMVAR; kkk++)
		  { 

   	
		for(int oooo = 0; oooo < NUMEQ; oooo++)
		{
		 a[oooo] =  a[oooo] + 0.000001;		
		 VARA1[oooo][kkk] += a[oooo]; 
		new_str  = fill_equation(line_buf,VARA1 ,oooo,new_str,strnew);
		strcpy(NEWSTR[oooo],new_str);
		
		result[oooo][0] = te_interp(NEWSTR[oooo] , 0);

		xxxc++;

		  if(kkk != xxxc)
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
		}  

}
for(int oooo = 0; oooo < NUMEQ; oooo++)
		{
		if(newloop == 0  || isnan(result[oooo][kkk]) == 0  &&  (result[oooo][kkk] < 25.0) && result[oooo][kkk] > 0.4 && result[oooo][kkk] != INFINITY && result[oooo][kkk] != NAN && result[oooo][kkk] != -NAN)
		{
		if(isnan(result[oooo][kkk]) == 0) 
		{
		if(result[oooo][kkk] != INFINITY && result[oooo][kkk] > 0.4 && result[oooo][kkk])
		{
			if(result[oooo][kkk] > 0.4)
			if(result[oooo][kkk] < 25.0)
				check_eq(oooo,0,NEWSTR ,eqline);
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
}	
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

 //if(countperm % 1000 == 0)
	  for(int oooo = 0; oooo < NUMEQ; oooo++)
	   printf("\ncountperm: %d eq: ="CYN" %s"RESET" "WHT" solution: "YEL" %f"RESET" "WHT" EQ linenr: "CYN" %d"RESET" "WHT" "RESET"",countperm,resultstr[oooo] , result[oooo][kkk],randme); 	
//printf("\n");
 	   if((result[0][kkk]) < solution[0]*1.02&& ((result[0][kkk])) > solution[0]*0.98)  
	   if((result[1][kkk]) < solution[1]*1.02&& ((result[1][kkk])) > solution[1]*0.98)
	    if((result[2][kkk]) < solution[2]*1.02&& ((result[2][kkk])) > solution[2]*0.98) 
 	   if((result[3][kkk]) < solution[3]*1.02&& ((result[3][kkk])) > solution[3]*0.98)  
	 //  if((result[4][kkk]) < solution[4]*1.02&& ((result[4][kkk])) > solution[4]*0.98)
 	 // if((result[5][kkk]) < solution[5]*1.02&& ((result[5][kkk])) > solution[5]*0.98)    
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
for(;;);

	}
}
