#include <stdio.h>

int dec2hex(char *p);
int base;
int num;

int main(void)
{
	char *hex = "AD13C";
	int dec;
	dec = dec2hex(hex);

	printf("%d\n", dec);
	return 0;
}

int dec2hex(char *p)
{
	if(*p == '\0')
	{
		base = 1;
		num = 0;
		printf("base = %d\n", base);
	}
	else
	{
		num = dec2hex(p+1);
		if(*p >= '0' && *p <= '9')
			num = num + (*p - '0') * base;
		else if(*p >= 'A' && *p <= 'F')
			num = num + (*p - 'A' + 10) * base;
		base = base * 16;
		printf("base = %d\n", base);
	}
	return num;
}
