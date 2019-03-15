#include <stdio.h>

#define PI 3.1415926
#define S(r) PI*r*r

int main(void)
{
	float a, b, area;
	a = 3.6;
	b = 2.4;
	area = S(a + b);
	printf("r = %f\narea = %f\n", a + b, area);
	return 0;
}
