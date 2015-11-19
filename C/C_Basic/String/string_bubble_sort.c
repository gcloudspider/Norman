#include <stdio.h>

int main(){
	int strChar[] = {1,5,4,2,3,6,8,7,9};
	int i,j,k;
	int tmp;
	int isChange = 0;

	for(i=0;i<9;i++) {
		printf("%d",strChar[i]);
	}
	printf("\n");
	printf("After Convert:");
	printf("\n");
	
	for(i=1;i<9;i++) {
		for(j=0;j<9-i;j++){
			if(strChar[j] > strChar[j+1]) {
				tmp = strChar[j];
				strChar[j] = strChar[j+1];
				strChar[j+1] = tmp;
				isChange = 1;
			}
		}
		if(!isChange)
			break;
	}

	for(i=0;i<9;i++){
		printf("%d",strChar[i]);
	}
	printf("\n");
	return 0;
}
