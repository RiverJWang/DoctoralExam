#include <stdio.h>
#include <string.h>

void selectionSort(char *p[10]);
void bubbleSort(char *p[10]);

int main(void)
{
	char str[10][100] = {};
	char *p[10];
	int i, n = 10;

	for(i = 0; i < n; i++)
		p[i] = str[i];

	printf("Input your string\n");
	for(i = 0; i < n; i++)
		scanf("%s", p[i]);

	bubbleSort(p);
	
	printf("\n");
	for(i = 0; i < n; i++)
		printf("%s\n", p[i]);

	return 0;
}

void selectionSort(char *p[10])
{
	char *temp;
	int i, j, minj, n = 10;
	for(i = 0; i < n -1; i++)
	{
		minj = i;
		for(j = i; j < n; j++)
		{
			if(strcmp(p[j], p[minj]) < 0)
				minj = j;
		}
		temp = p[i];
		p[i] = p[minj];
		p[minj] = temp;
	}
}

void bubbleSort(char *p[10])
{
	int i, j, flag = 1, n = 10;
	char *temp;
	for(i = 0; flag; i++)
	{
		flag = 0;
		for(j = n -1; j > i; j--)
		{
			if(strcmp(p[j], p[j - 1]) < 0)
			{
				flag = 1;
				temp = p[j];
				p[j] = p[j - 1];
				p[j - 1] = temp;
			}
		}
	}
}
