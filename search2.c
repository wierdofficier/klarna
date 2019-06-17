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
double solution99[] ={160.72,79.99,110.35,337.10,13.21,0.44};
double solution2[] = {30.0,10.0,20.0,60.0,1.0,25.0};

double solution3[] = {2, 1  ,  3,1.5,4.2,1.4 };

double solution[] = {9.8,3.7,8.89,24.79,0.62,8.69};
double a[] =  {.0006,.0006,.0006,.0006,.0006,.0006};
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
char   *new_str;
char   *strnew;
char   *strnew2;
char   *strnew3;
char   *strnew4;
char   *strnew5;
char   *strnew6;
char * new_str2; 
char * new_str3;
char * new_str4;
char * new_str5;
char * new_str6;
int newloop = 0;
int newloopnow = 0;
char * fill_equation(char * line_buf, double ** data , int lll,char * str,char *str2 )
{
	strcpy(str, line_buf);
	char buf1[1000];


	for(int ll = 0; ll < 12; ll++)
	{			 			
		char * ptr = strstr(str, search[ll]);
		if (ptr != NULL) /* Substring found */
		{
			//printf("%s contains '%s'\n", new_str, search[ll]);												 
			sprintf(buf1,"%f" ,data[lll][ll]  );
							 
			str2 = str_replace(str,search[ll],buf1);	 
			strcpy(str,str2); 	
			free(str2);		 
		}
	} 
return str;
}
int randme;
double   result[20][1000];
 
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
  
	strnew  = malloc(1000);
 	new_str  = malloc(1000);

 	strnew2  = malloc(1000);
 	new_str2  = malloc(1000);

	strnew3  = malloc(1000);
 	new_str3  = malloc(1000);

	strnew4  = malloc(1000);
 	new_str4  = malloc(1000);

	strnew5  = malloc(1000);
 	new_str5  = malloc(1000);

	strnew6  = malloc(1000);
 	new_str6  = malloc(1000);
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
	while(line_size >= 0 && line_count < 600000000)
	{
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

			/*double a1[] = {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};
			double a2[]= {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};
			double a3[]= {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};
			double a4[]= {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};
			double a5[]= {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};
			double a6[]= {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};*/
 
 
		line_size[line_count] = getline(  &line_buf  , &line_buf_size, fp5);	

		for(int oooo = 0; oooo < NUMEQ; oooo++)
		{ 
			for(int kkk = 0; kkk < NUMVAR; kkk++)
			{ 
				  VARA1[0][kkk] = a1[kkk];
				  VARA1[1][kkk] = a2[kkk];
				  VARA1[2][kkk] = a3[kkk];
				  VARA1[3][kkk] = a4[kkk];
				  VARA1[4][kkk] = a5[kkk];
				  VARA1[5][kkk] = a6[kkk];
			}
 		a[oooo] = 0;
		}	 	 
		newloop = 0;
	       	for(int llll = 0; llll < 100  ; llll++)
		{ 
	 		// for(int oooo = 0; oooo < NUMEQ; oooo++)
			// { 				 
				for(int kkk = 0; kkk < NUMVAR; kkk++)
				{ 

 							new_str = fill_equation(line_buf,VARA1 ,0,new_str,strnew);
							result[0][kkk] = te_interp(new_str, 0);
 
							new_str2 = fill_equation(line_buf,VARA1 ,1,new_str2,strnew2);
							result[1][kkk] = te_interp(new_str2, 0);

							new_str3 = fill_equation(line_buf,VARA1 ,2,new_str3,strnew3);
							result[2][kkk] = te_interp(new_str3, 0);
							
							new_str4 = fill_equation(line_buf,VARA1 ,3,new_str4,strnew4);
							result[3][kkk] = te_interp(new_str4, 0);

							new_str5 = fill_equation(line_buf,VARA1 ,4,new_str5,strnew5);
							result[4][kkk] = te_interp(new_str5, 0);

							new_str6 = fill_equation(line_buf,VARA1 ,5,new_str6,strnew6);
							result[5][kkk] = te_interp(new_str6, 0);
				
				for(int oooo = 0; oooo < NUMEQ; oooo++)
				{ 
					double ratio = result[oooo][kkk]/solution[oooo];
			 
					a[oooo] =  a[oooo] + 0.000005;		 
				}

				for(int lll = 0; lll < NUMVAR; lll++)
				{ 
						 if(kkk != lll)
						 {				
						
 		 
				double earth_i[100][100];
				int look[100][100];
				for(int aa = 0; aa <= NUMEQ; aa++)
				{
				for(int bb = 0; bb < NUMEQ; bb++)
				{
				 	if(bb != aa)
					{
						earth_i[aa][bb] = solution[aa]/solution[bb];	
						look[aa][bb] =bb; 
					}
				} 
				}

							int cc = 0;
							int xxxc = 0;	
 
							cc = 0;
 
		 					for(int xxxx = 0; xxxx <  NUMEQ; xxxx++)
							{ 

								for(int llllll = 0; llllll <  NUMEQ; llllll++)
								{ 
								 
									double diff = result[xxxx][kkk]/result[look[xxxx][llllll]][kkk];
										 
									double ratio = earth_i[xxxx][cc];
									if(llllll != xxxx)
								{	 
									if(diff > (ratio))	
									{
										VARA1[look[xxxx][llllll]][kkk]  += a[xxxx];	
											
									}
									else
									{
										VARA1[look[xxxx][llllll]][kkk]  -= a[xxxx];
										 									
									}
								 }
										cc++;
								}				 
								 cc = 0;
							} 
 				
						for(int oooo = 0; oooo < NUMEQ; oooo++)
						{
							VARA1[oooo][kkk] += a[oooo];

						}
							counter++;

					check_eq(NULL,kkk,new_str,new_str2,new_str3,new_str4,new_str5,new_str6);
							}
							if(newloop == 1)
								break;
						 }						
			 		 }
				if(newloopnow == 1  )
				{
					newloopnow = 0;
					break;
				}
				}
			
	 		// }

		line_count++;	 
		iterator++;
		isbreaked = 0;	
		randme = iterator;

	if(bufcnt > 25)
		break;											
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

void check_eq(int oooo,int kkk, char *resultstr,char *resultstr2,char *resultstr3,char *resultstr4,char *resultstr5,char *resultstr6)
{
	
  
	if((result[0][kkk]) < solution[0]*1.05  && ((result[0][kkk])) > solution[0]*0.95)
	{
	
		if((result[1][kkk]) < solution[1]*1.05  && ((result[1][kkk])) > solution[1]*0.95)
		{
			if((result[2][kkk]) < solution[2]*1.05  && ((result[2][kkk])) > solution[2]*0.95)
			{

		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("eq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n",resultstr, result[0][kkk],randme);
		printf("eq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n",resultstr2, result[1][kkk],randme);
		printf("eq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n",resultstr3, result[2][kkk],randme);
		printf("eq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n",resultstr4, result[3][kkk],randme);
		printf("eq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n",resultstr5, result[4][kkk],randme);
		printf("\neq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n",resultstr6, result[5][kkk],randme);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				if((result[3][kkk]) < solution[3]*1.05  && ((result[3][kkk])) > solution[3]*0.95)
				{


 
					if((result[4][kkk]) < solution[4]*1.05  && ((result[4][kkk])) > solution[4]*0.95)
				{
		 bufcnt++;
			sprintf(BIGBUF[bufcnt][0],"%s",resultstr);
			sprintf(BIGBUF2[bufcnt][1],"%s",resultstr2);
			sprintf(BIGBUF3[bufcnt][2],"%s",resultstr3);
			printf("%s\n", BIGBUF[bufcnt][0]);
			printf("%s\n", BIGBUF2[bufcnt][1]);
			printf("%s\n", BIGBUF3[bufcnt][2]);
 		newloop = 1;	
						//	for(int ppp = 0; ppp < 12; ppp++)
			 			//		printf("%f ",a1[0][ppp] );
							printf("\n");
							for(int i = 0; i < 12; i++)
							{
				 			 //	a1[0][i] = a1[i]; 
							 //	a1[1][i] = a2[i]; 
							//	a1[2][i] = a3[i]; 
							}
							isbreaked = 1;
							//break;	
	 
					 	 
	}
} 
}
}
}
}
 
 
