#include <stdio.h>

int main()
{
	int x = 1, y = 1;
	printf("%d\n", (!x++ || y--));
	return 0;
}
