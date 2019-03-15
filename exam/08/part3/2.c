#include <stdio.h>
#define PI 3.1415926
#define S(r) PI*r*r

int main(void)
{
	float a = 3.6, area;
	area = S(a + 1.4);
	printf("area = %f\n", area);
	return 0;
}

