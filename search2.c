#include "tinyexpr.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <complex.h>
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
double _count = 0;
int iterator = 0;
int isbreaked = 0;
void task1()
{

	char e[] = "abcdefghijk"; 
          permute_number(e, 0, 10,NULL);

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
char equation_[100011];
char eq_[100110];
char CHARACTER[1110000];
char CHARACTER_2[1001100];
 void print_stack_(char *a,char *var)
{
	if(onceopen == 1)
	{	     
	   fp = fopen ("datah.txt","w");
	   onceopen =0;
	}

        int i;
        for (i = 1; i <= n * 2; i++) {
 
        	if (stack[i] == LEFT) {
             
			 if(i < 33  )
			{
			 //  printf("%c(%c",a[kk],var[kk]);
			    sprintf(equation_,"%c(%c",a[kk],var[kk]);
 
			    strcpy(eq_,equation_);
			    if(i == 1)
			       fprintf (fp, "%s", (char*)(eq_+1));
			    else
			       fprintf (fp, "%s", eq_);				 
			}
			 else
			 {
			  // printf("(");
			   char C = '(';
			   sprintf(eq_,"%c",C);
			   	if(i == 1)
				  fprintf (fp, "%s", (char*)(eq_+1));
				else
			     	  fprintf (fp, "%s", eq_);					
			}		 
        }
        	else if (stack[i] == RIGHT) {		 
			//    printf(")%c%c",a[kk],var[kk]);
			    sprintf(equation_,")%c%c",a[kk],var[kk]);
			    fprintf (fp, "%s", equation_);		 	  
       		 }
		else {
		    //printf("ERROR!!!!\n");
		   // exit(-1);
		}
	kk++;
	if(kk > 10)
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
	 char e[] = "+-*/^+-*/^+"; 
	 permute_sign(e, 0, 10,a);
 
	}
  
   else
   {
        for (j = i; j <= n; j++)
       {
          swap_num((a+i), (a+j));
          permute_number(a, i+1, n,var);
          swap_num((a+i), (a+j)); //backtrack
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
          swap_sign((a+i), (a+j)); //backtrack
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
char   *new_str;
char   *strnew;
char * fill_equation(char * line_buf, double   **data )
{
			char buf[1000];
			strcpy(new_str, line_buf);
 
			 for(int lll = 0; lll < 3; lll++)
			 {
				for(int ll = 0; ll < 12; ll++)
				{	
 			
					 char * ptr = strstr(new_str, search[ll]);
				 
					 if (ptr != NULL) /* Substring found */
					 {
						//printf("%s contains '%s'\n", new_str, search[ll]);
						 
						sprintf(buf,"%f" ,data[lll][ll] );
					 
						strnew = str_replace(new_str,search[ll],buf);
						 
				 		strcpy(new_str,strnew);
						 
						free(strnew);
				 
 					}
				 }
	}
return new_str;
}

int main()
{
    printf("Number of parenthesis pairs (max %d): ", MAX_PAIRS);
    scanf("%d", &n);
    ind = 1;
    //srand(time(NULL));

while(1)
{
	_count = _count + 1;
	//  multitasks();

	//    for(;;);
 
        FILE *fp5;
 
        char str[1000000];
 
        char* filename = "datah.txt";
        fp5 = fopen(filename, "r");
 

        if (fp5 == NULL  ){
        	printf("Could not open file %s",filename);
        	return 1;
       }
  
	strnew  = malloc(1000);
 	new_str  = malloc(1000);
 
 
 
	#include <stdio.h>
	#define MAXBUFLEN 44*20000000 
 
 	char * line_buf = NULL;

 	size_t line_buf_size = 0;
	int line_count = 0;
	ssize_t * line_size;

 
	line_size = malloc(   MAXBUFLEN );
 
	double complex_solution2;
	int clocksec[1000000];
	int seconds = 0;
	 
	iterator = 0;
  
  	double increaser = 0.00001;
 
 
	double **VARA1;


	VARA1 = malloc( 10000*32);
	 
	int iiiii;

	for(int iiiii=0; iiiii<10000*1; iiiii++)
	VARA1[iiiii] =  malloc(32);
 
	VARA1[0][0] += increaser;
	VARA1[1][0] += increaser;
	VARA1[2][0] += increaser;
	double   result[20][1000];
	 

 	double a = 0.1;
	while(line_size >= 0 && line_count < 600000000)
	{
 		//leta upp en ekvation
		line_size[line_count] = getline(  &line_buf  , &line_buf_size, fp5);		 
		line_count++;
		double a1[] = {1 ,  465.1 ,    1,   6371000 ,  6.67e-11 ,   0.306, 1, 0.306,  288,  23.439,  1,   1   };
		//mars 
		double a2[] = {1 , 241.17 ,    1,   3389500,   6.67e-11 ,   0.170, 1, 0.170 , 210,  25.19 ,  1 ,  1   };
		 
		double a3[] = {1 , 1.81 ,      1,   6051800,   6.67e-11 ,   0.689, 1, 0.689 , 737,  177.36,  1,   1   };
		for(int i = 0; i < 12; i++)
		{
	 		VARA1[0][i] = a1[i]; 
			VARA1[1][i] = a2[i]; 
			VARA1[2][i] = a3[i]; 
		}
 
		iterator++;
	       	for(int llll = 0; llll < 100 ; llll++)
			{ 
			isbreaked = 0;	
 

			char *ptr,ptr2,ptr3,ptr4,ptr5,ptr6,ptr7; 
			int randme = iterator; 
	 			
 						
 			double solution[] = {9.8,3.7,8.89};

	 		for(int oooo = 0; oooo < 3; oooo++)
			{ 
				 
				for(int kkk = 0; kkk < 12; kkk++)
				{ 
					for(int lll = 1; lll < 12; lll++)
					{ 
						if(kkk != lll)
						{
							if( (result[oooo][kkk]) >  (result[oooo][lll]))
							{
								VARA1[oooo][kkk] -= a;

								new_str = fill_equation(line_buf,  VARA1 );
								result[oooo][kkk] = te_interp(new_str, 0);
								if(isnan( (result[oooo][kkk])) == 0 ||  (result[oooo][kkk]) == 0)
								{
									isbreaked =1;
									break;	
								}								 	
							}		
								else
								{
									 //printf("kkk = %d ::: oooo = %d\n",  kkk,oooo);
						   			 VARA1[oooo][kkk] += a;
									 new_str = fill_equation(line_buf,  VARA1 );	
									 result[oooo][kkk] = te_interp(new_str, 0);	
									 if(isnan( (result[oooo][kkk])) == 0 ||  (result[oooo][kkk]) == 0)
									{
										isbreaked =1;	
										break;
									}	 	 	
					 			}
						 
							}
					  
					}
			 
				}
 
					if((((( (result[0][11]))) < 5.97237e24*1.03   && ((result[0][11])) > 5.97237e24*0.97)   || (((result[0][11])) < solution[0]*1.02  && ((result[0][11])) > solution[0]*0.98)  || 			(((result[0][11])) <  5514*1.03    && ((result[0][11])) > 5514*0.97)  ) && isnan((result[0][11])) == 0)
					{
						printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
						printf("\neq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n\n",new_str,(result[0][11]),randme);
						printf("\neq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n\n",new_str,(result[1][11]),randme);
						printf("\neq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n\n",new_str,(result[2][11]),randme);
						printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
						if((((((result[1][11]))) < 6.4171e23*1.03   && ((result[1][11])) > 6.4171e23*0.97)   || (((result[1][11])) < solution[1]*1.02  && ((result[1][11])) > solution[oooo]*0.98)  || 			(((result[1][11])) <  3933.5*1.03    && ((result[1][11])) > 3933.5*0.97)  ) && isnan((result[1][11])) == 0)
						{



							for(int ppp = 0; ppp < 12; ppp++)
			 					printf("%f ",VARA1[oooo][ppp] );
							printf("\n");
							for(int i = 0; i < 12; i++)
							{
				 			 	VARA1[0][i] = a1[i]; 
							 	VARA1[1][i] = a2[i]; 
								VARA1[2][i] = a3[i]; 
							}
							isbreaked = 1;
							break;	
					}
					 	 
				 }
			 
		 	if(isbreaked == 1)			
				break;
 		 
	 		}
		}
	}
 }
  //fclose(fp5);

    return 0;
}


 
 
