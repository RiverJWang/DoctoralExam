//  指向指针的指针 字符串
#include <stdio.h>
#include <string.h>
#define N 10

void sort(char *p[N]);

int main(void)
{
	char a[N][100] = {
		"China","Africa","India","Japan","Canada",
		"Italy","Switherland","Asia","Brazil","Cuba"};
	char* p[N];
	for(int i = 0; i < N; i++)
		p[i] = a[i];

	sort(p);
	
	for(int i = 0; i < N; i++)
		puts(p[i]);
	return 0;
}

void sort(char *p[N])
{
	char *temp;
	int i, j, minj;

	for(i = 0; i < N; i++)
	{
		minj = i;
		for(j = i; j < N; j++)
		{
			if(strcmp(p[j], p[minj]) < 0)
				minj = j;
		}

		temp = p[i];
		p[i] = p[minj];
		p[minj] = temp;
	}
}
