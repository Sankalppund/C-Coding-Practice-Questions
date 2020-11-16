/*Header Files*/
#include <stdio.h>
#include <stdint.h> //for unit32_t data type.
#include <math.h>   //for log function
#include <stdbool.h>
#include <string.h>

//Get number of set bits in an integer number also called as HammingWeight.
//O(logn): since loop iterates only number of set bits times.
uint32_t getsetBits(uint32_t num){
   
    uint32_t count=0;
    while(num){
        num = num & (num-1);
        count++;
    }
    return count;
}

//Get total number of bits in an interger - log2 logic.
uint32_t getnumofBits(uint32_t num){
   
    return (log2(num)+1);
}

//Get bit position corrsoponding to MSB in a given integer - log2 Logic.
uint32_t getMSBpos(uint32_t num){
   
    return (log2(num));
}

//Find log2 of any given integer.
uint32_t getLog2(uint32_t num){
   
    int count=0;
    //Right shift number unitl value gets 0.
    while(num=num>>1){
        count++;
    }
    return count;
}

//Find given integer is Even or Odd
bool getEvenOdd(uint32_t num){
    
    if(num&1){
        
       printf("odd number\n");
       return true; 
    }
    else{
        
        printf("even number\n");
        return false;
    }
}

//Find if two input numbers have same or opposite sign using XOR.
void getsign(int32_t num1, int32_t num2){
    
    if(num1^num2){
        printf("Numbers have opposite sign\n");
    }
    else{
        printf("Numbers have same sign\n");
    }
}

//Get negative of a unsigned positive number using 2's compliment. 
int32_t getNegNum(uint32_t num){
    
    return ((~num)+1);
}

//Clear a bit at kth position
void clearkthBit(uint32_t num, uint32_t k){
    
    printf("Num before clearing bit: %d\n",num);
    num=num&(~(1<<(k-1)));
    printf("Num after clearing bit: %d\n",num);
}

//Set a bit at kth position
void setkthBit(uint32_t num, uint32_t k){
    
    printf("Num before Setting a bit: %d\n",num);
    num = num | (1 << (k-1));
    printf("Num after Setting a bit: %d\n",num);
}

//check if kth bit is set
void checksetBit(uint32_t num, uint32_t k){
    
    if(num&(1<<(k-1))){
        
        printf("bit %d is set in %d\n",k,num);
    }
    else{
        
        printf("bit %d is not set in %d\n",k,num);
    }
}

//check all bits if it is set or unset
void checkAllBits(uint32_t num){
    
    uint32_t k =32;
    
    while(k){
        
        if(num&(1<<(k-1))){
        
            printf("bit %d is set\n",k);
        }
        else{
        
            printf("bit %d is unset\n",k);
        }
        
        k--;
    }
}

//Toggle kth bit
void toggleKthBit(uint32_t num, uint32_t k){
    
    printf("Num before Toggling: %d\n",num);
    num=num^(1<<(k-1));
    printf("Num after Toggling: %d\n",num);
    
}

//Check if number is power of 2.
void powerofTwo(uint32_t num){
    
    if(num&(num-1)){
        printf("Number %d is not a power of 2.\n", num);
    }
    else{
        printf("Number %d is power of 2.\n", num);
    }
}

//find rightmost set bit.
//Step1: Clear rightmost bit of Number using n&(n-1)
//Step2: XOR with Number
//step3: Get the position of set bit using either logic or log2() function.
//Step3: if number is odd then return 1 always.
uint32_t findRightmostSetBit(uint32_t num){
    
    uint32_t orgNum = num;
    uint32_t count = 0;
    
    if(num&1){
        printf("The rightmost set bit is at position:1");
        return 0;
    }
    
    num = num^(num&(num-1));
    
    while(num){
        num>>=1;
        count++;
    }
    printf("The rightmost set bit is at position: %d\n",count);
}

//find rightmost set bit.
//Step1: n&(-n) gives you rightmost set bit.
void findRightmostSetBitAlternate(uint32_t num){
    uint32_t count = 0;
    num = num&(-num);
    while(num){
        num>>=1;
        count++;
    }
    printf("The rightmost set bit is at position: %d\n",count);
}

//find position of only set bit
uint32_t findposonlySetBit(uint32_t num){
    
    if(num&(num-1)){
        printf("Invalid i/p, it has more than 1 bit set.");
        return 0;
    }
    uint32_t count = 0;
    while(num){
        num>>=1;
        count++;
    }
    printf("The only set bit position is: %d\n",count);
}

//check parity of a number
//i.e. finding even or odd number of 1's.
//Even Parity: if number of 1s are even.
//Odd Parity: if number of 1s are odd.
void checkParity(uint32_t num){
    uint32_t count = 0;
    uint32_t orgNum = num;
    while(num){
        num=num&(num-1);
        count++;
    }
    if(count%2==0){
        printf("Number %d has got even parity.\n",orgNum);
    }
    else{
        printf("Number %d has got odd parity.\n",orgNum);
    }
}

//reversebits
//select rightmost bit using & 1
//shift that bit to (31-kth) position
//i.e. 0th will shift to 31st position
//1st will shift to 30th position
//Accumulate the result in 32 bit integer 
//O(1):since number of iteration is fixed. 

uint32_t reversebits(uint32_t num){
    
    uint32_t reverse=0, power = 31;//for 32 bit system
    
    //power = sizeof(num)*(8) // for unknown system
    
    while(num){
        
        //select rightmost bit abd shift to 31-kth pos.
        reverse += (num&1)<<power;
        
        //iterate through all 
        //bits from left to right.
        num=num>>1;
        
        power--;
    }
    
    return reverse;
}

//leading number of zeros
//get the MSB position and 
//subtract it from 31 in 32 bit system
uint32_t getLeadingZeros(uint32_t num){
    
    uint32_t count=0;
    
    uint32_t power = sizeof(num)*8;
    
    //get leftmost msb position
    while(num=num>>1){
        count++;
    }
    return (power-count-1);
}

//Rotatebits in left direction
uint32_t rotateBitsLeft(uint32_t num, uint32_t pos){
    
    uint32_t numBits = sizeof(num)*8;
    
    return (num<<pos)|(num>>(numBits-pos));
    
}

//Rotate Bits in right direction
uint32_t rotateBitsRight(uint32_t num, uint32_t pos){
    
    uint32_t numBits = sizeof(num)*8;
    
    return (num>>pos)|(num<<(numBits-pos));
    
}

//main function
int main(void){
    
    printf("%d\n",rotateBitsLeft(3,3));

    return 0;  
}



