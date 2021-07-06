/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    printf("\n------------------2D Array------------------\n\n");
    
    //2D array. 2 rows and 3 coloums
    //two 1D array of 3 integers
    int A[2][3] = {1,2,3,4,5,6};
    
    //pointer to 2D array
    int (*p)[3] = A;
    
    //Below pointer access are valid
    //address of 1st array of 3 integers
    printf("A:=>     %p\n",A);
    printf("&A[0]:=> %p\n",&A[0]);
    printf("A[0]:=>  %p\n",A[0]);
    printf("*A:=>    %p\n",*A);
    
    //address of 2nd array of 3 integers
    printf("\nA+1:=>     %p\n",A+1);
    printf("&A[0]+1:=> %p\n",&A[0]+1);
    printf("&A[1]:=>   %p\n",&A[1]);
    printf("A[1]:=>    %p\n",A[1]);
    printf("*(A+1):=>  %p\n",*(A+1));
    
    //accessing 3rd element of 2nd array
    //i.e.A[1][3] = 6
    printf("\n*(A+1)+2:=>     %p\n",*(A+1)+2);
    printf("*(*(A+1)+2):=>  %d\n",*(*(A+1)+2));
    
    //accessing 2nd element of 1st array
    //i.e. A[0][1] = 2
    printf("*((*A)+1):=>  %d\n",*((*A)+1));
    
    //A[i][j] can be accessed as *(A[i]+j)
    // or *(*(A+i)+j)
    printf("\ni=0, j=2 : *(A[0]+2):=>  %d\n",*(A[0]+2));
    printf("i=1, j=1 : *(*(A+1)+1):=>  %d\n\n",*(*(A+1)+1));
    
    printf("\n------------------3D Array------------------\n\n");
    
    //3D array
    //Three 1D array of 4 integers.
    // first: 1,2,3,4 = [1,2][3,4]
    // second: 5,6,7,8 = [5,6][7,8]
    //third: 9,10,11,12 = [9,10][11,12]
    //B[3][2][2] = {{{1,2},{3,4}},{{5,6},{7,8}},{{9,10},{11,12}}}
    //               <-0-> <-1->   <-0-> <-1->    <-0->  <-1->
    //              <-----0-----> <-----1-----> <-----2----->
    int B[3][2][2] = {1,2,3,4,5,6,7,8,9,10,11,12};
    
    //pointer to 3D array
    int (*pt)[2][2] = B;

    printf("B:=>  %p\n",B);
    printf("*B:=> %p\n",*B);
    printf("B[0]:=> %p\n",B[0]);
    printf("B[0][0]:=> %p\n",B[0][0]);
    
    //B[i][j][k]
    //*(B[i][j]+k) or *(*(B[i]+j+k)) or *(*(*B+i)+j)+k)
    //Example B[0][1][2]
    printf("B[0][1][2]:=> %d\n",B[0][1][1]);
    printf("Consider i=0, j=1, k=2\n");
    printf("*(B[0][1]+2):=>     %d\n",*(B[0][1]+2));
    printf("*(*(B[0]+1)+2):=>   %d\n",*(*(B[0]+1)+2));
    printf("*(*(*(B+0)+1)+2):=> %d\n",*(*(*(B+0)+1)+2));
    printf("*(B[0][1]+1):=>     %d\n",*(B[0][1]+1));
    printf("*(*(*(B+2)+2)+2):=>     %d\n",*(*(*(B+2)+1)+1));
    
    
    return 0;
}


