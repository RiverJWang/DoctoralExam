#include <stdio.h>

void increment(void);

int main(void)
{
	increment();
	increment();
	increment();
	return 0;
}

void increment(void)
{
	static int x= 0;
	x++;
	printf("x=%d\n",x);
}
