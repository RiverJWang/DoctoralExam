#include <stdio.h>

void light(int *a, int n, int m);

int main(void)
{
	int a[100] = {0}, n;
	scanf("%d", &n);

	light(a, n, n);
	for(int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
		if((i%10) == 0)
			printf("\n");
	}
	return 0;
}

void light(int *a, int n, int m)
{
	if(m == 1) // shutdown all light
	{
		for(int i = 1; i <= n; i++)
			a[i] = 0;
	}
	else if(m == 2) // light up 2 mutiple
	{
		light(a, n, m-1);
		for(int i = 2; i <= n; i = i + 2)
			a[i] = 1;
	}
	else
	{
		light(a, n, m-1);
		for(int i = m; i <= n; i = i + m)
		{
			if(a[i] == 0)a[i] = 1;
			else if(a[i] == 1)a[i] = 0;
		}
	}
}
