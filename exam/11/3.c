#include <stdio.h>

void change(int n);

int main(void)
{
	int n = 483;
	change(n);
	printf("\n");
	return 0;
}

void change(int n)
{
	int i;
	i = n / 10;
	if(i != 0)
		change(i);
	putchar(((n % 10) + '0'));
	putchar(' ');
}
