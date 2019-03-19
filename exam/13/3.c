#include <stdio.h>

void sort(int *p, int m, int n);

int main(void)
{
	int a[10], *p, m, n;
       	p = a;
	for(int i = 0; i < 10; i++)
		scanf("%d", p+i);
	printf("m , n:\n");
	scanf("%d %d", &m, &n);
	sort(p, m, n);
	for(int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}

void sort(int *p, int m, int n)
{
	int *p1, *p2, t;
	p1 = p + m - 1;
	p2 = p1 + n - 1;

	for(; p1 < p2; p1++, p2--)
	{
		t = *p1;
		*p1 = *p2;
		*p2 = t;
	}
}
