#include <stdio.h>
#define N 100
#define M 100


int main(void)
{
	int a[N][M] = {};
	int n, m;
	int flag, i, j, k;
	int maxi, maxj, mini, minj;

	printf("Inoput your n & m\n");
	scanf("%d %d", &n, &m);

	printf("A[n][m]");
	for(i = 0; i < n; i++)  // 输入数组
		for(j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	
	for(i = 0; i < n; i++)  
	{
		maxi = i;maxj = 0;  // 行最大
		for(j = 0; j < n; j++)
		{
			if(a[i][j] > a[maxi][maxj])
			{
				maxi = i; maxj = j;
			}
		}

		mini = 0; minj = maxj; // 列最小 
		for(k = 0; k < n; k++)
		{
			if(a[k][minj] < a[mini][minj])
			{
				mini = k;minj = maxj;
			}
		}
		if(maxi == mini && maxj == minj)
		{
			printf("a[%d][%d] = %d is point\n", mini, minj, a[mini][minj]);
			flag = 1;
		}
	}

	if( flag == 0)
		printf("No point!\n");

	return 0;
}
