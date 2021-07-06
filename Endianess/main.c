/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdint.h>

//Get Endianness of the system.
void getEndianess(uint32_t num){
    
    //uint16_t*ptr= (uint16_t*)&num;
    uint8_t*ptr = (uint8_t*)&num;
    
    printf("Mem 0::%x\n",*ptr);
       
    if(*ptr==(0x000000FF&num)){
        printf("Little Endian\n");
    }
    else if(*ptr==(0xFF000000&num)){
        printf("Big Endian\n");
    }
}

//Change Big2Little and vice versa.
uint32_t changeEndianess(uint32_t num){
    
    uint32_t result = 0;
    
    result |= (num & 0x000000FF) << 24;
    result |= (num & 0x0000FF00) << 8;
    result |= (num & 0x00FF0000) >> 8;
    result |= (num & 0xFF000000) >> 24;
    
    return result;
}

int main()
{
    uint32_t number = 0x44332211;
    
    //LSB:11 getting stored at lower memory location its little endian. 
    //MSB:44 getting stored at lower memory location its Big endian.
    getEndianess(number);
    
    //printf("%x",changeEndianess(number));
    
    return 0;
}



