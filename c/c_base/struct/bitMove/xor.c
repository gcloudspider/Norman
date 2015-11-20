#include <stdio.h>

int main() {
	unsigned a = 0x0;
	int mask = 0xff;

	printf("mask Bin=");
	decToBin(mask,2);
	printf("\n");

	a = a^mask;
	printf("a=0x%x\n",a);
	printf("Bin=");
	decToBin(a,2);
	printf("\n");

	int b=10,c=9;

	printf("b=%d,c=%d\n",b,c);
	printf("B Bin=");
	decToBin(b,2);
	printf("\n");
	printf("C Bin=");
	decToBin(c,2);
	printf("\n");

	b = b ^c;
	c= b^c;
	b = b^c;

	printf("b=%d,c=%d\n",b,c);

	printf("B Bin=");
	decToBin(b,2);
	printf("\n");
	printf("C Bin=");
	decToBin(c,2);
	printf("\n");

	return 0;
}
