#include <stdio.h>

int main() {
	int m[6] = {1,3,5,7,9};

	int *pm = m;
	int tmp;
	int i;
	int len = sizeof(m)/sizeof(m[0]);
	int half = len/2;
	printf("%d\n",len);
	
	for(i=0;i<6;i++) {
		printf("%d",m[i]);
	}
	printf("\n");

	while(*pm) {
		//printf("%p\n",pm);
		len = --len-1;
		if(len == half) {
			break;
		}
		tmp = *pm;
		*pm = *(pm+len);
		*(pm+len) = tmp;
		//printf("%d\n",*(pm+len));
		*pm++;
	}

	for(i=0;i<6;i++) {
		printf("%d",m[i]);
	}
	printf("\n");
	return 0;
}
