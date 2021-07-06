/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

//structure without bit-fields
struct time{
    unsigned int d;
    unsigned int m;
    unsigned int y;
}; // total 12 bytes

//structure with bit-field
struct date{
    unsigned int d:5; // 5 bits
    unsigned int m:4; // 4 bits (both 5+4 bits is 9 bits < 32 bits (i.e. 4 bytes))
    unsigned int y;   // 4 bytes
}; // total 8 bytes


struct datetest{
    unsigned int d:5;
    unsigned int :0; //unnamed bit field of size 0 force alignment
    unsigned int y:4;//to next boundry. Non-zero works normal  
}; 

int main()
{
    printf("Size w/o bit field = %lu \n",sizeof(struct time));
    
    printf("Size with bit field = %lu \n",sizeof(struct date));
    
    printf("Size with bit field 2 = %lu \n",sizeof(struct datetest));

    return 0;
}


