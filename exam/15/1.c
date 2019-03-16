#include <stdio.h>
#define MIN(a,b) ((a)>(b)?(b):(a))

int main(void)
{
	int a, b, c;
	scanf("%d %d", &a,&b);
	printf("%d\n", MIN(a,b));
	return 0;
}
