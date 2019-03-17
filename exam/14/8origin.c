#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(Node)


typedef struct NNode
{
	int n;
	struct NNode *next;
}Node, Head;

Head* del(Node* HA, Node* HB, int i, int m, int j)  // 假设A B足够长
{
	Node *p1, *p2, *p3, *p4;
	int alen = 0, blen = 0;
	p1 = p2 = HA;
	p3 = p4 = HB;	
	while(p1 != 0)
	{
		alen++;
		p1 = p1->next;
	}
	p1 = HA;
	while(p3 != 0)
	{
		blen++;
		p3 = p3->next;
	}
	p3 = HB;

	if(i <= 0 || i > alen || (m-i) > alen || j <= 0 || j > blen)
	{	
		printf("over bondary\n");
		exit(0);
	}
	if()
}
