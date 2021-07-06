#include <stdio.h>
#include <stdlib.h>

struct node{
    
    int data;
    
    struct node* next;
};

struct node* insert(struct node* head, int data){
    
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode->data=data;
    
    newNode->next=NULL;
    
    if(head==NULL){
        
        head = newNode;
        
        return head;
    }
    
    struct node*current=head;
    
    while(current->next!=NULL){
        
        current=current->next;
    }

    newNode->next = current->next;
    
    current->next = newNode;
    
    return head;
}

struct node* moveLastToFront(struct node* head, int n){
    
    if(head==NULL){
        return NULL;
    }
    struct node*current=head, *last;
    
    // while(current->next->next!=NULL){
    //     current=current->next;
    // }
    
    // last = current;
    // current=current->next;
    // current->next=head;
    // head = current;
    // last->next=NULL;
    
    while(n){
        
        while(current->next->next!=NULL){
            current=current->next;
        }
    
        last = current;
        current=current->next;
        current->next=head;
        head = current;
        last->next=NULL;
        n--;
    }
    
    return head;
    
}


void printlist(struct node* head){
    
    struct node*current=head;
    
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    
    printf("\n");
}

int main(){
    struct node* head=NULL;
    head = (struct node*)malloc(sizeof(struct node)); 
    head->data=0;
    head->next=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    printlist(head);
    head=moveLastToFront(head,4);
    printlist(head);
    // head=moveLastToFront(head);
    // printlist(head);
    // head=moveLastToFront(head);
    // printlist(head);

    return 0;
}

