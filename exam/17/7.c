#include <stdio.h>

int gcd(int a, int b);

void reduce(int *a, int *b);

void egypt(int a, int b);

int main(void)
{
	int a, b;
	scanf("%d/%d", &a, &b);
	egypt(a, b);
	return 0;
}

int gcd(int a, int b)
{
	int r;
	if(a < b)
	{
		r = a;
		a = b;
		b = r;
	}

	do
	{
		r = a % b;
		a = b;
		b = r;
	}while(b);
	return a;
}

void reduce(int *a, int *b)
{
	int common = gcd(*a, *b);
	*a = *a / common;
	*b = *b / common;
}

void egypt(int a, int b)
{
	int i = 1, k;
	// 加上一个判断真分数 假分数的。
	reduce(&a, &b);
	printf("After dividing %d / %d\n", a, b);

	while(1)
	{
		if(a == 1)
		{
			printf("1/%d.\nEnding\n", b);
			break;
		}	
		while(a*++i > b) // a/b > 1/i, 可以分解出1/i
		{
			printf("1/%d + ", i);
			a = a * i - b; // 从a/b中减去那个埃及分数
			b = b * i;	// 通分相减 
			reduce(&a, &b);  // 约分
		}
	}
}
