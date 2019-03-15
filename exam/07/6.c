#include <stdio.h>

struct stack
{
	int n;
	char x, y, z;
}sta[200];



void hanoi(int n, char a, char b, char c);
void hanoiStack(int n, char fr, char to, char by);

int main(void)
{
	int n;
	printf("How many hanoi TOWERS?\n");
	
	for(int loop = 0; loop < 200; loop++)
	{
		sta[loop].n = 0;
		sta[loop].x = '0';
		sta[loop].y = '0';
		sta[loop].z = '0';
	}
	
	scanf("%d", &n);
	hanoiStack(n, 'a', 'b', 'c');
	return 0;
}
void hanoi(int n, char a, char b, char c)
{
	if(n == 1)
		printf("%c --> %c\n", a, c);
	else
	{
		hanoi(n - 1, a, c, b);
		printf("%c --> %c\n", a, c);
		hanoi(n - 1, b, a, c);
	}
}
void hanoiStack(int n, char fr, char to, char by)
{
	int top = -1, n1, a, b, c;

	top++;
	sta[top].n = n; 
	sta[top].x = fr; 
	sta[top].y = to; 
	sta[top].z = by;

	while(top > -1)
	{
		n1 = sta[top].n;
		a = sta[top].x;
		b = sta[top].y;
		c = sta[top].z;
		top--;
		
		// 下面压栈
		if(n1 > 1)
		{
			top++;
			sta[top].n = n1 - 1;
			sta[top].x = b;
			sta[top].y = a;
			sta[top].z = c;
			
			top++;
			sta[top].n = 1;
			sta[top].x = a;
			sta[top].z = c;
			
			top++;
			sta[top].n = n1 - 1;
			sta[top].x = a;
			sta[top].y = c;
			sta[top].z = b;

		}
		else
		{
			printf("\nmove from %c to %c ", a, c);
		}
	}
}
