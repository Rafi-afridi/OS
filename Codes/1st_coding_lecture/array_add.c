#include<stdlib.h>
#define N 1024
int A[N], B[N], *C;
int main()
{
	int i;
	C = (int *)malloc(N*sizeof(int)); // dynamic memory allocation
	for(i=0; i<N; i++)
	{		
		A[i] = B[i] = i+1;
	}
	for(i=0; i<N; i++)
	{
		C[i] = A[i] + B[i];
	}	
	sleep(10);
	return 0;
}
