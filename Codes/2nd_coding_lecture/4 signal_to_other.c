//course OS
//Rafi Ullah Afridi

#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

static int alarm_fired = 0;

void ding(int sig)
{
	alarm_fired = 1;
}

int main()
{
	pid_t pid;
	printf("alarm application starting\n");

	pid = fork();
	
	if(pid == -1)
	{
		printf("fork failed\n");
		exit(1);
	}
	else if(pid == 0)
	{
		//child process area here
		sleep(5);
		kill(getppid(), SIGALRM);
		exit(0);
	}
	else
	{
		//parent process area here
		printf("parent is waiting for alarm to go off\n");
		(void) signal(SIGALRM, ding);

		pause();

		//just checking behavoir here
		//int a;
		//scanf("%d", &a);		

		if(alarm_fired)
		{
			printf("Now DONE\n");
			exit(0);
		}
	}
}
