#include <stdio.h>

int length(char *p);

int main(void)
{
	char *p = "I LOVE YOU~";
	printf("%d\n", length(p));
	return 0;
}

int length(char *p)
{
	int n = 0;
	int i;
	for(i = 0; *(p + i) != '\0'; i++)
		n++;
	return n;
}
