/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define heapMax 15

//return index of parent node
int parent_Index(int i){
    
    return (i-1)/2;
}

//return index of left child node
int leftChild_Index(int i){
    
    return (2*i+1);
}

//return index of right child node
int rightChild_Index(int i){
    
    return (2*i+2);
}


//swap elements
void swap(int*a, int*b){
    
    int temp = *a;
    *a=*b;
    *b=temp;
}

void HeapInsert(int heap[], int heapData, int* heapSize){
    
    if(*heapSize>=heapMax){
        printf("heap is full\n");
        return;
    }
    
    //first insert the data at the last position of the array
    //and move it up.
    heap[*heapSize] = heapData;
    *heapSize = *heapSize+1;
    
    //move up until heap property satisfies.
    int heapIndex = *heapSize-1;
    
    while(heapIndex!=0 && heap[parent_Index(heapIndex)] < heap[heapIndex]){
        
        swap(&heap[parent_Index(heapIndex)], &heap[heapIndex]);
        
        heapIndex = parent_Index(heapIndex);
    }
    
}

//moves the data at position i of array
//into its appropriate position.
void max_heapify(int heap[], int heapIndex, int heapSize){
    
    //find left child
    
    int left = leftChild_Index(heapIndex);
    
    int right = rightChild_Index(heapIndex);
    
    //find largest among 3 nodes
    int largestIndex = heapIndex;
    
    //check if left node is larger than current node
    if(left <= heapSize && heap[left] > heap[largestIndex]){
        
        largestIndex = left;
    }
    
    //check if right node is larger than current node
    if(right<=heapSize && heap[right] > heap[largestIndex]){
        
        largestIndex = right;
    }
    
    //swap the largest node is larger than the current node
    if(largestIndex!=heapIndex){
        
        swap(&heap[heapIndex], &heap[largestIndex]);
        // int temp = heap[heapIndex];
        
        // heap[heapIndex] = heap[largestIndex];
        
        // heap[largestIndex] = temp;
        
        max_heapify(heap,largestIndex,heapSize);
    }
}

//convert array into heap
int build_max_heap(int heap[], int heapSize){
    
    int idx;
    
    for(idx = (heapSize/2)-1; idx>=0; idx--){
        
        max_heapify(heap,idx,heapSize);
    }
}

//return maximum items of the heapSize
int get_max(int heap[]){
    
    return heap[0];
}

//print heap
void printheap(int heap[], int heapSize){
    
    int idx;
    
    for(idx=0; idx<heapSize; idx++){
        
         printf("%d\n", heap[idx]);
    }
    
    printf("\n");
}

int main()
{
    int heapSize = 10;
    
    int heap[heapMax];
    
    for(int i=0; i<11; i++){
        heap[i] = i;
    }
    
    build_max_heap(heap,heapSize);
    
    HeapInsert(heap,34,&heapSize);
    
    HeapInsert(heap,0,&heapSize);
    
    printheap(heap,heapSize);
    
    printf("Max:%d\n",get_max(heap));

    return 0;
}
