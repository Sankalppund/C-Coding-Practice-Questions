
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
static int myCompare (const void * a, const void * b)
{
    return strcmp (*(const char **) a, *(const char **) b);
}
 
void sort(const char *arr[], int n)
{
    qsort (arr, n, sizeof (const char *), myCompare);
}
 
int main ()
{
    //Array of const charcter pointers
    //[const char*p1, const char*p2, const char*p3]
    
    const char *arr[] = {"GeeksforGeeks", "GeeksQuiz", "CLanguage"};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;
    
    printf("%p,%p,%p\n",arr[0],arr[1],arr[2]);
    printf("%s,%s,%s\n",arr[0],arr[1],arr[2]);
 
    printf("Given array is\n");
    for (i = 0; i < n; i++)
        printf("%d: %s \n", i, arr[i]);
 
    sort(arr, n);
 
    printf("\nSorted array is\n");
    for (i = 0; i < n; i++)
        printf("%d: %s \n", i, arr[i]);
 
    return 0;
}
