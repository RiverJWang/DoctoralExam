#include <stdio.h>

int main(void)
{
	int s, t, a, b;
	scanf("%d %d", &a, &b);
	s = 1;
	t = 1;
	if(a > 0) s = s + 1;
	if(a > b) t = s + t;
	else if(a == b) t = 5;
	else t = 2 * s;
	printf("s=%d, t=%d\n", s, t);

	return 0;
}
