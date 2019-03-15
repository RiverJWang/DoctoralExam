#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Student *)

struct Student
{
	long num;
	float score;
	struct Student *next;
};

struct Student *creat(void);
void print(struct Student *);
void selectionSort(struct Student *head);
void merge(struct Student *head1, struct Student *head2);

int main()
{
	struct Student *head1, *head2, *head;
	head1 = creat();
	head2 = creat();

	printf("Now the head1\n");
	print(head1);
	printf("Now the head2\n");
	print(head2);

	merge(head1, head2);
	printf("Now the merge head\n");
	print(head1);
	selectionSort(head1);
	printf("Now the head after selectionSort\n");
	print(head1);

	return 0;
}

struct Student *creat(void)
{
	struct Student *head, *p1, *p2;
	int n = 0;
	head = (struct Student *)malloc(LEN);
	head->next = NULL;
	p1 = p2 =(struct Student *)malloc(LEN);
	printf("Enter info:(like 1001 98.6)\n"); //%ld %f
	scanf("%ld %f", &p1->num, &p1->score);
	while(p1->num != 0)
	{
		n++;
		if(n == 1)
			head->next = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct Student *)malloc(LEN);
		scanf("%ld %f", &p1->num, &p1->score);
	}
	p2->next = NULL;
	free(p1);
	return head;
}
void print(struct Student *head)
{
	struct Student *p;
	p = head;
	printf("**********          **********\n");
	while(p->next != 0)
	{
		p = p->next;
		printf("%ld %4.2f\n", p->num, p->score);
	}
	printf("**********          **********\n");
}

void merge(struct Student *head1, struct Student *head2)
{
	struct Student *p1;
	p1 = head1;
	
	while(p1->next != 0)
	{
		p1 = p1->next;
	//	printf("%ld %4.2f\n", p1->num, p1->score);
	}
	p1->next = head2->next;
	free(head2);
}

void selectionSort(struct Student *head)
{
	struct Student *p1, *p2, *minp1, *temp;
	
	temp = (struct Student *)malloc(LEN);

	for(p2 = head->next; p2->next != 0; p2 = p2->next)
	{
		minp1 = p2;
		for(p1 = p2; p1->next != 0;)
		{
			p1 = p1->next;
			if((p1->num) < (minp1->num))minp1 = p1;
		}
		temp->num = p2->num;
		temp->score = p2->score;
		p2->num = minp1->num;
		p2->score = minp1->score;
		minp1->num = temp->num;
		minp1->score = temp->score;
	}
	free(temp);

}
