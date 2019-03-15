#include <stdio.h>

void sort(int *p, int m, int n);

int main(void)
{
	int a[10] = {2,4,6,8,10,12,14,16,18,20};
	int *p, m, n;
	printf("Input m n\n");
	scanf("%d %d", &m, &n);
	sort(p, m, n);
	for(int i= 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}

void sort(int *p, int m, int n)
{
	for(int i = m -1; i < (m + n))
}
