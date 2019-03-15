#include <stdio.h>
#include <stdlib.h>

void getNum(void);
int isNum(char c);

int main(void)
{
	getNum();
	return 0;
}

void getNum(void)
{
	FILE *fp;
	int numc = 0, number = 0, sum = 0, count = 0, flag = 1;
	char c;
	float aver = 0.0;
	if((fp = fopen("num.txt", "rb")) == NULL)
	{
		printf("Cannot open this file.\n");
		exit(0);
	}

	while(!feof(fp))
	{
		c = fgetc(fp);
	//	printf("c = %c\n", c);
		if(1 == isNum(c)) // is a num
		{
			if(1 == flag) //start a new number
			{
				count++;
				numc = c - '0';
				sum = sum + number;
				printf("num%d: %d\n", count, number);
				number = numc;
				flag = 0;
			}
			else	// in a num
			{
				numc = c - '0';
				number = number * 10 + numc;
			}
		}
		else	// not in a num
		{
			flag = 1; // ready to start a new number
		}
		if((feof(fp)))
		{
			count++; 
			sum = sum + number;
			printf("last num%d: %d\n", count, number);
		}
	}
	count--; // count 在第一次计数的时候多算了一个
	printf("\n");
	aver = sum / count;
	printf("%f\n", aver);
	fclose(fp);
}
int isNum(char c)
{
	if(c <= '9' && c >= '0')
		return 1;
	else
		return 0;
}
