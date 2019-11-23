// C program to demonstrate working of Semaphores 
#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
#include<string.h>
sem_t mutex; 

static float balance = 50000.0;

int generateRandom(int lower, int upper,  
                             int count) 
{ 
    int i; 
    for (i = 0; i < count; i++) { 
        int num = (rand() % 
           (upper - lower + 1)) + lower; 
        return num; 
    } 
}

void* transfer(void* arg) 
{ 	
	int lower = 2, upper = 8, count = 1;
	
	//wait
	//sem_wait(&mutex); 
	
	printf("\nT:> Select Option\n");
	sleep(generateRandom(lower, upper, count));
	
	printf("\nT:> Enter PIN\n");
	sleep(generateRandom(lower, upper, count));
	
	printf("\nT:> 10k will be transfer\n");
	sleep(generateRandom(lower, upper, count));
	
	sleep(generateRandom(lower, upper, count));
	balance = balance + 10000.0;
	
	printf("\nT:> Balance transfered\n");
	sleep(generateRandom(lower, upper, count));
	
	//sem_post(&mutex); 
} 

void* withdraw(void* arg) 
{ 	
	
	int lower = 2, upper = 8, count = 1;
	
	//wait
	//sem_wait(&mutex); 
	
	printf("\nW:> Select Option\n");
	sleep(generateRandom(lower, upper, count));
	
	printf("\nW:> Enter PIN\n");
	sleep(generateRandom(lower, upper, count));
	
	printf("\nW:> 5k will be withdrawn\n");
	sleep(generateRandom(lower, upper, count));
	
	sleep(generateRandom(lower, upper, count));
	balance = balance - 5000.0;
	sleep(generateRandom(lower, upper, count));
	
	printf("\nW:> Thank You\n");
	sleep(generateRandom(lower, upper, count));
	
	//sem_post(&mutex); 
}

int main() 
{ 
    int lower = 5, upper = 7, count = 1;
	
	sem_init(&mutex, 0, 1); 
	
	pthread_t t1,t2; 
	//sleep(2); 
	
	int id = 7;
	
	if(id == 5)
	{
	char name[10] = "Rafi";
	pthread_create(&t1,NULL,transfer,&name); 
	char name1[10]  = "Some One";
	pthread_create(&t2,NULL,withdraw,&name1);	
	}
	else
	{
	char name1[10]  = "Some One";
	pthread_create(&t2,NULL,withdraw,&name1);
	char name[10] = "Rafi";
	pthread_create(&t1,NULL,transfer,&name); 
	}
	pthread_join(t1,NULL); 
	pthread_join(t2,NULL); 
	
	sem_destroy(&mutex);
	
	printf("Final Balance is %f\n", balance); 
	
	return 0; 
} 

