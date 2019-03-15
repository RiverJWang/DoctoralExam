#include <stdio.h>
#include <math.h>

void prime(int m, int n);
int counterprime(int n);
int sum = 0;
int base = 1;

int main(void)
{
	int m = 100, n = 1000;
	prime(m, n);
	return 0;
}

void prime(int m, int n)
{
	int i, j;
	int k;

	for(i = m; i <= n/2; i++)
	{
		for(j = 2; j <= sqrt(i); j++)
		{
			if(i % j == 0)
				j = i;
		}
		if(j == i)
		{
			k = counterprime(i);
			for(j = 2; j <= sqrt(k); j++)
			{
				if(k % j == 0)
					j = k;
			}
			if(j == k)
				printf("%d %d\n", i, k);
		}
	}
}
int counterprime(int n)
{
	int res;
	int t = n / 10;
	if(t == 0)
		sum = n;
	else
	{
		sum = counterprime(t);
		res = n % 10;
		base = base * 10;
		sum = res * base + sum;
	}
	return sum;

}
