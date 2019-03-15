// 1 辗转相除法求最大公约；
// 2 递归法求最大公约；
// 3 穷举法求最大公约和最大公倍；
// 4 最大公倍数 = m × n / 最大公约；

#include <stdio.h>

void beishu(int m, int n);
void yueshu(int m, int n);

int main(void)
{
	int m, n;
	scanf("%d %d", &m, &n);

	beishu(m, n);
	yueshu(m, n);
	return 0;
}

void yueshu(int m, int n)
{
	int t;
	if(m < n)
	{	t = m;
		m = n; 
		n = t;
	}

	do
	{
		t = m % n;
		m = n;
		n = t;
	}while(t);
	printf("最大公约数是%d\n", m);
}

void beishu(int m, int n)
{
	int t;
	int mt = m, nt = n;
	if(m < n)
	{
		t = m;
		m = n;
		n = t;
	}

	do
	{
		t = m % n;
		m = n;
		n = t;
	}while(n);

	printf("最小公倍数为%d\n", mt * nt / m);
}
