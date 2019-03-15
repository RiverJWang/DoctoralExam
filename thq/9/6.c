#include <stdio.h>

struct Person
{
	int num;
	int flag;
	struct Person *next;
};

void game(struct Person *head);


int main(void)
{
	struct Person a[13];
	struct Person *p;
	int i, n = 13;

	p = a;
	for(i = 0; i < 13 ; i++)
	{
		a[i].num = i + 1;
		a[i].flag = 1;
		a[i].next = &a[i + 1];
	}
	
	a[12].next = &a[0];

	game(p);
	
//	for(i = 0; i < 13 ; i++)
//	{
//		printf("num %d flag %d\n", a[i].num, a[i].flag);
//	}
		return 0;
}

void game(struct Person *head)
{
	struct Person *p;
	int n = 13, bomb = 0, nquit = 0;
	p = head;
	while(nquit < n - 1)
	{	
		if(p->flag == 1)
			bomb++;
		if(bomb == 3)
		{
			bomb = 0;
			p->flag = 0;
			nquit++;
			printf("num %d flag %d\n", p->num, p->flag);
		}
		p = p->next;
	}
	while(p->flag == 0)p = p->next;
	printf("Winner is %d player\n", p->num);
}
