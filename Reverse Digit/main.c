/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int reverse(int x){
    int res=0;
    while(x){
        int rem = x%10;
        res = rem+10*res;
        x=x/10;
    }
    return res;
}

int main()
{
    printf("Hello World %d",reverse(5426));

    return 0;
}
