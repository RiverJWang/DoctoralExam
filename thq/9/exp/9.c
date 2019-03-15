#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Student *)

struct Student
{
	long num;
	float score;
	struct Student *next;
};

int n = 0;

struct Student * creat(void);
void print(struct Student *);

int main(void)
{
	struct Student *p;
	int k = 1;
	while(k)
	{
		if(k == 1)
			p = creat();
		else if(k == 2)
			print(p);
		printf("\n**press 1 add**press 2 print all**press 0 exit****\n");
		scanf("%d", &k);
	}
	return 0;
}

struct Student * creat(void)
{
	struct Student *head;
	struct Student *p1, *p2;
	p1 = p2 = (struct Student *)malloc(LEN);
	head = NULL;
	printf("long num float score, *next\nWarning:num == 0 will exit\n");
	scanf("%ld %f", &p1->num, &p1->score);
	while(p1->num != 0)
	{
		n = n + 1;
		if(n == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct Student *)malloc(LEN);
		printf("long num float score, *next\nWarning:num == 0 will exit\n");
		scanf("%ld %f", &p1->num, &p1->score);
	}
	p2->next = NULL;
	return head;
}

void print(struct Student *head)
{
	struct Student *p;
	p = head;
	if(p->next != NULL)
	{
		do
		{
			printf("\nStudent num:%ld\nStudent Score:%f\n", p->num, p->score);
			p = p->next;
		}while(p != NULL);
	}
}
