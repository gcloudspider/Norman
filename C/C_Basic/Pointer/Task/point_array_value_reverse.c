#include <stdio.h>

int main() {
	int m[6] = {1,3,5,7,9};

	int *pm,*pn;
	int tmp;
	int i,j=0;
	int len = sizeof(m)/sizeof(m[0])-1;
	//printf("%d\n",len);
	
	for(i=0;i<6;i++) {
		printf("%d",m[i]);
	}
	printf("\n");

	while(j<len) {
		pm = &m[j];
		pn = &m[len];
		tmp = *pm;
		*pm = *pn;
		*pn = tmp;
		j++;
		len--;
	}

	for(i=0;i<6;i++) {
		printf("%d",m[i]);
	}
	printf("\n");
	return 0;
}
