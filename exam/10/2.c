#include <stdio.h>
#include <string.h>

int *count(char *s)
{
	int cnt[2] = {0, 0}, max[2] = {0, 0}, *p=max;
	int i = 0;

	while(s[i] != 0)
	{
		cnt[1] = cnt[0] = 0;
		if(s[i] == '0')
		{
			do
			{
				cnt[0]++;
				i++;
			}while(s[i] == '0');
			if(cnt[0] > max[0])
				max[0] = cnt[0];
		}

		if(s[i] == '1')
		{
			do
			{
				cnt[1]++;
				i++;
			}while(s[i] == '1');
			if(cnt[1] > max[1])
				max[1] = cnt[1];
		}
	}
	return p;
}

int main(void)
{
	int *p;
	char s[] = "00010111001110001111";
	p = count(s);
	printf("N0=%d\n", *(p+0));
	printf("N1=%d\n", *(p+1));

	return 0;
}
