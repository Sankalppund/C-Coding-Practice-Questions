/*Header Files*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


/*Data structue defination*/
typedef struct{

	uint8_t* buffer;

	int head;

	int tail;

	int maxlen;
}cb;

/*Discard or Wraparound after buffer is full*/
#define WRAPAROUND 0

/*Initialize the circular buffer*/

cb* Initialize_cb(uint8_t size_of_cb){

	cb* cirBuff = (cb*)malloc(sizeof(cb));

	cirBuff->buffer = (uint8_t*)malloc(size_of_cb);

	cirBuff->head = 0;

	cirBuff->tail = 0;

	cirBuff->maxlen = size_of_cb;

	return cirBuff;
}


/*Push function to add data to circular buffer*/

int pushCB(cb* cirBuff, uint8_t data){


	int next = cirBuff->head + 1;

	if(next >= cirBuff->maxlen){

		next=0;
	}

#if WRAPAROUND

	if(next == cirBuff->tail){

		/*Discard after buffer is full*/
		printf("Alert: CB is full\n");

		return -1;
	}

#else

	if(next == cirBuff->tail){

		/*Discard after buffer is full*/
		printf("Alert: CB is full\n");

		cirBuff->head = 0;

		printf("Wrapping from index 0\n");
	}

#endif	

	cirBuff->buffer[cirBuff->head] = data;

	printf("CB : %d\n",cirBuff->buffer[cirBuff->head]);

	cirBuff->head = next;

	return 0;

}

/*pop function to read from circular buffer*/

int popCB(cb* cirBuff){

	int next;

	if(cirBuff->head == cirBuff->tail){

		printf("CB is empty\n");

		return -1;
	}

	next = cirBuff->tail+1;

	if(next >= cirBuff->maxlen){

		next=0;
	}


	printf("Reading : %d\n", cirBuff->buffer[cirBuff->tail]);

	cirBuff->tail = next;
}



/*Main function*/
int main(){

	cb* cirBuff = Initialize_cb(10);


	for(int i=0; i<9; i++){

		pushCB(cirBuff,i);
	}

	for(int i=0; i<10; i++){

		popCB(cirBuff);
	}


	return 0;

}