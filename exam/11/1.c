#include <stdio.h>
#define N 3

void search(void);

int main(void)
{
	search();
	return 0;
}

void search(void)
{
	char a[N] = {'A', 'B', 'C'};
	char b[N] = {'X', 'Y', 'Z'};
	int flag = 1;
	int i, j;

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(i == 0 && j == 0)
				flag = 0;
			if(i == 2 && j == 0)
				flag = 0;
			if(i == 2 && j == 2)
				flag = 0;
			if(flag == 1)
				printf("%c VS %c\n", a[i], b[j]);
			flag = 1;
		}
	}
}
