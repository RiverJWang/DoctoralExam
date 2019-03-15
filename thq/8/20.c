#include <stdio.h>
#include <string.h>

void selectionSort(char **p);

int main(void)
{
	char a[5][30], *b[5], **p;
	int i;

	for(i = 0; i < 5; i++)
		b[i] = a[i];
	for(i = 0; i < 5; i++)
		scanf("%s", b[i]);
	p = b;
	selectionSort(p);
	printf("\n");
	for(i = 0; i < 5; i++)
		printf("%s\n", b[i]);
	return 0;
}

void selectionSort(char **p)
{
	int i, j, minj, n = 5;
	char *temp;
	
	for(i = 0; i < n - 1; i++)
	{
		minj = i;
		for(j = i; j < n; j++)
		{
			if(strcmp(*(p + j), *(p + minj)) < 0)
				minj = j;
		}
		temp = *(p + i);
		*(p + i) = *(p + minj);
		*(p + minj) = temp;
	}

}
