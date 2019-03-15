#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

int board[MAX][MAX];
int n, m;
int step_x[]={1,2,2,1,-1,-2,-2,-1},step_y[]={2,1,-1,-2,-2,-1,1,2};
 
void show(){
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			printf("%-5d ",board[i][j]);
		}
		printf("\n");
	}
}
 
_Bool isOut(int x,int y){
	return x < 0 || y < 0 || x >= n || y >= m;
}
 
_Bool isCome(int x,int y){
	return board[x][y];
}
 
void move(int x, int y,int journey)
{
/*	int i;
	board[x][y]=journey++;			//当前是第几步
	for (i = 0;i<8;i++) 
	{
		int next_x = x+step_x[i];
		int next_y = y+step_y[i];
		if(!isOut(next_x,next_y) && !board[next_x][next_y]){
			move(next_x,next_y);
		//	board[next_x][next_y]=0;			//当前是第几步
		}
	}
*/	int i, xx, yy;
	for(i = 0; i < 8; i++)
	{
		xx = x + step_x[i];
		yy = y + step_y[i];
		if(!isOut(xx, yy) && !board[xx][yy])
		{
			board[xx][yy] = journey;
			if(journey == n * m)
			{
				show();
				exit(0);
			}
			else
			{
				move(xx, yy, journey+1);
			}
			board[xx][yy] = 0;
		}
	}
}
 
int main(){
	int start_x,start_y;
	int i;
	int journey = 1;
	printf("m * n\n");
	scanf("%d %d",&n,&m);
	printf("Start:\n");
	scanf("%d %d",&start_x,&start_y);
	for (i = 0;i<10;i++) {
		memset(board[i],0,sizeof(board[0]));
	}
	move(start_x, start_y, journey);
	show();
	return 0;
}
