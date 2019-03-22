#include <stdio.h>
#include <string.h>

void fun(char str[])
{
	char m;
	int i, j;

	for(i = 0, j = strlen(str); i < strlen(str)/2; i++, j--)
	{
		m = str[i];
		str[i] = str[j-1];
		str[j-1] = m;
	}
}

int main(void)
{
	char str[100];
	gets(str);
	fun(str);
	puts(str);
	return 0;
}

