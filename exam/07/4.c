#include <stdio.h>

void setPrint(int n);

int main(void)
{
	int n;
	scanf("%d", &n);
	setPrint(n);
	return 0;
}
void setPrint(int n)
{
	int a[n];
	int i, j, k;
	for(i = 0; i < n; i++)
		a[i] = i;
	int t = 1 << n; //t表示最高位 逼她小的都是一种可能
	for (i = 0; i < t; i++)//每次i是一种可能
	{
		j = i;
		k = 0;
		printf("{");
		while (j)//一次选中一位
		{
			if (j & 1)
			{
				printf("%d", a[k]);
			}
			j >>= 1;
			++k;
		}
		printf("}\n");
	}

}

/*
 * 时间复杂度很显然，最少也是2^n，空间复杂度，是n，代码比较简单
 * （每个元素要么在子集中，要么不在，用 j 的二进制形式的每一位
 * 代表数组a中对应的位置的元素是否在子集中，例如，当i = 5时， j = i = 5，
 * 那么j = 0101; 我们对应的输出 a[0], a[2]， 这个过程在while循环中完成）
 */
