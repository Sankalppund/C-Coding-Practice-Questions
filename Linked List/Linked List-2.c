/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>// malloc and free
#include <stdbool.h>


struct node{
    
    int data;
    
    struct node* next;
};

//This function creates new node and returns address of new node.
struct node* createAndGetNode(int data){
    
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode->data=data;
    
    newNode->next=NULL;
    
    return newNode;
}

//function insert a node at head
void insertNode(struct node**ptrTohead, int data){
    
    struct node *newNode;
    
    newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode->data = data;
    
    newNode->next = *ptrTohead;
    
    *ptrTohead=newNode;
}

//print linked list
void printlist(struct node**ptrTohead){
    
    struct node* current = *ptrTohead;
    
    if(current==NULL){
        
        printf("Cannot print anything, the list is empty\n");
        
        return;
    }
    
    while(current!=NULL){
        
        printf("%d ", current->data);
        
        current=current->next;
    }
    
    printf("\n");
}


//Write a Count() function that counts the number of times a given int occurs in a list. The
//code for this has the classic list traversal.
int countIntegerOccurance(struct node**ptrTohead, int integer){
    
    struct node* current = *ptrTohead;
    
    int count = 0;
    
    while(current!=NULL){
        
        if(current->data == integer){
            
            count++;
        }
        
        current = current->next;
    }
    
    return count;
}

//This function gives number of nodes present in the list.
int getLenght(struct node**ptrTohead){
    
    struct node* current = *ptrTohead;
    
    int count = 0;
    
    while(current!=NULL){
        
        count++;
        
        current = current->next;
    }
    
    return count;
}

// Write a GetNth() function that takes a linked list and an integer index and returns the data
// value stored in the node at that index position.
int GetNth(struct node**ptrTohead, int index){
    
    if(!getLenght(ptrTohead)){
        printf("The list is empty\n");
        return -1;
    }
    
    struct node* current = *ptrTohead;
    
    while(current && index){
        
        current= current->next;
        
        index--;
    }
    
    if(index==0){
        return current->data;    
    }else{
        return -1;
    }
    
}

//Delete Linked list
void DeleteList(struct node**ptrTohead){
    
    struct node* current = *ptrTohead;
    
    struct node* temp;
    
    while(current!=NULL){
        
        temp = current;
        
        current=current->next;
        
        free(temp);
    }
    
    *ptrTohead = NULL;
    
    printf("\n");
}


//Write a Pop() function that is the inverse of Push(). 
//Pop() takes a non-empty list, deletes
//the head node, and returns the head node's data.
int pop(struct node**ptrTohead){
    
    
    if(!getLenght(ptrTohead)){
        printf("The list is empty\n");
        return -1;
    }
    
    struct node* current = *ptrTohead;
    
    struct node* nextHead = current->next;
    
    int data = current->data;
    
    free(current);
    
    *ptrTohead = nextHead;
    
    return data;
}

//A more difficult problem is to write a function InsertNth() which can insert a new node at
//any index within a list. Push() is similar, but can only insert a node at the head end of the
//list (index 0).
void insertNodeNth(struct node**ptrTohead, int index, int data){
    
    if(*ptrTohead==NULL){
        
        printf("List is empty and you need to add data at head first\n");
        
        *ptrTohead = createAndGetNode(data);
        
        printf("Node is being added to 0th index on head\n");
        
        return;
    }
    
    if(getLenght(ptrTohead)>=index){
        
        struct node* newNode = createAndGetNode(data);
    
        struct node* current = *ptrTohead;
    
        if(index==0){
            
            newNode->next = current;
            
            *ptrTohead = newNode;
        }
        else{
            for(int i = 0; i < index-2; i++){
        
                current=current->next;
            } 
            
            newNode->next = current->next;
    
            current->next = newNode;
        }

    }
    else{
        
        printf("Node is being added at wrong index\n");
        
        return;
    }

        
}

void sortedInsert(struct node**ptrTohead, struct node* newNode){
    
    struct node* current = *ptrTohead;
    
    int index = 1;
    
    while(current && current->data < newNode->data){
 
        printf("Index:%d data:%d\n", index,current->data);
        current=current->next;
        index++;
        printf("%p:%d\n", current, current->data);
    }
    
    printf("final index:%d\n", index);
    insertNodeNth(ptrTohead, index, newNode->data);
}

//detect a loop in the linked list.
//Time Complexity is O(n)
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

//swap consecutive pair of linked list
//1->2->3->4->NULL
//2->1->4->3->NULL
void swapPair(struct node**head){
    
    struct node* current, *next, *previous;
    previous=*head;
    current=(*head)->next;
    *head=current;
    
    while(1){
        
        next=current->next;
        current->next=previous;
        
        if(next==NULL || next->next==NULL){
            previous->next = next;
            break;
        }
        
        previous->next = next->next;
        
        previous=next;
        
        current=previous->next;
    }
    
    
}

void insertAtTail(struct node** head, int data){
    
    struct node*newNode = createAndGetNode(data);
    struct node*current=*head;
    
    if(*head==NULL){
        *head=newNode;
        return;
    }
    
    while(current->next!=NULL){
        current=current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    
}

//remove duplicates from sorted linked list.
void removeDupSortedLL(struct node**head){
    
    if(*head==NULL){
        return;
    }
    
    struct node*current=*head;
    
    while(current!=NULL){
        
        if(current->next!=NULL && current->data==(current->next->data)){
            
            struct node* delete = current->next;
            current->next = delete->next;
            free(delete);
        }
        
        current=current->next;
    }
    
}

//remove duplicates from unsorted linked list.
void removeDupUNSortedLL(struct node**head){
    
   //array size will depend upon 
   //max value of data type.
   int count[256]={0};
   
   if(*head==NULL){
       return;
   }
   
   struct node*current=*head;
   
   count[abs(current->data)]++;
   
   while(current->next!=NULL){
       
       if(count[abs(current->next->data)]==0){
           count[current->next->data]++;
           current=current->next;
       }
       else{
           struct node*delete=current->next;
           current->next=delete->next;
           free(delete);
       }
   }
}

int main()
{
    struct node* head = NULL;
    
    struct node** ptrTohead = &head;
    
    // for(int i = 1 ; i<=5; i++){
         
    //      //printf("%d\n",i);
    //      insertAtTail(ptrTohead,rand());
         
    // }
    //printlist(ptrTohead);
    
    insertAtTail(ptrTohead,-4);
    insertAtTail(ptrTohead,10);
    insertAtTail(ptrTohead,15);
    insertAtTail(ptrTohead,19);
    insertAtTail(ptrTohead,19);
    insertAtTail(ptrTohead,19);
    insertAtTail(ptrTohead,-4);
    insertAtTail(ptrTohead,-2);
    insertAtTail(ptrTohead,2);
    
    // insertAtTail(ptrTohead,5);
    
    // DeleteList(ptrTohead);
    
    // printf("\nInteger is = %d\n",pop(ptrTohead));
    
    // printlist(ptrTohead);
    
    // printf("\nInteger is = %d\n",pop(ptrTohead));
    
    //printlist(ptrTohead);
    
    // insertNodeNth(ptrTohead, 1, 16);
    
    // printlist(ptrTohead);
    
    // insertNodeNth(ptrTohead, 2, 45);
    
    // printlist(ptrTohead);
    
    // insertNodeNth(ptrTohead, 0, 90);
    
    // printlist(ptrTohead);

    //sortedInsert(ptrTohead, createAndGetNode(3));
    
    //printlist(ptrTohead);
    
    //swapPair(ptrTohead);
    
    printlist(ptrTohead);
    
    removeDupUNSortedLL(ptrTohead);
    
    //insertNodeNth(ptrTohead,2,0);
    
    printlist(ptrTohead);

    return 0;
}







