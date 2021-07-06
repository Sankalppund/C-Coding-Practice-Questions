
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define QUEUE_SIZE 5

void enQueue(int);
int deQueue();
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
int deQueue(){
    
    if(front==-1){
        
        printf("Queue is empty, cannot dequeue\n");
        
        return -1;
    }
    else{
        
        //printf("Dequeued:%d\n", queue[front]);
        
        // int x = queue[front];
    
        front++; 
        
        int x = queue[front];
        
        if(front>rear)
        {
            front=rear=-1;   
        }
        
        return x;
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

void reverse(int arr[], int size){
    
    int start=0;
    int end=size;
    
    while(start<end){
        
        int temp=arr[start];
        arr[start++]=arr[end];
        arr[end--]=temp;
        
    }
    
}

void push(x){
    enQueue(x);
}

int top(){
    
    return deQueue();
}



/*Main Function*/
int main()
{
    for(int i=1;i<=5;i++){
        push(i);
    }
    
    display();
    
    //reverse queue to make it look like stack;
    reverse(queue,QUEUE_SIZE);
    
    printf("Stack pop: ");
    
    for(int i=1;i<=5;i++){
        printf("%d ",top());
    }
    
    return 0;
}


