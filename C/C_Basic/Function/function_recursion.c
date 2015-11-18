#include <stdio.h>

int get_sum(int n) {
	int sum;
	printf("%s sum=%p\n",__func__,&sum);

	if(n==1) {
		return n;
	} else {
		sum = get_sum(n-1)+n;
		return sum;
	}
}

void dec2bin(int n) {
	if(n<2) {
		printf("%d",n);
		return;
	}
	
	printf("%s n=%p\n",__func__,&n);

	dec2bin(n/2);
	printf("%d",n%2);
}


int main() {
	int n;
	scanf("%d",&n);
	printf("1+2+....+n=%d\n",get_sum(n));
	
	printf("%s n=%p\n",__func__,&n);
	dec2bin(n);
	printf("\n");
	return 0;
}
