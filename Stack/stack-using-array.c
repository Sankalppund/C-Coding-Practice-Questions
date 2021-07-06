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

void printstack(){
    
    printf("Stack: ");
    
    for(int i=0; i<=top; i++){
        
        printf("%d ",stack[i]);
    }
    
    printf("\n");
}

int main()
{
    printf("Stack implementation of an array.\n");
    
    push(1);
    printstack();
    push(2);
    printstack();
    push(3);
    printstack();
    push(4);
    printstack();
    pop();
    printstack();
    push(5);
    printstack();
    pop();
    printstack();
    isempty();
    printstack();
    push(100);
    printstack();
    int x = Top();
    printf("top of stack is: %d\n",x);

    return 0;
}
