#include <stdio.h>

int main() {
	int m[6] = {2,1,3,4,5};			//数组初始化末尾不会赋值0
	int n[6] = {5,6,7,8,9};

	int *pm = m;
	int *pn = n;
	int tmp;
	int i;

	while(*pm) {
		tmp = *pm;
		*pm = *pn;
		*pn = tmp;
		*pm++;
		*pn++;
	}

	printf("After m exchange:");
	for(i=0;i<5;i++) {
		printf("%d",m[i]);
	}
	printf("\n");

	printf("After n exchange:");
	for(i=0;i<5;i++) {
		printf("%d",n[i]);
	}
	printf("\n");
	
	return 0;
}
