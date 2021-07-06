/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

//macro for sum
#define SUM(a,b) (a+b)

//macro fro subtraction
#define SUB(a,b) (a-b)

//macro for sum as function
#define SUMFUN(a,b) ({int retval; retval=a+b; retval;})

//Macro for increment
//need to store variable in int first and then pass it
#define INC(x) (++x)

//Macro for multiplication
#define MULT(a,b) ((a)*(b))

//Macro to merge
//merge(2,3) will give 23 as output
#define merge(a,b) a##b

//Macro to covert into string lietral
#define getString(a) #a

//Macro print limit function
#define PRINT(i, LIMIT) while(i<LIMIT)\
                        {\
                            printf("Macro is Cool\n");\
                            i++;\
                        }
                        
//Macro to swap two nibbles in the byte                        
#define swapNibbles(data) (((data & 0x0F)<<4)|((data & 0xF0)>>4))

//Macro to swap two bytes
#define swapBytes(data) (((data & 0x00FF)<<8 |(data & 0xFF00)>>8))

//macro to swap two numbers
#define SWAP(a,b) (a^=b^=a^=b)

//Macro to swap Endianess
#define swapEndianess(value) ((value & 0x000000FF)<<24 | (value & 0x0000FF00)<<8 | \
                                (value & 0x00FF0000)>>8 | (value & 0xFF000000)>>24 )
                                
//Macro to extract HIGH and Low bytes in word (16 bit i.e. 2 bytes)
#define LOWBYTE(x) ((unsigned char)(x) & 0xFF)

#define HIGHBYTE(x) ((unsigned char)(x>>8) & 0xFF)

//Macro to swap odd even bits
#define swapOddEven(x)  (((x & 0xAAAAAAAA)>>1) | ((x & 0x55555555)<<1)) 

//Macro to get minimum
#define getMin(a,b) ((a<b)?a:b)

//Macro to get maximum
#define getMax(a,b) ((a<b)?b:a)

//Macros:create own sizeof operator.
//#define SIZE_OF(x) ((char*)(&x+1)-(char*)(&x))
//Typecasting it into char* and taking the difference 
//will tell us how many variables of type char can be 
//stored in the given memory space (the difference). 
#define SIZE_OF(x) ((char*)(&x+1)-(char*)(&x))

int main()
{
    double a;
    printf("sizeof:%lu\n",SIZE_OF(a));
    return 0;
}



