#include <stdio.h>
int main(int argc,char *argv[])
{
	FILE *fi, *fo; char *cp; int c;
	if((cp = argv[1]) && *cp != '\0') 
	{ 
		// 命令行下输入的加密依据
		if((fi = fopen(argv[2], "rb")) != NULL)
		{
			//打开原文件
			if((fo=fopen(argv[3],"wb"))!= NULL)
			{
				//打开目标文件
				while((c = getc(fi)) != EOF) //读取二进制字符
				{
					if(!*cp) cp=argv[1]; //加密依据字符为‘\0’时，重回所输
					c^=*(cp++); //字符转密文，与取异或运算，同时改变加密依据
					putc(c,fo); //密文存入目标文件
				}
				fclose(fo);
			}
			fclose(fi);
		}
	}
	return 0;
} 
