#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
#define M 1000

void read(char *);
char* matrix(char a[][10]);

int main(void)
{
	char *filename = "code.txt";
	read(filename);
	return 0;
}

void read(char *s)
{
	char a[M][N] = {'\0'};
	int i = 0, j = 0, flag = 0;
	int I = 0, J = 0;
	char ch;
	char code[5];
	FILE *fp1, *fp2;


	if((fp1 = fopen(s, "r")) == NULL)
	{
		printf("fp1 cannot open\n");
		exit(0);
	}
	if((fp2 = fopen("codeResult.txt", "w")) == NULL)
	{
		printf("fp2 cannot open\n");
		exit(0);
	}

	ch = fgetc(fp1);
	while(!feof(fp1))
	{
		if(ch >= 'a' && ch <= 'z')
			flag = 1;
		else if(ch >= 'A' && ch <= 'Z')
			flag = 1;
		else if(ch >= '0' && ch <= '9')
			flag =1;
		if(flag == 1)
		{
			a[i][j] = ch;
			j++;
			if(j > N - 1)
			{
				i++;
				j = 0;
			}
		}
		flag = 0;
		ch = fgetc(fp1);
	}
	I = i;
	J = j;
	a[I][J] = 0;

	for(i = 0; i <= I; i++)
	{
		for(j = 0; j < N; j++)
		{
			fputc(a[i][j], fp2);
			fputc(' ', fp2);
			printf("%c ", a[i][j]);
		}
		fputc('\n', fp2);
		printf("\n");
	}
//	code = matrix(a);
	int cnt = 0;
	for(j = 0; j < N; j++)
	{
		for(i = 0; i <= I; i++)
		{
			if(a[i][j] >= 'A' && a[i][j] <= 'Z')
			{
				code[cnt] = a[i][j];
//				printf("i-%d j-%d cnt-%d code-%s\n", i, j, cnt, code);
				cnt++;
				if(cnt == 5)
				{
					fputs(code, fp2);
					fputc(' ', fp2);
					printf("%s ", code);
					cnt = 0;
					for(int tt = 0; tt < 5; tt++)
						code[tt] = 0;
				}
			}
		}
	}
	if(i >= I && j >= N -1 && cnt != 5)
	{
		fputs(code, fp2);
		fputc(' ', fp2);
		printf("%s ", code);
		cnt = 0;
	}

	fclose(fp1);
	fclose(fp2);
}
char* matrix(char a[][10])
{
		
}
