#include <stdio.h>
#define N 13

struct{
	int next;
	int num;
}link[N+1];

void win(void);

int main(void)
{
	win();
	return 0;
}

void win(void)
{
	int i;
	int cnt = 0;
	int p;
	for(i = 1; i <= N; i++)
	{
		if(i == N)
			link[i].next = 1;
		else
			link[i].next = i + 1;
		link[i].num = i;
	}
	
	p = N;
	while(cnt < N-1)
	{
		i = 0;
		while(i != 3)
		{
			p = link[p].next;
			if(link[p].num)
				i++;
		}

		printf("Out %d\n", p);
		link[p].num = 0;
		cnt++;

	}


	for(i = 0; i <= N; i++)
		if(link[i].num)
			printf("winner is %d\n", link[i].num);

}
