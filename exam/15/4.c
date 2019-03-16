#include <stdio.h>

int gcd(int n, int m)
{
	int r;
	if(n < m)
	{
		n = n^m;
		m = n^m;
		n = n^m;
	}
	
	do
	{
		r = n % m;
		n = m;
		m = r;
	}while(m);

	return n;
}

int rgcd(int m, int n)
{
	int r;
	if(m < n)
	{
		m = m^n;
		n = m^n;
		m = m^n;
	}
	
	r = m % n;
	if(r == 0)
		return n;
	rgcd(n, r);
}

int main(void)
{
	int m, n;
	scanf("%d %d", &m, &n);
	printf("gcd is %d\n", gcd(m,n));
	printf("rgcd is %d\n", rgcd(m,n));
	return 0;
	
}
