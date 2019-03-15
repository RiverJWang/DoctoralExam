#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BIRTH sizeof(Birth)
#define HEAD sizeof(Head)
#define NAME sizeof(Name)

typedef struct NName
{
	char str[30];
	struct NName *next;
}Name;

typedef struct BBirth
{
	int y;
	struct BBirth *next;
	struct NName *nextn;
}Birth, Head;

Birth *sortYear(Birth *, int);
void sortName(Birth *head, int year, char *str);

Head* creat(void)
{
	Head *head, *p1, *p2;
	Name *p3, *p4;
	head = NULL;
	p1 = p2 = (Head*)malloc(HEAD);
	p3 = p4 = (Name*)malloc(NAME);
	p1->next = NULL;
	p1->nextn = p3;
	p3->next = NULL;
	printf("CREAT 1980 Jessica:\n");
	scanf("%d %s", &p1->y, p3->str);
	if(p1->y != 0)
		head = p1;
	else
		printf("Creating LinkList fail\n");

//	free(p1);
//	free(p3);
	printf("Created Successed %d %s\n", head->y, (head->nextn)->str);
	return head;
}

Head* insert(Head *head)
{
	if(head == NULL || (head->nextn) == NULL)
	{
		printf("Please put a correct list head\n");
		return head;
	}

	Birth *p1, *p2;
	Name *p3, *p4;
	p1 = p2 = head;
	p3 = p4 = p2->nextn;
	p1 = (Birth*)malloc(BIRTH);
	p3 = (Name*)malloc(NAME);
	printf("ADD 1980 Jessica:\n");
	scanf("%d %s", &p1->y, p3->str);
	while(p1->y != 0)
	{
		head = sortYear(head, p1->y); // Birth *sortYear(Birth *, int);
		sortName(head, p1->y, p3->str); // void sortName(Birth *head, int year, char *str);
		printf("%d %s add Successed!\n", p1->y, p3->str);
		
		p1 = (Birth*)malloc(BIRTH);
		p3 = (Name*)malloc(NAME);
		printf("ADD 1980 Jessica:\n");
		scanf("%d %s", &p1->y, p3->str);
	}
//	free(p1);
//	free(p3);
	return head;

}
Birth *sortYear(Birth *head, int year)
{
	Birth *p1, *p2, *temp;
	p1 = p2 = head;
	int k = 0;
	if(year < p1->y)
	{
		temp = (Birth*)malloc(BIRTH);
		temp->y = year;
		temp->next = head;
		temp->nextn = NULL;
		head = temp;
		printf("Added year Node %d before the head.\n", temp->y);
	}
	else if(year >= p1->y)
	{
		while(1)
		{
			if(p1->y == year)
			{
				printf("Existed year Node%d\n", p1->y);
				break;
			}
			if(year > p2->y && year < p1->y)
			{
				temp = (Birth*)malloc(BIRTH);
				temp->y = year;
				temp->next = p1;
				temp->nextn = NULL;
				p2->next = temp;
				printf("Added year Node %d in the middle.\n", temp->y);
				break;
			}
			if(p1->next == NULL && p1->y < year)
			{	
				temp = (Birth*)malloc(BIRTH);
				temp->y = year;
				temp->next = p1;
				temp->nextn = NULL;
				p1->next = temp;
				printf("Added year Node %d after the last one\n", temp->y);
				break;
			}
			p2 = p1;
			p1 = p1->next;
			printf("In the add loop %d\n", ++k);
		}
	}
	return head;
}
void sortName(Birth *head, int year, char *str)
{
	Birth *p;
	Name *p1, *p2, *temp;
	int k = 0;
	p = head;
	p1 = p2 = NULL;
	while(1)
	{
		if(p->y == year)
			break;
		p = p->next;
	}

	p1 = p->nextn;
	p2 = NULL;
	while(1)
	{
		if(p->nextn == NULL)
		{
			temp = (Name*)malloc(NAME);
			strcpy(temp->str, str);
			temp->next = NULL;
			p->nextn =temp;
			printf("Added name Node in the void %s\n", temp->str);
			break;
		}
		if(p1 != NULL && p2 == NULL)
		{
			if(strcmp(p1->str, str) < 0)
			{
				temp = (Name*)malloc(NAME);
				strcpy(temp->str, str);
				temp->next = p1;
				p->nextn = temp;
				printf("Added name Node before the first %s\n", temp->str);
				break;
			}
			else
			{
				temp = (Name*)malloc(NAME);
				strcpy(temp->str, str);
				temp->next = NULL;
				p1->next = temp;
				printf("Added name Node after the first %s\n", temp->str);
				break;
			}
		}
		if(p1 != NULL && p2 != NULL && (strcmp(p1->str, str) <= 0) && (strcmp(p2->str, str) >= 0))
		{
			temp = (Name*)malloc(NAME);
			strcpy(temp->str, str);
			temp->next = p1;
			p2->next = temp;
			printf("Added name Node in the middle %s\n", temp->str);
			break;
		}
		if(p1 == NULL && p2 != NULL && (strcmp(p2->str, str) > 0))
		{
			temp = (Name*)malloc(NAME);
			strcpy(temp->str, str);
			temp->next = p1;
			p2->next = temp;
			printf("Added name Node after the last %s\n", temp->str);
			break;	
		}
	printf("In the Name loop %d\n", ++k);
	}
}

int main(void)
{
	Head *head;
	head = creat();
	head = insert(head);
	return 0;
}
