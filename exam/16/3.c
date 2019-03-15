/* 算法思路：
 * 1：设立3个指针pa、pb、pc，其中pa和pb分别指向ha和hb链表中
 * 待比较插入的结点，而pc指向hc表中当前最后一个结点。
 *
 * 2：比较pa->data和pb->data,将较小者插入hc的表尾,也就是连接到
 * pc所指向的结点之后,若pa->data和pb->data相等,则将两个结点均
 * 链接到pc所指结点之后.
 *
 * 3:如此反复,直到有一个表的元素已经完毕(pa或pb为空)为止,再将
 * 另一个表的剩余段连接到pc所指向的结点之后.
 *
 */

void mergeList(LinkList &ha, LinkList &hb, LinkList &hc)
{
	LNode *pa, *pb, *pc;

	pa = ha->next;
	pb = hb->next;
	hc = pc = ha;//用ha头结点作为hc的头结点,pc始终指向hc表尾
	
	while(pa && pb)
	{
		if(pa->data < pb->data)
		{
			pc->next = pa; pc = pa; pa = pa->next;
		}
		else if(pa->data > pb->data)
		{
			pc->next = pb; pc = pb; pb = pb->next;
		}
		else
		{
			pc->next = pa; pc = pa; pa = pa->next;
			pc->next = pb; pc = pb; pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb; // 插入剩余段
	free(hb);
} //若ha和hb表长为m和n, 最坏时间复杂度为O(m+n)
