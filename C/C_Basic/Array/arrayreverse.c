#include <stdio.h>

int main() {
	int m[5] = {1,2,4,5,8};
	int i,tmp;
	int sum = sizeof(m)/sizeof(m[0]);

	printf("%d",sum);

	int left=0,right=sum-1;

	while(left<right) {
		tmp = m[left];
		m[left] = m[right];
		m[right] = tmp;
		left ++;
		right --;
	}

	for(i=0;i<5;i++) {
		printf("%d",m[i]);
	}
	printf("\n");

	return 0;
}
