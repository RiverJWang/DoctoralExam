#include <stdio.h>
#define LEN sizeof(Node)

typedef struct Student
{
	int n;
	float s;
	struct Student *next;
}Node;

Node* creat(void);
Node* merge(Node* head1, Node* head2);
void selectionSort(Node* head);

Node* merge(Node* head1, Node* head2)
{
	Node* p1, *p2;
	p1 = head1;
	p2 = head2;
	if(p1 == NULL && p2 != NULL)
		return head2;
	if(p1 != NULL && p2 == NULL)
		return head1;
	if(p1 == NULL && p2 == NULL)
		return NULL;
	while(p1 = p1->next);
	p1->next = p2;
}

Node* selectionSort(Node* head)
{
	Node *p1, *p2, *temp, *min;
	p1 = p2 = head;
	temp = (Node*)malloc(LEN);
	for(; p1->next != NULL; p1 = p1->next)
	{
		min = p1;
		for(; p2 != NULL; p2 = p2->next)
		{
			if(p2->n < min->n)
				min = p2;
		}
		if(min->n != p1->n)
		{
			temp->n = min->n;
			temp->s = min->s;
			temp->next = min->next;

			min->n = p1->n;
			min->s = p1->s;
			min->next = p1->next;

			p1->n = temp->n;
			p1->s = temp->s;
			p1->next = temp->next;
		}
	}
	free(temp);
}
