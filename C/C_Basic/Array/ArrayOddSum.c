#include <stdio.h>

int main() {
	int i;
	int m[5];
	int sum = 0;

	for(i=0;i<5;i++) {
		scanf("%d",&m[i]);
	}

	for(i=0;i<5;i++) {
		if(m[i]%2==0){
			continue;		
		} else {
			sum+=m[i];
		}
	}
	
	printf("%d\n",sum);



	return 0;
}
