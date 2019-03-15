#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * code(int n)
{
	char p[32] = {0}, ch, *s = p;
	int bit = 1, m;

	printf("pre 0 %d\n", n);
	if(n >= 0)
	{
		for(int i = 0; i < 32; i++)
		{
			printf("n > 0 %d\n", i);
			m = (n & bit);
			bit = (bit << 1);
			m = (m >> i);
			ch = m + '0';
			p[31-i] = ch;
		}
		return s;
	}
	
	bit = 1;
	if(n < 0)
	{
//		n = abs(n);
//		n = ~n + 1;
		for(int i = 0; i < 32; i++)
		{
			printf("n < 0 %d\n", i);
			m = n & bit;
			bit = bit << 1;
			m = m >> i;
			ch = m + '0';
			p[31-i] = ch;
		}
		return s;// 最高位的char 是'\1111111111111111111011'
	}
}

int main(void)
{
	int n;
	char s[32];
	scanf("%d", &n);
	strcpy(s, code(n));
	for(int i = 0; i < 32; i++)
		printf("%d ", s[i]);
	printf("\n%s\n", s);
	return 0;
}
