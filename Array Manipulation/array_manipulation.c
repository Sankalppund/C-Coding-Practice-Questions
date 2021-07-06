/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int arr1[]={1,3,5,7,9,10,15,22,45};

int arr2[]={2,3,5,6};

//move 0 in an array to the end.
void putZeroAtEnd(int arr[], int size){
    
    int count=0;
    
    for(int i=0; i<size; i++){
        
        if(arr[i]!=0){
            arr[count++]=arr[i];
        }
    }
    
    while(count<size){
        arr[count++]=0;
    }
}


//remove duplicates from the sorted array.
int removeDuplicates(int arr[], int n){
    
    if (n==0 || n==1) 
        return n; 
  
    // To store index of next unique element 
    int j = 0; 
  
    // Doing same as done in Method 1 
    // Just maintaining another updated index i.e. j 
    for (int i=0; i < n-1; i++) 
        if (arr[i] != arr[i+1]) 
            arr[j++] = arr[i]; 
  
    arr[j++] = arr[n-1]; 
  
    return j; 
}

//remove duplicates from unsorted arrays
// condition 1<= arr[i] <= sizeof arr
int* rmDuplicates(int arr[], int size, int*returnSize){
    
    int*p = (int*)malloc(size*sizeof(int));
    
    int k=0;
    
    for(int i=0; i<size; i++){
        
        int idx = abs(arr[i]);
        
        if(arr[idx]>0){
            arr[idx] = -arr[idx];
            p[k++] = abs(arr[i]);
        }
    }
    
    *returnSize = k;
    return p;
    
}

//binary search algorithm
//o(logn)
//Condition: array should be sorted.
int binarySearch(int arr[], int data, int size){
    
    int mid = size/2;
    printf("%d\n",mid);
    int i=0;
    
    if(arr[mid]>=data){
        
        for(i=0;i<mid;i++){
            
            if(arr[i]==data){
                return i;
            }
        }
    }
    else{
        
        for(i=mid;i<size;i++){
            
            if(arr[i]==data){
                return i;
            }
        }
    }
    
    return -1;
}

//binary search algorithm
//o(logn)
//Condition: array should be sorted.
//recursive search
int BST_recursive(int arr[], int start, int end, int data){
    
    if(start<=end){
    
        int mid = start+(end-start)/2;
        
        printf("mid %d\n",mid);
        
        if(arr[mid]==data){
            return mid;
        }
        
        
        if(data<arr[mid]){
            
            return BST_recursive(arr,start,mid-1,data);
        }
        
        if(data>arr[mid]){
            
            return BST_recursive(arr,mid+1,end,data);
        }
    }
    
    return -1;
}


//find odd occuring element in an array in single traversal
uint32_t oddOccEle(uint32_t arr[], size_t n){
    
    uint32_t xor=0;
    
    for(int i=0; i<n; i++){
        xor = xor ^ arr[i];
    }
    
    printf("Number %d has odd occurance in array\n",xor);
    
    return xor;
}

//find union and intersection of an array
void unionAndIntersection(int arr1[], int m, int arr2[], int n){
    
    //get the minimum value
    int iscIdx = (m<n)?m:n;
    
    int i=0, j=0, k=0;
    
    int arr3[iscIdx];
    
    printf("Printing Union of arrays...\n");
    
    while(i<m && j<n){
        
        if(arr1[i]<arr2[j]){
            
            printf("%d ", arr1[i++]);
        }
        else if(arr1[i]>arr2[j]){
            
            printf("%d ", arr2[j++]);
        }
        else if(arr1[i]==arr2[j]){
            
            printf("%d ", arr2[j]);
            arr3[k++] = arr2[j++];
            i++;
        }
        
    }
    
    while(i<m){
        
        printf("%d ", arr1[i++]);
    }
    
    while(j<n){
        
        printf("%d ", arr2[j++]);
    }
    
    printf("\nPrinting intersection of arrays...\n");
    
    for(int a=0; a<k; a++){
        
        printf("%d ", arr3[a]);
    }
}

//get 2 non repeating numbers
//get XOR of all elements in the array which will
//remove all the elements present twice in the array 
//and then & with result number with only 1 right bit set.
void get2nonrepeatingNum(uint32_t arr[], size_t size){
    
    uint32_t xor=arr[0];
    
    uint32_t num1=0, num2=0;
    
    for(int i=0; i<size; i++){
        
        xor ^= arr[i];
    }
    
    printf("xor:%d\n",xor);
    //Keep only rightmost set bit in
    //the XOR.
    xor = (xor & ~(xor-1));
    
    printf("setbit:%d\n",xor);
    
    /* Now divide elements in two sets by 
    comparing rightmost set bit of Xor with bit 
    at same position in each element. */
    for(int j=0; j<size; j++){
        
        if(arr[j]&xor){
            
            printf("set1->%d\n",arr[j]);
            num1 ^= arr[j];
        }
        else{
            printf("set2->:%d\n",arr[j]);
            num2 ^= arr[j];
        }
    }
    
    printf("Two non-repreating elements: %d & %d\n", num1, num2);
}

//find a pair in sorted array to get 
//required difference.
void findpairdiff(int arr[], size_t size, int diff){
    
    int i=0; //start from 0th index of array
    int j=1; //start from 1st index of array
    
    while(i<size && j<size){
        
        if(i!=j && arr[j]-arr[i]==diff){
            
            printf("Pair found: %d & %d\n", arr[j], arr[i]);
            return;
        }
        else if(arr[j]-arr[i]<diff){
            j++;
        }
        else{
            
            i++;
        }
    }
    
    printf("pair not found\n");
}

//find a pair in sorted array to get required sum.
void findpairSum(int arr[], size_t size, int sum){
    
    int i=0; //start from 0th index of array
    int j=size-1; //start from last index of array
    
    while(i<j){
        
        if(arr[i]+arr[j]==sum){
            
            printf("Pair found: %d & %d\n", arr[i], arr[j]);
            return;
        }
        else if(arr[i]+arr[j]>sum){
            j--;
        }
        else if(arr[i]+arr[j]<sum){
            i++;
        }
        
    }
    
    printf("pair not found\n");
}


//Left rotate array by one
void leftRotateByOne(int arr[], size_t size){
    
    int first = arr[0];
    
    int i;
    
    for(i=0; i<size-1; i++){
        
        arr[i]=arr[i+1];
    }
    
    arr[i] = first;
}

//Left rotate array by given number
void leftRotateByNumber(int arr[], size_t size, int num){
    
    for(int i=0; i<num; i++){
        
        leftRotateByOne(arr,size);
    }
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
void rightRotateByNumber(int arr[], size_t size, int num){
    
    for(int i=0; i<num; i++){
        
        rightRotateByOne(arr,size);
    }
}


// find majority element in array
// A majority element in an array A[] of 
// 'size=n' is an element that appears more 
// than n/2 times 
// there are three sub function for this
// 1. find majority candidate
// 2. find if it has majority i.e [occurance > size/2]
// 3. print majority

int majorityCandidate(int arr[], int size){
    
    int count=1;
    
    int majIndex = 0;
    
    for(int i=1; i<size; i++){
        
        //If the next element is same then increment the count 
        //if the next element is not same then decrement the count.
        if(arr[majIndex]==arr[i]){
            count++;
        }
        else{
            count--;
        }
        
        //if the count reaches 0 then changes the maj_index 
        //to the current element and set the count again to 1.
        if(count==0){
            majIndex = i;
            count=1;
        }
    }
    
    return arr[majIndex];
}

bool ifMajaority(int arr[], int size, int cand){
    
    int count=0;
    
    for(int i=0; i<size; i++){
        
        if(arr[i]==cand){
            count++;
        }
    }
    
    if(count<size/2){
        return false;
    }
    else{
        return true;
    }
    
}

void printMajority(int arr[], int size){
    
    int cand = majorityCandidate(arr,size);
    
    if(ifMajaority(arr,size,cand)){
        
        printf("Majority Candidate is : %d\n", cand);
    }
    else{
        
        printf("No majority found\n");
    }
    
}

//find missing number in an array of consecutive numbers
//find sum of all numbers till n with n(n+1)/2
//and then take sum of all elements and subtract
//from sum to get missing number
// [1,2,4,5,6] missing is 3.
void findMissingNum(int arr[], int size){
    
    int arrSum=0;
    
    //because required size is 1 more than 
    //current array size because of missing number
    int n = size+1;
    
    int totalSum = ((n)*(n+1))/2;
    
    for(int i=0; i<size; i++){
        
        arrSum += arr[i];
    }
    
    printf("Missing number is %d\n",totalSum-arrSum);
    
}


//find missing number in an array using XOR property
// a = 1^2^3 
// b = 1^2
//then a^b = (3) missing number
void findMissingNumXOR(int arr[], int size){
    
    int a=0, b=0;
    int first = arr[0];
    int last = size+1;
    
    for(int i=first; i<=last; i++){
        a ^= i; 
    }
    for(int j=0; j<size; j++){
        b ^= arr[j];
    }
    
    printf("Missing number is %d\n",a^b);
    
}

//odd occuring element in more than one odd occuring
//element in array
int oddOCCinODD(int arr[], int size){
    
    
    int x;
    int sum;
    int result=0;
    
    //iterate through every bit
    for(int i=0; i<32; i++){
        
        sum=0;
        x = 1<<i;
        
        //find sum of set bits at ith position in an element.
        for(int j=0; j<size; j++){
            printf("x&arr[j] = %d\n",x&arr[j]);    
            if(x&arr[j]){
                sum++;
            }
            
        }
        printf("sum=%d\n",sum);
      // The bits with sum not multiple of 3, are the
      // bits of element with single occurrence.
        if(sum%3){
            result |= x;
            printf("result=%d\n",result);
        }
        
    }
    
    return result;
}



void printArray(int arr[], size_t size){
    
    for(int i=0; i<size; i++){
        
        printf("%d ",arr[i]);
    }
    
    printf("\n");
}


//find pair of number in an array with sum
void findpairSumalt(int arr[], int size, int sum){
    int i,j;
    for(i=0; i<size; i++){
        
        for(j=0; j<size;j++){
            
            if(arr[i]+arr[j]==sum){
                printf("pair (%d,%d) gives sum=%d\n",arr[i],arr[j],sum);
            }
        }
    }    
    
}


int main()
{
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
  
    // int ps=0;
    // int* p = rmDuplicates(arr1,m, &ps);
    
    // for(int i=0; i<ps; i++){
    //     printf("%d ",p[i]);   
    // }
    
   findpairSumalt(arr1,m,25);
    
    
    return 0;
}


















