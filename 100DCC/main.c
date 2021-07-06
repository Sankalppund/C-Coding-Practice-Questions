/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

char A[3][4];

int B[3][4];

int a ()
{
  static int d;
  printf ("%d\n", d++);
  return d;
}

int b ()
{
  //puts("4");
  return 4;
}

//print fibonacci
void printfibonacci(int n){
    
    int f1=0;
    int f2=1;
    
    for(int i=1; i<=n;i++){
        int result = f1+f2;
        printf("%d ",result);
        f1=f2;
        f2=result;
    }
}

//square with recursion
int square(int num){
    
    if(num==0){
        return 0;    
    }
    if(num<0){
        num=-num;
    }
    int x = num>>1;
    if(num%2==0){
        return (4*square(x));
    }
    else{
        return (4*square(x)+(4*x)+1);
    }
}

int main ()
{
  //Q1
  int x = a () + a () + b ();
  printf ("X=%d\n", x);

  //Q2
  printf ("Offset:%lu\n", &A[2][1] - &A[0][0]);

  //Q3
  printf("Offset:%lu\n", &B[2][1] - &B[0][0]);
 
  //Q4
  printf("A[0][0]:%c\n",A[0][0]);
  
  //Q5
  printf("B[0][0]:%d\n",B[0][0]);

  char ch = 10;

  void *ptr = &ch;

  //print performs stack operation hence second argument is 
  //evaluated first and then first 
  //second argument makes ch value to 11 and then 1st argument
  //reads the same value 11.
  printf ("%d, %d\n", *(char *) ptr, ++(*(char *) ptr));
  
  printfibonacci(5);
  
  printf("\nSquare:%d\n",square(5));

  return 0;
}



