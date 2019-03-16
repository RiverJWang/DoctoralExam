//上楼梯
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
}
