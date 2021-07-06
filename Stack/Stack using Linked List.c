/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

struct node{
    
    int data;
    
    struct node* next;
};

struct node*top=NULL;

//function to push new data into stack;
void push(int x){
    
    struct node*newpush = (struct node*)malloc(sizeof(struct node));
    
    newpush->data = x;
    
    newpush->next = top;
    
    top = newpush;
}

//function to pop the entry from the stack
void pop(){
    
    if(top==NULL){
        
        printf("Your Stack is empty, you cannot pop it further.\n");
        
        return;
    }
    
    struct node*popit = (struct node*)malloc(sizeof(struct node));
    
    popit = top;
    
    top = popit->next;
    
    free(popit);
}

//function to get the top entry from the stack.
//Actual
int returnTop(){
    
    return(top->data);
}

//function to get the top entry from the stack.
//to avoid printing at main.
void Top(){
    
    if(top!=NULL){
    printf("Top: %d\n",top->data);}
    else{
        printf("Alert:Stack is empty, no top\n");}
}

//function to check if stack is empty or not.
void isempty(){
    
    if(top==NULL){
        printf("Your stack is empty.\n");
    }
    else{
        printf("Your stack is not empty\n");
    }
}

//function to print the stack 
void printstack(){
    
    struct node*printnode  = top;

    printf("Stack: ");
    
    while(printnode!=NULL){
        
        printf("%d ",printnode->data);
        
        printnode=printnode->next;
    }
    printf("\n");
}

int main()
{
    printf("Stack Implementation using Linked List\n");
    
    isempty();
    
    push(1);
    push(2);
    printstack();
    push(3);
    for(int i=4; i<15; i++){
        push(i);
    }
    printstack();
    pop();
    pop();
    printstack();
    
    isempty();
    
    Top();
    pop();
    pop();
    printstack();
    for(int i=4; i<15; i++){
        pop();
    }
    printstack();
    Top();
    push(111);
    printstack();
    
    
    return 0;
}


