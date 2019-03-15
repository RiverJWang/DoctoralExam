#include <stdio.h>

void getbits(unsigned short value, int n1, int n2);

int main(void)
{
	int value, n1, n2;
	scanf("%o", &value);
	printf("Your number is %o, unsigned short is %ld\n", value, sizeof(unsigned short));
	printf("from where to where\n");
	scanf("%d %d", &n1, &n2);
	getbits(value, n1, n2);
	return 0;
}

void getbits(unsigned short value, int n1, int n2)
{
	unsigned short int z;
	z = ~0;  // 16位全为1;
	z = z << (n1-1); z = z >> (n1-1);
	z = z >> (16-n2); z = z << (16-n2);
	z = value & z;
	
	
	z = z >> (16-n2);
	printf("Result = %o\n", z);  // 输入和输出都是八进制
}
