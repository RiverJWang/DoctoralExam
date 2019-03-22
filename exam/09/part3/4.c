#include <stdio.h>

int fun(int x, int y, int *cp, int *dp)
{
	*cp = x+y;
	*dp= x-y;
}

int main(void)
{
	int a,b,c,d;
	a=30;b=50;
	fun(a,b,&c,&d);
	printf("%d,%d\n",c,d);
	return 0;
}
