#include <stdio.h>

void takeBall(void);

int main(void)
{
	takeBall();
	return 0;
}

void takeBall(void)
{
	int i, j, k;
	int cnt = 0;
	for(i = 1; i <= 3; i++)
		for(j = 1; j <=5; j++)
			for(k = 0; k <= 6; k++)
				if(i + j + k == 8)
					printf("%dred,%dwhite,%dblack, total%d\n", i, j, k, ++cnt);
}
