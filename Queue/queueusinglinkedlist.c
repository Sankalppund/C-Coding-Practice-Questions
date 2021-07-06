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

/*Front and rear pointer*/
struct node* front=NULL;

struct node* rear=NULL;

/*Enqueue operation*/
void enqueue(int data){
    
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode->data = data;
    
    newNode->next = NULL;
    
    if(rear==NULL && front==NULL){
        
        rear = newNode;
        
        front = newNode;
        
        return;
    }
    
    rear->next = newNode;
    
    rear = newNode;
}

/*dequeue operation*/
void dequeue(){
    
    struct node* dequeueData = front;
    
    if(front==NULL){
        return;
    }
    if(front==rear){
        front=rear=NULL;
    }
    else{
        front = front->next;
    }
    
    free(dequeueData);
}

/*get the first element of queue*/
int Front(){
    
    if(front == NULL) {
		printf("Queue is empty\n");
		return;
	}
	
	return front->data;
}

/*print queue*/
void printQueue(){
    
    struct node*current=front;
    
    while(current!=NULL){
        
        printf("%d ", current->data);
        
        current=current->next;
    }
    
    printf("\n");
}

/*Driver code*/
int main()
{
   	enqueue(2); printQueue(); 
	enqueue(4); printQueue();
	enqueue(6); printQueue();
	dequeue();  printQueue();
	enqueue(8); printQueue();

    return 0;
}
