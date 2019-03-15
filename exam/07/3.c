#include <stdio.h>
#include <string.h>
#define min(x, y) (((x) < (y)) ? (x) : (y))

int editDistance(char *word1, char *word2)
{
	int len1 = strlen(word1);
	int len2 = strlen(word2);
	printf("len1 = %d; len2 = %d;\n", len1, len2);
	int dp[len1 + 1][len2 + 1];

	for(int i = 0; i <= len1; i++)
	{
		for(int j = 0; j <= len2; j++)
		{
			if(i == 0)
			{
				dp[i][j] = j;
				continue;
			}
			if(j == 0)
			{
				dp[i][j] = i;
				continue;
			}
			if(word1[i - 1] == word2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
			{
				dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
			}
		}
	}

	for(int i = 0; i <= len1; i++)
	{
		for(int j = 0; j <= len2; j++)
		{
			printf("%d  ", dp[i][j]);
		}
		printf("\n");
	}
	return dp[len1][len2];
}

int main(int argn, char *argv[])
{
	int n;
	n = editDistance(argv[1], argv[2]);

	printf("Minimal distance is %d\n", n);
	return 0;
}
