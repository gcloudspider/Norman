#include <stdio.h>

int main() {
	int m[10] = {1,2,5,3,7};

	scanf("%d",&m[5]);

	int *pm = m;
	int i,tmp;

	while(*pm) {
		if(*pm >*(pm+1)){
			tmp = *pm;
			*pm = *(pm+1);
			*(pm+1) = tmp;
		}
		*pm ++;
	}

	for(i=0;i<6;i++) {
		printf("%d",m[i]);
	}
	printf("\n");

	return 0;
}
