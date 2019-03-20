#include <stdio.h>

void sort(int **p, int n);

int main(void)
{
	int a[100] = {};
	int *p[100] = {};
	int i, n;
	for(i = 0; i < 100; i++)
		p[i] = a+i;

	printf("n?\n");
	scanf("%d", &n);
	printf("a[]?\n");
	for(i = 0; i < n; i++)
		scanf("%d", p[i]);

	sort(p, n);

	for(i = 0; i < n; i++)
		printf("%d ", *p[i]);
	printf("\n");
	return 0;
}

void sort(int **p, int n)
{
	int i, j, minj, *t;
	for(i = 0; i < n; i++)
	{
		minj = i;
		printf("in sort :i = %d\n", i);
		for(j = i + 1; j < n; j++)
		{
                	printf("in sort :j = %d\n", j);
			if(**(p+j) < **(p+minj)){
				minj = j;
				printf("in sort :**(p+j) = %d\n", **(p+j));
			
			}
		}
		printf("in sort :*t = %ld\n", t);

		t = *(p+minj);
		printf("in sort :new*t = %ld\n", t);
		*(p+minj) = *(p+i);
		printf("in sort :*(p+minj) = %ld\n", *(p+minj));
		*(p+i) = t;
		printf("in sort :*(p+i) = %ld\n", *(p+i));


	}
}
