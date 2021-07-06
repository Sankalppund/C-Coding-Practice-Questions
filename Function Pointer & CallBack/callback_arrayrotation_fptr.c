#include <stdio.h>

int arr1[]={1,2,3,4,22,43};

//Left rotate array by one
void leftRotateByOne(int arr[], size_t size){
    
    int first = arr[0];
    
    int i;
    
    for(i=0; i<size-1; i++){
        
        arr[i]=arr[i+1];
    }
    
    arr[i] = first;
}

//Right rotate array by one
void rightRotateByOne(int arr[], size_t size){
    
    int last = arr[size-1];
    
    int i;
    
    for(i=size-1; i>=0; i--){
        
        arr[i] = arr[i-1];
    }
    
    arr[0] = last;
}

//Left rotate array by given number
void RotateArray(int arr[], size_t size, int num, void(*fptr)(int*,size_t)){
    
    for(int i=0; i<num; i++){
        
        fptr(arr,size);
    }
}


int main()
{
    char i;
    int j;
    printf("How do you want to rotate array.\n");
    printf("Press 'l':left and 'r':right\n");
    scanf("%s",&i);
    printf("By how many numbers (Max:6)\n");
    scanf("%d",&j);
    int m = sizeof(arr1)/sizeof(arr1[0]);
    //int n = sizeof(arr2)/sizeof(arr2[0]);
    
    void(*Lfptr)(int*,size_t)=leftRotateByOne;
    void(*Rfptr)(int*,size_t)=rightRotateByOne;
    
    for(int i=0; i<m;i++){
        printf("%d ",arr1[i]);
    }
  
    if(i=='l'){
        RotateArray(arr1,m,j,Lfptr);   
    }
    else if(i=='r'){
        RotateArray(arr1,m,j,Rfptr);
    }
    else{
        printf("\nInvalid input. not rotating the array\n");
    }
    
    
    printf("\n");
    for(int i=0; i<m;i++){
        printf("%d ",arr1[i]);
    }
    
    
    return 0;
}