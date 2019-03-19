#include <stdio.h>
#include <string.h>

void getSubString(char *str1, char *str2);

int main(void)
{
	char str1[100], str2[100];
	gets(str1);
	gets(str2);

	getSubString(str1, str2);
	return 0;
}

void getSubString(char *str1, char *str2)
{
	int index = 0;
	int maxlen = 0, len1 = strlen(str1), len2 = strlen(str2);
	int i, j, k = 0;

	for(i = 0; i < len1; i++)
	{
		for(j = 0; j < len2; j++)
		{
			if(str1[i] == str2[j])
			{
				for(k = 1; str1[i + k] == str2[j + k] && str1[i+k] != '\0' && str2[j+k] != '\0'; k++);
			}
			if(k > maxlen)
			{
				maxlen = k;
				index = i;
			}
		}
	}
	

	if(maxlen > 0)
	{
		printf("maxlen = %d\n", maxlen);
		printf("index = %d\n", index);
		for(i = index; i <= index + maxlen; i++)
			printf("%c ", str1[i]);
	}

}








/*
 * #import <Foundation/Foundation.h>
**
 找出 两个 字符串 的 最长 公共 子串 (穷举法)
 @param str1 字符串1
 @param str2 字符串2

void maxPublicSubStringOne(char *str1, char *str2) {
    assert(str1 != NULL && str2 != NULL);

    // 起始 位置
    int startPosition = 0;
    // 公共 子串 长度
    int maxStringLength = 0;

    // 循环 遍历 所有 子字符串
    for (int i = 0; i < strlen(str1); i ++) {
        for (int j = 0; j < strlen(str2); j++) {
            // 如果 两个 字符 相等
            if(str1[i] == str2[j]) {
                // 继续 比较 后面的字符
                int k = 1;
                while (str1[i + k] == str2[j + k] && str1[i + k] != '\0' && str2[j + k] != '\0') {
                    k ++;
                }
                // 如果 k 大于 最长 字符串
                if (k > maxStringLength) {
                    // 公共 子串 长度
                    maxStringLength = k;
                    // 起始位置
                    startPosition = i;
                }
            }
        }
    }

    if(maxStringLength > 0) {
        for (int i = startPosition; i <= maxStringLength; i++) {
            printf("%c ", str1[i]);
        }
    }
}
*/


