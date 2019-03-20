#include <stdio.h>

long int stair(int res)
{
	if(res == 1 || res == 0)
		return 1;
	else
	{
		int res1 = stair(res - 1);
		int res2 = stair(res - 2);
		return res1 + res2;
	}
}

int main(void)
{
	printf("%ld\n", stair(20));
	return 0;
}















/*
//上楼梯  这是一个斐波拉切数列
#include <stdio.h>


int step(int n);

int main(void)
{
	printf("%d\n", step(20));
	return 0;
}

int step(int n)
{
	if(n == 0 || n == 1)
		return 1;
	else return step(n-1) + step(n-2);
}*/
