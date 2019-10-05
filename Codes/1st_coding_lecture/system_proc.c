#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{	
	printf("Running ps -ax with system\n");
	
	//forground process attached to bash	
	//system("ps -ax");
	//system("ls -al");
	//system("ps -ax &");

	system("ps -ax &");
	system("ls -al &");

	//int a;
	//scanf("%d", &a);

	printf("done");	
}
