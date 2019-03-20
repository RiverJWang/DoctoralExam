#include <stdio.h>
#include <stdlib.h>

void cpyfile(char *filename1, char *filename2);

int main(int argn, char *argv[])
{
	cpyfile(argv[1], argv[2]);
	return 0;
}

void cpyfile(char *filename1, char *filename2)
{
	FILE *fp1, *fp2;
	char ch;

	if((fp1 = fopen(filename1, "r")) == NULL)
	{
		printf("Filename1 cannot open!\n");
		exit(0);
	}

	if((fp2 = fopen(filename2, "w")) == NULL)
	{
		printf("Filename2 cannot open!\n");
		exit(0);
	}

	ch = fgetc(fp1);

	while(!feof(fp1))
	{
		fputc(ch, fp2);
		putchar(ch);
		ch = fgetc(fp1);
	}
}
