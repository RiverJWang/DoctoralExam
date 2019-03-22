#include <stdio.h>

int  cmp(char *s1, char *s2)
{
	while(*s1 && *s2 && (*s1 == *s2))
	{
		s1++;s2++;
	}
	return (*s1 - *s2);
}

int main(void)
{
	printf("%d\n", cmp("abC", "abc"));
	return 0;
}
