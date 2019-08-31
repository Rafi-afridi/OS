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
		if(execlp("ls","ls",(char *)0) == -1){
			perror("exec");
			exit(1);
		}
	}

	printf("Parent Again Here\n");
	wait(&waitStatus);
	printf("Good Bye\n");
	return 0;
}
