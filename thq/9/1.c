#include <stdio.h>

struct Date
{
	int year;
	int month;
	int day;
};

int countDay(struct Date date1);
int isLeapyear(struct Date date1);

int main(void)
{
	int n;
	struct Date date1;
	printf("year month day\n");
	scanf("%d %d %d", &date1.year, &date1.month, &date1.day);
	n = countDay(date1);
	printf("is %d day\n", n);
	return 0;
}

int countDay(struct Date date1)
{
	int n;
	int monthn = 0, i, sum = 0;
	int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	monthn = date1.month;
	for(i = 0; i < monthn; i++)
		sum = sum + m[i];
	sum = sum + date1.day;
	if((isLeapyear(date1) == 1) && (date1.month >= 3))
		sum = sum + 1;
	return sum;
}

int isLeapyear(struct Date date1)
{
	int year;
	int flag = 0;
	year = date1.year;
	if((year % 4 == 0) && (year % 100 > 0))
		flag = 1;
	else if(year % 400 == 0)
		flag = 1;
	else
		flag = 0;
	return flag;
}
