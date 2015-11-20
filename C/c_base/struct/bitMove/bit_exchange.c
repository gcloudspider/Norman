#include <stdio.h>

int main() {

	int a = 0x12345678;
	int b,c;

	printf("0x%x\n",a);
	printf("Before exchange a Bin=");
	decToBin(a,2);
	printf("\n");
	
	b=(a/16)+(a%16)*16;
	
	//c=rcol(a,4);
	//int x = 0x56781234;

	printf("After exchange a Bin=");
	decToBin(b,2);
	printf("\n");
	
	printf("0x%x\n",b);
	return 0;
}
