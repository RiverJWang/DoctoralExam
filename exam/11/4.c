#include <stdio.h>

int length(char *p)
{
	int i = 0;
	for(i = 0; *(p+i) != 0; i++);
	return i;
}

int main(void)
{
	char a[100];
	gets(a);
	printf("%d\n", length(a));
	return 0;
}
