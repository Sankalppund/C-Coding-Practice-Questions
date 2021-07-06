/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

//converts decimal to binary recursively.
int binary(int decimal){
    
    if(decimal==0){
        return 0;
    }
    else{
        //remainder + 10*binary() (multiply by 10 to shift it left) 
        return (decimal%2+10*binary(decimal/2));
    }
}

//convert decimal to binary
void binary2(int decimal){
    
    if(decimal==0){
        printf("\n");
        return;
    }
    
    binary2(decimal>>1);
    
    (decimal&1)?printf("1"):printf("0");
    
}


int binary3(int num){
    char str[50];
    int i=0;
    while(num){
        int rem = num%2;
        str[i++]=(rem)?'1':'0';
        num=num/2;
    }
    
    str[i]='\0';
    printf("%s\n",str);
    //reverse str to get correct binary number.
}


int main()
{
    for(int i =0; i<=16; i++){
        
        binary2(i);
        //printf("%d\n",binary2(i));
    }

    return 0;
}



