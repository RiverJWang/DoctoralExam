#include <stdio.h>

void magic(void)
{
	int a[26] = {0};
	int i;
	int cards = 1, blank = 2;
	char deck[26][10] = {"黑桃A", "黑桃2", "黑桃3","黑桃4","黑桃5","黑桃6",
		"黑桃7","黑桃8","黑桃9","黑桃10","黑桃J","黑桃Q","黑桃K",
		"红桃A", "红桃2", "红桃3","红桃4","红桃5","红桃6",
                "红桃7","红桃8","红桃9","红桃10","红桃J","红桃Q","红桃K"
	};
	

	for(i = 0; i < 26;i++)
	{
		if(a[i] == 0)
		{
			if(blank == 2)
			{
				a[i] = cards++;
				blank = 0;
			}
			else
			{
				blank++;
			}
		}

		if(cards <= 26 && i >= 25)
			i = 0; // 循环数组 与 退出数组
	}

	for(int k = 0; k < 26; k++)
	{
		printf("%6s ", deck[a[k]-1]);
		if(k == 12)
			printf("\n");
	}
	printf("\n");
}


int main(void)
{
	magic();
	return 0;
}
