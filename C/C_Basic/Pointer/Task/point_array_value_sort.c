#include <stdio.h>

int main() {
	int m[6] = {8,2,5,3,7};

	scanf("%d",&m[5]);

	int *pm = m;
	int i,j,tmp;
	
	for(i=1;i<6;i++) {
		for(j=0;j<6-i;j++) {
			if(*(pm+j) >(*(pm+j+1))) {
				tmp = *(pm+j);
				*(pm+j) = *(pm+j+1);
				*(pm+j+1) = tmp;
			}
		}
	}
	
	for(i=0;i<6;i++) {
		printf("%d",m[i]);
	}
	printf("\n");

	return 0;
}
