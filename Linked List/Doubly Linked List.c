/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

struct node{
    
    int data;
    struct node* next;
    struct node* prev;
};

//struct node* head;

//function to get new node in doubly linked list.
struct node* getNewNode(int data){
    
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode->data = data;
    
    newNode->next = NULL;
    
    newNode->prev = NULL;
    
    return newNode;
}

//function to add new node at head
struct node* insertNodeatHead(struct node* head,int data){
    
    struct node* newNode = getNewNode(data);
    
    if(head==NULL){
        head = newNode;
        return;
    }
    
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    
    return head;
}

//insert node at tail of DLL
void insertodetail(struct node* head, int data){
    
    struct node* newNode = getNewNode(data);
    
     if(head==NULL){
        head = newNode;
        return;
    }
    
    struct node* temp = head;
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    newNode->prev = temp;
    
    temp->next = newNode;
    
}

//print DLL
void printlist(struct node* head){
    
    struct node*temp = head;
    
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

//reverse print DLL
void reverseprint(struct node* head){
    
    struct node*temp = head;
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    
    printf("\n");
    
}

//insert at N th position in DLL
void insertNpos(struct node*head, int data, int pos){
    
    if(pos==1){
        
        insertNodeatHead(head,data);
        
        return;
    }
    
    struct node* newNode = getNewNode(data);
    
    struct node* temp = head;
    
    for(int i=0; i<pos-2;i++){
        
        temp=temp->next;
        
        printf("%d\n", i);
    }
    
    struct node* temp2 = temp->next;
    newNode->next = temp2;
    newNode->prev = temp;
    temp->next=newNode;
    temp2->prev=newNode;
}

//reverse doubly linked list.
struct node* reverseDLL(struct node* head){
    
    struct node*current=head;
    struct node*previous;
    
    while(current!=NULL){
        
        previous = current->prev;
        current->prev = current->next;
        current->next = previous;
        current=current->prev;
    }
    
    if(previous){
        head = previous->prev;
    }
    
    return head;
}



int main()
{
    struct node*head = NULL;
    
    head=insertNodeatHead(head,1);
    head=insertNodeatHead(head,2);
    head=insertNodeatHead(head,3);
    head=insertNodeatHead(head,4);
    head=insertNodeatHead(head,5);
    
    printlist(head);
    
    // insertodetail(11);
    // insertodetail(12);
    // insertodetail(13);
    // insertodetail(14);
    // insertodetail(15);
    
    // printlist();
    
    // insertNpos(100,2);
    // insertNpos(101,3);
    // insertNpos(103,6);
    // insertNpos(111,1);
    
    // printlist();
    // reverseprint();
    
    head=reverseDLL(head);
    
    printlist(head);
    
    return 0;
}


