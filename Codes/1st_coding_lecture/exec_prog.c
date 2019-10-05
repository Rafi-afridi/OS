#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{	
	printf("Running ps -ax with system\n");
	

	//int a;
	//scanf("%d", &a);	

	//replace process image	
	execlp("ps", "ps", "ax", 0);
	
	//char *const arguments[] = {"ps","ax",0}; 
	//execvp("ps",arguments);
	
	int a;
	scanf("%d", &a);

	printf("done");	
}
