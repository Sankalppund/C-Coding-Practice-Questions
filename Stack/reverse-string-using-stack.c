/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX 101

int stack[MAX];

int top=-1;

//function to push charcter in stack
void push(char x){
    
    if(top==MAX-1){
        printf("overflow error\n");
        return;
    }
    
    stack[++top]=x;
}

//function to pop character from stack
void pop(){
    top--;
}

//function to get top character from stack
char Top(){
    return(stack[top]);
}

//function to reverse the string using stack functions'
void reversestring(char *c, int l){
    
    for(int i=0;i<l;i++){
        
        printf(":%c ",c[i]);
        push(c[i]);
    }
    
    for(int i=0;i<l;i++){
        
        c[i] = Top();
        pop();
    }
}

//main function.
int main()
{
    printf("Enter string you want to reverse: \n");
    char c[50];
    scanf("%s",c);
    printf("Entered string is: %s %d\n",c, strlen(c));
    reversestring(c,strlen(c));
    printf("Reversed string is : %s\n",c);
    return 0;
}


