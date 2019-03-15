#include <stdio.h>

void search(void);

int main(void)
{
	search();
	return 0;
}

void search(void)
{
	char name[7] = {'Z','A','B','C','D','E','F'}; // 名字
	int country[7] = {0,1, 2, 3, 4, 5, 6}; // 1美国 2德国 3英国 4法国 5俄罗斯 6意大利
	int thing[7] = {0,1,2,3,4,5,6,7}; // 1医生 2教师 3技师 4当兵  5年纪一 6西安 7杭州 8年纪二
	int flag[8] = {0};

	for(int i = 1; i <= 6; i++)  // name
	{
		for(int j = 1; j <= 6; j++) // country
		{
			for(int k = 1; k <= 7; k++) //thing
			{
				if(name[i] == 'A' && j == 1 && thing[k] == 1) //医生
					flag[1] = 1;
				if(name[i] == 'E' && j == 5 && thing[k] == 2) // Teacher
					flag[2] = 1;
				if(name[i] == 'C' && j == 2 && thing[k] == 3) // Technician
					flag[3] = 1;
				if(name[i] == 'B' && name[i] == 'F' && thing[4] && j != 2) //  当兵 有互斥
					flag[4] = 1;
				if((j == 4 && name[i] == 'A' && thing[k] == 5) && ( (j == 6 && name[i] == 'C') )) //年纪
					flag[5] = 1;
				if(name[i] == 'B' && j == 1 && thing[k] == 6)
					flag = 

			}
		}
	}
}
