/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define QUEUE_SIZE 5

void enQueue(int);
void deQueue();
void displayQueue();

int queue[QUEUE_SIZE]; 

/*front rear index*/
int front = -1;
int rear = -1;

/*check if queue is full or not.*/
int isFull(){
    
    //if((front==rear+1 || (front==0 && rear==QUEUE_SIZE-1))){
    if(front==0 && rear==QUEUE_SIZE-1){    
        return 1;
    }
    
    return 0;
}

/*check if queue is empty or not*/
int isEmpty(){
    
    if(front==-1){
        return 1;
    }
    
    return 0;
}

/*Enqueue operation*/
void enQueue(int data){
    
    if(isFull()){
        printf("Queue is full\n");
    }
    else{
        
        if(front == -1){
        
            front++;
        }
        
        //rear wraps to 0 when buffer is full.
        rear = (rear+1)%QUEUE_SIZE;
        
        queue[rear] = data;
    }

}

/*Dequeue operation*/
void deQueue(){
    
    if(isEmpty()){
        
        printf("Queue is empty, cannot dequeue\n");
        
        return;
    }
    else{
        
        printf("Dequeued:%d\n", queue[front]);
    
        if(front==rear)
        {
            front=rear=-1;   
        }
        else{
            
            front = (front+1)%QUEUE_SIZE;
        }
    }

}

/*Display Operation*/
void display(){
    
    int i;
    
    if(isEmpty()){
        printf("Queue is empty\n");
        
        return;
    }
    
    printf("Queue elements are: ");
    
    for(i=front; i!=rear; i = (i+1)%QUEUE_SIZE){
        
        printf(" %d", queue[i]);
        
    }
    
    printf(" %d", queue[i]);
    printf("\n");
}

/*Main Function*/
int main()
{
    
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    enQueue(6);
    
    display();
    
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    
    display();
    
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    
    display();
    
    deQueue();
    deQueue();
    
    display();
    
    enQueue(1);
    enQueue(2);
    
    display();
    
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    
    return 0;
}
