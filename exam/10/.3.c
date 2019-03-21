
//head.h
#ifndef _HEAD_H   
#define _HEAD_H  

#include <string.h>
struct LNode_Name
{
public:
    char* name;	
    LNode_Name* name_next;
};

struct LNode_Year
{
public:
    int year;
	LNode_Name* name_next;
    LNode_Year* year_next;
};


class CLinkList
{
private:
	LNode_Year* head;
	LNode_Year* last;
	LNode_Year* cur;	
public:
	CLinkList();
	~CLinkList();
	void Insert(char* name,int year);
	void Display();
	void Sort(LNode_Year* lnode_year);
	void Sort(LNode_Name* lnode_name);
	void DeleteAll();
	int  GetSize(LNode_Year* lnode_year);
	int  GetSize(LNode_Name* lnode_name);
	int  GetSize();
    int  GetItem(int row,int line,char* str,int& year);
};


CLinkList::CLinkList()
{
	head=cur=last=NULL;
}

CLinkList::~CLinkList()
{
	while(head!=NULL)
	{
		cur=head->year_next;
		LNode_Name* name_temp=head->name_next;
		while(name_temp!=NULL)
		{
			LNode_Name* temp = name_temp->name_next;
			delete name_temp->name;
			delete name_temp;
			name_temp=temp;
		}
		delete head;
		head=cur;
	}
}

void CLinkList::Insert(char* name,int year)
{
	if(head==NULL)
	{
		head = new LNode_Year;	
		head->year =year;
		head->name_next = new LNode_Name;		
		head->name_next->name = new char[100];
		memset(head->name_next->name,0,100);
		strcpy(head->name_next->name ,name);
		head->name_next->name_next=NULL;
		head->year_next = NULL;
		return ;
	}
	cur =head;
	while(cur->year!=year&&cur->year_next!=NULL)
	{
		cur = cur->year_next;
	}
	if(cur->year==year)
	{
		LNode_Name* temp = new LNode_Name;
		temp->name = new char[100];
		memset(temp->name,0,100);
		strcpy(temp->name ,name);
		temp->name_next = cur->name_next;
		cur->name_next=temp;
		Sort(cur->name_next);
		return;
	}
	else
	{
		cur->year_next = new LNode_Year;
		cur->year_next->year =year;
		cur->year_next->name_next = new LNode_Name;
		cur->year_next->name_next->name = new char[100];
		memset(cur->year_next->name_next->name,0,100);
		strcpy(cur->year_next->name_next->name,name);
		cur->year_next->name_next->name_next=NULL;
		cur->year_next->year_next = NULL;
		Sort(head);
		return ;
	}	
}

void CLinkList::Display()
{	
	int count = 0;
	if(head==NULL)
	{
		printf("Error: No Items\n");
		return ;
	}
	cur =head;
	while(cur!=NULL)
	{				
		printf("[%d]:%d ",count,cur->year);
		LNode_Name* temp = cur->name_next;
		while(temp!=NULL)
		{
			printf("%s ",temp->name);
			temp= temp->name_next;
		}
		printf("\n");
		count++;
		cur = cur->year_next;		
	}
}

void CLinkList::DeleteAll()
{
	while(head!=NULL)
	{
		cur=head->year_next;
		LNode_Name* name_temp=head->name_next;
		while(name_temp!=NULL)
		{
			LNode_Name* temp = name_temp->name_next;
			delete name_temp->name;
			delete name_temp;
			name_temp=temp;
		}
		delete head;
		head=cur;
	}
	return;
}

int CLinkList::GetSize(LNode_Year* lnode_year)
{
	int index=0;
	LNode_Year* cur_year=lnode_year;
	while(cur_year){
		cur_year=cur_year->year_next;
		index++;
	}
	return index;	
}

int CLinkList::GetSize(LNode_Name* lnode_name)
{
	int index=0;
	LNode_Name* cur_name=lnode_name;
	while(cur_name){
		cur_name=cur_name->name_next;
		index++;
	}
	return index;	
}

int CLinkList::GetSize()
{
	int index=0;
	LNode_Year* cur_year=head;
	while(cur_year){
		cur_year=cur_year->year_next;
		index++;
	}
	return index;	
}
void CLinkList::Sort(LNode_Year* lnode_year)
{	
	int length=GetSize(lnode_year);
	for(int i=0;i<length;i++)
	{
		LNode_Year* cur_year = lnode_year;
		for(int j=0;j<length;j++)
		{
			if(cur_year->year_next!=NULL)
			{
				int temp = cur_year->year;
				LNode_Name* name_temp=cur_year->name_next;
				if(temp > cur->year_next->year)
				{
					//year exchange
					cur_year->year=cur_year->year_next->year;
					cur_year->year_next->year=temp;
					
					//name exchange
					cur_year->name_next = cur_year->year_next->name_next;
					cur_year->year_next->name_next = name_temp;
				}
			}
			cur_year=cur_year->year_next;
		}
	}	
}
void CLinkList::Sort(LNode_Name* lnode_name)
{	
	int length=GetSize(lnode_name);
	for(int i=0;i<length;i++)
	{
		LNode_Name* cur_name = lnode_name;
		for(int j=0;j<length;j++)
		{
			if(cur_name->name_next!=NULL)
			{
				char* temp = cur_name->name;
				if(strcmp(temp,cur_name->name_next->name)==1)
				{
					//name exchange
					cur_name->name=cur_name->name_next->name;
					cur_name->name_next->name=temp;
				}
			}
			cur_name=cur_name->name_next;
		}
	}	
}

int CLinkList::GetItem(int row,int line,char* str,int& year)
{
	if(row <0||line<0)
	{
		return NULL;
	}

	if(row>=GetSize())
	{
		return NULL;
	}

	cur =head;
	int cur_row = 0 ;
	while(cur_row!=row)
	{
		cur = cur->year_next;
		cur_row++;
	}
	
	if(line>=GetSize(cur->name_next))
	{
		return NULL;
	}
	year = cur->year;
	LNode_Name* cur_name=cur->name_next;
	int cur_line=0;
	while(cur_name!=NULL)
	{
		if(cur_line==line)
		{
			strcpy(str,cur_name->name);
			break;
		}
		cur_line++;
		cur_name = cur_name->name_next;
	}
	return 1;//OK
}
#endif  


