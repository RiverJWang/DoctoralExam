#include <stdio.h>

void string(unsigned long int n)
{
	unsigned long int r = n / 10;

	if(r == 0)
		printf("%c ", n % 10 + '0');

	else
	{
		string(r);
		printf("%c ", n % 10 + '0');
	}
}

int main(void)
{
	unsigned long int n;
	scanf("%ld", &n);

	string(n);
	putchar('\n');
	return 0;
}
