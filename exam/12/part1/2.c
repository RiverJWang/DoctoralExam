#include <stdio.h>

int main(void)
{
	char a[] = "123456789", *p;
	int i = 0;
	p=a;
	while(*p)
	{
		if(i%2 == 0) *p='*';
		p++;
		i++;
	}
	puts(a);

	return 0;
}
