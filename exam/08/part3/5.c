#include <stdio.h>

int f(int n)
{
	static int s = 1;
	s = s * n;
	return s;
}

int main()
{
	int i;
	for(i = 1; i <= 5; i++)
	{
		printf("%d\n",f(i));
	}
	return 0;
}

