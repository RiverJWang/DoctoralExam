#include <stdio.h>

int dunno(int m)
{
	int value;
	if(m == 0) value = 3;
	else value = dunno(m-1)+5;
	return value;
}

int main(void)
{
	printf("%d\n", dunno(3));
	return 0;
}
