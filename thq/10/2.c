#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp1, *fp2;
	char ch, in[20], out[20];
	printf("Input file1 name:\n");
	scanf("%s", in);
	printf("Input file2 name:\n");
	scanf("%s", out);

	if((fp1 = fopen(in, "rb")) == NULL)
	{
		printf("Couldnt open %s\n", in);
		exit(0);
	}
	
	if((fp2 = fopen(out, "wb")) == NULL)
	{
		printf("Couldnt open %s\n", in);
		exit(0);
	}

	while(!feof(fp1))
	{
		ch = fgetc(fp1);
		fputc(ch, fp2);
		putchar(ch);
	}

	putchar('\n');
	fclose(fp1);
	fclose(fp2);
	return 0;
}
