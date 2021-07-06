/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
//#include <algorithm.h>

/*bubbleSort
Keeps comapring adjecent elements till
the array is sorted.
Time Complexity is always O(n2) if
array is sorted in reverse order
Time complexity is O(n) if array is already sorted.
Auxillary space: O(1) since in place algorithm
*/
void swap(int*num1, int*num2){
    
    int temp = *num1;
    
    *num1 = *num2;
    
    *num2 = temp;
}

/*bubbleSort*/
void bubbleSort(int arr[], size_t n){
    
    for(int i=0; i<(n-1); i++){
        
        for(int j=0; j<(n-i-1); j++){
            
            if(arr[j]>arr[j+1]){
                
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

/*Optimized bubble sort.
Restricting the inner loop if no swap made
Auxillary space: O(1) since in place algorithm
*/
void bubbleSort_OPT(int arr[], size_t n){
    
    bool swapped = false;
    
    for(int i=0; i<(n-1); i++){
        
        for(int j=0; j<(n-i-1); j++){
            
            if(arr[j]>arr[j+1]){
                
                swap(&arr[j],&arr[j+1]);
                
                swapped=true;
            }
            
            if(swapped==false){
                break;   
            }
        }
    }
}


/*Selection sort: selects the min element
in the array. This algo swaps the current 
element with min element till array sorts
Time Complexity:O(n2) since we are running
two loops.
useful when memory write is costly operation
Auxillary space: O(1) since in place algorithm*/
void selection_Sort(int arr[], size_t n){
    
    int i, j, minIndex;
    
    for(i=0; i<n-1; i++){
        
        minIndex=i;
        
        for(j=i+1; j<n; j++){
            
            if(arr[j]<arr[minIndex]){
                
                minIndex=j;
            }
        }
        
        swap(&arr[minIndex],&arr[i]);
    }
}


/*Insertion sort: Insert the small element
in the place in first iteration.
Time Complexity: O(n2)
Auxillary space: O(1) since in place algorithm
*/
void insertion_sort(int arr[], size_t n){
    
    int i,j,key;
    
    for(int i=1; i<n; i++){
        
        key = arr[i];
        
        j=i-1;
        
        while( j>=0 && key<arr[j]){
            
            arr[j+1] = arr[j];
            
            j--;
        }
    
        arr[j+1]=key; 
    }
}


/*mergesort
Time complexity: O(nlogn);
Space complexity: O(n);
*/
void mergesort(int p[], size_t size){
    
    if(size<2){
        return;
    }
    
    int mid = size/2;
    
    int la[mid];
    
    int ra[size-mid];
    
    for(int i=0; i<mid; i++){
        la[i] = p[i];
    }
    
    for(int j=mid; j<size; j++){
        ra[j-mid] = p[j];
    }
    
    mergesort(la,mid);
    
    mergesort(ra,size-mid);
    
    merge(la,mid,ra,size-mid,p);
    
}

void merge(int la[], int lasize, int ra[], int rasize, int p[]){
    
    int i=0,j=0,k=0;
    
    while(i<lasize && j<rasize){
        
        if(la[i]<ra[j]){
            
            p[k++]=la[i++];
        }
        else{
            
            p[k++]=ra[j++];
        }
        
    }
    
    while(i<lasize){
        p[k++] = la[i++];
    }
    
    while(j<rasize){
        p[k++] = ra[j++];
    }
}


/*quickSort
Time complexity: O(nlogn);
worst case: O(n2);
Space complexity: O(logn);
*/
int getpivot(int arr[], int start, int end){
    
    int pivot = arr[end];
    
    int divIndex=start;
    
    for(int i=start; i<end; i++){
       
       if(arr[i]<=pivot){
           
            swap(&arr[i],&arr[divIndex]);   
       
            divIndex++;
       } 
   
    }
    
    swap(&arr[divIndex], &arr[end]);
    
    return divIndex;    
}

void quickSort(int arr[], int start, int end){
    
    if(start<end){
       
       int pivIndex =  getpivot(arr,start,end);
       
       quickSort(arr, start, pivIndex-1);
       
       quickSort(arr, pivIndex+1,end);
    }
    
}

void printArray(int arr[], size_t n){
    
    for(int i=0; i<=(n-1); i++){
        
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//main
int main()
{
    int array[] = {5,1,8,4,6,3,7,1,9};
    
    size_t size = sizeof(array)/sizeof(array[0]);
    
    printArray(array,size);

    quickSort(array,0,size-1);
    
    printArray(array,size);
    
    return 0;
}




