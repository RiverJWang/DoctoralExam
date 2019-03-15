#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)

struct Student
{
	long num;
	char name[20];
	char sex[20];
	int year;
	struct Student *next;
};


struct Student *creat(void);
void check(struct Student *, int year);
void print(struct Student *);

int main(void)
{
	struct Student *head;
	int year;
	head = creat();

	printf("which year would you like to deleted?\n");
	scanf("%d", &year);
	
	printf("\n------------list before----------\n");
	print(head);
	printf("------------list before----------\n");
	
	check(head, year);
	
	printf("\n------------list after----------\n");
	print(head);
	printf("------------list after----------\n");

	return 0;
}

struct Student *creat(void)
{
	struct Student *head, *p1, *p2;
	long *np;
	head = (struct Student *)malloc(LEN);
	head->next = NULL;
	strcpy(head->name, "NoName");
	strcpy(head->sex, "NoSex");
	head->year = 99;
	np = &head->num;
	*np = 0;
	p2 = head;
	p1 = (struct Student *)malloc(LEN);
	printf("101 Jessica W 20\n");
	scanf("%ld %s %s %d", &p1->num, p1->name, p1->sex, &p1->year);
	while(p1->num != 0)
	{
		*np = *np + 1;
		p2->next = p1;
		p2 = p1;
		p1 = (struct Student *)malloc(LEN);
		scanf("%ld %s %s %d", &p1->num, p1->name, p1->sex, &p1->year);
	}
	p2->next = NULL;
	free(p1);
	return head;
}
void check(struct Student *head, int year)
{
	struct Student *pre, *p, *temp;
	int i = 0, j = 0;
	p = head->next;
	pre = head;
	while(p)
	{
		printf("\n****%dst loop****\n", ++i);
		printf("-----%ld %s %s %d from pre\n", pre->num, pre->name, pre->sex, pre->year);
		printf("-----%ld %s %s %d fromp\n", p->num, p->name, p->sex, p->year);
		if((p->year) == year)
		{
			if(p->next == NULL)
			{
				pre->next = NULL;
				temp = p;
				p = NULL;
				printf("%ld %s %s %d will be deleted\n", temp->num, temp->name, temp->sex, temp->year);
				free(temp);

			}
			else
			{
				pre->next = p->next;
				temp = p;
				p = p->next;
				//	pre = pre->next; 
				printf("%ld %s %s %d will be deleted\n", temp->num, temp->name, temp->sex, temp->year);
				free(temp);
			}
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
}

void print(struct Student *head)
{
        struct Student *p;
        for(p = head; p->next != 0;)
        {
                p = p->next;
		printf("%ld %s %s %d\n", p->num, p->name, p->sex, p->year);
        }
        printf("\n");
}

