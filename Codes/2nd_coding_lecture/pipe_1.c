#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
	FILE *read_fp;
	char buffer[BUFSIZ + 1];
	int chars_read;
	memset(buffer, '\0', sizeof(buffer));
	read_fp = popen("rm ", "r");
	if (read_fp != NULL) {
		chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		if (chars_read > 0) 
		{
			printf("Output was:-\n%s\n", buffer);
		}
		else
		{
			printf("nothing found\n");
		}
	}
	else
	{
		printf("no process\n");
	}
	pclose(read_fp);
	exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
