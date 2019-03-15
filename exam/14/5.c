#include <stdio.h>

void trans(int n);

int main(void)
{
	int n;
	scanf("%d", &n);
	trans(n);
	printf("\n");
//	printf("%s is string\n", trans(n));
	return 0;
}

void trans(int n)
{
	int i = n / 10;
	if(i == 0)
		printf("%c ", n + '0');
	else
	{
		trans(i);
		printf("%c ", (n % 10) + '0');
	}
}
