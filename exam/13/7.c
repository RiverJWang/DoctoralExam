/*
 * 我们可以假设物品就是按编号顺序来选择的，某个物品不被选上可看作被选用了0个。
 * 这样的话，我们的问题就是在5种物品里选择，以满足重量体积限制，并使总价值最大。
 * 按顺序在5种物品里选可以分解为先在前4种物品里选，最后确定最后一种物品怎么选，
 * 一般地，要在前n种物品里选，可以先看作在前n-1种物品里选，最后选第n种，
 * 但我们要用一个状态（也就是子问题）来记录前n-1种物品选择的状态，目标是使目标问题能递归的分解成子问题，
 * 但要注意状态数目不能太多，否则内存可能不够。我们定义子问题如下：在前n种物品里选择，
 * 满足总体积为x和总重量为y的条件下，总价值最多是多少？
 * 记这个最大总价值为f(n,x,y). 根据这个定义, 原问题就是求f(5,500,100).
 * 当我们求f(n,x,y)的时候, 可以先考虑第n个物品的选择,假设它被选用i个,
 * 那么前面它的总体积为i*v[n], 总重量为i*w[n], 于是前(n-1)个物品的总体积为x-i*v[n],
 *  总重量为y-i*w[n], 于是f(n,x,y)归约为f(n-1, x-i*v[n], y-i*w[n]),
 *  而这个i的取值限制为i>=0, i<=c[n], x-i*v[n]>=0,y-i*w[n]>=0. 即:
 *  f(n,x,y)= MAX{ f(n-1, x-i*v[n], y-i*w[n]) + i*t[n] }
 */

#include <iostream>
#include <string>

using namespace std;

int num, maxx, maxy;
int v[6], w[6], c[6], t[6];
int f[6][501][101]; // 用于保存f(n, x, y)

int getf(int n, int x, int y)
{
	if(f[n][x][y] >= 0)
		return f[n][x][y]; // 判断是否被求结果，若是返回
	if(n == 0 || x == 0 || y == 0)
		f[n][x][y] = 0;
	else
	{
		int maxi = c[n];
		if(x/v[n] < maxi) maxi = x/v[n];
		if(y/w[n] < maxi) maxi = y/w[n];
		for(i = 0; i <= maxi; i++)
		{
			if(f[n-1][x-i*v[n]][y-i*w[n]] + i*t[n] > f[n][x][y])
				f[n][x][y] = f[n-1][x-i*v[n]][y-i*w[n]];
		}
	}
	return f[n][x][y];
}

int main(void)
{
	int i;
	scanf("%d", &num); // 5 iterms. 1 2 3 4 5
	for(i = 1; i <= num; i++)
		scanf("%d %d %d %d", v[i], w[i], c[i], t[i]);
	memset(f, 0xff, sizeof(f)); // 设置初始解， 全部设置为-1
	int ans = 0, x, y;
	for(x = 0; x <= maxx; x++)
		for(y = 0; y <= maxy; y++)
			if(getf(num, x, y) > ans) 
				ans = getf(num, x, y);
	cout << ans << endl;

}
