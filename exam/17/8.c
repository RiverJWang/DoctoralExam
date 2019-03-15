#include <stdio.h>

void table(int k);

int main(void)
{
	int k;
	scanf("%d", &k);

	table(k);
	return 0;
}

void table(int k)
{
	int i=1, j=1;  // i, j是当前数组元素位置
	int t; // t代表共有k个大步骤
	int temp=1; // temp代表每次填写的距离第一行有多远
	int n=2; // n代表在k步中每多一次就多n*2,控制temp
	int m = 2;  // m = m^k;

	int a[1024][1024] = {0};

	a[1][1] = a[2][2] = 1; // 给一个起始条件
	a[1][2] = a[2][1] = 2; // 当只有 1 和2 比赛时的日程表

	for(t = 1; t < k; t++) // 控制三大步骤
	{
		temp = n;
		n = n * 2;
		
		//开始新的列 填写左下角新的方阵
		for(i = temp + 1; i <= n; i++) // 进入新的行,第一次在第三行，因为已经有两行了,要多增加temp行
			for(j = 1; j <= temp; j++) // 进入新的列。行列数相等,因为要构成一个正方形
				a[i][j] = a[i - temp][j] + temp;
		
		// 填写右上角的方阵，从左下角复制。 
		for(i = 1; i <= temp; i++)  // 从第一行开始，一共复制了temp行
			for(j = temp + 1; j <= n; j++) // 从第temp+1列开始，到n列，总的也是复制了temp列
				a[i][j] = a[i + temp][(j - temp)];
		
		// 填写右下角的方泽你，从左上角复制。
		for(i = temp + 1; i <= n; i++)  // 从temp+1行开始填写，到n行，共复制了temp列
			for(j = temp + 1; j <= n; j++) // 从temp+1列开始填写，到n列， 共复制了temp列
				a[i][j] = a[i - temp][j - temp];
	}

	for(int p = 1; p < k; p++)
		m = m * 2;

	for(int p = 1; p <= m; p++)
	{
		for(int q = 1; q <= m; q++)
			printf("%d ", a[p][q]);
		printf("\n");
	}
}
