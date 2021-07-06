/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int multiplication(int a, int b){
    return a*b;
}

int add(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}

int main()
{
    int(*funptr[])(int,int) = {multiplication,add,sub};
    printf("Which function do you want to execute?\n");
    printf("Press 0 for multiplication\n");
    printf("Press 1 for addition\n");
    printf("Press 2 for subtraction\n");
    int y,j,k;
    scanf("%d",&y);
    printf("Which two numbers you want to do operation on?\n");
    printf("Enter num1 = ");
    scanf("%d",&j);
    printf("\nEnter num2 = ");
    scanf("%d",&k);
    int x = funptr[y](j,k);
    printf("Output = %d\n",x);
    return 0;
}
