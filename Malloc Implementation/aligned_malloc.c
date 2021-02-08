/*Header files*/
#include <stdio.h>
#include <stdlib.h>


/*Function Name: aligned_malloc
  description: It will allocate memory with starting address 
  multiple of alignment passed and returns pointer 
  to it on success.

  Arguments:- number of bytes & Alignment Boundry

  Return :- NULL on error
  valid pointer on success
	
  Ex. 
  aligned_malloc(50,128);
  This will allocate 50 bytes of memory with
  starting address multiple of 128.
*/	
void* aligned_malloc(size_t bytes, size_t alignment){

	/*p1 to store malloc return and p2 to give 
	modified aligned memory address*/
	void *p1, *p2;

	

	/*bytes: requested by user
	  alignment: malloc can give us 
	  			 any address and we need to find multiple of 'alignment', 
	  			 so at maximum, multiple
	  			 of alignment will be 'alignment' bytes away from any location.
	  sizeof(size_t): for implementing aligned_free*/

	p1 = (void*)malloc(bytes + alignment + sizeof(size_t));

	if(p1==NULL){

		return NULL;
	}

	/*find next address after p1 which is multiple of alignment*/
	/*Store it in p2*/
	size_t address = (size_t)p1 + alignment + sizeof(size_t);

	p2 = (void*)(address - address%alignment);

	
	/*Store malloced addrress size_t bytes above p2*/
	*((size_t*)p2-1) = (size_t)p1; 

	return p2;
}



/*aligned free*/
void aligned_free(void*ptr){

	free((void*)(*((size_t*)ptr-1)));
}


/*main function*/
int main(){

	int*p = aligned_malloc(10,4);

	printf("%p\n",p);

	*p = 100;

	printf("%d\n",*p);

	aligned_free(p);

	return 0;
}