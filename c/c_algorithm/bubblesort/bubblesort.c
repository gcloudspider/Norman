#include <stdio.h>


void sort(int *m,int n) {
	int i,j,tmp,flag;

	for(i=1;i<n;i++) {
		flag = 0;
		for(j=0;j<n-i;j++) {
			if(m[j] < m[j+1]) {
				tmp = m[j];
				m[j] = m[j+1];
				m[j+1] = tmp;
				flag = 1;
			}
		}

		if(flag == 0) {
			break;
		}
	}
}


int main() {
	int i;
	int str[7] = {1,3,2,4,5,6,6};

	for(i=0;i<7;i++) {
		printf("%d ",str[i]);
	}
	printf("\n");

	printf("After Sort.....\n");
	
	sort(str,7);
	
	for(i=0;i<7;i++) {
		printf("%d ",str[i]);
	}
	printf("\n");

	return 0;
}
