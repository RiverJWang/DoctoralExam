#include <stdio.h>
#define M 5
#define N 5

void point(int a[M][N]);

int main(void)
{
	int a[M][N] = {
		{10, 10, 10, 10, 10},
		{10, 20, 30, 40, 50}, 
		{1,  2,  4,  3,  0}, 
		{10, 30, 40, 50, 60}, 
		{20, 40, 30, 50, 30}};
	point(a);
	return 0;
}

void point(int a[M][N])
{
	int i, j;
	int maxi, maxj, mini, minj;
	for(i = 0; i < M; i++)
	{
		maxi = i;
		maxj = 0;
		for(j = 0; j < N; j++)
		{
			if(a[i][j] > a[maxi][maxj])
			{
				maxi = i;
				maxj = j;
			}
		}
		mini = 0;
		minj = maxj;
		for(int k = 0; k < M; k++)
		{
			if(a[k][maxj] < a[mini][minj])
			{
				mini = k;
			}
//			printf("(%d, %d) = %d\n", k, maxj, a[k][maxj]);
//			printf("min (%d, %d) = %d\n", mini, minj, a[mini][minj]);
		}
//		printf("\n");
//		printf("max is (%d, %d) = %d\n", maxi, maxj, a[maxi][maxj]);
//		printf("min is (%d, %d) = %d\n", mini, minj, a[mini][minj]);
		if(a[maxi][maxj] == a[mini][minj])
			printf("point is (%d, %d) = %d\n", maxi, maxj, a[maxi][maxj]);
	}
}
