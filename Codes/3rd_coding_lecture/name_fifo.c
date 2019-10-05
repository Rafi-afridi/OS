#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	int res = mkfifo("/tmp/my_fifo_os", 0777);
	if (res == 0) printf("FIFO created\n");	
	exit(EXIT_SUCCESS);
}
