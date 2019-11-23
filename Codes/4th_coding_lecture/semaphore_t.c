// C program to demonstrate working of Semaphores 
#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
#include<string.h>
//sem_t mutex; 

void* threadFunction(void* arg) 
{ 	
	//wait
	//sem_wait(&mutex); 
	printf("\nEntered..\n"); 
	//int a = scanf("enter number");
	//critical section 
	for(int i=0; i<5; i++)
	{
	printf("%s is working here\n", arg); 
	}

	//signal 
	printf("\nJust Exiting...\n"); 
	//sem_post(&mutex); 
} 


int main() 
{ 
	//sem_init(&mutex, 0, 1); 
	pthread_t t1,t2; 
	//sleep(2); 
	char name[10] = "Rafi";
	
	pthread_create(&t1,NULL,threadFunction,&name); 
	char name1[10]  = "Some One";
	sleep(2);
	pthread_create(&t2,NULL,threadFunction,&name1);	
	
	pthread_join(t1,NULL); 
	pthread_join(t2,NULL); 
	//sem_destroy(&mutex);
	printf("i am done\n"); 
	return 0; 
} 

