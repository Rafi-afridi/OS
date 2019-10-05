#include<stdio.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{	
	//it create copy of calling process
	//printf("parent process\n");
	
	int pid;	
	pid = fork();

	if(pid == 0)
	{
	//child area
	//for(int o=0; o<1000; o++)
	//{  printf("child process\n"); }

	int pid_3;
	pid_3 = fork();

	if(pid_3 == 0) { printf("child of child1\n"); }
	else { printf("child 1\n"); }
	}
	else
	{
	//parent area
	//for(int o=0; o<1000; o++)
	//{ printf("parent process\n"); }
	
	int pid_2;
	pid_2 = fork();
	if(pid_2 == 0)
	{ printf("child 2\n");
	printf("code multiplication\n");}
	else
	{ printf("parent\n");
	printf("code of addition\n");} 
	}
	
	int a;
	scanf("%d", &a);
	//printf("great\n");

}
