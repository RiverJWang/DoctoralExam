#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Student)

struct Student 
{
	long num;
	char name[10];
	struct Student *next;
};

struct Student *creat(void);
void repeat(struct Student *head1, struct Student *head2);
void delNode(struct Student *head1, struct Student *p);
void print(struct Student *head);

int main(void)
{
	struct Student *head1, *head2;
	head1 = creat();
	head2 = creat();

	printf("----------Old head1----------\n");
	print(head1);
	printf("----------Old head2----------\n");
	print(head2);
	
	repeat(head1, head2);
	printf("----------New list----------\n");
	print(head1);
	return 0;
}

struct Student *creat(void)
{
	struct Student *head, *p1, *p2;
	long *pn;
	head = (struct Student *)malloc(LEN);
	p2 = head;
	pn = &head->num;
	*pn = 0;
	head->next = NULL;
	p1 = (struct Student *)malloc(LEN);
	printf("Input:(like1001 Jessica)\n");
	scanf("%ld %s", &p1->num, p1->name);
	while(p1->num != 0)
	{
		*pn = *pn + 1;
		p2->next = p1;
		p2 = p1;
		p1 = (struct Student *)malloc(LEN);
		scanf("%ld %s", &p1->num, p1->name);
	}
	p2->next = NULL;
	return head;
}
void repeat(struct Student *head1, struct Student *head2)
{
	struct Student *p1, *p2, *prep, *temp;
	int i = 0, j = 0;
	p1 = head1->next;
	p2 = head2->next;
	prep = head1;
	for(; p2 != 0; p2 = p2->next)
	{
		printf("%dst outer loop\n", ++j);
		for(p1 = head1->next, prep = head1; p1 != 0;)
		{
			printf("---------------%dst inner loop----------------\n", ++i);
			printf("%ld %s from p1\n", p1->num, p1->name);
			printf("%ld %s from p2\n\n", p2->num, p2->name);
			if(p2->num == p1->num)
			{
				prep->next = p1->next;
				temp = p1;
				p1 = p1->next;
				printf("%ld %s will be deleted\n", temp->num, temp->name);
				free(temp);	
			}
			else 
			{	
				prep = p1;
				p1 = p1->next;
			}
		}
	}
}
void delNode(struct Student *head1, struct Student *p)
{
}
void print(struct Student *head)
{
	struct Student *p;
	for(p = head; p->next != 0;)
	{
		p = p->next;
		printf("%ld %s\n", p->num, p->name);
	}
	printf("\n");
}
