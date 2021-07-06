/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h> //for INT_MIN and INT_MAX

//Macro to get max value
#define MAX(a,b) ((a>b)?a:b)

//binary tree node.
struct node{
    
    int data;
    
    struct node*left;
    
    struct node*right;
};

//function to get new node.
struct node* getNewNode(int data){
    
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode->data=data;
    
    newNode->left=NULL;
    
    newNode->right=NULL;
    
    return newNode;
}

//function to insert new node in the BST.
struct node* insert(struct node* root, int data){
    
    if(root==NULL){
        
        root = getNewNode(data);
        
        return root;
    }
    else if(data <= root->data){
        
        root->left = insert(root->left,data);
    }
    else if(data > root->data){
        
        root->right = insert(root->right, data);
    }
    
    return root;
}

//function to search node with given data
//in the BST.
bool Search(struct node* root, int data){
    
    if(root==NULL){
        
        return false;
    }
    else if(root->data==data){
        return true;
    }
    else if(data <= root->data){
        return Search(root->left, data);
    }
    else if(data > root->data){
        return Search(root->right, data);
    }
    
}

//this function finds a node with max value.
int maxinBST(struct node* root){
    
    if(root==NULL){
        return INT_MIN;
    }
    
    int rootRes = root->data;
    
    int leftRes = maxinBST(root->left);
    
    int rightRes = maxinBST(root->right);
    
    if(leftRes>rootRes){
        
        rootRes = leftRes;
    }
    if(rightRes>rootRes){
        
        rootRes = rightRes;
    }
    
    return rootRes;
}


//max in ordered BST in one traversal
//keep traversing in right direction
int findmax(struct node* root){
    
    struct node*current=root;
    
    while(current && current->right!=NULL){
        
        current=current->right;
    }
    
    return current->data;
    
}

//min in ordered BST in one traversal
//Keep traversing in left direction.
int findmin(struct node* root){
    
    struct node*current=root;
    
    while(current && current->left!=NULL){
        current=current->left;
    }
    
    return current;
}

//this function find node with min value
int minINBST(struct node* root){
    
    if(root==NULL){
        
        return INT_MAX;
    }
    
    int rootRes = root->data;
    
    int leftRes = minINBST(root->left);
    
    int rightRes = minINBST(root->right);
    
    if(leftRes<rootRes){
        
        rootRes = leftRes;
    }
    if(rightRes<rootRes){
        
        rootRes = rightRes;
    }
    
    return rootRes;
}

/*this function finds max path in tree
For each node there can be four ways that the max path goes through the node:
1. Node only
2. Max path through Left Child + Node
3. Max path through Right Child + Node
4. Max path through Left Child + Node + Max path through Right Child

The idea is to keep trace of four paths and pick up the max one in the end. 
An important thing to note is, root of every subtree need to return maximum 
path sum such that at most one child of root is involved. This is needed for 
parent function call. In below code, this sum is stored in ‘max_single’ and 
returned by the recursive function.
*/
int maxPath(struct node* root, int* res){

    if(root==NULL){
        return 0;
    }
    
    int leftPath = maxPath(root->left,&res);

    int rightPath = maxPath(root->right,&res);
    
    int max_single = MAX(MAX(leftPath,rightPath)+root->data, root->data);
    
    int max_top = MAX(max_single, leftPath+rightPath+root->data);
    
    *res = MAX(*res, max_top);
    
    return max_single;
}

int findMAXsum(struct node* root){
    
    static int*res=NULL;
    
    maxPath(root,&res);

    return res;
}

//In case of binary search trees (BST), 
//Inorder traversal gives nodes in non-decreasing order.
void inorder(struct node* root){
    
    if(root==NULL){
        return;
    }
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

//Preorder traversal is used to create a copy of the tree. 
//Preorder traversal is also used to get prefix expression
//on of an expression tree.
void preorder(struct node* root){
    
     if(root==NULL){
        return;
    }
    
    printf("%d ", root->data);
    
    inorder(root->left);
    
    inorder(root->right);
}

//Postorder traversal is used to delete the tree.
void postorder(struct node* root){
    
    if(root==NULL){
        return;
    }
    
    postorder(root->left);
    
    postorder(root->right);
    
    printf("%d ", root->data);
}

//delete node in BST
struct node* deleteNodeinBST(struct node*root, int data){
    
    if(root==NULL){
        return root;
    }
    
    if(root->data > data){
        
        root->left = deleteNodeinBST(root->left, data);
    }
    else if(root->data > data){
        
        root->right = deleteNodeinBST(root->right, data);
    }
    
    //node with only one child
    if(root->left==NULL){
            
        struct node* child = root->right;
        free(root);
        return child;
    }
    else if(root->right==NULL){
            
        struct node* child = root->left;
        free(root);
        return child;
    }
    else{    
        // //node with two children
        // //get inorder successor
        // //smallest in right subtree
        // struct node* successor = findmin(root->right);
        
        // //copy inorder successor's content to this node
        // root->data = successor->data;
        
        // //delete inorder successor
        // root->right = deleteNodeinBST(root->right, successor->data);
        struct node* successorParent = root;
        
        struct node* successor = root->right;
        
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        
        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (successorParent != root)
            successorParent->left = successor->right;
        else
            successorParent->right = successor->right;
 
        // Copy Successor Data to root
        root->data = successor->data;
 
        // Delete Successor and return root
        free(successor);
        return root;
    }
    
    //return root;
}


//main function.
int main()
{
    struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    //int x = Search(root,5);
    
    // root = getNewNode(10); 
    // root->left        = getNewNode(2); 
    // root->right       = getNewNode(10); 
    // root->left->left  = getNewNode(20); 
    // root->left->right = getNewNode(1); 
    // root->right->right = getNewNode(-25); 
    // root->right->right->left   = getNewNode(3); 
    // root->right->right->right  = getNewNode(4); 
    
    // root = insert(root,1);
    // root = insert(root,2);
    // root = insert(root,3); 
    
    inorder(root);
    
    printf("\n");
    
    root = deleteNodeinBST(root,80);
    
    inorder(root);
    
    // printf("Max:%d\n",maxinBST(root));
    
    // printf("Max with findmax:%d\n",findmax(root));
 
    // printf("Min:%d\n",minINBST(root));
    
    // printf("Max Path: %d\n",findMAXsum(root));
    
    // if(x){
    //  printf("Number Found\n");   
    // }
    // else{
    //  printf("Number NOT Found\n");   
    // }
    return 0;
}





