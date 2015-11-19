#include <stdio.h>

int main() {

	int m[5] = {1,3,5,7,9};
	int n[5] = {1,3,6,7,8};

	int *pm = m;
	int *pn = n;
	int max = pm[0];

	while(*pm) {
		if(*pm == *pn) {
			if(*pm>max) {
				max = *pm;
			}
		}
		*pn++;
		*pm++;
	}

	printf("the same value=%d\n",max);
	return 0;
}
