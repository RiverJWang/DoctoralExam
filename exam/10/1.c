#include <stdio.h>
#include <stdlib.h>

void process(char *filename, int n);

int main(void)
{
	char *filename = "file.c";
	int n = 100;
	process(filename, n);
	return 0;
}

void process(char *filename, int n)
{
	FILE *fp1, *fp2;
	char str[n];
	int flag1 = 0, flag2 = 0;
	int i, j;
	if((fp1 = fopen(filename, "r")) == NULL)
	{
		printf("Cannot open this file1.\n");
		exit(0);
	}
	if((fp2 = fopen("temp.c", "w")) == NULL)
	{
		printf("Cannot open this file2.\n");
		exit(0);
	}

	while((fgets(str, n, fp1)) != NULL)
	{
		for(i = 0; i < n; i++)
		{
			if(str[i] == '/' && str[i-1] == '/')
			{
				str[i-1] = '\n';
				str[i] = '\0';
			}
			if(str[i] == '*' && str[i-1] == '/')
			{
				str[i-1] = '\0';
				flag1 = 1;
				/**/fputs(str, fp2);
			}
			if(str[i] == '/' && str[i-1] == '*')
			{
				for(j = 0; j < n - i; j++)
					str[j] = str[i+j+1];
				str[j] = '\0';
				flag1 = 0;
			}
			if(str[i]  == '"' && flag2 == 0)
				flag2 = 1;
			if(str[i] == '"' && flag2 == 1)
				flag2 = 0;
			if(str[i] == ' ' && flag2 == 0 && str[i-1] == ' ')
			{
				
			}
		}
		if(flag1 == 0)
			fputs(str, fp2);
	}
//	remove(filename);
//	rename("temp.c", filename);
	fclose(fp1);
	fclose(fp2);
}
