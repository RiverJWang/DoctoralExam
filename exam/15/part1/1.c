#include <stdio.h>
#define product(x) ((x)*(x))
int main(void)
{
	int i =3, j, k;
	j = product(i++); // i++ = 3, i++ =4; 3 *4=12; gcc是12
	k = product(++i); // ++i = 6, ++i = 7; 42 ;gcc是49 答案不确定,和编译器有关
	printf("j = %d, k = %d\n", j, k);
	return 0;
}
