#include <stdio.h>

void month(int n);

int main(void)
{
	int n;
	printf("Input your num\n");
	scanf("%d", &n);
	month(n);

	return 0;
}

void month(int n)
{
	char *a[] = {"Jan","Feb", "Mar", "Apr", "May", "Jun", 
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	char **b[12];
	int i;

	for(i = 0; i < 12; i++)
		b[i] = a + i;

	if(n > 0 && n < 13)
		printf("%s", **(b + n - 1));
	else
		printf("1--12");
	printf("\n");
}
