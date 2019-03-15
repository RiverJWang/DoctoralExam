#include <stdio.h>

int cmp(char *a, char *b)
{
	int i, n = 0;
	int flag = 1;

	for(i = 0; *(a+i) != '\0' && *(b+i) != '\0'; i++)
	{

		if(*(a+i) != *(b+i))
		{
			n = *(a+i) - *(b+i);
			flag = 0;
			break;
		}

	}
	if(flag)  // 若结束之前的char都一样。
	{
		n = *(a+i) - *(b+i);
	}

	return n;
}

int main(void)
{
	char a[100], b[100];
	gets(a);
	gets(b);
	printf("%d\n", cmp(a, b));
	return 0;
}
