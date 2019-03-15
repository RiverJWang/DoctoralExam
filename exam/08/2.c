#include <stdio.h>
#include <stdlib.h>

void sum(int a, int n);

int main(void)
{
	int a, n;
	printf("a=2 n=4\n");
	scanf("%d %d", &a, &n);
	sum(a, n);
	return 0;
}

void sum(int a, int n)
{
	int i;
	int sum = 0;
	int aa;
	aa = a;
	for(i = 1; i <= n; i++)
	{	
		sum = sum + aa;
		printf("aa = %d sum = %d\n", aa, sum);
		aa = aa * 10 + a;
	}
	printf("sum = %d\n", sum);
}
