/*Header Files*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

/*sem_init pshared parameter*/
#define SHARED 1

/*Buffer Size*/
#define BUFF_SIZE 5

/*Function Prototyping*/
void* producer();
void* consumer();

/*Empty = buffer is empty
  full = buffer is full
  lock = lock/unlock for mutual exclusion*/
sem_t empty, full, lock;

/*Producer-consumer common buffer*/
int data[BUFF_SIZE];


/*Main*/
int main(){

	/*Producer and consumer thread ID*/
	pthread_t producer_threads, consumer_threads;

	
	/*Initialization of semaphore integers*/
	sem_init(&empty,SHARED,BUFF_SIZE);

	sem_init(&full,SHARED,0);

	sem_init(&lock,SHARED,1);

	/*Create Producer thread*/
	pthread_create(&producer_threads,NULL,producer,NULL);

	/*Create consumer thread*/
	pthread_create(&consumer_threads,NULL,consumer,NULL);

	
	/*joing both threads*/
	pthread_join(producer_threads,NULL);

	pthread_join(consumer_threads,NULL);

	return 0;

}


/*Producer Thread*/
void* producer(void*arg){

	int i,k;

	for(i=1;i<=BUFF_SIZE;i++){

		sem_wait(&empty);

		sem_wait(&lock);

		data[i]=i;

		printf("\n\nProduced: %d\n",data[i]);	

		printf("\nBuff Content:");

		for(k=1;k<=BUFF_SIZE;k++){
			printf(" %d",data[k]);
		}

		sem_post(&lock);

		sem_post(&full);

		if(i==BUFF_SIZE){

			printf("\n\nBuffer is full. Consumer Start consuming...\n");
		}
	}
}


/*consumer thread*/
void* consumer(){

	int j;

	for(int j=1; j<=BUFF_SIZE; j++){

		
		sem_wait(&full);

		sem_wait(&lock);

		printf("\nConsumed: %d\n",data[j]);

		sem_post(&lock);

		sem_post(&empty);

		if(j==BUFF_SIZE){

			printf("\nBuffer consumed completely, Producer need to produce. \n");
		}

	}	

}