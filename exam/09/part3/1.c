#include <stdio.h>

struct stu
{
	int num;
	char name[10];
	int age;
};

void fun(struct stu *p)
{
	printf("%s\n", (*p).name);
}

int main(void)
{
	struct stu student[3] = {
		{9801, "Zhang",20},
		{9802, "Wang", 19},
		{9803, "Zhao", 18}
	};
	fun(student+2);
	return 0;
}

