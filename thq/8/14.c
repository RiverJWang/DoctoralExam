#include <stdio.h>

void inverNum(int a[], int n);

int main(void)
{
	int a[100];
	int i, *p, n;
	p = a;
	printf("How many number do you  input?\n");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", p + i);
	}

	inverNum(p, n);
	
	for(i = 0; i < n; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");
	return 0;
}

void inverNum(int a[], int n)
{
	int b[n];
	int i, j;
	for(i = 0, j = n - 1; i < n; i++, j--)
		b[j] = a[i];
	for(i = 0; i < n; i++)
		a[i] = b[i];
}
