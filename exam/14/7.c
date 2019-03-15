#include <stdio.h>
#include <string.h>

void sort(char *s[10]);

int main(void)
{
	char a[10][100];
	char *p[10];
	for(int i = 0; i < 10; i++)
	{
		gets(a[i]);
		p[i] = a[i];
	}

	sort(p);
	for(int i = 0; i < 10; i++)
	{
		printf("%s\n", p[i]);
	}
	return 0;
}

void sort(char *s[10])
{
	char *t;
	int i, j, minj;
	for(i = 0; i < 10; i++)
	{
		minj = i;
		for(j = i; j < 10; j++)
		{
			if(strcmp(s[j], s[minj]) < 0)
				minj = j;
		}
		t = s[i];
		s[i] = s[minj];
		s[minj] = t;
	}
}
