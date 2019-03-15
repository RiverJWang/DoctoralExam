#include <stdio.h>

void setPrint(int n);

int main(void)
{
	int n;
	scanf("%d", &n);
	setPrint(n);
	return 0;
}
void setPrint(int n)
{
	int a[n];
	int i, j, k;
	for(i = 0; i < n; i++)
		a[i] = i;
	int t = 1 << n;
	for (i = 0; i < t; i++)
	{
		j = i;
		k = 0;
		printf("{");
		while (j)
		{
			if (j & 1)
			{
				printf("%d", a[k]);
			}
			j >>= 1;
			++k;
		}
		printf("}\n");
	}

}
