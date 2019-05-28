
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_PAIRS   16
// C++ program to print all combination  
// of size r in an array of size n  
 double *num_var;
  int iterator = 0;
void combinationUtil(double arr[], double data[],  
                    int start, int end,  
                    int index, int r);  
  
// The main function that prints  
// all combinations of size r  
// in arr[] of size n. This function 
// mainly uses combinationUtil()  
void printCombination(double arr[], int n, int r)  
{  
    // A temporary array to store 
    // all combination one by one  
    double data[r];  
  
    // Print all combination using 
    // temprary array 'data[]'  
    combinationUtil(arr, data, 0, n-1, 0, r);  
}  
  
/* arr[] ---> Input Array  
data[] ---> Temporary array to  
store current combination  
start & end ---> Staring and 
Ending indexes in arr[]  
index ---> Current index in data[]  
r ---> Size of a combination to be printed */
void combinationUtil(double arr[], double data[],  
                    int start, int end,  
                    int index, int r)  
{  
    // Current combination is ready 
    // to be printed, print it  
    if (index == r)  
    {  
        for (int j = 0; j < r; j++)  
            printf("%f ", data[j]);
printf("\n"); 
        //cout << endl;  
        return;  
    }  
  
    // replace index with all possible  
    // elements. The condition "end-i+1 >= r-index" 
    // makes sure that including one element  
    // at index will make a combination with  
    // remaining elements at remaining positions  
    for (int i = start; i <= end &&  
        end - i + 1 >= r - index; i++)  
    {  
        data[index] = arr[i];  
        combinationUtil(arr, data, i+1,  
                        end, index+1, r);  
    }  
}  
  
 
typedef enum _PARENTHESIS {                     /* Parenthesis type */
    NONE,
    LEFT,
    RIGHT
} PARENTHESIS;

int n;
PARENTHESIS stack[MAX_PAIRS * 2 + 1] = {NONE, };/* Simulate parenthesis stack */
int ind;                                        /* Current stack location */

/**
 * print_stack
 * Prints out the stack content
 */
 FILE * fp;
 FILE * fp2;
 FILE * fp3;

 FILE * fp4;
 #include "tinyexpr.h"
#include <stdlib.h>
# include <stdio.h>
  char par2[1000][10];
int p_inc = 0;
char BUF_num[1000]; 
int linenr = 0;
int onceopen = 1;


//aluminium
double VARA1[1000] = {1.61  };
double VARA2[1000] = {41762};
double VARA3[1000] = { 2.61e10};
double VARA4[1000] = { 897}; 
double VARA5[1000] = { 933.473}; 
//copper 
double VARB1[1000] = {1.9};
double VARB2[1000] = {119159};
double VARB3[1000] = {4.83e10};
double VARB4[1000] = {385};
double VARB5[1000] = {1357.77};
//gold
double VARC1[1000] = {2.4 };
double VARC2[1000] = {222749};
double VARC3[1000] = { 2.7e10};
double VARC4[1000] = {129 };
double VARC5[1000] = {1337.33 };
void print_stack(char *var, char *num__)
{
char equation[1000];
    int i;
     char a[4] = {'+','-','/','*'};
	char p[2] = {'(',')'};
	 //int num[1000];
char par1[1000][10];
char par2[1000][10];
char par3[1000][10];
char par4[1000][10];
char par5[1000][10];
char par6[1000][10];
double num[1000];	
double num2[1000];
double num3[1000];


   		     		   
                    
int kk = 0;
int cnt = 1;
int left[1000];
int right[1000];
int counter = 0;
int counter2 = 0;
char r[1000];
int  op[12];

  
 
 
 int kkk = 0;

if(onceopen == 1)
{	     
   fp = fopen ("data.txt","w");
  fp2 = fopen ("data2.txt","w");
  fp3 = fopen ("data3.txt","w");
onceopen =0;
}


int nn = 0;

			    for (i = 1; i <= n * 2; i++) {
 num[i] = (double)num__[kkk];
 num2[i] = (double)num__[kkk];
 num3[i] = (double)num__[kkk];

if(num[i] == 'a')
{
	 num[i] =  	1.672e-27 ;
 	 num2[i] =  	1.672e-27 ;	
	 num3[i] =  	1.672e-27 ;

//printf("%f  :: %d\n", num[i], i );
}
if(num[i] == 'b')
{
	 num[i] = 9.109e-31;
	 num2[i] = 9.109e-31;
	 num3[i] = 9.109e-31;
//printf("%f  :: %d\n", num[i], i );
}
if(num[i] == 'c')
{
	 num[i] = 1.602e-19;
	 num2[i] = 1.602e-19;
  	 num3[i] = 1.602e-19;
//printf("%f  :: %d\n", num[i], i );
}
 
if(num[i] == 'd')
{
	 num[i] =VARA1[iterator] ;  //hämta nya
	 num2[i] =VARB1[iterator] ; 
	 num3[i] =VARC1[iterator]; 
 
//printf("%f  :: %d\n", num[i], i );
}

if(num[i] == 'e')
{
	 num[i] =VARA2[iterator] ;
	 num2[i] =VARB2[iterator] ; 
	 num3[i] =VARC2[iterator]; 
 
//printf("%f  :: %d\n", num[i], i );
}

if(num[i] == 'f')
{
	 num[i] =VARA3[iterator] ;
	 num2[i] =VARB3[iterator] ; 
	 num3[i] =VARC3[iterator]; 
 
//printf("%f  :: %d\n", num[i], i );
}


if(num[i] == 'g')
{
	 num[i] =VARA4[iterator] ;
	 num2[i] =VARB4[iterator] ; 
	 num3[i] =VARC4[iterator]; 
 
//printf("%f  :: %d\n", num[i], i );
}

if(num[i] == 'h')
{
	 num[i] =VARA5[iterator] ;
	 num2[i] =VARB5[iterator] ; 
	 num3[i] =VARC5[iterator]; 
 
//printf("%f  :: %d\n", num[i], i );
}
		  
 		    op[i] = a[rand() % 4]; 
 cnt += 1;
 
 kkk++;
if(kkk > 5)
kkk = 0;
        if (stack[i] == LEFT) {
  counter++;
 
	     sprintf(par1[i],"%.35f",num[i]  );
	     sprintf(par3[i],"%.35f",num2[i]  );
	     sprintf(par5[i],"%.35f",num3[i]  );
 //  printf("%s\n", par1[i]);
 if(i > 1)
{
sprintf(par2[i],"%c(%s",op[i],par1[i] );
sprintf(par4[i],"%c(%s",op[i],par3[i] );
sprintf(par6[i],"%c(%s",op[i],par5[i] );
}
else
{
sprintf(par2[i],"(%s",par1[i] );
sprintf(par4[i],"(%s",par3[i] );
sprintf(par6[i],"(%s",par5[i] );

}
left[counter] = i;
 

fprintf (fp, "%s", par2[left[counter]]);
fprintf (fp2, "%s",par4[left[counter]]);
fprintf (fp3, "%s",par6[left[counter]]);
 
        }
        else if (stack[i] == RIGHT) {
 
	fprintf (fp, ")");
	fprintf (fp2, ")");
	fprintf (fp3, ")");
 
 
                        
        }
 
nn++;
 }
 
 fprintf (fp, "\n");
 fprintf (fp2, "\n");
 fprintf (fp3, "\n");
}

    
 

/**
 * matching_parenthesis_pairs
 *
 * Generate matching parenthesis pair sequences in a simulated stack.
 * Initially call matching_parenthesis_pairs(0, 0)
 *
 * @param left_in_stack Current number of left parentheses in stack
 * @param right_in_stack Current number of right parentheses in stack
 */
void matching_parenthesis_pairs(int left_in_stack, int right_in_stack,char *var,char *num)
{
    if (left_in_stack < right_in_stack) {
        return;
    }

    if (ind == n * 2 + 1)
    {
        print_stack(var,num);
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
/* Function to swap values at two pointers */
void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
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
   if (i == n) //kombinera
	{
  
 
 	
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


void permute(char *a, int i, int n)
{
   int j;
   if (i == n) //kombinera
	{
 

	//printf("%c%c%c%c%c%c%c%c\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);

	char e[] = "abcdef"; //add variable
   	permute_number(e, 0, 5,a);
 	 
	}
  
   else
   {
        for (j = i; j <= n; j++)
       {
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
}
 
 


int c = 0;
int main()
{
    printf("Number of parenthesis pairs (max %d): ", MAX_PAIRS);
    scanf("%d", &n);
num_var = malloc(1000);
    ind = 1;
srand(time(NULL));


        char d[] = "+-*/+-*/"; //add variable
   	//permute(d, 0, 5);

while(1)
{
char e[] = "abcdefgh"; //add variable
	permute_number(e, 0, 7,NULL);
  fclose(fp);
  fclose(fp2);
  fclose(fp3);
 FILE *fp5;
 FILE *fp6;
 FILE *fp7 ;
    char str[1000];
   char str2[1000];
   char str3[1000];
    char* filename = "data.txt";
    fp5 = fopen(filename, "r");

    char* filename2 = "data2.txt";
    fp6 = fopen(filename2, "r");

    char* filename3 = "data3.txt";
    fp7 = fopen(filename3, "r");

    if (fp5 == NULL || fp6 == NULL || fp7 == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
fp4 = fopen ("data4.txt","w");
    while (fgets(str, 1000, fp5) != NULL && fgets(str2, 1000, fp6) != NULL && fgets(str3, 1000, fp7) != NULL)
{
           // printf("\n%s=%f\n",str, te_interp(str, 0) );

if((te_interp(str, 0) <  5.68000000000000000000000000000000e-26    && te_interp(str, 0) > 3.28000000000000000000000000000000e-26)   )
{

if((te_interp(str2, 0) <  1.55520e-25    && te_interp(str2, 0) > 0.255520e-25 )   )
{

if((te_interp(str3, 0) < 4.4738000000000000000000000000000000e-25    && te_interp(str3, 0) > 2.67038000000000000000000000000000000e-25)   )
{
 	printf("\n1%s=%.35f\n",str, te_interp(str, 0) );
	printf("\n2%s=%.35f\n",str2, te_interp(str2, 0) );
	printf("\n3%s=%.35f\n",str3, te_interp(str3, 0) );
fprintf (fp4, "%s\n",str);
}
}
 }
  
}
printf("iterator = %d \n", iterator);
iterator++;
}
    return 0;
}
