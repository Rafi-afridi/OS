#include<stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include<stdlib.h>
int main(int argc, char *argv[])
{
int pid=0;
printf("Process 0\n");
pid = fork();
if(pid == 0){
	printf("Process 1\n");
	pid = fork();
	if(pid == 0) { printf("Process 4\n"); exit(0); }	
	wait(NULL);
	exit(0);
	}
	pid = 0;
	pid = fork();
	if(pid == 0){ printf("Process 2\n"); exit(0); }
	pid = 0;
	pid = fork();
	if(pid == 0){
		pid = fork();
		if(pid == 0) { printf("Process 5\n"); exit(0); }
		wait(NULL);
		exit(0);
	}
	printf("Process 3\n");
wait(NULL); wait(NULL); wait(NULL);
exit(0);
}
