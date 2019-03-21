#include <stdio.h>
#include <stdlib.h>
#define N 100

void merge(char *A, char *B, char *C);
void sort(char *a, int n);

int main(void)
{
	char A[N] = {}, B[N] = {}, C[N] = {};
	gets(A);
	gets(B);
	gets(C);

	merge(A, B, C);
	return 0;
}

void merge(char *A, char *B, char *C)
{
	FILE *fp1, *fp2, *fp3;
	char c[N+1] = {}, ch;
	int len = 0;
	
	if( (fp1 = fopen(A, "r")) == NULL )
	{
		printf("fp1 cannot open!\n");
		exit(0);
	}
	if( (fp2 = fopen(B, "r")) == NULL )
	{
		printf("fp2 cannot open!\n");
		exit(0);
	}

	if( (fp3 = fopen(C, "w")) == NULL )
	{
		printf("fp3 cannot open!\n");
		exit(0);
	}

	ch = fgetc(fp1);
	while(!feof(fp1) && (ch != '\n'))
	{
		c[len++] = ch;
		ch = fgetc(fp1);
	}

	ch = fgetc(fp2);
	while(!feof(fp2) && (ch != '\n'))
	{
		c[len++] = ch;
		ch = fgetc(fp2);
	}
	
	c[len] = '\0';

	printf("before %s\n", c);
	
	for(int k = 0; k < len; k++)
		printf("%d ", c[k]);
	printf("\n");

	sort(c, len);

	printf("after %s\n", c);
	for(int k = 0; k < len; k++)
		printf("%d ", c[k]);
	printf("\n");
	fputs(c, fp3);

	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}

void sort(char *a, int n)
{
	int i, j, minj;
	char t;

	for(i = 0; i < n; i++)
	{
		minj = i;
		for(j = i; j < n; j++)
		{
			if(a[j] < a[minj])
				minj = j;
		}

		t = a[i];
		a[i] = a[minj];
		a[minj] = t;
	}
}
