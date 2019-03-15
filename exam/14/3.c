#include <stdio.h>
#include <stdlib.h>

void merge(char *filename1, char *filename2);
void sort(char *a, int n);

int main(void)
{
	merge("A", "B");
	return 0;
}

void merge(char *filename1, char *filename2)
{
	FILE *fp1, *fp2, *fp3;
	char a[1000] = {}, *p = a;
	int n = 0;
	char ch;

	if((fp1 = fopen(filename1, "r")) == NULL)
	{
		printf("Cannot open this file1\n");
		exit(0);
	}
	if((fp2 = fopen(filename2, "r")) == NULL)
	{
		printf("Cannot open this file2\n");
		exit(0);
	}
	if((fp3 = fopen("C", "w")) == NULL)
	{
		printf("Cannot open this file3\n");
		exit(0);
	}

	ch = fgetc(fp1);
	while(!feof(fp1))
	{
		a[n] = ch;
		n++;
		ch = fgetc(fp1);
	}
	ch = fgetc(fp2);
	while(!feof(fp2))
	{
		a[n] = ch;
		n++;
		ch = fgetc(fp2);
	}
	a[n] = '\0';

	sort(p, n);
	for(int i = 0; a[i] != '\0'; i++)
	{
		fputc(a[i], fp3);
		printf("%c", a[i]);
	}
}

void sort(char *a, int n)
{
	int i, j, minj;
	char temp;

	for(i = 0; i < n-1; i++)
	{
		minj = i;
		for(j = i; j < n; j++)
		{
			if(*(a+j) < *(a+minj))
				minj = j;
		}
		temp = *(a+i);
		*(a+i) = *(a+minj);
		*(a+minj) = temp;
	}
}
