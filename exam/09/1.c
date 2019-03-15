#include <stdio.h>

int binarySearch(int a[], int low, int high, int n);

int main()
{
	int a[] = {1, 3, 5, 6, 7, 8, 9, 34, 235, 555};
	int key = 555, low = 0, high = 9;
	int r;
	r = binarySearch(a, low, high, key);
	printf("%d\n", r);
	return 0;
}

int binarySearch(int a[], int low, int high, int key)
{
	int mid = (low + high) / 2;
	if(low > high)
		printf("error\n");
	if(key == a[mid])
		return a[mid];
	else if(key < a[mid])
		return (a, low, mid - 1, key);
	else
		return (a, mid + 1, high, key);
}

