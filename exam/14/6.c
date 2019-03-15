#include <stdio.h>

void partition(unsigned long num)
{
	union
	{
		unsigned long num;
		unsigned int part[2];
	}a, *p;
	p = &a;
	a.num = num;
	printf("unsigned long num is %lx\n", num);
	printf("In union unsigned long num is %lx\n", a.num);
	printf("part1 = %d, part2 = %d\n", p->part[0], p->part[1]);
	printf("long =%ld, int =%ld\n", sizeof(long), sizeof(int));
}

int main(void)
{
	unsigned long num;
	scanf("%lx", &num);
	partition(num);
	return 0;
}

