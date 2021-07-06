/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

//Time complexity is O(nlogn)

//swap
void swap(int*a, int*b){
    
    int temp = *a;
    *a=*b;
    *b=temp;
}    


//moves the data at position i of array
//into its appropriate position.
void heapify(int heap[], int heapIndex, int heapSize){
    
    //find left child
    
    int left = (2*heapIndex+1);
    
    int right = (2*heapIndex+2);
    
    //find largest among 3 nodes
    int largestIndex = heapIndex;
    
    //check if left node is larger than current node
    if(left < heapSize && heap[left] > heap[largestIndex]){
        
        largestIndex = left;
    }
    
    //check if right node is larger than current node
    if(right< heapSize && heap[right] > heap[largestIndex]){
        
        largestIndex = right;
    }
    
    //swap the largest node is larger than the current node
    if(largestIndex!=heapIndex){
        
        swap(&heap[heapIndex], &heap[largestIndex]);
 
        heapify(heap,largestIndex,heapSize);
    }
}

void heapSort(int heap[], int heapSize){
    
    //build heap
    for(int i=heapSize/2 - 1; i>=0; i-- ){
        
        heapify(heap,i,heapSize);
    }
    
    //One by one extract element from heap
    for(int i=heapSize-1; i>=0; i--){
        
        //Move current root to end;
        swap(&heap[0],&heap[i]);
        
        //call heapify to reduce the heap
        heapify(heap,0,i);
        
    }
    
}

//print array
void print(int arr[], size_t size){
    
    for (int i=0; i<size; ++i)
    {
        printf("%d ",arr[i]);
    }
    
    printf("\n");
}    


int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    heapSort(arr,n);
    
    print(arr,n);

    return 0;
}
