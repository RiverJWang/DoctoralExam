#include <stdio.h>

short int logic(unsigned short int a, int n); //一定要用unsigned 才能右移
short int vector(unsigned short int a, int n);
/*
 * 不管是正数还是负数，右移1位时丢弃最右1位，复制原有符号位作为新的符号位。
所以，对于正数x，x>>1=x/2
对于负数x，x>>1=(x-1)/2
所以，-1,右移还是-1。
负数的右移1，符号位还是1。符号位原来的1也是右移1的。
 * */
int main(void)
{
	int x = 0xffff;
	int flag = 0;
	int n = 8;

	if((x >> 1) >= 0)
	{
		printf("It's logic!\n");
//		printf(" %d >> 8 = %d\n", x, vector(x , n));
	}

	else if((x >> 1) < 0)
	{
		printf("It's vector!\n");
		flag = logic(x, n);
//		printf("sizeof(short int) = %d, %d >> 8 = %d\n", sizeof(short int), x, logic(x , n));
	}

	printf(" %x >> 8 = %x\n", x, x >> 8);
	return 0;
}

short int logic(unsigned short int a, int n)
{
	printf("before, a=%d, n=%d\n", a, n);
	a = (unsigned short int)a >> 8;
	printf("after, a=%d, n=%d\n", a, n);
	a = a & (0x7fff);
	printf("final, a=%d, n=%d\n", a, n);
	return a;
}

short int vector(unsigned short int a, int n)
{
	if(a >= 0)
		a = a >> n;
	else{
		a = a >> n;
		a = a & (0xffff);
	}
	return a;
}
