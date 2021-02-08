/*Header Files*/
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <stdbool.h>

/*Malloc implementation using sbrk without free*/
void* my_malloc(size_t size){

	void*p = sbrk(0);

	void* request = sbrk(size);

	if(request==(void*)-1){

		return NULL;
	}
	else{

		assert(request==p);

		return p;
	}

}

/*main function*/
int main(){

	int*p=(int*)my_malloc(10);

	printf("Reuqested memory : %p\n",p);

	*p = 100;

	printf("data in reuqested memory : %d\n",*p);	

	return 0;
}