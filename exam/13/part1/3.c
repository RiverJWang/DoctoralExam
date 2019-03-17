#include <stdio.h>

int main(void)
{
	int a[][3] = {{1,2,3},{4,5,0}}, (*pa)[3], i;
	pa = a;
	for(i = 0; i < 3; i++)
		if(i <= 2) *(*(pa+1) + i) = *(*(pa + 1) + i) - 1;
		else *(*(pa + 1) + i) = 1;
	printf("%d\n", *(*(pa + 1) + 0) + *(*(pa + 1) + 1) + *(*(pa + 1) + 2));

	return 0;
}
