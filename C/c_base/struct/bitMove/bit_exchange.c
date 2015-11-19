#include <stdio.h>

int main() {

	int a = 0x12345678;

	printf("Before exchange a Bin=");
	decToBin(a,2);
	printf("\n");
	
	int x = 0x56781234;

	printf("Before exchange x Bin=");
	decToBin(x,2);
	printf("\n");
	
	return 0;
}
