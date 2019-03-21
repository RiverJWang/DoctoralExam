#include <stdio.h>
#include <stdlib.h>

void mergeDoc(char *fp1, char *fp2);

int main(void)
{
	mergeDoc("A", "B");
	return 0;
}

void mergeDoc(char *f1, char *f2)
{
	FILE *fp1, *fp2, *fp3;
	char cha, chb, temp, *s, a[1024];
	int len = 0, minj;
	s = a;
	if((fp1 = fopen(f1, "r")) == NULL)
	{
		printf("f1 cannot open\n");
		exit(0);
	}
	if((fp2 = fopen(f2, "r")) == NULL)
	{
		printf("f2 cannot open\n");
		exit(0);
	}
	if((fp3 = fopen("C", "w")) == NULL)
	{
		printf("f3 cannot open\n");
		exit(0);
	}
	
	cha = fgetc(fp1); // read file a to string *s
	while(!feof(fp1))
	{
		*(s + len) = cha;
		len++;
		printf("fp1 %s\n", s);
		cha = fgetc(fp1);
	}
	chb = fgetc(fp2); // b to *s
	while(!feof(fp2))
	{
		*(s + len) = chb;
		len++;
		printf("fp2 %s\n", s);
		chb = fgetc(fp2);
	}
	*(s + len) = '\0';

	for(int i = 0; i < len; i++) //selection sort
	{
		minj = i;	
		for(int j = i; j < len; j++)
		{
			if(*(s+j) < *(s+minj))
				minj = j;
		}
		temp = *(s+minj);
		*(s+minj) = *(s+i);
		*(s+i) = temp;
	}
	
	printf("after sorted %s\n", s);
	for(int i = 0; i < len; i++) // write to c
		fputc(*(s+i), fp3);
	
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}
