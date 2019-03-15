#include <stdio.h>
#include <string.h>
#define MAX 101

int board[MAX][MAX];
int n, m;
int journey = 1;
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
 
void move(int x, int y ){
	if(journey>n*m) return;
	int i;
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
}
 
int main(){
	int start_x,start_y;
	int i;
	printf("m * n\n");
	scanf("%d %d",&n,&m);
	printf("Start:\n");
	scanf("%d %d",&start_x,&start_y);
	for (i = 0;i<10;i++) {
		memset(board[i],0,sizeof(board[0]));
	}
	move(start_x,start_y);
	show();
	return 0;
}
