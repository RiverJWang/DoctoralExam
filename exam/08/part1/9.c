#include <stdio.h>

int main(void)
{
	int a[5] = {2, 4, 6, 8, 10}, *p, **k;
	p = a;
	k = &p;
	printf("%d", *(p++));
	printf("%d\n", **k);
	return 0;
}
