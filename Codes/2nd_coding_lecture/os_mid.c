#include<stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include<stdlib.h>
#include<string.h>
int main()
{
pid_t pid, waitStatus;
pid = fork();	
if(pid == 0)
{
	printf("i am process1\n");
}
else
{
	pid = fork();	
	if(pid == 0)
	{
		pid = fork();	
		if(pid == 0)
		{
		printf("I am process4\n");
		}
		else
		{
		wait(&waitStatus);	
		printf("I am process2\n");
		}	
	}
	else
	{	
		pid = fork();	
		if(pid == 0)	
		{
			pid = fork();	
			if(pid == 0)
			{
			printf("I am process5\n");
			}
			else
			{
			wait(&waitStatus);
			printf("I am process3\n");
			}
		}
		else
		{		
		wait(&waitStatus);
		printf("I am process0\n");
		}
	}
}
return 0;
}
