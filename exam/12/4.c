#include <stdio.h>

int main(void)
{
	int m, n, k, i, j, q, sum = 0;
	int A[100][100] = {}, B[100][100] = {}, C[100][100] = {};

	printf("m , n:\n"); // 输入A[][]
	scanf("%d %d", &m, &n);
	printf("A[M][N]\n");
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &A[i][j]);  // scanf.&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

	printf("n , k:(only k)\n");  //输入B[][]
	scanf("%d", &k);
	printf("B[M][N]\n");
	for(i = 0; i < n; i++)
		for(j = 0; j < k; j++)
			scanf("%d", &B[i][j]);
	
	for(i = 0; i < m; i++) // 矩阵乘法
	{
		for(q = 0; q < k; q++)
		{
			for(j = 0; j < n; j++)
			{
				sum = sum + A[i][j]*B[j][q];
			}
			C[i][q] = sum;
			sum = 0;
		}
	}

	for(i = 0; i < m; i++){	
		for(j = 0; j < k; j++){
			printf("%6d", C[i][j]);
		}
		printf("\n");
	}
	return 0;

}
