#include <stdio.h>

void link(char *a, char *b);

int main(void)
{
	char a[100] = {}, b[100] = {};
	gets(a);
	gets(b);
	link(a, b);
	puts(a);
	return 0;
}

void link(char *a, char *b)
{
	int i = 0;
	while(a[i]) i++; // 这是一个坑，会导致多出一位。

	for(int j = 0; b[j] != '\0' && j < 5; i++, j++)
	{
		a[i] = b[j];
	}
	a[i] = '\0';
	for(int k = 0; k < 20; k++)
		printf("%d ", a[k]);
	printf("\n");
}

