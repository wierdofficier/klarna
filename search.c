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
double a[] =  {.00001,.00001,.00001,.00001,.00001,.00001};
int randme = 0;
double solution[] ={160.72,79.99,110.35,337.10,13.21,0.44};
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
double   result[20][1000];
char search[1000][1000] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q"};	
char * fill_equation(char * line_buf, double ** data , int lll,char * str,char *str2 )
{
	strcpy(str, line_buf);
	char buf1[1000];


	for(int ll = 0; ll < NUMVAR; ll++)
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
int main()
{
int investigate = 0;
 

FILE *fp5;	
char* filename = "data2.txt";
#define MAXBUFLEN 44*20000000
fp5 = fopen(filename, "r");	
  
	strnew  = malloc(1000);
 	 char *new_str  = malloc(1000);	

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
 
   
 	double **VARA1;
	VARA1 = malloc( 100*32);
	 
  	for(int iiiii=0; iiiii<200*1; iiiii++)
	VARA1[iiiii] =  malloc(1233);
	double inc  = 0;
	int counter = 0;

while(line_size >= 0 && line_count < 600000000)
{
  	line_size[line_count] = getline(  &line_buf  , &line_buf_size, fp5);
	line_count++;
for(int xxxx = 0; xxxx <  NUMEQ; xxxx++)	
for(int investigate = 0; investigate < NUMVAR; investigate++)
	VARA1[xxxx][investigate] = 1.0;
	for(int kkkk = 0; kkkk < 10000000 ; kkkk++)
	{
	for(int xxxx = 0; xxxx <  NUMEQ; xxxx++)
	{	
		for(int investigate = 0; investigate < NUMVAR; investigate++)
		{ 		
			//printf("Solution: %f,iterations = %d,  With variables: \n",result[0][investigate],investigate);
			for(int kkk = 0; kkk < NUMVAR; kkk++)
			{ 

				for(int lll = 1; lll < NUMVAR; lll++)
				{ 
					if(kkk != lll)
					 {
						if(result[xxxx][kkk] > result[xxxx][lll])
						{
							 VARA1[xxxx][kkk] -= a[xxxx];	
							 a[xxxx] = a[xxxx] - 0.0000000001; 	
						}
						else
				   			 VARA1[xxxx][kkk] += a[xxxx];
							 a[xxxx] = a[xxxx] + 0.0000000001;
			 			}
					}
VARA1[xxxx][kkk] +=a[xxxx];
			}
}
			double earth_i[100][100] = {{solution[0]/solution[2],solution[0]/solution[1],solution[0]/solution[3] ,solution[0]/solution[4],solution[0]/solution[5]},
				{solution[1]/solution[2],solution[1]/solution[0],solution[1]/solution[3],solution[1]/solution[4],solution[1]/solution[5] },
				{solution[2]/solution[1],solution[2]/solution[0],solution[2]/solution[3],solution[2]/solution[4],solution[2]/solution[5]},
				{solution[3]/solution[2],solution[3]/solution[0],solution[3]/solution[1] ,solution[3]/solution[4],solution[3]/solution[5]},
				{solution[4]/solution[2],solution[4]/solution[0],solution[4]/solution[1] ,solution[4]/solution[3],solution[4]/solution[5]},
				{solution[5]/solution[2],solution[5]/solution[0],solution[5]/solution[1] ,solution[5]/solution[3],solution[5]/solution[4]}
				};
 
				int cc = 0;
				int xxxc = 0;	
 
				cc = 0;
				 for(int kkk = 0; kkk < NUMVAR; kkk++)
				{ 
				int look[100][100] = {{2,1,3,4,5},{2,0,3,4,5},{1,0,3,4,5},{2,0,1,4,5},{2,0,1,3,5},{2,0,1,3,4}};
		 		for(int xxxx = 0; xxxx <  NUMEQ; xxxx++)
				{ 
				for(int llllll = 0; llllll <  NUMEQ; llllll++)
				{ 
				double diff = result[xxxx][kkk]/result[look[xxxx][llllll]][kkk];
										 
				double ratio = earth_i[xxxx][cc];
				if(diff > (ratio))	
				{
					VARA1[look[xxxx][llllll]][kkk]  += a[xxxx];
					a[xxxx] = a[xxxx] + 0.0000000001;	
											
				}
				else
				{
					VARA1[look[xxxx][llllll]][kkk]  -= a[xxxx];
					a[xxxx] = a[xxxx] - 0.0000000001;					 									
				}
				cc++;
				}				 
				cc = 0;
				} 
 				
				for(int xxxx = 0; xxxx <  NUMEQ; xxxx++)
				{ 				
					VARA1[xxxx][kkk] += a[xxxx];
				}
			new_str = fill_equation(line_buf,VARA1 ,0,new_str,strnew);
			new_str2 = fill_equation(line_buf,VARA1 ,1,new_str2,strnew2);
			new_str3 = fill_equation(line_buf,VARA1 ,2,new_str3,strnew3);
			new_str4 = fill_equation(line_buf,VARA1 ,3,new_str4,strnew4);
			new_str5 = fill_equation(line_buf,VARA1 ,4,new_str5,strnew5);
			new_str6 = fill_equation(line_buf,VARA1 ,5,new_str6,strnew6);
			result[0][kkk] = te_interp(new_str, 0);
			result[1][kkk] = te_interp(new_str2, 0);
			result[2][kkk] = te_interp(new_str3, 0);
			result[3][kkk] = te_interp(new_str4, 0);
			result[4][kkk] = te_interp(new_str5, 0);
			result[5][kkk] = te_interp(new_str6, 0);
			check_eq(NULL,investigate,new_str,new_str2,new_str3,new_str4,new_str5,new_str6);
				}
			}
		}
randme++;
	} 
}
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m" 

void check_eq(int oooo,int kkk, char *resultstr,char *resultstr2,char *resultstr3,char *resultstr4,char *resultstr5,char *resultstr6)
{
	if((result[0][kkk]) < solution[0]*1.05  && ((result[0][kkk])) > solution[0]*0.95)
	{
		if((result[1][kkk]) < solution[1]*1.05  && ((result[1][kkk])) > solution[1]*0.95)
		{
			if((result[2][kkk]) < solution[2]*1.05  && ((result[2][kkk])) > solution[2]*0.95)
			{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\neq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n\n",resultstr, result[0][kkk],randme);
		printf("\neq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n\n",resultstr2, result[1][kkk],randme);
		printf("\neq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n\n",resultstr3, result[2][kkk],randme);
		printf("\neq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n\n",resultstr4, result[3][kkk],randme);
		printf("\neq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n\n",resultstr5, result[4][kkk],randme);
		printf("\neq: ="CYN" %s\n"RESET" "WHT" solution: "YEL" %f\n"RESET" "WHT" EQ linenr: "CYN" %d\n"RESET" "WHT" "RESET"\n\n",resultstr6, result[5][kkk],randme);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				if((result[3][kkk]) < solution[3]*1.05  && ((result[3][kkk])) > solution[3]*0.95)
				{
	
		}
	}
	}
}
}

