#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *fp;
	char str[3][10], temp[10];
	int i, j, minj, n = 3;
	printf("Enter 3 strings\n");
	for(i = 0; i < n; i++)
		gets(str[i]);

	//selectionSort
	for(i = 0; i < n - 1; i++)
	{
		minj = i;
		for(j = i + 1; j < n; j++)
		{
			if(strcmp(str[j], str[minj]) < 0)
				minj = j;
		}
		strcpy(temp, str[i]);
		strcpy(str[i], str[minj]);
		strcpy(str[minj], temp);
	}

	//read into file
	if((fp = fopen("string.dat", "w")) == NULL)
	{
		printf("Couldnt open!\n");
		exit(0);
	}
	printf("New sequence!\n");
	for(i = 0; i < n; i++)
	{
		fputs(str[i], fp);
		fputs("\n", fp);
		printf("%s\n", str[i]);
	}

	return 0;
}
