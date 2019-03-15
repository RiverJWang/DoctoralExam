#include <stdio.h>

void getbits(unsigned short value, int n1, int n2);

int main(void)
{
	int value;
	scanf("%o", &value);
	printf("Your number is %o, unsigned short is %ld\n", value, sizeof(unsigned short));

	getbits(value, 5, 8);
	return 0;
}

void getbits(unsigned short value, int n1, int n2)
{
	value = value << n1;
	value = value >> n1;
	
	value = value >> (16-n2);
	printf("Result = %o\n", value);
}
