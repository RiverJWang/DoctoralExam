#include <stdio.h>
#define FLAG 1
int main(void)
{
	char ch;
	int flag;
	char a[100] = {};
	gets(a);
	printf("Original txt is 0;\nEncode txt is 1;\n");
#if FLAG
	printf("flag = 1\n");
	for(int i = 0; a[i] != 0; i++)
	{
//		printf("a[i]=%c i=%d\n", a[i], i);
		if(a[i] == 'z' || a[i] == 'Z')
			printf("%c", a[i]+1-26);
		else if(a[i] >= 'a' && a[i] < 'z' || a[i] >= 'A' && a[i] < 'Z')
			printf("%c", a[i]+1);
		else printf("%c", a[i]);
	}
#else
	puts(a);
#endif
	return 0;
}
