#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
	int data_processed;
	int file_pipes[2]; // {0=reading, 1=writing}
	const char some_data[] = "1234567890"; // {'1', '2', '3'}
	char buffer[BUFSIZ + 1];
	pid_t fork_result;
	memset(buffer, '\0', sizeof(buffer));
	if (pipe(file_pipes) == 0) {
		fork_result = fork();
		if (fork_result == -1) {
			fprintf(stderr, "Fork failure");
			exit(EXIT_FAILURE);
		}
		if (fork_result == 0) {
			data_processed = read(file_pipes[0], buffer, BUFSIZ);
			printf("Read %d bytes: %s\n", data_processed, buffer);
			exit(EXIT_SUCCESS);
		}
		else {
			sleep(10);
			data_processed = write(file_pipes[1], some_data, 10);
			printf("Wrote %d bytes\n", data_processed);
		}
	}
	exit(EXIT_SUCCESS);
}

