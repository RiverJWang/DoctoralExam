#include <stdio.h>

int king(int m, int n, int k);

int main(void)
{
	int m, n, k;
	printf("bomb total startNum\n");
	scanf("%d %d %d", &m, &n, &k);
	printf("%d\n", king(m,n,k));
	return 0;
}

int king(int m, int n, int k)
{
	int q = 0;
	for(int i = 2; i <=n; i++)
		q = (q + m) % i;  // 倒过来推到，从只有一个玩家开始，每赢一次就后退一个， %i为了防止越界。
	
	q = (q + k - 1) % n; //q现在是从第一个开始获胜的，现在从k个开始，就是从k开始数第q个那个人就是winner
	q = q + 1;
	return q;
}
