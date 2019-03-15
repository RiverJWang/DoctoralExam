#include <stdio.h>
#include <string.h>

void substring(char *s, int *index, int *length);

int main(void)
{
	char s[100];
	int index = 0, length = 0;
	gets(s);
	substring(s, &index, &length);

	for(int i = 0; i < length; i++)
	{
		printf("%c", s[index + i]);
	}
	printf("\n");

	return 0;
}

void substring(char *s, int *index, int *length)
{
	int i, j, k;
	int slen = strlen(s), len;
	


	for(i = 0; i < slen; i++)
	{
		for(j = i+1; j < slen; j++)
		{
			if(s[i] == s[j])
			{
				for(len = 1; s[i+len] == s[j+len]; len++);
				if(len > *length)
				{
					*length = len;
					*index = i;
				}
			}
		}
	}
}
