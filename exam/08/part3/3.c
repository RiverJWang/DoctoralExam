#include <stdio.h>

int main()
{
	char *p, s[] = "ABCD";
	for(p = s; p < s + 4; p++)
	{
		printf("%s\n", p);
	}
	return 0;
}
