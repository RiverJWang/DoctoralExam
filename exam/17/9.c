#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void plus(char *a, char *b);

int main(void)
{
	char a[MAX], b[MAX];

	gets(a);
	gets(b);
	plus(a, b);
	return 0;
}

void plus(char *a, char *b)
{	
	char c[MAX+1];
	int len_a = strlen(a);
	int len_b = strlen(b);
	int i = len_a - 1; // 字符串a倒序
	int j = len_b - 1; // 字符串b倒序
	int k = 0; // 字符串c正序 c[k] = a[i] - b[j];
	int flag = 0; // 是否本次有进位,有的话在下一次循环加1；
	int x, y, z; // 相加的临时变量x = a[i], y = b[j], z = x- y

	while(i >= 0 || j >= 0)
	{
		if(i < 0)
			x = '0';
		else
			x = a[i];

		if(j < 0)
			y = '0';
		else
			y = b[j];

		z = x - '0' + y - '0';
		if(flag)
			z += 1;
		if(z > 9)
		{
			flag = 1;
			z = z % 10;
		}
		else
			flag = 0;
		c[k++] = z + '0';
		i--;
		j--;
	}
	

	if(flag)
		c[k++] = '1';
	c[k++] = '\0';
	

	for(int p = strlen(c) - 1; p>=0; p--)
	{
		printf("%c ", c[p]);
	}
	printf("\n");
}
