#include <stdio.h>
#include <string.h>


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

	diff = strcmp(p1, p2);
	printf("%d\n", diff);

	return 0;
}
