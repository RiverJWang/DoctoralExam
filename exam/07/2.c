#include <stdio.h>


void dec_to_hex(int dec, char *hex);

int main(void)
{
	int dec;
	char *hex;
	scanf("%d", &dec);

	dec_to_hex(dec, hex);

	printf("Our funciton\n");
	printf("%d --> %s\n", dec, hex);
	printf("Funciton\n");
	printf("%d --> %x\n", dec, dec);
	return 0;
}

void dec_to_hex(int dec, char *hex)
{
	int temp, i;
	char c;
	if(dec == 0)
		*hex = '0';
	else
	{
		for(i = 0; dec > 0; i++)
		{
			temp = dec % 16;
			dec = dec / 16;
			switch(temp)
			{
				case 0: *(hex + i) = '0';break;
				case 1: *(hex + i) = '1';break;
				case 2: *(hex + i) = '2';break;
				case 3: *(hex + i) = '3';break;
				case 4: *(hex + i) = '4';break;
				case 5: *(hex + i) = '5';break;
				case 6: *(hex + i) = '6';break;
				case 7: *(hex + i) = '7';break;
				case 8: *(hex + i) = '8';break;
				case 9: *(hex + i) = '9';break;
				case 10: *(hex + i) = 'A';break;
				case 11: *(hex + i) = 'B';break;
				case 12: *(hex + i) = 'C';break;
				case 13: *(hex + i) = 'D';break;
				case 14: *(hex + i) = 'E';break;
				case 15: *(hex + i) = 'F';break;

			}
		}
		*(hex + i) = '\0';
		for(int j = 0; j < i / 2 ; j++)
		{
			c = *(hex + j);
			*(hex + j) = *(hex + i - 1 - j);
			*(hex + i - 1 - j) = c;
		}
	}
}
