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

int main(void)
{
	FILE *fp;
	int i;
	if((fp = fopen("studentMsg.dat", "rb")) == NULL)
	{
		printf("couldn read file.\n");
		exit(0);
	}
	for(i = 0; i < SIZE; i++)
	{
		fread(&stu[i], sizeof(struct Student), 1, fp);
		printf("%ld %s %d %s\n", stu[i].num, stu[i].name, stu[i].age, stu[i].room);
	}
	fclose(fp);
	return 0;
}
