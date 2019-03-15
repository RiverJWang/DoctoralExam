#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Student *)

struct Student 
{
	long num;
	float score;
	struct Student *next;
};

int n;

struct Student * creat(void);
void add(struct Student *);
void del(struct Student *);
void update(struct Student *);
void read(struct Student *);

int inputNode(void);

int main(void)
{
	struct Student *head;
	int loop;
	head = creat();
	printf("Please input 1(add) or 2(del) or 3(update) or 4(read a node or all) or 0(exit)\n");
	scanf("%d", &loop);
	while(loop)
	{
		if(1 == loop)
			add(head);
		else if(2 == loop)
			del(head);
		else if(3 == loop)
			update(head);
		else if(4 == loop)
			read(head);
		else
			printf("Error! \n");
		printf("Please input 1(add) or 2(del) or 3(update) or 4(read a node or all) or 0(exit)\n");
		scanf("%d", &loop);
	}
}

struct Student * creat(void)
{
	struct Student *head, *p1, *p2;
	p1 = p2 = (struct Student *)malloc(LEN);
	printf("Please input a node longnum & float scorei, you could 0 0 to add head only.\n");
	scanf("%ld %f", &p1->num, &p1->score);
	n = 0;
	head = (struct Student *)malloc(LEN);
	while(p1->num != 0)
	{
		n = n + 1;
		if(n == 1)
			head->next = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct Student *)malloc(LEN);
		printf("Please input a node longnum & float score\n");
		scanf("%ld %f", &p1->num, &p1->score);
	}
	p2->next = NULL;
	free(p1);
	return head;
}
void add(struct Student *head)
{
	struct Student *p1, *p2;
	p2 = head;
	while(p2->next != 0)
	{
		p2 = p2->next;
	}
	p1 =  (struct Student *)malloc(LEN);
	printf("Please input a node longnum & float score, ---0 0 to exit!---\n");
	scanf("%ld %f", &p1->num, &p1->score);
	while(p1->num != 0)
	{
		n = n + 1;
		if(n == 1)
			head->next = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct Student *)malloc(LEN);
		printf("Please input a node longnum & float score, --- 0 0 to exit!---\n");
		scanf("%ld %f", &p1->num, &p1->score);
	}
	p2->next = NULL;
	free(p1);
}
void del(struct Student *head)
{
	struct Student *p1, *p2;
	int node;
	node = inputNode();
	p2 = head;
	if(p2->next == NULL)
	{	
		printf("Only a head node, it couldn't be deleted\n");
		exit(0);
	}
	for(int i = 0; i < node - 1; i++)
	{
		p2 = p2->next;
	}
	if(node == n)
	{
		p1 = p2->next;
		p2->next = NULL;
		n--;
	}
	else
	{
		p1 = p2->next;
		p2->next = p1->next;
		n--;
	}
	free(p1);
}

void update(struct Student *head)
{
	struct Student *p1, *p2;
	int node;
	long tempnum;
	float tempscore;
	
	printf("Which one would like update?\n");
	node = inputNode();
	printf("num and score\n");
	scanf("%ld %f", &tempnum, &tempscore);
	
	p2 = head;
	if(p2->next == NULL)
	{	
		printf("Only a head node, it couldn't be updated\n");
		exit(0);
	}
	for(int i = 0; i < node; i++)
	{
		p2 = p2->next;
	}
	p2->num = tempnum;
	p2->score = tempscore;
	printf("%dnode stunum%ld has changed\n", node, p2->num);
}
void read(struct Student *head)
{
	struct Student *p2;
	int node;
	int i = 0;
	
	printf("Which one would like read? 1~%d to read, 0 to all\n", n);
	scanf("%d", &node);
	
	p2 = head;
	if(p2->next == NULL)
	{	
		printf("Only a head node, it couldn't be readed\n");
		return;
	}
	if(node >= 1 && node <= n)
	{
		for(int i = 0; i < node; i++)
		{
			p2 = p2->next;
		}
		printf("%dnode, stunum%ld, stuscore%f\n", node, p2->num, p2->score);
	}
	else
	{
		while(p2->next != NULL)
		{
			p2 = p2->next;
			printf("%dnode, stunum%ld, stuscore%f\n", (i++) + 1, p2->num, p2->score);
		}

	}
}

int inputNode(void)
{
	int node;
	while(1)
	{
		printf("which node would like delete? 0 is exit, 1~%d\n", node);
		scanf("%d", &node);
		if(node <= n && node >= 0)
			break;
		else
		{	
			printf("Please input correct node\n");
			printf("which node would like delete? 0 is exit, 1~%d\n", node);
			scanf("%d", &node);
		}
	}
	return node;
}
