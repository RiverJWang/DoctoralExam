#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp1, *fp2;
	char buff[1024];
	int line = 0;
	if((fp1 = fopen("from.txt", "r")) == NULL)
	{
		printf("Cannot open this file\n");
		exit(0);
	}
	if((fp2 = fopen("to.txt", "w")) == NULL)
	{
		printf("Cannot open this file\n");
		exit(0);
	}

	while(fgets(buff, 1024, fp1) > 0)
	{
		fprintf(fp2, "The %dst line:%s", line++, buff);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
