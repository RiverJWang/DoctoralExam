#include <stdio.h>

void completeNum(int n);

int main(void)
{
	for(int i = 2; i < 1000; i++)
		completeNum(i);
	return 0;
}

void completeNum(int n)
{
	int i, sum = 0;
	for(i = 1; i < n; i++)
	{
		if(n%i == 0)
			sum = sum + i;
	}
	if(sum == n)
		printf("%d is complete num.\n", n);
}
