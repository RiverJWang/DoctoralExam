void Del(Node* head, int i, int k)
{
	Node *p, *q;
	int j;
	if(i == 1)
		for(j = 1; j <= k; j++)
		{
			p = head;
			head = head->next;
			free(p);
		}
	else
	{
		p = head; //一前一后
		for(j = 1; j <= i-2; j++)
			p = p->next; //p在第i-1个节点
		for(j = 1; j <= k; j++)
		{
			q = p->next; //第一次的时候q在第i个节点
			p->next = q->next;
			free(q);
		}
	}
}
