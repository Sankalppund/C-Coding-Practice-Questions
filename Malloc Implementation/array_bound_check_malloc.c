#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    //Allocate 1 byte more than needed to store sentinel values.
    int *p = (int*)malloc(SIZE*sizeof(int)+1);
    
    int i;
    
    for(i=0; i<10; i++){
        
       p[i]=i; 
    }
   
    //Store this sentinel value at position 1+last valid position.
    p[SIZE]=(int)'x';
    
    for(i=0; i<=100; i++){
        
        //check if you come across that sentinel value while traversing the array.
        if(p[i]==(int)'x'){
        	
        	printf("\nArray going out of bound, exiting the program.\n");
        	break;
        }
        else{
    		printf("%d ",p[i]);    	
        }
        
    }

    return 0;
}
