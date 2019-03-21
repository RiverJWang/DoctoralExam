#include <stdio.h>

int main(void)
{
	int i, j, k; // i , j ,k分别是ABC, 从里面选择1 2 3,也就是XYZ对手 

	for(i = 1; i <= 3; i++){
	       if(i != 1){
		       for(j = 1; j <= 3; j++){
			       if(i != j){
				       for(k = 1; k <= 3; k++){
					       if(i != k && j != k && (k != 1 && k != 3))
						       printf("A-%d, B-%d, C-%d\n", i, j, k);
				       }
			       }
		       }
	       }
	}
	return 0;
}
