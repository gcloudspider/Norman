#include <stdio.h>

int main() {
	int max1,max2;
	int i;
	int m[5];

	for(i=0;i<5;i++) {
		scanf("%d" ,&m[i]);
	}

	for(i=0;i<5;i++) {
		printf("%d",m[i]);
	}
	printf("\n");
	
	max1 = m[0];
	for(i=0;i<5;i++) {
		if(m[i] > max1) {
			max1 = m[i];
		}
	}
	printf("Max: %d\n",max1);
	
	if(m[0] != max1) {
		max2 = m[0];
	}
	
	for(i=0;i<5;i++) {
		if(m[i] != max1 && m[i]>max2) {
			max2 = m[i];
		}
	}
	printf("%d\n",max2);

	return 0;
}
