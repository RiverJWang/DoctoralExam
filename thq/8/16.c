#include <stdio.h>

int getnum(char str[], int a[]);

int main(void)
{
	char str[100] = {}, *pstr;
	int a[100] = {}, total, *p, i;
	p = a;
	pstr = str;
	printf("Input your string\n");
	gets(pstr);
	total = getnum(str, a);
	for(i = 0; a[i] != '\0'; i++)
		printf("%d ", a[i]);
	printf("total = %d\n", total);
	return 0;
}

int getnum(char str[], int a[])
{
	int count = 0, temp = 0;
	int i = 0, j = 0, k = 0, m = 0, e10;
	char *p;
	int *pa;
	p = str;
	pa = a;
	while(*(p + i) != '\0')
	{
		if((*(p + i) >= '0') && (*(p + i) <= '9'))
		{
			j++;
		}
		else
		{
			if(j > 0)
			{
				temp = *(p + i -1) - '0';
				k = 1;
				while(k < j)
				{
					e10 = 1;
					for(m = 1; m <= k; m++)
						e10 = e10 * 10;
					temp = temp + (*(p + i - 1 - k) - '0') * e10;
					k++;
					printf("2th while e10 temp =  %d\n", temp);
				} //while
				*pa = temp;
				printf("pa++ = %d\n", *pa);
				pa++;
				j = 0;
				count++;
			} //if
		} //else
		i++;
	} // while
	
	if(j > 0)
	{
		temp = *(p + i -1) - '0';
		k = 1;
		while(k < j)
		{
			e10 = 1;
			for(m = 1; m <= k; m++)
				e10 = e10 * 10;
			temp = temp + (*(p + i - 1 - k) - '0') * e10;
			k++;
			printf("2th while e10 temp =  %d\n", temp);
		} //while
		*pa = temp;
		printf("pa++ = %d\n", *pa);
		j = 0;
		pa++;
		count++;
	} //if
	*pa = '\0';
	return count;
}

