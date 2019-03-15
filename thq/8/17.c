#include <stdio.h>

int mystrcmp(char *p1, char *p2);

int main(void)
{
	char a[100], b[100];
	char *p1, *p2;
	int diff;
	p1 = a;
	p2 = b;

	printf("Input your string1\n");
	scanf("%s", p1);
	printf("Input your string2\n");
	scanf("%s", p2);

	diff = mystrcmp(p1, p2);
	printf("%d\n", diff);

	return 0;
}

int mystrcmp(char *p1, char *p2)
{
	int i = 0;
	while(*(p1 + i) == *(p2 + i))
	{
		if(*(p1 + i++) == '\0')
			return 0;
	}
	return (*(p1 + i) - *(p2 + i));
}
