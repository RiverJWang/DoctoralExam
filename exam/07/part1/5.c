#include <stdio.h>

void swap(int x, int y)
{
	int c = x;
	x = y;
	y = c;
}

int main(void)
{
	int a = 8, b = 10;
	swap(a, b);
	printf("a = %d, b = %d\n", a, b);
	return 0;
}

