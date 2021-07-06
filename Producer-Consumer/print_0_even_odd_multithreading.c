#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

//Shared is 0 if semaphore is shared between threads.
//shared is 1 if semaphore is shared between process.
#define shared 0

#define PRINTLEN 10

void* thread1();
void* thread2();
void* thread3();

sem_t zero, even, odd;

int count=0;

int main(){

	pthread_t t1,t2,t3;

	sem_init(&zero,shared,1);
	sem_init(&even,shared,0);
	sem_init(&odd,shared,0);

	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);
	pthread_create(&t3, NULL, thread3, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);

	return 0;
}

//zero
void* thread1(){

	while(count<PRINTLEN){

		sem_wait(&zero);
		
		if(count%2==0){
			
			printf("%d",0);
			count++;
			sem_post(&even);
		}
		else{
			
			count++;

			if(count==PRINTLEN){

				sem_post(&zero);
			}
			else{
				
				printf("%d",0);
				//count++;
				sem_post(&odd);	
			}
			
		}

	}

	printf("\n");
	pthread_exit(0);
	
	
}

//odd
void* thread2(){

	while(count<PRINTLEN){
	
		sem_wait(&odd);
		printf("%d",count);
		sem_post(&zero);
	}
    	//printf("2\n");
	pthread_exit(0);
}

//even
void* thread3(){

	while(count<PRINTLEN){
	
		sem_wait(&even);
		printf("%d",count);
		sem_post(&zero);
	}
	//printf("3\n");
	pthread_exit(0);
}

