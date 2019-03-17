#include <stdio.h>

void matrix(int a[5][5]);

int main(void)
{
	int a[5][5] = {
		{6,14,3,4,5}, 
		{1,7,8,9,11}, 
		{12,13,2,15,16}, 
		{17,18,19,20,21}, 
		{22,23,24,26,25}};
	matrix(a);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void matrix(int a[5][5])
{
	int temp;
	int i, j, maxi=0, maxj=0;
	int mini = 0, minj = 0;
	
	for(i = 0; i < 5; i++)  // central max
	{
		for(j = 0; j < 5; j++)
		{
			if(a[i][j] > a[maxi][maxj]) //求最大
			{
				maxi = i;
				maxj = j;
			}
			if(a[i][j] < a[mini][minj]) // 求最小
			{
				mini = i;
				minj = j;
			}

		}
	}
	temp = a[2][2];   // 交换中间
	a[2][2] = a[maxi][maxj];
	a[maxi][maxj] = temp;
	

	temp = a[0][0];  // 交换第一个
	a[0][0] = a[mini][minj];
	a[mini][minj] = temp;
	mini = 0;
	minj = 1;

	for(i = 0; i < 5; i++)  // 找第二个
	{
		for(j = 0; j < 5; j++)
		{
			if(i == 0 && j == 0)continue;
			if(a[i][j] < a[mini][minj])
			{
				mini = i;
				minj = j;
			}
		}
	}
	temp = a[0][4];  // 交换第二个
	a[0][4] = a[mini][minj];
	a[mini][minj] = temp;
	mini = 0;
	minj = 1;
	
	for(i = 0; i < 5; i++) // 找第三个
	{
		for(j = 0; j < 5; j++)
		{
			if((i == 0 && j == 0) || (i==0 && j==4))continue;
			if(a[i][j] < a[mini][minj])
			{
				mini = i;
				minj = j;
			}
		}
	}
	temp = a[4][0];  // 交换第三个
	a[4][0] = a[mini][minj];
	a[mini][minj] = temp;
	mini = 0;
	minj = 1;

	for(i = 0; i < 5; i++)  // 找第四个
	{
		for(j = 0; j < 5; j++)
		{
			if((i == 0 && j == 0) || (i==0 && j==4) || (i==4 && j ==0))continue;
			if(a[i][j] < a[mini][minj])
			{
				mini = i;
				minj = j;
			}
		}
	}
	temp = a[4][4];  // 交换第四个
	a[4][4] = a[mini][minj];
	a[mini][minj] = temp;
	mini = 0;
	minj = 1;
}
