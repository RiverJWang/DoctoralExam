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
	char ch, pre;
	int flag = 0;
	int i, j;
	if((fp1 = fopen(filename, "rb")) == NULL)
	{
		printf("Cannot open this file1.\n");
		exit(0);
	}
	if((fp2 = fopen("temp.c", "wb")) == NULL)
	{
		printf("Cannot open this file2.\n");
		exit(0);
	}
	
	pre = '\0';	
	ch = fgetc(fp1);
	while(!feof(fp1))
	{
		if(ch == '/' && pre == '/')
		{
			while(!feof(fp1))
			{
				pre = ch;
				ch = fgetc(fp1);
				if(ch == '\n')
				{
					ch = fgetc(fp1);
					pre = '\n';
					break;
				}
			}
		}

		if(ch == '*' && pre == '/')
		{
			while(!feof(fp1))
			{
				pre = ch;
				ch = fgetc(fp1);
				if(ch == '/' && pre == '*')
				{
					ch = fgetc(fp1);
					pre = '\0';
					break;
				}
			}
		}


		if(ch == '"')
		{
			while(!feof(fp1))
			{
				fputc(pre, fp2);
				putchar(pre);
				pre = ch;
				ch = fgetc(fp1);
				if(ch == '"')
					break;
			}
		}
		if(ch == ' ' && pre == ' ')
		{
			while(!feof(fp1))
			{
				ch = fgetc(fp1);
				if(ch != ' ')
				{
					break;
				}

			}
		}
		


		fputc(pre, fp2);
		putchar(pre);
		pre = ch;
		ch = fgetc(fp1);
	}
	
//	remove(filename);
//	rename("temp.c", filename);
	fclose(fp1);
	fclose(fp2);
}
