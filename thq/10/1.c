#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	char ch, filename[20];
	printf("Input your filename:\n");
	scanf("%s", filename);
	if((fp = fopen(filename, "wb")) == NULL)
	{
		printf("Couldnt find file.\n");
		exit(0);
	}

	ch = getchar();
	printf("Input a char to the file in disk\n");
	ch = getchar();
	while(ch != '#')
	{
		fputc(ch, fp);
		putchar(ch);
		ch = getchar();
	}

	fclose(fp);
	putchar('\n');
	return 0;
}

