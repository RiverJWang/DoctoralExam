#include <stdio.h>

void lessonOne(float (*p)[5]);
void failLesson(float (*p)[5]);
void goodLesson(float (*p)[5]);

int main(void)
{
	float a[4][5] = {{100, 100, 80, 99, 99}, {86, 86, 87, 88, 89}, {59, 58, 80, 90, 100}, {34, 67, 38, 99, 99}};
	lessonOne(a);
	failLesson(a);
	goodLesson(a);

	return 0;
}

void lessonOne(float (*p)[5])
{
	int i;
       	float sum = 0;
	for(i = 0; i < 4; i++)
		sum = sum + *(*(p + i) + 0);
	printf("lesson one ave is %f\n", sum / 5.0);
}

void failLesson(float (*p)[5])
{
	int counter = 0;
	int i, j;
	float sum;
	for(i = 0; i < 4; i++)
	{
		counter = 0;
		sum = 0;
		for(j = 0; j < 5; j++)
		{
			if(*(*(p + i) + j) < 60)
				counter++;
		}
		if(counter >= 2)
		{
			printf("students number is %d fail\n", i);
			for(j = 0; j < 5; j++)
			{
				printf("courese%d is %f ", j, *(*(p + i) + j));
				sum = sum + *(*(p + i) + j);
			}
			printf("aver is %f\n", sum / 5.0);
		}
	}
}
void goodLesson(float (*p)[5])
{
	int counter = 0, flag = 0;
	int i, j;
	float sum;
	for(i = 0; i < 4; i++)
	{
		counter = 0;
		sum = 0;
		flag = 0;
		for(j = 0; j < 5; j++)
		{
			if(*(*(p + i) + j) >= 85)
				counter++;
		}
		if(counter == 5)
			flag++;
		for(j = 0; j < 5; j++)
		{
			sum = sum + *(*(p + i) + j);
		}
		if(sum / 5.0 >= 90)
			flag++;
		if(flag >= 1)
			printf("Student %d has a nice work\n", i);
	}
}
