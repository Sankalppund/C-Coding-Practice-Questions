/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define rows 3
#define colms 3
#define DOUBLEPTR 1

int main(){

#if DOUBLEPTR //2D array using double pointer
    
    printf("2D array using double pointer.\n");
    
    //we are taking double pointer which stores address
    //of pointer. All the location of rows will store 
    //starting address of dynamically allocated columns.
    //https://aticleworld.com/dynamically-allocate-2d-array-c/
    int**twoDA = (int**)malloc(rows*sizeof(int*));
    
    if(twoDA==NULL){
        return -1;
    }
    
    for(int i=0; i<rows; i++){
       
        //allocating memory equal to number of coloums
        //if number of colomuns are equal in all rows.
        twoDA[i] = (int*)malloc(colms*sizeof(int));
        
        if(twoDA[i]==NULL){
            return -1;
        }
      
       //if number of coloums are different then allocate
       //memory as per number of coloums in each row
       //below if column is increasing one by one.
       //twoDA[i] = (int*)malloc(number of coloumns*sizeof(int));
               
    }
    
    //accessing the dynamically allocated 2D array.
    for(int i=0; i<rows; i++){
     
        for(int j=0; j<colms; j++){
            
            twoDA[i][j] = 1;
            
        }   
    }
    
    //printing the dynamically allocated 2D array.
    for(int i=0; i<rows; i++){
     
        for(int j=0; j<colms; j++){
            
            printf("twoDA[%d][%d]:%d\n",i,j,twoDA[i][j]);
            
        }   
    }
    
    //free the dynamically allocated 2D array
    for(int i=0; i<rows; i++){
     
            free(twoDA[i]);  
    }
    
    free(twoDA);
    
    twoDA=NULL;
    
    return 0;
    
#else //2D array using single pointer.     
    
    printf("2D array using single pointer.\n");
    
    //allocating memory equal to [number of rows * number of coloums]
    int*arr2D = (int*)malloc(rows*colms*sizeof(int));
    
    //accessing each row and its respective coulums.
    //index = row*NumberOfColoumns+coloumn.
    for(int i=0; i<rows; i++){
        
        for(int j=0; j<colms; j++){
            
            arr2D[i*colms+j] = 1;
        }
    }
    
    for(int i=0; i<rows; i++){
        
        for(int j=0; j<colms; j++){
            
            printf("arr2D[%d][%d]:%d\n",i,j,arr2D[i*colms+j]);
        }
    }
    
    free(arr2D);
    
    arr2D=NULL;
    
    return 0;
    
#endif    
}
