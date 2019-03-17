#include <iostream>
using namespace std;
 
typedef struct LNode
{
	int data;
	LNode *next;
}LNode,*LinkList;
 
//创建链表
int CreateList(LinkList &L,int n)
{
	LNode *p,*r;int i;
	L=new LNode;
	L->next=NULL;
	r=L;
	for(i=0;i<n;i++)
	{
		p=new LNode;
		cin>>p->data;
		p->next=NULL;r->next=p;
		r=p;
	}
	return 0;
}
 
 
 
//输出链表
void display(LinkList L)
{
	LNode *p;
	p=L->next;
	cout<<"{";
	while(p)
	{cout<<p->data<<" ";
	p=p->next;}
	cout<<"}"<<endl;
}
 
//交集
void MergeList_L(LinkList &LA,LinkList &LB,LinkList &LC)
{
    LNode *pa;LNode *pb;LNode *pc;LNode *p;
    pa=LA->next;pb=LB->next;
    LC=LA;
    pc=LC;
    while(pa&&pb)
    {
        if(pa->data==pb->data)
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
            pb=pb->next;
        }
        else if (pa->data<pb->data)
            pa=pa->next;
        else
            pb=pb->next;
    }
    pc->next=NULL;
    LA=LC;
    delete LB;
}
 
int main()
{
	LinkList LA;LinkList LB;LinkList LC;int n;
	cout<<"请输入需要创建的A集合元素的个数："<<endl;
	cin>>n;
	cout<<"请依次输入需要存入的数据(尾插法&&递增)："<<endl;
	CreateList (LA,n);
 
 
	cout<<"请输入需要创建的B集合元素的个数："<<endl;
	cin>>n;
	cout<<"请依次输入需要存入的数据(尾插法&&递增)："<<endl;
	CreateList (LB,n);
 
 
	cout<<"集合A为：";
	display(LA);
	cout<<"集合B为：";
	display(LB);
 
	MergeList_L(LA,LB,LC);
	cout<<"二者的交集为：";
 
	display(LA);
	return 0;
}
 
