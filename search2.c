#include "tinyexpr.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#define NUM_THREADS 3
#define MAX_PAIRS   16
double _count = 0;
int iterator = 0;
void task1()
{

	char e[] = "abcdefghijklmnopqrstuvwxyz123456789"; 
          permute_number(e, 0, 32,NULL);

}

void task2()
{

	char e[] = "+-*/^+-*/^+-*/^+-*/^+-*/^+-*/^+-*/^+-*/^"; 
        permute_sign(e, 0, 32,NULL);

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

 if(data->tid ==1)
  	task2();

  if(data->tid ==2)
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
char equation_[100011];
char eq_[100110];
char CHARACTER[1110000];
char CHARACTER_2[1001100];
 void print_stack_()
{
	if(onceopen == 1)
	{	     
	   fp = fopen ("dataf.txt","w");
	   onceopen =0;
	}

        int i;
  

        for (i = 1; i <= n * 2; i++) {
 
        	if (stack[i] == LEFT) {
             
			 if(i < 33  )
			{

			  	//    printf("%c(%c",CHARACTER_2[kk],CHARACTER[kk]);
			    sprintf(equation_,"%c(%c",CHARACTER_2[kk],CHARACTER[kk]);
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
			   sprintf(equation_,"%c",C);
			   fprintf (fp, "%c", equation_);
			}

		 
			 
		 
        }
        	else if (stack[i] == RIGHT) {
			 
			   //   printf(")%c%c",CHARACTER_2[kk],CHARACTER[kk]);
			    sprintf(equation_,")%c%c",CHARACTER_2[kk],CHARACTER[kk]);
			    fprintf (fp, "%s", equation_);
		 
		 	  
       		 }
		else {
		    //printf("ERROR!!!!\n");
		   // exit(-1);
		}
kk++;
if(kk > 16)
{
kk  = 0; 

}
    }
 
  // printf("\n");
    fprintf (fp, "\n");
}

 
void matching_parenthesis_pairs(int left_in_stack, int right_in_stack)
{
    if (left_in_stack < right_in_stack) {
        return;
    }
 
    if (ind == n * 2 + 1)
    {
        print_stack_();
        return;
    }

    if (left_in_stack < n) {
        stack[ind++] = LEFT;
        matching_parenthesis_pairs(left_in_stack + 1, right_in_stack);
        ind--;
    }
    if (right_in_stack < left_in_stack) {
        stack[ind++]= RIGHT;
        matching_parenthesis_pairs(left_in_stack, right_in_stack + 1);
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
  
 
 	// printf("%c%c%c%c%c%c%c%c%c%c\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
	CHARACTER[0] = a[0];
	CHARACTER[1] = a[1];
	CHARACTER[2] = a[2];
	CHARACTER[3] = a[3];
	CHARACTER[4] = a[4];
	CHARACTER[5] = a[5];
	CHARACTER[6] = a[6];
	CHARACTER[7] = a[7];
	CHARACTER[8] = a[8];
	CHARACTER[9] = a[9];
	CHARACTER[10] = a[10];
	CHARACTER[11] = a[11];
	CHARACTER[12] = a[12];
	CHARACTER[13] = a[13];
	CHARACTER[14] = a[14];
	CHARACTER[15] = a[15];
 	 

 
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
  
 
 	// printf("%c%c%c%c%c%c%c%c%c%c\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
	CHARACTER_2[0] = a[0];
	CHARACTER_2[1] = a[1];
	CHARACTER_2[2] = a[2];
	CHARACTER_2[3] = a[3];
	CHARACTER_2[4] = a[4];
	CHARACTER_2[5] = a[5];
	CHARACTER_2[6] = a[6];
	CHARACTER_2[7] = a[7];
	CHARACTER_2[8] = a[8];
	CHARACTER_2[9] = a[9];
	CHARACTER_2[10] = a[10];
	CHARACTER_2[11] = a[11];
	CHARACTER_2[12] = a[12];
	CHARACTER_2[13] = a[13];
	CHARACTER_2[14] = a[14];
	CHARACTER_2[15] = a[15];
 	 

 
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
int main()
{
    printf("Number of parenthesis pairs (max %d): ", MAX_PAIRS);
    scanf("%d", &n);
    ind = 1;
    srand(time(NULL));

while(1)
{
	_count = _count + 1;
	//  multitasks();

	//  for(;;);
 
        FILE *fp5;
 
        char str[1000000];
        char str2[1000];
        char str3[1000];
        char* filename = "dataf.txt";
        fp5 = fopen(filename, "r");
 

        if (fp5 == NULL  ){
        	printf("Could not open file %s",filename);
        	return 1;
       }
 
 
	int cccc = 0;
	char search[1000][1000] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q"};

	char   *strnew  = malloc(1000);
	char   *strnew2 = malloc(1000);
	char   *strnew3 = malloc(1000);
	char   *strnew4 = malloc(1000);
	char   *strnew5 = malloc(1000);
	char   *strnew6 = malloc(1000);
	char   *strnew7 = malloc(1000);


	char   *new_str  = malloc(1000);
	char   *new_str2 = malloc(1000);
	char   *new_str3 = malloc(1000);
	char   *new_str4 = malloc(1000);
	char   *new_str5 = malloc(1000);
	char   *new_str6 = malloc(1000);
	char   *new_str7 = malloc(1000);


	double inc_ = 1;
	 
	char  *str_44 = malloc(10000);
 
	#include <stdio.h>
	#define MAXBUFLEN 44*20000000 
 
 	char * line_buf = NULL;

 	size_t line_buf_size = 0;
	int line_count = 0;
	ssize_t * line_size;

 
	line_size = malloc(   MAXBUFLEN );
	 
	double ch;
	double DE;
	double V;

 
	int clocksec[1000000];
	int seconds = 0;
	 
	iterator = 0;
  
  	double increaser = 0.0006;
 
	int investigate = 0;
	double VARA1[] = {100 , 100*2 , 200 ,    300  ,  100  , 100,     100, 100 ,  100, 100 , 100,          100,  100, 	  100,  100 ,   1001};	 
	double VARA2[] = {1 , 1*2 , 2  ,   3 ,   1,   4,     5.0, 1 ,  7, 1,  24007,          1.850 , 1 ,          5.93543e7,  3389500  ,  6.67e-11};	 
	double VARA3[] = {1 , 1*2 , 2 ,    3  ,  1  , 4,     5.0, 1 ,  7, 1,  35020,          3.394,  1,           1.9414e7 ,  6051800 ,   6.67e-11};
	double var[] = { 1.5,2.12,2.12,2.2,2.5,2.12  };
	VARA1[0] += increaser;
	int lookupX[]   =  { 1,0,2,0,2,2,3,3,3,0,1,2,4,4,4,4,0,1,2,3,5,5,5,5,5,0,1,2,3,4,6,6,6,6,6,6,0,1,2,3,4,5,7,7,7,7,7,7,7,0,1,2,3,4,5,6,8,8,8,8,8,8,8,8,0,1,2,3,4,5,6,7,8,10,10,10,10,10,10,10,10,10,10,0,1,2,3,4,5,6,7,8,9,11,11,11,11,11,11,11,11,11,11,11,12,12,12,12,12,12,12,12,12,12,12,12,13,13,13,13,13,13,13,13,13,13,13,13,13,0,1,2,3,4,5,6,7,8,9,10,11,12,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0,1,2,3,4,5,6,7,8,9,10,11,0,1,2,3,4,5,6,7,8,9,10,11,12,13,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16   };
				int lookupY[]	=  { 0,2,1,1,0,1,0,1,2,3,3,3,0,1,2,3,4,4,4,4,0,1,2,3,4,5,5,5,5,5,0,1,2,3,4,5,6,6,6,6,6,6,0,1,2,3,4,5,6,7,7,7,7,7,7,7,0,1,2,3,4,5,6,7,9,9,9,9,9,9,9,9,9,0,1,2,3,4,5,6,7,8,9,10,10,10,10,10,10,10,10,10,10,0,1,2,3,4,5,6,7,8,9,10,11,11,11,11,11,11,11,11,11,11,11,0,1,2,3,4,5,6,7,8,9,10,11,0,1,2,3,4,5,6,7,8,9,10,11,12,13,13,13,13,13,13,13,13,13,13,13,13,13,0,1,2,3,4,5,6,7,8,9,10,11,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15  };
	double *result = malloc(1000000);
	char *new_str_ 	= malloc(1000000);


	while(line_size >= 0 && line_count < 600000000)
	{
 		//leta upp en ekvation
		line_size[line_count] = getline(  &line_buf  , &line_buf_size, fp5);		 
		line_count++;

	for(int i = 0; i < 16; i++)
 			 	VARA1[i] = 1.001;

       	for(int llll = 0; llll < 10000; llll++)
		{ 
		iterator++;
		char buf[1000],buf1[1000],buf2[1000],buf3[1000],buf4[1000],buf5[1000],buf6[1000];
 	 

			/*
			 time_t now;
			    struct tm *tm;

			    now = time(0);
			    if ((tm = localtime (&now)) == NULL) {
				printf ("Error extracting time stuff\n");
				return 1;
			    }
			 

			 clocksec[cccc] = tm->tm_sec;
			 
			 
			if(( abs(clocksec[cccc])  - abs(clocksec[cccc-1] )) != 0 && (abs(clocksec[cccc])  - abs(clocksec[cccc-1] )) > 0)  
				seconds =  ( abs(clocksec[cccc]) - abs(clocksec[cccc-1] ));


			if(seconds > 2)
			break;*/


			char *ptr,ptr2,ptr3,ptr4,ptr5,ptr6,ptr7; 
			int randme = iterator; 
		for(int lll = 0; lll < 16; lll++)
		{ 
			
	 
			
				strcpy(new_str, line_buf);
				/*strcpy(new_str2, line_buf);
				strcpy(new_str3, line_buf);


				strcpy(new_str4,line_buf);
				strcpy(new_str5, line_buf);
				strcpy(new_str6, line_buf);
				strcpy(new_str7, line_buf);*/
		 
				for(int ll = 0; ll < 16; ll++)
				{	

	 			        //double VARA1[] = {a1[one] , 	a1[one]   ,  a1[one] ,   a1[one],  a1[one]  ,  a1[one], a1[one],a1[one] ,  a1[one],    a1[one],   a1[one],   a1[one] };	 
					//double VARA2[] = {a2[one] , 	a2[one]   ,  a2[one] ,   a2[one],  a2[one]  ,  a2[one], a2[one],a2[one] ,  a2[one],    a2[one],   a2[one],   a2[one] };	 	 
					//double VARA3[] =  {a3[one] , 	a3[one]   ,  a3[one] ,   a3[one],  a3[one]  ,  a3[one], a3[one],a3[one] ,  a3[one],    a3[one],   a3[one],   a3[one] };	 

					
					double VARA4[] = {2439700 ,  1    ,     1,   1,   6.67e-11 ,  1, 1, 1 ,  1,     1,    2439700    };
					double VARA5[] = {25362000 ,  1    ,     1,   1,   6.67e-11 ,  1, 1, 1 ,  1,     1,    25362000    };
					double VARA6[] = {1188300 ,  1    ,     1,   1,   6.67e-11 ,  1, 1, 1 ,  1,     1,    1188300    };
					double VARA7[] = {1737100 ,  1    ,     1,   1,   6.67e-11 ,  1, 1, 1 ,  1,     1,    1737100    };			
					
					f = f + 0.1;
					if(f > 9)
					f = 1;

				      /*double VARA1[] = {7.43e-6 , 5e-6    ,    1,   0.1,  1,  0.231, 0.231,  1 ,f,   5e-6  ,  1, 0.1, 7.43e-6,  0.231,  0.1, 5e-6  };
					double VARA2[] = {7.43e-6 , 5e-6    ,    1,   0.2,  1,  0.925, 0.925,  1 ,f,   5e-6  ,  1, 0.2, 7.43e-6,  0.925,  0.2, 5e-6  };
					double VARA3[] = {7.43e-6 , 5e-6    ,    1,   0.3,  1,  2.077, 2.077,  1 ,f,   5e-6  ,  1, 0.3, 7.43e-6,  2.077,  0.3, 5e-6  };
					double VARA4[] = {7.43e-6 , 5e-6    ,    1,   0.4,  1,  3.7,   3.7,    1 ,f,   5e-6  ,  1, 0.4, 7.43e-6,  3.7,    0.4, 5e-6  };
					double VARA5[] = {7.43e-6 , 5e-6    ,    1,   0.5,  1,  5.78,  5.78,   1 ,f,   5e-6  ,  1, 0.5, 7.43e-6,  5.78,   0.5, 5e-6  };
					double VARA6[] = {7.43e-6 , 5e-6    ,    1,   0.6,  1,  8,     8,      1 ,f,   5e-6  ,  1, 0.6, 7.43e-6,  8,      0.6, 5e-6  };
					double VARA7[16]; */

					 ptr = strstr(new_str, search[ll]);
					/* ptr2 = strstr(new_str2, search[ll]);
					 ptr3 = strstr(new_str3, search[ll]);

					 ptr4 = strstr(new_str4, search[ll]);
					 ptr5 = strstr(new_str5, search[ll]);
					 ptr6 = strstr(new_str6, search[ll]);
					 ptr7 = strstr(new_str7, search[ll]);*/
					 if (ptr != NULL) /* Substring found */
					 {
						//printf("%s contains '%s'\n", new_str, search[ll]);
						sprintf(buf,"%.35f" ,VARA1[ll]);
						/*sprintf(buf1,"%.35f",VARA2[ll]);
						sprintf(buf2,"%.35f",VARA3[ll]);
						sprintf(buf3,"%.35f",VARA4[ll]);
						sprintf(buf4,"%.35f",VARA5[ll]);
						sprintf(buf5,"%.35f",VARA6[ll]);
						sprintf(buf6,"%.35f",VARA7[ll]);*/
						strnew = str_replace(new_str,search[ll],buf);
						/*strnew2 = str_replace(new_str2,search[ll],buf1);
						strnew3 = str_replace(new_str3,search[ll],buf2);

				 		strnew4 = str_replace(new_str4,search[ll],buf3);
						strnew5 = str_replace(new_str5,search[ll],buf4);
						strnew6 = str_replace(new_str6,search[ll],buf5);
						strnew7 = str_replace(new_str7,search[ll],buf6);*/
				 		strcpy(new_str,strnew);
						/*strcpy(new_str2,strnew2);
						strcpy(new_str3,strnew3);

				 		strcpy(new_str4,strnew4);
						strcpy(new_str5,strnew5);
						strcpy(new_str6,strnew6);
						strcpy(new_str7,strnew7);*/
						free(strnew);
						/*free(strnew2);
						free(strnew3);
						free(strnew4);
						free(strnew5);
						free(strnew6);
						free(strnew7);*/
				 VARA1[ll] += increaser;
				 }

				

				result[0+lll] = te_interp(new_str, 0);
				
				

			}
 
			
			int k = 0;
			int l = 1;
			for(int i = 0; i < 16; i++)
			{
				if(result[0+lookupX[i]] > result[0+lookupY[i]])
				{
				 	VARA1[k] -= increaser;	 	
				}
				 else
				     VARA1[k] += increaser;
				
			   if(l == 2)
			   {
				k++;
				l = 0;
			   }
				l++;
			}
		
			//printf(":%s\n  %f\n",new_str,  te_interp(new_str , 0) );
	 
			//  for(int i = 0; i < 16; i++)
 			 //	printf("variables: %f ", VARA1[i]  );
			// printf("\n");
			if(9.8 - result[0+15]  < 1 && isnan(result[0+15]) == 0)
			{
			printf(":%s\n  %f\n",new_str,  result[0+15] );
				// for(;;);
				break;	
			}
			//investigate++;
			//sprintf(new_str,"%f",var[0]+pow(var[1],2.0)*pow(var[1],2.0)*var[2]*var[3]*var[4]*var[5] );
				//printf("solution: %s with variables: %f %f %f %f %f %f\n", new_str,VARA1[0],VARA1[1],VARA1[2],VARA1[3],VARA1[4],VARA1[5],VARA1[6] );
		}

 
			inc_ = inc_ + .00000001 ; 

			#define RED   "\x1B[31m"
			#define GRN   "\x1B[32m"
			#define YEL   "\x1B[33m"
			#define BLU   "\x1B[34m"
			#define MAG   "\x1B[35m"
			#define CYN   "\x1B[36m"
			#define WHT   "\x1B[37m"
			#define RESET "\x1B[0m" 

			/*if((((te_interp(new_str, 0))) < 0.947*1.05   && (te_interp(new_str, 0)) > .947*0.95)  )
			{
	 
				if((((te_interp(new_str2, 0))) < 0.277*1.05   && (te_interp(new_str2, 0)) > .277*0.95)  )
				{
	 
					
					if( (( (te_interp(new_str3, 0))) >  -1.61*1.05   &&  (te_interp(new_str3, 0)) < -1.61*0.95)  )
					{*/
				 	
					
			if((((te_interp(new_str, 0))) < 5.97237e24*1.03   && (te_interp(new_str, 0)) > 5.97237e24*0.97)   || ((te_interp(new_str, 0)) < 9.805*1.02  && (te_interp(new_str, 0)) > 9.805*0.98)  || 			((te_interp(new_str, 0)) <  5514*1.03    && (te_interp(new_str, 0)) > 5514*0.97)  )
			{

				if((((te_interp(new_str2, 0))) < 6.4171e23*1.03   && (te_interp(new_str2, 0)) > 6.4171e23*0.97)   || ((te_interp(new_str2, 0)) < 3.720*1.02  && (te_interp(new_str2, 0)) > 3.720*0.98)  || ((te_interp(new_str2, 0)) <  3933.5 *1.03    && (te_interp(new_str2, 0)) > 3933.5*0.97)  )
				{
						printf(YEL "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n",RESET); 
						printf(RESET"");
						printf("\nEarth: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"", new_str, (te_interp(new_str, 0)) ,randme);
				 		printf("\nMars: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"", new_str2, (te_interp(new_str2, 0)) ,randme);
						printf("\nVenus: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"", new_str3, (te_interp(new_str3, 0)) ,randme);

						printf("\nMercury: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"", new_str4, (te_interp(new_str4, 0)) ,randme);
				 		printf("\nUranus: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"", new_str5, (te_interp(new_str5, 0)) ,randme);
						printf("\nPluto: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"", new_str6, (te_interp(new_str6, 0)) ,randme);
				 		printf("\nMoon: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"", new_str7, (te_interp(new_str7, 0)) ,randme);
						printf("\n__Earth DE: ="CYN" %f\n"RESET" "WHT" ch: "YEL" %f\n"RESET" "WHT" V: "CYN" %f\n"RESET" "WHT" "RESET"", ch, DE ,V );
						printf(YEL "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n",RESET); 
					if((((te_interp(new_str3, 0))) < 4.8675e24*1.03   && (te_interp(new_str3, 0)) > 4.8675e24*0.97)   || ((te_interp(new_str3, 0)) < 8.87*1.02  && (te_interp(new_str3, 0)) > 8.87*0.98)  || ((te_interp(new_str3, 0)) <  5243*1.03    && (te_interp(new_str3, 0)) > 5243*0.97)  )
					{
		
						printf("\n%d",iterator );
						printf(" .. ");
		
	 
				}
			}
	 
	 	}
	 	}
	 
	}
 }
  //fclose(fp5);

    return 0;
}


 
 
