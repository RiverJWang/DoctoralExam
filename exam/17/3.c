#include <stdio.h>

void getnum(int n)
{
	int t = n / 10;
	if(t == 0)
		printf("%d ", n);
	else
	{
		getnum(t);
		printf("%d ", n % 10);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	getnum(n);
	return 0;
}
