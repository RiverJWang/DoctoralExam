#include <stdio.h>
#define LEN 1000

char a[LEN];
char* newp = a;

char *alloc(int n)
{
	if(newp >= a && newp <= a+LEN)
	{
		newp = newp + n;
		return newp - n;
	}
	else
		return NULL;
}

void free(char *p)
{
	if(p >= a && p <= a+LEN)
		newp = p;
}
