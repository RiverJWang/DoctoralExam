#include <stdio.h>

int lcm(int a, int b)
{
	int r, aa, bb;
	if(a < b)
	{
		r = a;
		a = b;
		b = r;
	}
	aa = a;
	bb = b;

	do
	{
		r = a % b;
		a = b;
		b = r;
	}while(b);

	return  aa * bb / a;
}

int lcm3(int a, int b, int c)
{
	int n1, n2;
	n1 = lcm(a, b);
	n2 = lcm(n1, c);
	return n2;
}

int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", lcm3(a, b, c));
	return 0;
}

