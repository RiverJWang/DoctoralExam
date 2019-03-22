#include <stdio.h>

int main(void)
{
	int *p,a=10,b=1;
	p=&a;
	a = *p+b;
	printf("%d\n", a);
	return 0;
}
