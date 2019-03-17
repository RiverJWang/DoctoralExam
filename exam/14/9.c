#include <stdio.h>

int king(int n, int s);

int cir(int n,int k)  // 原题,生死游戏
{
    int p=0;
    for(int i=2;i<=n;i++)
    {
        p=(p+k)%i;
    }
    return p+1;
}


int main(void)
{
	int n, s;
	printf("total savingNum\n");
	scanf("%d %d", &n, &s);
	printf("%d\n", king(n, s));
	return 0;
}

int king(int n, int s)  // 找到最小的 N, 给定人数n 和胜利者s,求最小的炸弹m.
{
	int q = 0;
	int m;
	for(m = 1; m < n; m++) // 思路,将炸弹从1开始循环到n, 如果第一个m等于胜利者s,那么就找到了,如果循环结束未找到,
	{ 			// 那么就返回-1;
		q = 0;// q玩家是胜利者,且只有一个人的时候,序号为0;
		for(int i = 2; i <=n; i++) // i是参与游戏人数, 每多一个人,就后退m步,因为是数组,需要除去数组长度i个人.
		{
			q = (q + m) % i;  // 倒过来推到，从只有一个玩家开始，每赢一次就后退一个， %i为了防止越界。
		}
		if(q + 1 == s) //  若炸弹m的胜利者和s相同,那么就找到了m.
		{
			return m;
		}
	}	
//	q = (q + k - 1) % m; //q现在是从第一个开始获胜的，现在从k个开始，就是从k开始数第q个那个人就是winner
//	q = q + 1;
	return -1;
}
