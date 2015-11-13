#include <stdio.h>


int main() {
	int m[5];
	int n[5];
	int i,j;
	int max=0;

	for(i=0;i<5;i++) {
		scanf("%d",&m[i]);
	}

	for(i=0;i<5;i++) {
		scanf("%d",&n[i]);
	}

	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			if(m[i] == n[j]&&m[i]>max) {
				max = m[i];
			}
		}
	}

	printf("%d\n",max);

	return 0;
}
