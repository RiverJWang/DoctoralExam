#include <stdio.h>

int main(void)
{
	static char a[] = "ABCDEFGH", b[] = "abCDefGh";
	char *p1, *p2;
	int k;
	p1 = a; p2 = b;
	for(k = 0; k<=7; k++)
		if((*(p1+k)==*(p2+k)))printf("%c", *(p1+k));
	printf("\n");
}
