#include <stdio.h>

int main() {
	int m[5];
	int i;

	for(i=0;i<5;i++){
		scanf("%d",&m[i]);
	}

	int *pm = m;

	while(*pm){
		*pm=*pm*2;
		*pm++;
	}

	for(i=0;i<5;i++) {
		printf("%d ",m[i]);
	}
	printf("\n");
}
