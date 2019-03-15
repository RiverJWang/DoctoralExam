#include <stdio.h>
#define max 101

int cnt = 1; //走的步数
int n, m;  // 棋盘大小
int start_x, start_y;  // 起点位置

int dx[8] = {-2,-1,1,2,2,1,-1,-2}; // 马的八种走法
int dy[8] = {1,2,2,1,-1,-2,-2,-1}; // cordinate y
int board[max][max] =  {0};

void show(int n, int m); // show board status of maxtrix;
int isOut(int x, int y); // is out of board in x,y
int isCome(int x, int y); // was come in x, y
void move(int x, int y); // horse movement

int main(void)
{
	printf("how big is the board:n m\n");
	scanf("%d %d", &n, &m);
	printf("where start?:x y\n");
	scanf("%d %d", &start_x, &start_y);
	
	move(start_x-1, start_y-1);
	show(n, m);
	return 0;
}


void show(int n, int m) // show board status of maxtrix;
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			printf("%4d", board[i][j]);
		printf("\n");
	}
}
int isOut(int x, int y) // is out of board in x,y
{
	if(x>=0&&x<m && y>=0&&y<n)
		return 1;
	return 0;
}

int isCome(int x, int y) // was come in x, y
{
	return board[x][y];
}

void move(int x, int y) // horse movement
{
	if(cnt > m*n)
		return;
	printf("Add a new step:(%d, %d), cnt = %d\n", x, y, cnt);
	show(n , m);
	for(int i = 0; i < 8; i++) // 把在一个点的八种走法都走一遍
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if(!isOut(next_x, next_y) && !board[next_x][next_y]) // 如果不出棋盘，并且每走过
		{
			board[next_x][next_y] = cnt++;
			move(next_x, next_y);
			board[next_x][next_y] = 0; // 回溯清零是关键

		}
	}
}

