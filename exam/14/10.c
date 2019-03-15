#include <stdio.h>

void lier(void)
{
	int a, b, c, d, e;
	int flag1 = 0, flag2=0, flag3=0, flag4=0, flag5=0; // a == 0表示说的没有发生，a==1表示说的发生了；0表示黑纸，1表示白纸

	for(a = 0; a <= 1; a++){
		for(b = 0; b <= 1; b++){
			for(c = 0; c <= 1; c++){
				for(d = 0; d <= 1; d++){
					for(e = 0; e <= 1; e++){
						if((a == 1 && (b+c+d+e) == 3) || (a != 1 && (b+c+d+e) != 3)) //a说实话或者谎话
							flag1 = 1;
						if((b == 1 && (a+c+d+e) == 0) || (b != 1 && (a+c+d+e) != 0))
							flag2 = 1;
						if((c == 1 && (a+b+d+e) == 1) || (c != 1 && (a+b+d+e) != 1))
							flag3 = 1;
						if((d == 1 && (a+b+c+e) == 4) || (d != 1 && (a+b+c+e) != 4))
							flag4 = 1;
				//		if(c == ((a+b+d+e)==1) )  // 对判断语句的优化，说谎和不说谎都是这种情况
				//			flag3 = 1;
				//		if(d == ((a+b+c+e)==4))
				//			flag4 = 1;
						if(flag1 && flag2 && flag3 && flag4)
							printf("%d %d %d %d %d\n", a, b, c, d, e);
						flag1 = 0;
						flag2 = 0;
						flag3 = 0;
						flag4 = 0;

					}
				}
			}
		}
	}
}

int main(void)
{
	lier();
	return 0;
}
