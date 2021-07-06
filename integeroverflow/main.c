/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <limits.h>

/*Checks overflow by checking the 
boundry condition. If there is no overflow, 
the function places the resultant = sum a+b 
in “result” and returns 0, otherwise it returns -1 */
int sumOvf(int*result, int a, int b){
    
    *result = a+b;
    
    if(a>0 && b>0 && *result<0){
        return -1;
    }
    if(a<0 && b<0 && *result>0){
        return -1;
    }
    
    return 0;
    
}

int main()
{
    int*result = (int*)malloc(sizeof(int));
    
    //int max value
    int x = 2147483640;
    
    int y = 10;
    
    printf("%d\n",sumOvf(result, x,y));
    
    printf("%d", *result);

    return 0;
}

