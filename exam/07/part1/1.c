#include <stdio.h>

void ins(char s[], int start, char t[])
{
	int m, n, i, k;
	n = 0; m = 0;
	for(i = 0; s[i] != '\0'; i++) m++;
	for(i = 0; t[i] != '\0'; i++) n++;
	for(k = 1; k < m - start; k++) s[m + n - k] = s[m - k];
	for(k = start; k < start + n; k++) s[k] = t[k - start];
	s[m + n] = '\0';
}

int main(void)
{
	char s[10] = "1234", t[] = "23";
	ins(s, 1, t);
	printf("%s\n%s\n", s, t);
	return 0;
}
