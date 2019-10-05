#include<stdio.h>
#include <unistd.h>
#include <sys/types.h> 
int main()
{
pid_t pid;
pid = fork();
if(pid == 0)
{
	printf("I am child %d of process ID = %d\n", getpid(), getppid());
	sleep(5); // assume parent process is terminated at this step
	printf("I am child %d of process ID = %d\n", getpid(), getppid());
}
else
{
	printf("I am parent %d of process ID = %d\n", getpid(), pid);
}
return 0;
}
