#include <stdio.h>

int main() {

	int m[6]={0};
	int i;
	int sum=0;
	for(i=0;i<5;i++) {
		scanf("%d",&m[i]);
	}

	int *pm = m;

	while(*pm) {
		if(*pm%2 ==0) {
			*pm++;
			continue;
		} else {
			sum+=*pm;
		} 
		*pm++;
	}

	printf("%d\n",sum);
	
	return 0;
}
