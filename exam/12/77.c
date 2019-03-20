#include <stdio.h>
#include <stdlib.h>

void ring(int n, int k);

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	ring(n, k);
	return 0;
}

void ring(int n, int k)
{
	int q = 0;
	int i;
	for(i = 2; i <= n; i++)
	{
		q = (q + k) % i;
	}

	printf("winner is %d\n", q+1);
}
