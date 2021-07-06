/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define QUEUE_SIZE 5

void enQueue(int);
void deQueue();
void displayQueue();

int queue[QUEUE_SIZE]; 

int front = -1;
int rear = -1;

/*Enqueue operation*/
void enQueue(int data){
    
    
    if(rear==QUEUE_SIZE-1){
        
        printf("Queue is full\n");

    }
    else{
        
        if(front == -1){
        
            front++;
        }
        
        rear++;
        
        queue[rear] = data;
    }

}

/*Dequeue operation*/
void deQueue(){
    
    if(front==-1){
        
        printf("Queue is empty, cannot dequeue\n");
        
        return -1;
    }
    else{
        
        printf("Dequeued:%d\n", queue[front]);
    
        front++; 
        
        if(front>rear)
        {
            front=rear=-1;   
        }
    }

}

/*Display Operation*/
void display(){
    
    if(front==rear){
        printf("Queue is empty\n");
        
        return -1;
    }
    printf("Queue elements are: ");
    for(int i=front; i<=rear; i++){
        
        printf(" %d", queue[i]);
        
    }
    
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
    
    display();
    
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    
    display();
    
    return 0;
}

