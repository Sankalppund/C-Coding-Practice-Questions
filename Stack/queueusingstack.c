/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define MAX_SIZE 101

int stack[MAX_SIZE];

int top = -1;

//function to push an element in stack.

void push(int x){
    
    if(top == MAX_SIZE-1)
    {
        printf("Error: overflow of stack\n");
        
        return;
    }
    
    stack[++top]=x;
}

//function to pop an element out of stack.
void pop(){
    
    if(top==-1)
    {
        printf("Stack is empty, cannot pop\n");
    }
  
  top--;
}

//function to return the top value. 
int Top(){
    
    return stack[top];
}

//function to check if stack is empty.
void isempty(){
    
    if(top==-1){
        printf("Stack is empty.\n");
    }
    else{
       printf("Stack is not empty\n"); 
    }
}

void printqueue(){
    
    printf("Queue: ");
    
    for(int i=0; i<=top; i++){
        
        printf("%d ",stack[i]);
    }
    
    printf("\n");
}

void reverse(int arr[], int size){
    
    int start=0;
    int end=size;
    
    while(start<end){
        
        int temp=arr[start];
        arr[start++]=arr[end];
        arr[end--]=temp;
        
    }
    
}

void enqueue(int x){
    
    push(x);
}

int Dequeue(){

    int x = Top();
    pop();
    return x; 
}

int main()
{
    printf("Queue using stack.\n");
    
    for(int i=1; i<=15; i++){
        enqueue(i);
    }
    
    printqueue(); 
    reverse(stack,top);
    
    printf("Dequeud:");

    for(int i=1; i<=15; i++){
        printf("%d ",Dequeue());
    }

    printf("\n");

    return 0;
}

