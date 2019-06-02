#include "tinyexpr.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_PAIRS   16
double _count = 0;
int iterator = 0;
 
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

char equation_[1000];
char eq_[1000];
char CHARACTER[100];
 void print_stack_()
{
	if(onceopen == 1)
	{	     
	   fp = fopen ("datac.txt","w");
	   onceopen =0;
	}

        int i;
        char a[5] = {'+','-','/','*','^'};

        for (i = 1; i <= n * 2; i++) {
        	if (stack[i] == LEFT) {
             
			if(i < 11   )
			{
			    printf("%c(%c",a[rand() % 5],CHARACTER[i-1]);
			    sprintf(equation_,"%c(%c",a[rand() % 5],CHARACTER[i-1]);
			    strcpy(eq_,equation_);
				if(i == 1)
				    fprintf (fp, "%s", (char*)(eq_+1));
				else
				    fprintf (fp, "%s", eq_);
			}
			else
			{
			   printf("(");
			   char C = '(';
			   sprintf(equation_,"%c",C);
			   fprintf (fp, "%c", equation_);
			}
        }
        	else if (stack[i] == RIGHT) {
			if(i < 11   )
			{
			    printf(")%c%c",a[rand() % 5],CHARACTER[i-1]);
			    sprintf(equation_,")%c%c",a[rand() % 5],CHARACTER[i-1]);
			    fprintf (fp, "%s", equation_);
			}
			else
			{
			   printf(")");
			   char C = ')';
			   sprintf(equation_,"%c",C);
			   fprintf (fp, "%c", equation_);
			}
       		 }
		else {
		    printf("ERROR!!!!\n");
		    exit(-1);
		}
    }

    printf("\n");
    fprintf (fp, "\n");
}

 
void matching_parenthesis_pairs(int left_in_stack, int right_in_stack,char *var,char *num)
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
        matching_parenthesis_pairs(left_in_stack + 1, right_in_stack,var,num);
        ind--;
    }
    if (right_in_stack < left_in_stack) {
        stack[ind++]= RIGHT;
        matching_parenthesis_pairs(left_in_stack, right_in_stack + 1,var,num);
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

void permute_number(char *a, int i, int n,char *var)
{
   int j;
   if (i == n) 
	{
  
 
 	printf("%c%c%c%c%c%c%c%c%c%c\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
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
 	   matching_parenthesis_pairs(0, 0,var,a);

 
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
int f = 0;
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
	char e[] = "abcdefghijk"; 
        permute_number(e, 0, 10,NULL);
	for(;;);
 
        FILE *fp5;
 
        char str[1000000];
        char str2[1000];
        char str3[1000];
        char* filename = "datac.txt";
        fp5 = fopen(filename, "r");
 

        if (fp5 == NULL  ){
        	printf("Could not open file %s",filename);
        	return 1;
       }
 
 
	int cccc = 0;
	char search[1000][1000] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","o","p","q"};

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
 
 
	while(line_size >= 0 && line_count < 600000000)
	{
		line_size[line_count] = getline(  &line_buf  , &line_buf_size, fp5);		 
		line_count++;

		iterator++;

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

		char buf[1000],buf1[1000],buf2[1000],buf3[1000],buf4[1000],buf5[1000],buf6[1000];
		char *ptr,ptr2,ptr3,ptr4,ptr5,ptr6,ptr7; 
		int randme = iterator; 

		strcpy(new_str, line_buf);
		strcpy(new_str2, line_buf);
		strcpy(new_str3, line_buf);


		strcpy(new_str4,line_buf);
		strcpy(new_str5, line_buf);
		strcpy(new_str6, line_buf);
		strcpy(new_str7, line_buf);
 
		for(int ll = 0; ll < 16; ll++)
		{	
 
			ch = 299792458.0/(2*M_PI*6371000.0);
			double ch1 = 299792458.0/(2*M_PI*3389500.0);
			double ch2 = 299792458.0/(2*M_PI*6051800.0);
			double ch3 = 299792458.0/(2*M_PI*2439700.0);
			double ch4 = 299792458.0/(2*M_PI*25362000.0);
			double ch5 = 299792458.0/(2*M_PI*1188300.0);
			double ch6 = 299792458.0/(2*M_PI*1737100.0);

			  DE = 8.99e9*1.0/6371000.0;  
			double DE1 = 8.99e9*1.0/3389500.0;
			double DE2 = 8.99e9*1.0/6051800.0;
			double DE3 = 8.99e9*1.0/2439700.0;  
			double DE4 = 8.99e9*1.0/25362000.0;
			double DE5 = 8.99e9*1.0/1188300.0;
			double DE6 = 8.99e9*1.0/1737100.0;
				
			  V = (1*pow(299792458,2.0))/(pow(6371000.0, 3.0)*4.0/3.0*M_PI);  
			double V1 = (1*pow(299792458,2.0))/(pow(3389500.0, 3.0)*4.0/3.0*M_PI);
			double V2 =(1*pow(299792458,2.0))/(pow(6051800.0, 3.0)*4.0/3.0*M_PI);

			double V3 = (1*pow(299792458,2.0))/(pow(2439700.0, 3.0)*4.0/3.0*M_PI);  
			double V4 = (1*pow(299792458,2.0))/(pow(25362000.0, 3.0)*4.0/3.0*M_PI);
			double V5 =(1*pow(299792458,2.0))/(pow(1188300.0, 3.0)*4.0/3.0*M_PI);
			double V6 =(1*pow(299792458,2.0))/(pow(1737100.0, 3.0)*4.0/3.0*M_PI);
 
			f++;

			if(f > 9)
			f = 0;
 
			/*
			double VARA1[] = {6371000 ,  465.1 ,    1,   1 ,  6.67e-11 ,  0.306, 1, 0.306,288, 23.439,  6371000  };
			//mars 
			double VARA2[] = {3389500 , 241.17 ,    1,   1,  6.67e-11 ,   0.170, 1, 0.170 , 210,  25.19 , 3389500  };
			//venus
			double VARA3[] = {6051800 , 1.81   ,    1,   1,  6.67e-11 ,  0.689, 1,  0.689 , 737, 177.36 , 6051800  };


			double VARA4[] = {2439700 , 3.026   ,    1,   1, 6.67e-11 ,  0.142, 1, 0.142 ,340,2.04 , 2439700 };
			//mars 
			double VARA5[] = {25362000 , 2590   ,    1,  1, 6.67e-11 ,  0.488, 1, 0.488 ,76,97.77 ,  25362000   };
			//venus
			double VARA6[] = {1188300 , 13.106    ,    1,   1, 6.67e-11 ,  0.55, 1,0.55 ,44,   122.53, 1188300  };

			double VARA7[] = {1737100 , 4.627    ,    1,   1, 6.67e-11 ,  0.55, 1,0.136 ,220,   6.687, 1737100  };
			*/

			double VARA1[] = {7.43e-6 , 5e-6    ,    1,   0.1,  1,  0.231, 0.231,  1 ,f,   5e-6  ,  1, 0.1, 7.43e-6,  0.231,  0.1, 5e-6  };
			double VARA2[] = {7.43e-6 , 5e-6    ,    1,   0.2,  1,  0.925, 0.925,  1 ,f,   5e-6  ,  1, 0.2, 7.43e-6,  0.925,  0.2, 5e-6  };
			double VARA3[] = {7.43e-6 , 5e-6    ,    1,   0.3,  1,  2.077, 2.077,  1 ,f,   5e-6  ,  1, 0.3, 7.43e-6,  2.077,  0.3, 5e-6  };
			double VARA4[] = {7.43e-6 , 5e-6    ,    1,   0.4,  1,  3.7,   3.7,    1 ,f,   5e-6  ,  1, 0.4, 7.43e-6,  3.7,    0.4, 5e-6  };
			double VARA5[] = {7.43e-6 , 5e-6    ,    1,   0.5,  1,  5.78,  5.78,   1 ,f,   5e-6  ,  1, 0.5, 7.43e-6,  5.78,   0.5, 5e-6  };
			double VARA6[] = {7.43e-6 , 5e-6    ,    1,   0.6,  1,  8,     8,      1 ,f,   5e-6  ,  1, 0.6, 7.43e-6,  8,      0.6, 5e-6  };
			double VARA7[16]; 

 
 

			 ptr = strstr(new_str, search[ll]);
			 ptr2 = strstr(new_str2, search[ll]);
			 ptr3 = strstr(new_str3, search[ll]);

			 ptr4 = strstr(new_str4, search[ll]);
			 ptr5 = strstr(new_str5, search[ll]);
			 ptr6 = strstr(new_str6, search[ll]);
			 ptr7 = strstr(new_str7, search[ll]);
			 if (ptr != NULL) /* Substring found */
			 {
				//printf("%s contains '%s'\n", new_str, search[ll]);
				sprintf(buf,"%.35f" ,VARA1[ll]);
				sprintf(buf1,"%.35f",VARA2[ll]);
				sprintf(buf2,"%.35f",VARA3[ll]);
				sprintf(buf3,"%.35f",VARA4[ll]);
				sprintf(buf4,"%.35f",VARA5[ll]);
				sprintf(buf5,"%.35f",VARA6[ll]);
				sprintf(buf6,"%.35f",VARA7[ll]);
				strnew = str_replace(new_str,search[ll],buf);
				strnew2 = str_replace(new_str2,search[ll],buf1);
				strnew3 = str_replace(new_str3,search[ll],buf2);

		 		strnew4 = str_replace(new_str4,search[ll],buf3);
				strnew5 = str_replace(new_str5,search[ll],buf4);
				strnew6 = str_replace(new_str6,search[ll],buf5);
				strnew7 = str_replace(new_str7,search[ll],buf6);
		 		strcpy(new_str,strnew);
				strcpy(new_str2,strnew2);
				strcpy(new_str3,strnew3);

		 		strcpy(new_str4,strnew4);
				strcpy(new_str5,strnew5);
				strcpy(new_str6,strnew6);
				strcpy(new_str7,strnew7);
				free(strnew);
				free(strnew2);
				free(strnew3);
				free(strnew4);
				free(strnew5);
				free(strnew6);
				free(strnew7);
			 }

		 }	
		

		inc_ = inc_ + .0001 ; 

		#define RED   "\x1B[31m"
		#define GRN   "\x1B[32m"
		#define YEL   "\x1B[33m"
		#define BLU   "\x1B[34m"
		#define MAG   "\x1B[35m"
		#define CYN   "\x1B[36m"
		#define WHT   "\x1B[37m"
		#define RESET "\x1B[0m" 

		if((((te_interp(new_str, 0))) < 0.947*1.05   && (te_interp(new_str, 0)) > .947*0.95)  )
		{
 
			if((((te_interp(new_str2, 0))) < 0.277*1.05   && (te_interp(new_str2, 0)) > .277*0.95)  )
			{
 
				printf("\n%d",iterator );
				if( (( (te_interp(new_str3, 0))) >  -1.61*1.05   &&  (te_interp(new_str3, 0)) < -1.61*0.95)  )
				{
					printf(" .. ");
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
				 }
			}
		}
 
 }
 
}
 
  //fclose(fp5);

    return 0;
}
