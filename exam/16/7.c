// 小括号：　Parentheses; 中括号：　Brackets; 大括号：　Braces; 
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define ERRO -1
#define TRUE 1
#define FALSE 0

typedef struct
{
	char data[MAX];
	int top;
}Stack;

void push(Stack *s, char item)
{
	if(s->top < MAX-1)
	{
		s->data[(s->top)+1] = item;
		s->top++;
	}
}

char pop(Stack *s)
{
	char* n = NULL;
	if(s->top != -1)
	{
		*n = s->data[(s->top--)];
	}
	return *n;
}

char peek(Stack *s)
{
	char *n = NULL;
	if(s->top != -1)
		*n = s->data[(s->top)];
	return *n;
}

int isempty(Stack *s)
{
	int flag = FALSE;
	if(s->top == -1)
	{
		flag = TRUE;
	}
	return flag;
}

int isfull(Stack *s)
{
	int flag = FALSE;
	if(s->top == MAX-1)
		flag = TRUE;
	return flag;
}


int match(char *filename)
{
	Stack a, *s = a;
	FILE *fp;
	char ch;

	if((fp = fopen(filename, "r")) == NULL)
	{
		printf("file cannot open\n");
		exit(0);
	}

	ch = fgetc(fp);
	while(!feof(fp))
	{
		switch(ch)
		{
			case '{':
			case '[':
			case '(':
				push(s, ch);
				break;
			case '}':
				if(peek(s) == '{')
					pop(s);
				else
					return 0;
				break;
			case ']':
				if(peek(s) == ']')
					pop(s);
				else
					return 0;
				break;
			case ')':
				if(peek(s) == ')')
					pop(s);
				else
					return 0;
				break;

		}

		ch = getc(fp);
	}
	if(isempty(s))
		return 1;
	else 
		return 0;
}

int main(void)
{
	printf("%d\n", match("7"));
	return 0;
}
