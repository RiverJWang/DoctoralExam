#include <stdio.h>
#include <string.h>

int *count(char *s);

int main(void)
{
	int *p;
	char *s = "00010111001110001111";
	p = count(s);
	printf("NO=%d\n", *(p+0));
	printf("N1=%d\n", *(p+1));
	return 0;
}

int *count(char *s)
{
	int a[2] = {0, 0}, *pa = a;
	int cnt0 = 0, cnt1 = 0, max0 = 0, max1 = 0, flag = 2;;
	char *p;
	int i;
	p = s;
	for(i = 0; *(p+i) != '\0'; i++)
	{
		if(*(p+i) == '0')
		{
			cnt0++;
			printf("i = %d, *(p+i) = %c, cnt0 = %d, flag = %d\n", i, *(p+i), cnt0, flag);
			if(flag == 1)
			{
				if(max1 < cnt1)
					max1 = cnt1;
				cnt1 = 0;
			}
			flag = 0;
		}
		if(*(p+i) == '1')
		{
			cnt1++;
			printf("i = %d, *(p+i) = %c, cnt1 = %d, flag = %d\n", i, *(p+i), cnt1, flag);
			if(flag == 0)
			{
				if(max0 < cnt0)
					max0 = cnt0;
				cnt0 = 0;
			}
			flag = 1;
		}
	}
	if(flag == 1)
		if(max1 < cnt1)
			max1 = cnt1;
	if(flag == 0)
		if(max0 < cnt0)
			max0 = cnt0;
	a[0] = max0;
	a[1] = max1;
	return pa;
}
