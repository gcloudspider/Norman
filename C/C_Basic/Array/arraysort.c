#include <stdio.h>

int main() {
	int i,j;
	int m[7] = {2,1,4,2,6,7};
	int tmp;

	scanf("%d",&m[6]);

	for(i=0;i<7;i++) {
		printf("%d",m[i]);
	}
	printf("\n");

	for(i=0;i<7;i++) {
		for(j=0;j<7-i;j++) {
			if(m[j]>m[j+1]) {
				tmp = m[j];
				m[j] = m[j+1];
				m[j+1] = tmp;
			}
		}
	}


	for(i=0;i<7;i++) {
		printf("%d",m[i]);
	}
	printf("\n");
	return 0;
}
