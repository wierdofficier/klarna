#include "tinyexpr.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <complex.h>
#include <stdio.h>
#define NUMEQ  6
#define NUMVAR 12
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
double solution666[] ={160.72,79.99,110.35,337.10,13.21,0.44};
double solution2[] = {30.0,10.0,20.0,60.0,1.0,25.0};

double solution3[] = {2, 1  ,  3,1.5,4.2,1.4 };

double solution[] = {9.8,3.711,8.89,3.7,24.79,0.62};
   
double solution00[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765 };

double a[NUMEQ+1];
#define AMP 10 
int bufcnt = 0;
char BIGBUF[1000][1000][3];
char BIGBUF2[1000][1000][3];
char BIGBUF3[1000][1000][3];
double _count = 0;
int iterator = 0;
int isbreaked = 0;
void task1()
{
	char e[] = "abcdefghijkl"; 
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
	   fp = fopen ("data2.txt","w");
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
	 char e[] = "+-*/^+-*/^+-"; 
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
char   **strnew;
 
int newloop = 0;
 
 
 
 
char ** fill_equation(char * line_buf, double ** data , int lll,char ** str,char **str2 )
{
	strcpy(str[lll], line_buf);
	char buf1[1000];
	for(int ll = 0; ll < 12; ll++)
	{			 			
		char * ptr = strstr(str[lll], search[ll]);
		if (ptr != NULL) /* Substring found */
		{
			//printf("%s contains '%s'\n", new_str, search[ll]);												 
			sprintf(buf1,"%f" ,data[lll][ll]  );
							 
			str2[lll] = str_replace(str[lll],search[ll],buf1);	 
			strcpy(str[lll],str2[lll]); 	
			free(str2[lll]);		 
		}
	} 
return str[lll] ;
}
int randme;
double   result[20][1000];
 int newloopnew = 0;
int once1 = 0;
int main()
{
        printf("Number of parenthesis pairs (max %d): ", MAX_PAIRS);
        scanf("%d", &n);
	ind = 1;
        srand(time(NULL));
	//multitasks();

	  //    for(;;);
	FILE *fp5;	
        char* filename = "data4.txt";
        fp5 = fopen(filename, "r");
	ind = 1;
        if (fp5 == NULL  ){
        	printf("Could not open file %s",filename);
        	return 1;
        }
  
 
	strnew = malloc( 1000);
 
  		for(int iiiii=0; iiiii<NUMEQ+1; iiiii++)
			strnew[iiiii] =  malloc(123);


	new_str = malloc( 1000);
	 
  		for(int iiiii=0; iiiii<NUMEQ+1; iiiii++)
			new_str[iiiii] =  malloc(123);
  
 	char * line_buf = NULL;
 	size_t line_buf_size = 0;
	int line_count = 0;
	ssize_t * line_size;

	line_size = malloc(   MAXBUFLEN );	 
	iterator = 0;
   
 	double **VARA1;
	VARA1 = malloc( 100*32);
	 
  		for(int iiiii=0; iiiii<200*1; iiiii++)
			VARA1[iiiii] =  malloc(1233);

 

	double inc  = 0;
	int counter = 0;
for(int oooo = 0; oooo < NUMEQ; oooo++)
	a[oooo] = 0.0000001;
		
	while(line_size >= 0 && line_count < 600000000)
	{
 	
				/*double a1[]  =  {6371000.0 ,  1.0 ,      6.67e-11,   6371000.0 ,     1,   1.0,     6371000.0 ,  6371000.0,  1.0   };
				double a2[] =   {3389500.0 ,  1.0 ,     6.67e-11,   3389500.0,       1,    1,   3389500.0,   3389500.0 ,  1.0  };	 
				double a3[]  =  {6051800.0 ,  1.0 ,     6.67e-11,   6051800.0,       1 ,   1.0,     6051800.0 ,  6051800.0, 1.0    };
				double a4[] =   {2439700.0 ,  1.0 ,     6.67e-11,   2439700.0,       1.0,   1.0,     2439700.0,   2439700.0 , 1.0  };	 
				double a5[]  =  {25362000.0 , 1.0 ,    6.67e-11,   25362000.0 ,     1.0,    1.0 ,    25362000.0 ,  25362000.0,   1.0   };
				double a6[] =  {1188300.0 ,   1.0 ,     6.67e-11,   1188300.0,       1.0,   1.0,     1188300.0,   1188300.0 ,  1.0  };	*/

			/*double a1[NUMEQ+1][100] ;
			for(int oooo = 0; oooo < NUMEQ; oooo++)
				for(int kkk = 0; kkk < NUMVAR; kkk++)
	 				a1[oooo][kkk] = 2.0;
 */
 		newloopnew = 0;
		line_size[line_count] = getline(  &line_buf  , &line_buf_size, fp5);	
/*
		for(int oooo = 0; oooo < NUMEQ; oooo++)
		{ 
			for(int kkk = 0; kkk < NUMVAR; kkk++)
			{ 
				  VARA1[oooo][kkk] = a1[oooo][kkk];
			 
			}
		 a[oooo] = 0;
		}*/	 	 
		//srand(time(NULL));
// int slump2 =  rand() % 12;


	int oooo = 0;
				  double a1[]  =   {25 ,   pow(6371000.0,1.0/(2+1)) ,      a[oooo]/6371000.0,   1.0 ,   a[oooo]/6371000.0 ,  pow(6371000.0,1.0/(3+1)) ,       a[oooo] ,   6.67e-11 ,       a[oooo],  6371000.0,     a[oooo]/6371000.0 ,   a[oooo]/6371000.0  };
oooo++;
				  double a2[] =    {25 ,   pow(3389500.0,1.0/(2+1)) ,      a[oooo]/3389500.0,   1.0,    a[oooo]/3389500.0 ,  pow(3389500.0,1.0/(3+1))  ,     a[oooo] ,   6.67e-11 ,       a[oooo],    3389500.0,    a[oooo]/3389500.0,   a[oooo]/ 3389500.0   };	
oooo++; 
				  double a3[]  =   {25 ,   pow(6051800.0,1.0/(2+1)),       a[oooo]/6051800.0,   1.0,    a[oooo]/6051800.0 ,  pow(6051800.0,1.0/(3+1)) ,        a[oooo] ,   6.67e-11,        a[oooo] ,  6051800.0,     a[oooo]/6051800.0 ,  a[oooo]/ 6051800.0   };
oooo++;
				  double a4[] =   {25 ,   pow(2439700.0,1.0/(2+1)),      a[oooo]/2439700.0,    1.0,    a[oooo]/2439700.0 ,  pow(2439700.0,1.0/(3+1)) ,        a[oooo] ,   6.67e-11,        a[oooo],   2439700.0,     a[oooo]/2439700.0,  a[oooo]/  2439700.0   };
oooo++;	 
				  double a5[]  =   {25 ,   pow(69911000.0,1.0/(2+1)),       a[oooo]/69911000.0,   1.0 ,  a[oooo]/69911000.0   ,pow(69911000.0,1.0/(3+1))  ,    a[oooo] ,   6.67e-11  ,      a[oooo],   69911000.0 ,    a[oooo]/69911000.0 ,  a[oooo]/69911000.0 } ;
oooo++;
				  double a6[] =   { 25 ,   pow(1188300.0,1.0/(2+1)),       a[oooo]/1188300.0,   1.0,    a[oooo]/1188300.0 ,  pow(1188300.0,1.0/(3+1)),       a[oooo] ,   6.67e-11,        a[oooo],   1188300.0,    a[oooo]/1188300.0,   a[oooo]/ 1188300.0  }; 
 		for(int kkk = 0; kkk < NUMVAR; kkk++)
			{ 

				//srand(time(NULL));
				// int slump1 =  rand() % 12;
		



				  VARA1[0][kkk] = a1[kkk];
				  VARA1[1][kkk] = a2[kkk];
				  VARA1[2][kkk] = a3[kkk];
				  VARA1[3][kkk] = a4[kkk];
				  VARA1[4][kkk] = a5[kkk];
				  VARA1[5][kkk] = a6[kkk];
			}
	       	for(int llll = 0; llll < 1000   ; llll++)
		{ 
	
				if(newloopnew == 1)
					break;
 				for(int oooo = 0; oooo < NUMEQ; oooo++)
				{
				if(newloopnew == 1)
					break;
				for(int kkk = 0; kkk < NUMVAR; kkk++)
				{ 
					new_str[oooo] = fill_equation(line_buf,VARA1 ,oooo,new_str,strnew);
	 				result[oooo][kkk] = te_interp(new_str[oooo], 0);	 				 
	//}					
					if(isnan(result[oooo][kkk]) == 0 &&  (result[oooo][kkk] < 100.0 && result[oooo][kkk] > 0.0) &&    result[oooo][kkk] != 0)
					{
						check_eq(oooo,kkk,new_str);
					}
					 else
					   newloopnew = 1;
					
					//if(( result[oooo][kkk] < 1.000 && result[oooo][kkk] > 0.999))
					//		newloopnew = 1;	
					//if(isnan(result[oooo][kkk]) == 0 &&  (result[oooo][kkk] < 100.0 && result[oooo][kkk] > 0.0))
					//{
				 
					   			 
				//for(int kkk = 0; kkk < NUMVAR; kkk++)
			//	{ 
			 
				//for(int oooo = 0; oooo < NUMEQ; oooo++)
				//{ 
				 	a[oooo] =  a[oooo] + 0.000000005;		 
				//}

				for(int lll = 0; lll < NUMVAR; lll++)
				{ 
						 if(kkk != lll)
						 {				
						
 		 
				double earth_i[100][100];
				for(int aa = 0; aa <= NUMEQ; aa++)
				{
				for(int bb = 0; bb < NUMEQ; bb++)
				{
				 	if(bb != aa)
						earth_i[aa][bb] = solution[aa]/solution[bb];	
				} 
				}
							int cc = 0;
							int xxxc = 0;	
 
							cc = 0;
 
		 					for(int xxxx = 0; xxxx <  NUMEQ; xxxx++)
							{ 

								for(int llllll = 0; llllll <  NUMEQ; llllll++)
								{ 
								if(llllll != xxxx)
								{
									double diff = result[xxxx][kkk]/result[llllll][kkk-1];
										 
									double ratio = earth_i[xxxx][cc];
										 
									if(diff > (ratio))	
									{
										VARA1[llllll][kkk]  += a[xxxx];	
									  //	a[oooo] =  a[oooo] + 0.000000005;		
									}
									else
									{
										VARA1[llllll][kkk]  -= a[xxxx];
									 // 	a[oooo] =  a[oooo] - 0.000000005;	 
									}
								}
										cc++;
								}				 
								 cc = 0;
							} 
 				
						//for(int oooo = 0; oooo < NUMEQ; oooo++)
						//{
							VARA1[oooo][kkk] += a[oooo];

					 	//}
						
					}
					 
					}
					}
//if(isnan(result[oooo][kkk]) == 0 &&  (result[oooo][kkk] < 100.0 && result[oooo][kkk] > 0.0))
	//				{

				//	}
				//	else
				//	break;

				//	}

			//	}
				}
		
	 		// for(int oooo = 0; oooo < NUMEQ; oooo++)
			// { 	
		
							counter++;
							if(counter % 10000 == 0)
							{
			 	/* printf("\neq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n\n",new_str, result[0][kkk],randme);
			 	printf("\neq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n\n",new_str2, result[1][kkk],randme);
			 	printf("\neq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n\n",new_str3, result[2][kkk],randme);
				printf("\neq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n\n",new_str4, result[3][kkk],randme);
			 	printf("\neq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n\n",new_str5, result[4][kkk],randme);
		   */
							 }
				}
 

		line_count++;	 
		iterator++;
		isbreaked = 0;	
		randme = iterator;
 										
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

void check_eq(int oooo,int kkk, char **resultstr )
{	

 	 if((result[0][kkk]) < solution[0]*1.03 && ((result[0][kkk])) > solution[0]*0.97)
	 if((result[1][kkk]) < solution[1]*1.03 && ((result[1][kkk])) > solution[1]*0.97)
	 if((result[2][kkk]) < solution[2]*1.03 && ((result[2][kkk])) > solution[2]*0.97)
	 if((result[3][kkk]) < solution[3]*1.03 && ((result[3][kkk])) > solution[3]*0.97)
	 if((result[4][kkk]) < solution[4]*1.03 && ((result[4][kkk])) > solution[4]*0.97)
	 {	
			printf("eq: ="CYN" %s"RESET" "WHT" solution: "YEL" %f"RESET" "WHT" EQ linenr: "CYN" %d %f %f %f"RESET" "WHT" "RESET"\n",resultstr[0], result[0][kkk],randme,a[oooo],pow(6371000.0,1.0/(kkk+1)),a[oooo]/6371000.0);
			printf("eq: ="CYN" %s"RESET" "WHT" solution: "YEL" %f"RESET" "WHT" EQ linenr: "CYN" %d %f %f %f"RESET" "WHT" "RESET"\n",resultstr[1], result[1][kkk],randme,a[oooo],pow(3389500.0,1.0/(kkk+1)),a[oooo]/3389500.0);
			printf("eq: ="CYN" %s"RESET" "WHT" solution: "YEL" %f"RESET" "WHT" EQ linenr: "CYN" %d %f %f %f"RESET" "WHT" "RESET"\n",resultstr[2], result[2][kkk],randme,a[oooo],pow(6051800.0,1.0/(kkk+1)),a[oooo]/6051800.0);
			printf("eq: ="CYN" %s"RESET" "WHT" solution: "YEL" %f"RESET" "WHT" EQ linenr: "CYN" %d %f %f %f"RESET" "WHT" "RESET"\n",resultstr[3], result[3][kkk],randme,a[oooo],pow(2439700.0,1.0/(kkk+1)),a[oooo]/2439700.0);
			printf("eq: ="CYN" %s"RESET" "WHT" solution: "YEL" %f"RESET" "WHT" EQ linenr: "CYN" %d %f %f %f"RESET" "WHT" "RESET"\n",resultstr[4], result[4][kkk],randme,a[oooo],pow(69911000.0,1.0/(kkk+1)),a[oooo]/69911000.0); 
			printf("eq: ="CYN" %s"RESET" "WHT" solution: "YEL" %f"RESET" "WHT" EQ linenr: "CYN" %d %f %f %f"RESET" "WHT" "RESET"\n\n",resultstr[5], result[5][kkk],randme,a[oooo],pow(1188300.0,1.0/(kkk+1)),a[oooo]/1188300.0);
			 	 
	 }

}
 		 
 
