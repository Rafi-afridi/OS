#include<stdio.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{	
	int pid;
	//printf("this line will execute once\n");	
	pid = fork();
	if(pid ==0)
	{
	sleep(10);
	printf("child process and My ID is %d and My Parent is %d\n", getpid(), getppid());
	//sleep(10);
	//printf("child process and My ID is %d and My Parent is %d\n", getpid(), getppid());
	int a;
	scanf("%d",&a);
	}
	else
	{
	printf("Parent process and My ID is %d and My Child is %d\n", getpid(), pid);
//wait(NULL);
	//sleep(10); //to make zombie process
	//sleep(1);
		
	// to make process running	
	int status = 0;
	while (status == 0)
	{
	status = waitpid(pid, (int *) 0, WNOHANG);
	}
	
	printf("done");
	int a;
	scanf("%d",&a);
	//exit(0);
	}
	//printf("Enter any number\n");
	//int a;	
	//scanf("%d", &a);	
	//printf("hello world\n");
}
