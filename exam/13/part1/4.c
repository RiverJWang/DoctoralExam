#include <stdio.h>

int wordlength(void)
{
	int i;
	unsigned int v = ~0;
	for(i = 1; (v = v >> 1) > 0; i++);
	return i;
}

int main(void)
{
	printf("%d\n", wordlength());
	return 0;
}
