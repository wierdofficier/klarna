
#include <stdio.h>
#include <stdlib.h>

#define MAX_PAIRS   16
// C++ program to print all combination  
// of size r in an array of size n  
 double *num_var;
  
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
 #include "tinyexpr.h"
#include <stdlib.h>
# include <stdio.h>
  char par2[1000][10];
int p_inc = 0;
char BUF_num[1000]; 
int linenr = 0;
int onceopen = 1;
void print_stack(char *var, char *num2)
{
char equation[1000];
    int i;
     char a[4] = {'+','-','/','*'};
	char p[2] = {'(',')'};
	 //int num[1000];
char par1[1000][10];

double num[1000];	
 char par3[1000][10]; 		     		   
                    
int kk = 0;
int cnt = 1;
int left[1000];
int right[1000];
int counter = 0;
int counter2 = 0;
char r[1000];
int  op[12];

  
  
 
 int kkk = 0;
    for (i = 1; i <= n*2 ; i++) {
	 
 
 	 num[i] = (double)num2[kkk];

if(num[i] == 'a')
{
	 num[i] = 0.231;

//printf("%f  :: %d\n", num[i], i );
}
if(num[i] == 'b')
{
	 num[i] = 0.231;

//printf("%f  :: %d\n", num[i], i );
}
if(num[i] == 'c')
{
	 num[i] = 0.752479;

//printf("%f  :: %d\n", num[i], i );
}
if(num[i] == 'd')
{
	 num[i] = 1.0;

//printf("%f  :: %d\n", num[i], i );
}
if(num[i] == 'e')
{
	 num[i] = 1.0;

//printf("%f  :: %d\n", num[i], i );
}

if(num[i] == 'f')
{
	 num[i] = 1.0;

//printf("%f  :: %d\n", num[i], i );
}
		  
 		    op[i] = a[rand() % 4]; 
 cnt += 1;
 
 kkk++;
if(kkk > 5)
kkk = 0;
}



  /*   for (i = 1; i <= n*2; i++) {
printf("%f  :: %d\n", num[i], i );

}*/
//printf("\n");
if(onceopen == 1)
{	     
   fp = fopen ("data.txt","w");
onceopen =0;
}


int nn = 0;

			    for (i = 1; i <= n * 2; i++) {
 
        if (stack[i] == LEFT) {
  counter++;
 
	     sprintf(par1[i],"%f",num[i]  );
   
 if(i > 1)
sprintf(par2[i],"%c(%s",op[i],par1[i] );
else
sprintf(par2[i],"(%s",par1[i] );

left[counter] = i;
 

fprintf (fp, "%s",par2[left[counter]]);
 
 
        }
        else if (stack[i] == RIGHT) {
 
	fprintf (fp, ")");
 
 
                        
        }
 
      

nn++;
 }
 
 fprintf (fp, "\n");
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
 
 

 

int main()
{
    printf("Number of parenthesis pairs (max %d): ", MAX_PAIRS);
    scanf("%d", &n);
num_var = malloc(1000);
    ind = 1;
srand(time(NULL));


        char d[] = "+-*/+-*/"; //add variable
   	permute(d, 0, 5);

  fclose(fp);
 FILE *fp;
    char str[1000];
    char* filename = "data.txt";
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, 1000, fp) != NULL)
{
            printf("\n%s=%f\n",str, te_interp(str, 0) );

if(te_interp(str, 0) < 0.966 && te_interp(str, 0) > 0.964)
  sleep(5);
}
	
    return 0;
}
