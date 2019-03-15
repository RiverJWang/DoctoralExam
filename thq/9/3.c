#include <stdio.h>

struct Student
{
	long num;
	char name[20];
	float score[3];
};

void input(struct Student stu[5]);
void output(struct Student stu[5]);

int main(void)
{
	struct Student stu[5];
	input(stu);
	output(stu);
	return 0;
}

void input(struct Student stu[5])
{
	int n = 5;
	printf("Now, you are inputing 'long num' 'char name[]' 'float score[0] [1] [2]'\n");
	for(int i = 0; i < n; i++)
	{
		scanf("%ld %s %f %f %f", &stu[i].num, stu[i].name, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
	}
}
void output(struct Student stu[5])
{
	int n = 5;
	for(int i = 0; i < n; i++)
	{
		printf("\nStudent num:%ld \nStudent name:%s \nscore1:%f score2:%f score3:%f\n\n", 
				stu[i].num, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
	}
}
