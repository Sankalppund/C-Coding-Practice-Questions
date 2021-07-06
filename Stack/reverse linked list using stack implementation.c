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

struct stacknode{
    
    int data;
    struct stacknode* next;
};

struct node* head;

struct stacknode* top=NULL;

void inserthead(int x){
    
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    
    temp->data = x;
    
    temp->next = head;
    
    head = temp;
}

void printlist(struct node* head){
    
    struct node* temp = head;

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    
}


void push(int x){
    
    struct stacknode* temp = (struct stacknode*)malloc(sizeof(struct stacknode));
    
    temp->data = x;
    
    temp->next = top;
    
    top = temp;
}

void pop(){
    
    struct stacknode*temp = (struct stacknode*)malloc(sizeof(struct stacknode));
    
    temp = top;
    
    top = temp->next;
    
    free(temp);
}

int Top(){
    
    if(top!=NULL)
    return top->data;
    else
    return 1;
}

//function to check if stack is empty or not.
int isempty(){
    
    if(top==NULL){
        return 0;
    }
    else{
        //printf("Your stack is not empty\n");
    }
}

void reverselinkedlist(struct node* head){
    
    struct stacknode*temp = head;
     
    while(temp!=NULL){
        
        push(temp);
        temp = temp->next;
    }
    
    struct stacknode*temp2=Top();

    head=temp2;
    
    pop();
    
    while(isempty()){
       temp2->next = Top();
       pop();
       temp2 = temp2->next;
    }
    
    temp2->next=NULL;
    
    printlist(head);
}




int main()
{
    inserthead(8);
    inserthead(3);
    inserthead(587);
    inserthead(245);
    inserthead(212);
    inserthead(2);
    inserthead(247);inserthead(982);
    inserthead(452);inserthead(266);
    printlist(head);
    reverselinkedlist(head);
    return 0;
}

