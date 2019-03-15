// 张老师借书
#include <stdio.h>

void book(void)
{
	int a[4] = {0,1,2,3}; // 1A 2B 3C
	int books[6] = {0,1,2,3,4,5}; // 1~5 代表各种不同的五本书
	int i, j, k, cnt = 0;

	for(i = 1; i <= 5; i++) // 学生
	{
		for(j = 1; j <= 5; j++)
		{
			for(k = 1; k <= 5; k++)
			{
				if(i != j && i != k && j != k)
					printf("A-book%d, B-book%d, C-book%d, cnt%d\n", i, j, k, ++cnt);
			}
			
		}
	}


}

int main(void)
{
	book();
	return 0;
}
