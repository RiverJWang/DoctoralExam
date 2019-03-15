#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char* plus(char *a, char *b);

int main(void)
{
	char a[MAX], b[MAX];

	gets(a);
	gets(b);
	printf("%s\n", plus(a, b));
}

char* plus(char *a, char *b)
{
	char temp[MAX] = {0}, sum[MAX+1] = {'0'}, *p = sum;
	char ch;
	int n1 = strlen(a), n2 = strlen(b);
	int i, j;
	char add = 0; // 进位

	if(n1 < n2) // 使a是最长的串  最大的数
	{
		strcpy(temp, b);
		strcpy(b, a);
		strcpy(a, temp);
	}
	n1 = strlen(a); // a大数, n1最大 
	n2 = strlen(b);
	
	printf("n1=%d n2=%d\na=%s b=%s\n", n1, n2, a, b);
	
	

	for(i = n1 - 1, j = n2 - 1; j > 0; i--, j--)
	{
		ch = (a[i] - '0') + (b[j] - '0');
		add = ch / 10;
		ch = ch % 10;

		a[i] = ch;
//		printf("i = %d, a= %s, add = %d\n", i, a, add);
		if(add)
		{
			a[i-1] = a[i-1] + add;
			printf("a[%d-1]%d\n", i, a[i-1]);
		}
	}

	ch = (a[i] - '0') + (b[j] - '0');
	add = ch / 10;
	ch = ch % 10;

	a[i] = ch;
	printf("%d ", a[i]);
	if(add == 1)
	{
		strcpy(sum+1, a);
		sum[0] = '1';
		p = sum;
		return p;
	}
	else
	{	p = a;
		return p;
	}
}
