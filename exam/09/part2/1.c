#include <stdio.h>

int main(void)
{
	unsigned long num, max, t;
	int cnt;
	cnt = max = 0;
	scanf("%ld", &num);

	do
	{
		t = num % 10;
		if(t == 0)
			cnt++;
		else
			if(max < t)
				max = t;
		num /= 10;
	}while(num);
	printf("cnt = %d, max = %d\n", cnt, max);
	return 0;
}
