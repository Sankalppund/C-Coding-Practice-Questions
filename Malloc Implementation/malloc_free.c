/*Header Files*/
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <stdbool.h>

/*Structure for storing the 
metadata information such as 
size allocated, block is free or
not and pointer to next block.*/
struct metadata{

	size_t size;
	bool free;
	struct metadata* next;
};

/*Size of metadata*/
#define META_SIZE sizeof(struct metadata)

/*Head of malloc singly linked list*/ 
void* global_head = NULL;


/*Function to iterate through linked list to find 
if there is any free block of memory larger or equal
to requested to memory block*/
struct metadata* find_free_block(struct metadata** last, size_t size){

	struct metadata* current = global_head;

	while(current && !(current->free && current->size >= size)){

		*last = current;

		current=current->next;
	}

	return current;
}

/*function to request memory block using sbrk system call*/
struct metadata* request_memory(struct metadata* last, size_t size){

	struct metadata* mem_block = sbrk(0);

	void* request_block = sbrk(size + META_SIZE);

	assert(mem_block == request_block);

	/*Error*/
	if(request_block == (void*)-1){

		return NULL;
	}

	mem_block->size = size;

	mem_block->free = 0;

	mem_block->next = NULL;

	/*if malloc linked list is not empty*/
	if(last!=NULL){

		last->next = mem_block;
	}

	return mem_block;

}




/*Malloc implementation using find_free_block and 
request_memory helper function. It checks if memory block
is free or not and then allocates accordingly*/
void* my_malloc(size_t size){

	struct metadata* block;

	if(size<=0){

		return NULL;

	}

	if(global_head==NULL){

		/*Very first call to malloc when 
		linked list is empty*/
		block = request_memory(NULL,size);

		if(!block){

			return NULL;
		}

		/*Make first requested block as head of linked
		list*/
		global_head = block;

	}
	else{

		/*last_block will iterate through linked list
		until it gets free memory block or NULL*/
		struct metadata* last_block = global_head;

		block = find_free_block(&last_block, size);

		if(block == NULL){

			block = request_memory(last_block, size);

			if(block == NULL){

				return NULL;
			}

		}
	}

	/*we return block+1 because we want to 
	return a pointer to the region after block_meta*/
	return (block+1);
}


/*function to get metadata block*/
struct metadata* get_metadata_ptr(void* ptr){

	return (struct metadata*)ptr - 1;

}

/*Free function which sets free=1*/
void my_free(void* ptr){

	if(ptr==NULL){
		return;
	}

	struct metadata* metadata_ptr = get_metadata_ptr(ptr);

	assert(metadata_ptr->free == 0);

	metadata_ptr->free = 1;
}


/*main function*/
int main(){

	int *p=NULL;

	p = (int*)my_malloc(100);

	printf("New Heap : %p\n",p);
	
	*p = 100;

	printf("New Heap data: %d\n",*p);

	my_free(p);

	return 0;
}