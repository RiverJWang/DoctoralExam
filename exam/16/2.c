// 递归
#include <stdio.h>

int  getmax(int *p, int n)
{
	int max;
	if(n == 1)
		max = *p;
	else
	{
		max = getmax(p+1, n-1);
		if(max < *p)
			max = *p;
	}
	return max;
}

int getsum(int *p, int n)
{
	int sum = 0;
	if(n == 1)
		sum = *p;
	else
	{
		sum = *p + getsum(p+1, n-1);
	}
	return sum;
}

float getaver(int *p, int n)
{
	float aver = 0;
	if(n == 1)
		aver = *p;
	else
	{
		aver = *p + getaver(p+1, n-1) * (n-1);
		aver = aver/ n;
	}
	printf("aver = %f, n = %d\n", aver, n);
	return aver;
}

int main(void)
{
	int A[10] = {0,1,2,4,3,5,7,6,9,8}, n = 10;
	printf("max = %d\n", getmax(A, n));
	printf("sum = %d\n", getsum(A, n));
	printf("aver = %f\n", getaver(A, n));
	
	return 0;
}
