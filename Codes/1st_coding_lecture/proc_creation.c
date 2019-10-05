#include<stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include<stdlib.h>
#include <sys/wait.h>
int main()
{
	pid_t pid, waitStatus;
	printf("Parent Starts Here\n");
	pid = fork();
	if(pid == 0)
	{						
	printf("child i am %d and my parent is %d\n", getpid(), getppid());
	}
	printf("parent i am %d and my parent is %d\n", getpid(), getppid());
	return 0;

}
