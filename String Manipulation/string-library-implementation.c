/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//Strcmp:compares if two strings are equal.
uint32_t mystrcmp(const char* str1, const char* str2){
    
    while(*str1==*str2){

        if(*str1=='\0'||*str2=='\0'){
            break;
        }
        str1++;
        str2++;
    }
    
    if(*str1=='\0' && *str2=='\0'){
        return 0;
    }
    else{
        return 1;
    }
}

//strncmp: compares given number of bytes only.
uint32_t mystrcmpbytes(const char* str1, const char* str2, size_t nbytes){
    
    while(*str1==*str2){

        if(*str1==*str2){
            nbytes--;
            str1++;
            str2++; 
        }
        if(nbytes==0){
            return 0;
        }
    }
    return 1;
}

//strlen:gives the string length.
size_t mystrlen(const char *str)
{
    const char* offset = str;
    
    while(1){
        offset++;
        if(*offset=='\0'){
            break;
        }
    }
    return (offset-str);
}

//strcat: concatenate two strings.
char* mystrcat(char* dest, const char* src){

    while(1){
        
        dest++;
        
        if(*dest=='\0'){
            
            break;
        }
    }
    
    while(*dest++ = *src++){

    }

    return dest;
}

//strchr: Finds the first occurance of character.
uint32_t mystrchr(const char* str, char ch){

    while(1){
        
        if(*str==ch){
            return 0;
        }
        else if(*str=='\0'){
            return 1;
        }
        str++;
    }
}

//strnchr: gives position of first occurance of character.
uint32_t mystrchrFirstpos(const char* str, char ch){

    uint32_t count = 1;
    
    while(1){
        
        if(*str==ch){
            break;
        }
        else if(*str=='\0'){
            return -1;
        }
        str++;
        count++;
    }
    return count;
}

//strstr: find a substring in a string attempt1.
char* mystrstr(const char* pstr, const char* subStr){
    
    int n = mystrlen(subStr);
    char*OrgStr = subStr;
    char*retStr;

    while(*pstr!='\0'){
        
        if(*pstr==*subStr && n!=0){
            
            if(subStr==OrgStr){
                retStr=pstr;
            }
        
            pstr++;
            subStr++;
            n--;
            
            if(n==0){
                printf("found");
                return retStr;
            }
        }
        else{
            subStr=OrgStr;
            pstr++;
        }
        
    }
    
    return NULL;
}

//mystrstr check if substring is present or not.
int Mystrstr_check(const char* str1, const char* str2){
    
    const char* main=str1;
    const char* sub=str2;
    
    do{
        
        if(*str1==*str2){
            
            str1++;
            str2++;
        }
        else{
            
            str2=sub;
            str1++;
        }
        
    }while(*str1 && *str2);
    
    return !*str2 ? (str1-main)-(str2-sub) : -1;
    
}


//strcpy: copies string from source to destination.
char* mystrcpy(char*dest, const char*src){
    
    while(*dest++=*src++){}
    
    return dest;
}

//strcpy using memcpy library function.
char* mystrcpy2(char*dest, const char*src){
    
    memcpy(dest, src, mystrlen(src));
    
    return dest;
}

//strcpy using memcpy library function.
char* mystrncpy(char*dest, const char*src, size_t len){
    
    memcpy(dest, src, len);
    
    return dest;
}

//Memcpy implementation.
void* mymemcpy(void* dest, void* src, size_t nbytes){
    
    char* cdest = (char*)dest;
    char* csrc = (char*)src;
    
    while(nbytes){
        *cdest++=*csrc++;
        nbytes--;
    }
    
    return dest;
}

//Memove implementation
void* mymemmove(void* dest, void* src, size_t nbytes){
    
    char* cdest = (char*)dest;
    char* csrc = (char*)src;
    
    char temp[nbytes];
    
    for(int i=0; i<nbytes; i++){
        temp[i]=csrc[i];
        //printf("%c\n",csrc[i]);
    }
    
    for(int i=0; i<nbytes; i++){
        cdest[i]=temp[i];
    }
    
    return dest;
    
    
}

//Optimized memmove implementation which checks if overlap is present or not.
void* mymemmoveopt(void* dest, void* src, size_t nbytes){
    
    char* cdest = (char*)dest;
    char* csrc = (char*)src;
    
    if(cdest==csrc || nbytes == 0){
        
        return dest;
    }
    
    if(cdest > csrc && cdest-csrc < (int)nbytes){
        
        /* cdest overlaps with csrc */
		/*  <csrc......>         */
		/*         <cdest........>  */
		/* copy in reverse, cdest avoid overwriting csrc */
		
		for(int i=nbytes-1; i>=0; i--){
		    cdest[i] = csrc[i];
		}
		
		return dest;
    }
    
    if(cdest < csrc && csrc-cdest < (int)nbytes){
        
		/* cdest overlaps with csrc */
		/*        <csrc......>   */
		/*  <cdest........>         */
		/* copy forwards, cdest avoid overwriting csrc */
		
		for(int i=0; i<=nbytes-1; i++){
		    cdest[i] = csrc[i];
		}
		
		return dest;
    }
    
    //if not overlapping then simply memcpy
    while(nbytes){
        *cdest++=*csrc++;
        nbytes--;
    }
    
    return dest;
}


//string reversal
void reverseString(char* str){
    
    char *start, *end, ch;
    
    start = str;
    
    end = str;
    
    for(int i = 0; i<mystrlen(str)-1;i++){
        end++;
        printf("%d\n",mystrlen(str));
    }
    
    for(int j = 0; j<mystrlen(str)/2; j++){
        
        ch = *end;
        *end=*start;
        *start=ch;
        
        start++;
        end--;
    }
}

void check_palindrome(char* str){
    
    char temp[50];
    mystrcpy(temp,str);
    reverseString(str);
 
    if(mystrcmp(temp, str)){
       printf("Number is not palindrome\n");
    }
    else{
       
       printf("Number is palindrome\n"); 
    }
    
}


//check if string is palindrome.
void palindrome(char*str){
    
    if(str==NULL){
        printf("String is NULL\n");
        return;
    }
    
    int start;
    int end;
    int len = strlen(str);
    
    for(start=0,end=len-1;start<end;start++,end--){
        
        if(str[start]!=str[end]){
            printf("Not palindrome\n");
            return;
        }
    }
    
    printf("String is Palindrome\n");
}


int main()
{
    
    // char*string1 = (char*)malloc(50*sizeof(char));
    
    // char*string2 = (char*)malloc(50*sizeof(char));
    
    // char*string3 = (char*)malloc(50*sizeof(char));
    
    char string1[50];
    char string2[50];
    char* result;

    printf("Enter string 1\n");
    scanf("%s",string1);
    //check_palindrome(string1);
    printf("Enter string 2\n");
    scanf("%s",string2);
    
    //reverseString(string1);
    printf("In function:%s\n",mystrstr(string1,string2));
    // printf("Result:%d\n",mystrchrFirstpos(string1, 'o'));
    // mymemmove(string1,string2,4);
    // printf("Result:%s",string1);
    //palindrome(string1);
    return 0;
}














