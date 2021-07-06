#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Crating a node of linked list
struct node{
    
    int data;
    struct node* next;
};

//function to create a new node at the beginning of linked list.
struct node* insert_node(struct node* head, int data){

 struct node* new_node;
 
 new_node = (struct node*)malloc(sizeof(struct node));
 
 new_node->data = data;
 
 new_node->next = head;
 
 head = new_node;
 
 return head;
 
}

//function to create a new node at the beginning of linked list using double pointer.
void insert_node_dp(struct node** pointer_to_head, int data){

 struct node* new_node;
 
 new_node = (struct node*)malloc(sizeof(struct node));
 
 new_node->data = data;
 
 new_node->next = *pointer_to_head; // *pointer_to_head = head (head is present at that pointer which stores address of head)
 
 *pointer_to_head = new_node;
 
}

//function to print the new linked list.
void print_list(struct node* head){
    
    struct node* print_node = head;
    
    printf("Linked list is:");
    
    while(print_node!=NULL){
        
        printf(" %d",print_node->data);
        
        print_node=print_node->next;
        
    }
    
    printf("\n");
    
}

//function to print linked list recursively.
void recursive_print(struct node* head){
    
    printf("Linked list is:");
    if(head==NULL){return;}
    printf("%d ",head->data);
    recursive_print(head->next);
    printf("\n");
}

//this function prints the linked-list in reverse order.
void recursive_print_reverse(struct node* head){
    
    if(head==NULL){return;}
    recursive_print_reverse(head->next);
    printf(" %d",head->data);
}

//This function is used to add data in the given linked list at nth position. pass by reference or double pointer
void insert_node_nth_dp(struct node** pointer_to_head, int data, int pos){
    
    struct node*new_node;
    
    struct node*previous_node;
    
    new_node = (struct node*)malloc(sizeof(struct node));
    
    new_node->data = data;
    
    new_node->next = NULL;
    
    if(*pointer_to_head==NULL && pos!=1){
        
        printf("The list is empty so you need to add number at position one\n");
        return;
    }
    
    
    if(pos==1){
    
         new_node->next = *pointer_to_head;
         
         *pointer_to_head = new_node;
         
         return;
    }
    
    previous_node = *pointer_to_head;
    
    for(int i=0; i<(pos-2); i++){
        
        previous_node = previous_node->next;
    }
    
    new_node->next = previous_node->next;
    
    previous_node->next = new_node; 
}

//This function is used to add data in the given linked list at nth position.
struct node* insert_node_nth(struct node*head, int data, int pos){
    
    struct node*new_node;
    
    struct node*previous_node;
    
    new_node = (struct node*)malloc(sizeof(struct node));
    
    new_node->data = data;
    
    new_node->next = NULL;
    
    if(pos==1){
    
         new_node->next = head;
         
         head = new_node;
         
         return head;
    }
    
    previous_node = head;
    
    for(int i=0; i<(pos-2); i++){
        
        previous_node = previous_node->next;
    }
    
    new_node->next = previous_node->next;
    
    previous_node->next = new_node; 
    
    return head;
}

//this function is used to delete a node at nth position.
struct node* delete_node(struct node*head, int pos){
    
    struct node* temp = head;
    
    if(pos==1){
        
        head=temp->next;
        
        free(temp);
        
        return head;
    }
    
    struct node* node_to_delete;
    
    for(int  i=0; i<(pos-2); i++){
        
        temp=temp->next;
    }
    
    node_to_delete = temp->next;
    
    temp->next = node_to_delete->next;
    
    free(node_to_delete);
    
    return head;
    
}


//this function reverses the linked list-> iterative method.
struct node* reverselist(struct node* head){
    
    struct node *current_node, *previous_node, *next_node;
    
    current_node = head;
    
    previous_node = NULL;
    
    while(current_node!=NULL){
        
        next_node = current_node->next;
        
        current_node->next = previous_node;
        
        previous_node = current_node;
        
        current_node = next_node;
    }
    
    head = previous_node;
    
    return head;
}


//this function reverses the linked list with double pointer or pass by reference.-> iterative method
void reverselist_dp(struct node** pointer_to_head){
    
    struct node *current_node, *previous_node, *next_node;
    
    current_node = *pointer_to_head;
    
    previous_node = NULL;
    
    while(current_node!=NULL){
        
        next_node = current_node->next;
        
        current_node->next = previous_node;
        
        previous_node = current_node;
        
        current_node = next_node;
    }
    
    *pointer_to_head = previous_node;
}

//detect loop in the linked list.
bool detectloop(struct node* head){
    
    struct node* slow = head;
    
    struct node* fast = head;
    
    while(slow && fast && fast->next){
        
        slow=slow->next;
        
        fast=fast->next->next;
        
        if(slow==fast){
            
            return true;
        }
        
    }
    
    return false;
}

int main(){
    
    struct node* head=NULL;
  
    printf("How many numbers?\n");
    
    int n,i,x,y,a;
    char z,b;
    
    scanf("%d",&n);
    
    for(int i=0; i<n; i++){
        
        printf("Enter the numbers \n");
        scanf("%d", &x);
        printf("now enter the position\n");
        scanf("%d",&y);
        //head = insert_node(head, x);
        //insert_node_dp(&head,x);
        //insert_node_nth_dp(&head,x,y);
        head=insert_node_nth(head,x,y);
        print_list(head);
        //recursive_print(head);
    }
    
    printf("Do you want to delete any node or reverse the linked list (Enter d=Delete/r=reverse)?\n");
    
    scanf("%s",&z);
    
    if(z=='D' || z=='d'){
      
      printf("Alright!, so you decided to delete a node!\n");
      
      printf("Enter the node you want to delete\n");
      
      scanf("%d",&a);
      
      delete_node(head,a);
      
      print_list(head);

    }
    else if(z=='r'){
        
        printf("Alright!, so you want to actually reverse the whole linked list or just print it in reverse order\n");
        printf("Enter L=Reverse Linked List or P=print in revrse order\n");
        //head=reverselist(head);
        
        scanf("%s",&b);
        
        if(b=='l'){
        
            reverselist_dp(&head);
        
            printf("Printing the reverse linked list\n");
        
            print_list(head);
        }
        else if(b=='p')
        {
            printf("Printing linked list in reverse order\n");
            recursive_print_reverse(head);
        }
       
    }
    else{
        
        printf("Good, You are not deleting any node or reversing the linked list!\n");
        printf("Goodbye!\n");
    }
    
    return 0;
}








