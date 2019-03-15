#include <stdio.h>

int king(int n, int s);

int main(void)
{
	int n, s;
	printf("total savingNum\n");
	scanf("%d %d", &n, &s);
	printf("%d\n", king(n, s));
	return 0;
}

int king(int n, int s)
{
	int q = 0;
	int m;
	for(m = 1; m < n; m++)
	{
		q = 0;
		for(int i = 2; i <=n; i++)
		{
			q = (q + m) % i;  // 倒过来推到，从只有一个玩家开始，每赢一次就后退一个， %i为了防止越界。
		}
		if(q + 1 == s)
		{
			return m;
		}
	}	
//	q = (q + k - 1) % m; //q现在是从第一个开始获胜的，现在从k个开始，就是从k开始数第q个那个人就是winner
//	q = q + 1;
	return -1;
}
