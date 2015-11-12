#include<stdio.h>

int main()	{
	int m[5] = {0};
	int i;
	for(i=0;i<5;i++) {
		m[i] = i*2;	
	}

	for(i=0;i<5;i++) {
		printf("%d",m[i]);
	}
	printf("\n");
	return 0;
}
