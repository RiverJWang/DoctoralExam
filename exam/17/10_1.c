#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int board[MAX+1][MAX+1] = {0};

int dx[10] = {2,1,-1,-2,-2,-1,1,2};
int dy[10] = {-1,-2,-2,-1,1,2,2,1};

int n, m;

int check(int x, int y)
{
	if(x < 1 || y <1 || x > n|| y > m || board[x][y] != 0)
		return 0;
	return 1;
}

void show(void)
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
			printf("%5d", board[i][j]);
		printf("\n");
	}
}

void move(int a, int b, int number)
{
	if(number >= n*m)
	{
		return;
	}

	for(int i = 0; i < 8; i++)
	{
		if(check(a+dx[i], b+dy[i]))
		{
			int x = a + dx[i];
			int y = b + dy[i];
			board[x][y] = number + 1;
			move(x, y, number+1);
			board[x][y] = 0; // 回溯
		}
	}
}

void run(int x, int y)
{
	int number = 1;
	board[x][y] = number;
	move(x, y, number);
	show();
}

int main(void)
{
	int x, y;
	printf("棋盘大小：\n");
	scanf("%d %d", &n, &m);
	printf("开始位置：\n");
	scanf("%d %d", &x, &y);
	run(x,y);
	return 0;
}
