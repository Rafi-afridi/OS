#include<stdio.h>
#include<unistd.h>
int main()
{
	int a = 0;
	fork();
	a++;
	fork();
	a++;
	if(fork() == 0)
	{
		printf("Hello\n");
	}
	else
	{
		printf("GoodBye\n");
	}
	a++;
	printf("a is %d\n", a);
}
