#include <stdio.h>

void spiral(int n);

int main(void)
{
	int n;
	scanf("%d", &n);
	spiral(n);
	return 0;
}

void spiral(int n)
{
	int cnt = 1, m = n * n;
	int x = 0, y = 0;
	int a[100][100] = {0};

	a[x][y] = cnt;
	while(m  !=  cnt)
	{
		while(y+1 < n && a[x][y+1] == 0)
		{
			a[x][++y] = ++cnt;
		}
		while(x+1 < n && a[x+1][y] == 0)
		{
			a[++x][y] = ++cnt;
		}
		while(y-1 >= 0 && a[x][y-1] == 0)
		{
			a[x][--y] = ++cnt;
		}
		while(x-1 >= 0 && a[x-1][y] == 0)
		{
			a[--x][y] = ++cnt;
		}

	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%6d", a[i][j]);
		}
		printf("\n");
	}
}
