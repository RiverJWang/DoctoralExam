#include <stdio.h>

int f(char *s)
{
	if(s[0] == 0)
		return 0;
	else
	{
		if(s[0] >= '0' && s[0] <= '9')
			return (s[0] - '0' + f(s + 1));
		else
			return (f(s + 1));
	}

}

int main(void)
{
	char s[] = "12abc77jbzujasx";
	printf("%d\n", f(s));
	return 0;
}
