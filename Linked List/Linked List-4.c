/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Singly linked list structure/node */
struct node{
    int data;
    struct node* next;
};

/*Doubly linked list structure/node */
struct DLnode{
    int data;
    struct DLnode*next;
    struct DLnode*previous;
};

/**********Singly Linked List************/

//insert or push elements at the last nodes.
struct node* insert(struct node* head, int data){
    
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode->data=data;
    
    newNode->next=NULL;
    
    if(head==NULL){
        
        printf("The list is empty, adding this 1st node to head\n");
        
        head=newNode;
        
        return head;
    }
    
    printf("The list is non-empty, pushing the values to last node\n");
    
    struct node* current = head;
    
    while(current->next!=NULL){
        current=current->next;
    }
    
    newNode->next=current->next;
    
    current->next=newNode;
    
    return head;
}

void printlist(struct node* head){
    
    if(head==NULL){
        printf("Linked list is empty\n");
        return;
    }
    struct node* current = head;
    
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    
    printf("\n");
}

int getsizeofLL(struct node* head){
    int count = 0;
    struct node* current = head;
    while(current!=NULL){
        count++;
        current=current->next;
    }
    return count;
}

void recursive_printlist(struct node* head){
    
    if(head==NULL){return;}
    
    printf("%d ",head->data);
    
    recursive_printlist(head->next);
}

void reverseprint(struct node* head){
    
    if(head==NULL){return;}
    
    reverseprint(head->next);
    
    printf("%d ",head->data);
}


struct node* insertatNth(struct node*head, int data, int pos){
    
    if(pos>getsizeofLL(head)+1){
        printf("Currently linked list has %d nodes and thus cannot add at position %d\n",getsizeofLL(head),pos);
        return head;
    }
    
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode->data=data;
    
    newNode->next=NULL;
    
    
    if(pos==1){
        
        newNode->next=head;
        
        head=newNode;
        
        return head;
    }
    
    struct node*current = head;
    
    for(int i = 0; i<(pos-2); i++){
        
        current=current->next;
    }
    
    newNode->next=current->next;
    
    current->next=newNode;
    
    return head;
    
}

struct node* deleteNthNodefromfront(struct node*head, int pos){
    
    if(pos==0 || pos>getsizeofLL(head)){
        printf("Currently linked list is numbered from 1 to %d nodes and thus cannot delete %d position.\n",getsizeofLL(head),pos);
        return head;
    }
    
    struct node* delete=NULL;
    
    if(pos==1){
        
        delete=head;
        head=head->next;
        free(delete);
        return head;
    }
    
    struct node*previous=head;
    
    for(int i = 0; i<(pos-2); i++){
        previous=previous->next;
    }
    
    delete=previous->next;
    previous->next=delete->next;
    free(delete);
    
    return head;
}

struct node* deleteNthFromEnd(struct node*head, int pos){
    
    struct node*delete=NULL;
    struct node*previous=head;
    int LLSize = getsizeofLL(head);
    int endPos = LLSize-pos+1;
    
    if(endPos==1){
        
        delete=head;
        head = head->next;
        free(delete);
        return head;
    }
    
    for(int i = 0; i<(endPos-2); i++){
        previous=previous->next;
    }
    
    delete=previous->next;
    previous->next=delete->next;
    free(delete);
    
    return head;
}

//delete nth node from end in one traversal using two pointers.
struct node* deleteNthFromEndDb(struct node*head, int pos){
    
    struct node*first=head;
    struct node*second=head;

    for(int i=0; i<pos; i++){
        
        second=second->next;
    }

    if(second==NULL){
        head=head->next;
        free(first);
        return head;
    }
    
    while(second->next!=NULL){
        second=second->next;
        first=first->next;
    }
    
    struct node*previous=first;
    first=first->next;
    previous->next=first->next;
    free(first);
    
    return head;
}

/*********************************************************************/
/*Doubly Linked List practice*/
/*********************************************************************/
//Gives new doubly linked list node
struct DLnode* getNewNode(int data){
    
    struct DLnode*NewNode=(struct DLnode*)malloc(sizeof(struct DLnode));
    
    NewNode->data=data;
    NewNode->next=NULL;
    NewNode->previous=NULL;
    
    return NewNode;
}

//insert node at head
struct DLnode* insertAtHeadDL(struct DLnode*head, int data){
    
    struct DLnode*NewNode=getNewNode(data);
    
    if(head==NULL){
        
        head=NewNode;
        return head;
    }
    
    head->previous=NewNode;
    NewNode->next=head;
    head=NewNode;
    
    return head;
}

//insert at nth position.
struct DLnode* NthinsertDL(struct DLnode*head, int data, int pos){
    
    struct DLnode*NewNode=getNewNode(data);
    
    if( head==NULL){
        
        head=NewNode;
        return head;
    }
    if(pos==1){
        
        head->previous = NewNode;
        NewNode->next = head;
        head = NewNode;
        return head;
    }
    
    
    struct DLnode*current=head;
    struct DLnode*ahead;
    
    for(int i=0; i<(pos-2); i++){
        current=current->next;
    }
    
    ahead=current->next;
    NewNode->next=ahead;
    NewNode->previous=current;
    current->next=NewNode;
    ahead->previous=NewNode;
    
    return head;
}

//delete nth node from front.
struct DLnode* deleteDLN(struct DLnode*head, int pos){
    
    struct DLnode*current=head;
    struct DLnode*delete;
    struct DLnode*ahead;
    
    if(pos==1){
        delete=head;
        head=head->next;
        free(delete);
        return head;
    }
    
    for(int i=0; i<(pos-2); i++){
        current=current->next;
    }
    
    delete=current->next;
    ahead=delete->next;
    current->next=ahead;
    
    if(ahead!=NULL){
    
        ahead->previous=current;
    }

    free(delete);
    
    return head;
}

//printDLL
void printDLL(struct DLnode* head){
    
    struct DLnode*current=head;
    
    while(current!=NULL){
        
        printf("%d ",current->data);
        current=current->next;
    }
    
    printf("\n");
}

//reverseprint
void rvprintDLL(struct DLnode* head){
    
    struct DLnode*current=head;
    
    while(current->next!=NULL){
        current=current->next;
    }
    
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->previous;
    }
    
    printf("\n");
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

            printf("Loop Detected and now at %d\n",slow->data);
            
            removeloop(slow, head);
            //llcycle(slow,head);
            return true;
        }
        
    }
    
    printf("Loop not Detected\n");
    
    return false;
}

//functrion to remove loop present inside the linked list.
void removeloop(struct node* loopNode, struct node*head){
    
    struct node* ptr1;
    struct node* ptr2;
    
    ptr1=head;
    
    while(1){
        
        ptr2=loopNode;

        while(ptr2->next!=loopNode && ptr2->next!=ptr1){
            
            ptr2=ptr2->next;
        }
        
        if(ptr2->next==ptr1){

            break;
        }
        
        ptr1=ptr1->next;
        
    }
    
    ptr2->next=NULL;
    
}


//this is same as one below it.
void llcycle(struct node* loopNode, struct node*head){
    
    struct node* ptr1;
    struct node* ptr2;
    
    ptr1=head;
    
    while(1){
        
        ptr2=loopNode;

        while(ptr2->next!=loopNode && ptr2->next!=ptr1){
            
            ptr2=ptr2->next;
        }
        
        if(ptr2->next==ptr1){

            break;
        }
        
        ptr1=ptr1->next;
        
    }
    
    printf("Cycle begins at:%d\n",ptr1->data);
    
}


//Given a linked list, return the node where the cycle or loop begins. 
//If there is no cycle, return null.
struct node* detectCycle(struct node *head) {
    
    if(head==NULL){
        return NULL;
    }
    
    struct node *slow=head;
    struct node *fast=head;

    if(slow->next==NULL || fast->next->next==NULL){
        
        return NULL;
    }
    
    fast=fast->next->next;
        
    slow=slow->next;
    
    while(fast!=slow && fast!=NULL){
       
        slow=slow->next;
        
        if(fast->next!=NULL){
             
            fast=fast->next->next;
        }
        else{
            return NULL;
        }
    }
    
    if(fast==NULL){
        
        return NULL;
        
    }
    
    slow=head;
    
    while(slow!=fast){
                
        fast=fast->next;
        
        slow=slow->next;
    }
    
    return slow;
}

//delete m nodes after n nodes in linked list
void deleteMafterN(struct node* head, int m, int n){
    
    if(head==NULL){
        return -1;
    }
    
    struct node* current, *previous, *delete;
    
    current=head;
    
    printf("n before while:%d\n",n);
    
    while(--n){
        
        printf("n in while while:%d\n",n);
        current=current->next;
    }

    previous = current;
    
    current=current->next;
    
    while(current && m){
        m--;
        delete = current;
        previous->next = current->next;
        current=current->next;
        free(delete);
        
    }
    
}

//delete node without head pointer
void deleteNodeWOHEAD(struct node* node){
    
    if(node==NULL){
        return -1;
    }
    
    struct node* delete = node->next;
    
    node->data = delete->data;
    
    node->next = delete->next;
    
    free(delete);
}

//swap two nodes in linked list
struct node* swapTwoNodes(struct node*head, int node1, int node2){
    
    if(node1==node2){
        return head;
    }
    
    struct node* prevNode1=NULL, *prevNode2=NULL, *currNode1, *currNode2;
    
    currNode1=head;
    
    while(currNode1 && currNode1->data!=node1){
        
        prevNode1=currNode1;
        currNode1=currNode1->next;
    }
    
    currNode2=head;
    
    while(currNode2 && currNode2->data!=node2){
        
        prevNode2=currNode2;
        currNode2=currNode2->next;
    }
    
    if(currNode1==NULL || currNode2==NULL){
        return;
    }
    
    if(prevNode1!=NULL){
        prevNode1->next=currNode2;
    }
    else{
        head=currNode2;
    }
    
    if(prevNode2!=NULL){
        prevNode2->next=currNode1;
    }
    else{
        head=currNode1;
    }
    
    struct node* temp = currNode2->next;
    currNode2->next=currNode1->next;
    currNode1->next=temp;
    
    return head;
}

//merge two sorted linked list so that
//resultant linked is also sorted
//1->2->4->null
//3->5->6->null
//1->2->3->4->5->6->null
struct node* mergeTwoLL(struct node*head1, struct node*head2){
    
    if(head1==head2){
        
        return head1;
    }
    
    if(!head1){
        return head2;
    }
    
    if(!head2){
        return head1;
    }
    
    if(head1->data < head2->data){
        
        head1->next = mergeTwoLL(head1->next,head2);
        return head1;
    }
    else{
        
        head2->next = mergeTwoLL(head1,head2->next);
        return head2;
    }
    
}

//merge two sorted linked list without recursion.
struct node* mergeTwoLLALt(struct node* head1, struct node* head2){
    
    if(head1==head2){
        return head1;
    }
    
    if(!head1){
        
        return head2;
    }
    
    if(!head2){
        
        return head1;
    }
    
    struct node*mhead = (struct node*)malloc(sizeof(struct node));
    
    mhead->data=-1;
    
    mhead->next=NULL;
    
    struct node*mergehead=mhead;
    
    while(head1 && head2){
        
        printf("h1:%d\n",head1->data);
        printf("h2:%d\n",head2->data);
        if(head1->data < head2->data){
            
            mergehead->next = head1;
            
            head1 = head1->next;
        }
        else{
            
            mergehead->next = head2;
            
            head2 = head2->next;
        }
        
        mergehead = mergehead->next;
    }
    
    if(head1){
       
        mergehead->next = head1;
            
        head1 = head1->next;
        
        mergehead=mergehead->next;
    }
    
    if(head2){
        
        mergehead->next = head2;
            
        head2 = head2->next;
        
        mergehead=mergehead->next;
    }
    
    return mhead->next;
}

//this function reverses the linked list-> iterative method.
//TC:o(n)
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

//This function reverse linked list recursively
struct node* reverseLLRec(struct node*head){
    
    if(head==NULL){
        return NULL;
    }
    
    struct node* rthead;
    
    struct node* current=head;
    
    if(current->next==NULL){
       
       rthead = current;
       
       return rthead;
    }
    
    rthead=reverseLLRec(current->next);
    
    struct node*new = current->next;
    
    new->next=current;
    
    current->next = NULL;
    
    return rthead;
}

//delete consecutive nodes in linked list.
struct node* deleteConsecutiveNodes(struct node*head, int pos){
    
    struct node*current=head,*delete;
    
    int cons=2;
    
    if(pos==1){
        
                
        while(current && cons){
        
            delete=current;
            current=delete->next;
            free(delete);
            cons--;
        }
        
        return current;
    }
    else{
        
        for(int i=0; i<(pos-2); i++){
        
            current=current->next;
        }
        
        while(current->next && cons){
        
            delete=current->next;
            current->next=delete->next;
            free(delete);
            cons--;
        }
        
        return head;
    }
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


int main()
{
    struct node*head=NULL;
    struct node*head1=NULL;
    
    head = insert(head,1);
    head = insert(head,2);  
    head = insert(head,3);
    head = insert(head,4);
    head = insert(head,5);
    
    // head1 = insert(head1,3);
    // head1 = insert(head1,6);
    // head1 = insert(head1,7);
    //struct node*del = head->next->next;
    
    //head->next->next->next->next->next=head->next->next->next->next;//;
    
    printlist(head);
    //printlist(head1);
    //head=reverseLLRec(head);
    //printlist(head1);
    
    //deleteMafterN(head,1,3);
    
    //deleteNodeWOHEAD(del);
    
    //printlist(head);
    
    //printf("%d\n",detectloop(head));
    //head = detectCycle(head);
    
    //printf("Cycle begin detected at : %d\n",head->data);
    
    //deleteMafterN(head,4,2);
    
    // head=swapTwoNodes(head,2,5);
    
    // printlist(head);
   
   //head=mergeTwoLL(head,head1);
   //head = mergeTwoLLALt(head,head1);
   
   //head=deleteNthFromEndDb(head,4);
   head=deleteConsecutiveNodes(head,5);
   printlist(head);
    
    return 0;
}















