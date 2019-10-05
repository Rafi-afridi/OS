#include<stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include<stdlib.h>
#include<string.h>

//getpid() ----> used to extract process id
//getppid() ----> used to extract id parent of process

int main()
{
	int a = 9;
	float c = a*0.5;	
	pid_t pid;
	pid = fork();
	if(pid == 0)
	{ 
	printf("I am child %d of process ID = %d\n", getpid(), getppid());
	}
	else
	{		
	printf("I am parent %d of process ID = %d\n", getpid(), pid);
	}
}














