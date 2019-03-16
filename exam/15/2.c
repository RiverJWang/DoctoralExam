#include <stdio.h>
/*
其中加减，乘除容易越界，用位运算异或效率最高，且不会越界。
使用位运算交换两个数，是利用了异或的自反性： a^b^b=a^0=a;
 */

void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
void swap1(int *a,int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    8a = *a - *b;
}
void swap2(int *a,int *b)
{
    *a = *a * *b;
    *b = *a / *b;
    *a = *a / *b;
}
void swap3(int *a,int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main(void)
{
	int a = 10, b = 99;

	printf("After %d %d\n", a, b);
	swap(&a, &b);
	printf("After %d %d\n", a, b);
	return 0;
}
