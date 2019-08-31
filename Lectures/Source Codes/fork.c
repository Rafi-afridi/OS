#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int pid, waitStatus;
	char buf[BUFSIZ];
	printf("Parent Starts Here\n");
	pid = fork();

	if (pid < 0){
		perror("Fork");
		exit(1);
	}

	if(pid == 0){
		printf("Child Starts Here\n");
		printf("Bye\n");
		exit(0);
	}

	printf("Parent Again Here\n");
	wait(&waitStatus);
	printf("Good Bye\n");
	return 0;
}
