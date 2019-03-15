#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct Student
{
	long num;
	char name[10];
	int age;
	char room[20];
}stu[SIZE];

void save();

int main(void)
{
	int i;
	printf("Enter msg: 1001 Job 11 room101:\n");
	for(i = 0; i < SIZE; i++)
	{
		scanf("%ld %s %d %s", &stu[i].num, stu[i].name, &stu[i].age, stu[i].room);
	}
	save();
	return 0;
}

void save()
{
	FILE *fp;
	int i;
	if((fp = fopen("studentMsg.dat", "wb")) == NULL)
	{
		printf("Couldnt open file.\n");
		exit(0);
	}

	for(i = 0; i < SIZE; i++)
	{
		if(fwrite(&stu[i], sizeof(struct Student), 1, fp) != 1)
			printf("file write error!\n");
	}
	fclose(fp);

}
