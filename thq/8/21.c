#include <stdio.h>

void bubbleSort(int **p, int n);

int main(void){

	int a[100];
	int *b[100];
	int n, i, **p;

	printf("Input your n(n < 100)\n");
	scanf("%d", &n);
	printf("Input your a[n]\n");
	for(i = 0; i < n; i++)
		scanf("%d", a + i);
	for(i = 0; i < n; i++)
		b[i] = a + i;
	p = b;
	bubbleSort(p, n);
	for(i = 0; i < n; i++)
		printf("%d ", *b[i]);
	printf("\n");
	return 0;
}

void bubbleSort(int **p, int n){
	int i, j, flag = 1;
	int *temp;
	for(i = 0; flag; i++){
		flag = 0;
		for(j = n - 1; j > i; j--){
			flag = 1;
			if(**(p + i) > **(p + j)){
				temp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = temp;
			}
		}


	}
}
