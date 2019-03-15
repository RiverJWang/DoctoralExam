#include <stdio.h>


void win(void);

int main(void)
{
	win();
	return 0;
}

void win(void)
{
	int all = 21;
	int player = 0;
	int computer = 0;
	

	while(1)
	{
		printf("Would you take ?1 ~ 4\n");	
		scanf("%d", &player);
		computer = 5 - player;
		printf("Computer take %d\n", computer);
		all = all - 5;
		if(all == 1)
		{
			printf("remains = %d\nWinner is copmuter.\n", all);
			break;
		}
	}
}
