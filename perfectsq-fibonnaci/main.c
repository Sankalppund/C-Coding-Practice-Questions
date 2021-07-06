/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//check if number is perfect square
bool isperfectSquare(int num){
    
    int s = sqrt(num);
    
    return (s*s==num);
}

//check if number is fibinacci number
//number is fibonnaci only if (5*n*n-4) or
// (5*n*n+4) is perfect square.
bool fibonnaci(int num){
    
    return (isperfectSquare(5*num*num-4)||isperfectSquare(5*num*num+4));
}

int main()
{
    for(int i=1; i<10; i++){
        
        fibonnaci(i)?printf("Yes:%d\n",i):printf("No:%d\n",i);
    }

    return 0;
}
