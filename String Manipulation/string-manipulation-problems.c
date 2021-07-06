/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//compress a string
//aabbcc->a2b2c2
void compressString(char* str){
    
    size_t len = strlen(str);
    
    int count=1;
    
    for(int i=0; i<len; i++){
        
        while(i<len && str[i]==str[i+1]){
            count++;
            i++;
        }
        
        if(count==1){
           printf("%c",str[i]);
        }
        else{
            printf("%c%d",str[i],count);
            count=1;
        }
    }
}

//remove duplicates using iterative method
//Time Complexity: O(n2)
//space Complexity: O(1)
char* removeDuplicate(char* str){
    
    int i,j,k;
    
    k=0;
    for(i=0;i<=strlen(str);i++){
        
        for(j=0; j<i; j++){
            
            if(str[i]==str[j]){
                break;
            }    
        }    
        
        
        if(j==i){
            str[k++]=str[i];
        }
        
    }
    
    return str;
}

//remove duplicates using Hashing
//Time complexity: O(n)
#define BINSIZE 256
#define UNIQUE 0
#define MARKED 1
char* removeDuplicate_hash(char* str){
    
    short binTable[BINSIZE]={'0'};
    int startIndex=0;
    int resultIndex=0;
    unsigned char binTableIndex = 0;
    
    while(*(str+startIndex)){
        
        binTableIndex = *(str+startIndex);
        
        if(binTable[binTableIndex]==UNIQUE){
            
            binTable[binTableIndex]=MARKED;
            
            *(str+resultIndex)=*(str+startIndex);
            
            resultIndex++;
        }
        
        startIndex++;
    }
    
    *(str+resultIndex)='\0';
    
    return str;
}


char* removeDuplicate_hashAlt(char* str){
    
    int count[256]={0};
    int i=0;
    int k=0;
    
    while(*(str+i)!=NULL){
 
        if(count[*(str+i)]==0){

            count[*(str+i)]++;
            *(str+k)=*(str+i);
            k++;
        }
        
        i++;
    }

    *(str+k)='\0';

    return str;
}

//reverse the given string with given size
char* reverseString(char* str, size_t stringSize){
    
    char*start,*end;
    start=str;
    end=str;
    
    for(int i=0; i<stringSize-1;i++){
        end++;
    }
    
    for(int j=0; j<stringSize/2;j++){
        
        char ch = *end;
        
        *end=*start;
        
        *start=ch;
        
        start++;
        
        end--;
    }
    
    return str;
}

//reverse string with start and end
//of the string.
void reverse(char*start, char*end){
    
    char temp;
    
    while(start<end){
        
        temp=*end;
        *end=*start;
        *start=temp;
        start++;
        end--;
    }
    
}

//reverse word
//"How are you -> you are How"
void reverWord(char *str){
    
    char *start=NULL;
    
    char *temp=str;
    
    while(*temp){
        
        if(start==NULL && *temp!=' '){
            
            start = temp;
        }
        
        if(start && (*(temp+1)==' ' || *(temp+1)=='\0')){
            
            reverse(start,temp);
            start=NULL;
        }
        
        temp++;

    }
    
    reverse(str,temp-1);
}

//reverse word with more number of spaces.
// void reverWord(char *str){
    
//     char *start=NULL;
    
//     char *temp=str;
    
//     while(*temp){
        
//         if(start==NULL && *temp!=' '){
            
//             start = temp;
//         }
        
//         if(start && (*(temp+1)==' ' || (*(temp+1)==' ' && *(temp+2)==' ')|| *(temp+1)=='\0')){
            
//             reverse(start,temp);
//             start=NULL;
//         }
        
//         temp++;

//     }
    
//     reverse(str,temp-1);
// }

//"<hello> world\\"
//converts to "\<hello\> world\\"
char* escape_char(char* str){
    
    char*newString = (char*)malloc(100*sizeof(char));
    
    int index=0;
    
    while(*str!='\0'){
        
        char temp = *str;
        
        if(*str=='<' || *str=='>' || *str=='\\'){
            
            newString[index++] = '\\';
        }
        
        newString[index++] = temp;
        
        str++;
    }
    
    //index++;
    
    newString[index]='\0';
    
    return newString;
}

void NumberOfWords(char* str){
    
    int count=0;
    
    while(*str!='\0'){
       
        if(*str==' ' || *str=='\0'){
            count++;
        }
    
        str++; 
    }
    
    printf("Total Number of words = %d\n", count+1);
}

//sort charcters in the String
#define MAX 26 

void sortString(char*str){
    
    
    char charData[MAX]={0};
    
    for(int i=0; i<strlen(str); i++){
        
        printf("str[i]=%c & str[i]-'a'= %d charData[str[i]-'a'] = %d\n",str[i],str[i]-'a', charData[str[i]-'a']);
        charData[str[i]-'a']++;
        printf("str[i]=%c & str[i]-'a'= %d charData[str[i]-'a'] = %d\n",str[i],str[i]-'a', charData[str[i]-'a']);
    }
    
    for(int i=0; i<MAX; i++){
        
        for(int j=0;j<charData[i];j++){
            
            printf("%c",(char)('a'+i));
        } 
    }
}

//use hash table to get max occurance of character in a String
//hash table is character array. each character in a string 
//has its associated ASCII value (Char l has ASCII value 108)
//we take string i.e. its ASCII value as index of hash table
//increment the value at that index each time we come across
//repeating character.
void maxOccInString(char* str){
    
    int len = strlen(str);
    
    char hash[127]={0};
    
    int max=0;
    
    char result;
    
    for(int i=0; i<len; i++){
        
        //print for understanding purpose
        printf("hash[str[i]] = %d & %d & %d\n",hash[i], str[i], hash[str[i]]);
        
        //post increment the value at index str[i] 
        hash[str[i]]++;
        
        
        if(max<hash[str[i]]){
            
            max = hash[str[i]];
            
            result = str[i];
        }
    }
    
    printf("Max occuriung character is : %c and has occured %d times.\n", result, hash[result]);
    
}

//myatoi: This function converts character
//string into integer string.
int myatoi(const char* str){
    
    if(*str==NULL){
        return -1;
    }
    
    int result=0;
    
    int sign=1;
    
    int index=0;
    
    if(*str=='-'){
        
        sign = -1;
        index++;
    }
    
    // Iterate through all characters
    // of input string and update result
    // take ASCII character of corrsoponding digit and
    // subtract the code from '0' to get numerical
    // value and multiply res by 10 to shuffle
    // digits left to update running total
    
    for(;str[index]!='\0'; index++){
        
        result = result*10 + (str[index]-'0');
    }
    
    return (sign*result);
}


//myitoa: This function converts an 
//integer number to a null-terminated string.
//base can be 2(binary), 10(decimal), 16(hex)
char* myitoa(int num, char*str, int base){
    
    int index = 0;
    
    bool isNegative = false;
    
    int rem;
    
    if(num==0){
        
        str[index++]='0';
        str[index] = '\0';
        return str;
    }
    
    if(num<0 && base==10){
        
        isNegative=true;
        
        num=-num;
    }
    
    while(num){
        
        rem = num%base;
        
        str[index++] = (rem>9)? ((rem-10) +'a') : (rem + '0');
        
        num = num/base;
    }
    
    if(isNegative){
        
        str[index++]='-';
    }
    
    str[index] = '\0';
    
    reverseString(str,index);
    
    return str;
    
}

void swap(char *a, char *b)
{
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

//string permutation
//shuffle the character within string
void stringPermutation(char*str, int start, int end){
    
    static int x=0;
    if(start==end){
        printf("%d:%s\n",++x,str);
    }
    else{
        
        int i;
        
        for(i=start; i<=end; i++){
            
            swap(str+start,str+i);
            
            stringPermutation(str,start+1,end);
            
            swap(str+start,str+i);
        }
    }
}

//function to print duplicate characters from the 
//given string
char* printDuplicate(char*str){
        
    //integer array which would store
    //corrsoponding ASCII integer values.
    int count[256]={0};
    
    int strIdx=0;
    
    int dupIdx=0;
    
    while(strIdx<strlen(str)){
        
        count[str[strIdx]]++;
        
        if(count[str[strIdx]]==2){
            
            str[dupIdx++]=str[strIdx];
        }
        
        strIdx++;
    }
        
    str[dupIdx]='\0';
    
    return str;
        
}

//remove duplicates char of string 1 from string 2.
//Given two strings s1 & s2, remove those characters 
//from first string which are present in second string. 
//Both the strings are different and contain only lowercase characters.
char* rmDupS1S2(char*str1, char*str2){
    
    int count[256]={0};
    
    int l1 = strlen(str1);
    
    int l2 = strlen(str2);
    
    int i1=0,i2=0,i3=0;;
    
    while(i2<l2){
        
        count[str2[i2++]]++;
    }
    
    
    while(i1<l1){
        
        if(count[str1[i1]]==0){
            
            str1[i3++]=str1[i1];
        }
        
        i1++;
    }
    
    str1[i3]='\0';
    
    return str1;
}

//reverseString recursively
void recRevStr(char*str){
    
    if(*str=='\0'){
        return;
    }
    
    recRevStr(str+1);
    
    printf("%c",*str);
    
}


bool stringAnagram(char*str1, char*str2){
    
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    
    if(l1!=l2){
        printf("String are not anagram\n");
        return false;
    }
    
    
    if(str1==NULL || str2==NULL){
        printf("NULL\n");
        return false;
    }
    
    int i=0,j=0;
    
    int count1[256] = {0};
    int count2[256] = {0};
    
    while(*str1!='\0'||*str2!='\0'){
        count1[*str1]++;
        count2[*str2]++;
        str1++;
        str2++;
    }
    
    for(int i=0; i<256; i++){
        
        if(count1[i]!=count2[i]){
            printf("String are not anagram\n");
            return false;
        }
    }
    
    printf("String are anagram\n");
    return true;
}

char* sortstringP(char*str){
    
    int x=0;
    
    char strArr[26]={0};
    
    for(int i=0; i<26; i++){
        
        strArr[str[i]-'A']++;
    }
    
    for(int j=0; j<26; j++){
        
        for(int k=0; k<strArr[j]; k++){
            
            str[x++] = (char)('A'+j);
        }
    }
    
    str[x]='\0';
    
    return str;

}

bool anagramWSort(char*str1, char*str2){
    
    str1 = sortstringP(str1);
    str2 = sortstringP(str2);
    
    printf("S1:%s\n",str1);
    printf("S2:%s\n",str2);
    
    while(*str1!='\0' && *str2!='\0'){
        
        if(*str1==*str2){
            str1++;
            str2++;
            printf("S2");
        }
        else{

            break;
        }
    }

    if(*str1=='\0' && *str2=='\0'){
        
        printf("\nStrings are anagram\n");
        return true;
    }
    
    printf("\nStrings are not anagram\n");
    return false;
    
}

int main(){
    
    char string1[100]= "apple";
    char string2[100] = "elppa";
    
    //sortstringP(string1);
    
    stringAnagram(string1,string2);
    
    //printf("%s\n",string1);
    // reverWord(string1);
    // printf("%s\n",string1);
    // //char*ret;
    
    // char string[] = "<hello> world\\";
    
    // printf("%s",escape_char(string));

    
    //stringOcc("AAaa");
    
    //ret=rmDupS1S2(string2,string1);
    
    //printf("%s\n",ret);
    //printf("%s\n",myitoa(10,string,16));
    
    //NumberOfWords(string);
    
    //printf("String after removal of duplicates = %s\n",string);
    
    return 0;
}



























