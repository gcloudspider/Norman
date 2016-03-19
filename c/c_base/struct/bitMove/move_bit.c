#include <stdio.h>

int main() {
	int a = 18273;

	printf("A before << 8 Bin=");
	decToBin(a,2);
	printf("\n");

	a = a<<8;

	printf("a=0x%x\n",a);

	printf("A after << 8 Bin=");
	decToBin(a,2);
	printf("\n");

	int b = 18273;

	printf("b Before >> 8 Bin=");
	decToBin(a,2);
	printf("\n");

	b = b >>8;

	printf("b=0x%04x\n",b);

	printf("B After >> 8 Bin=");
	decToBin(b,2);
    printf("\n");
    char buf = 'a';
    printf("%c\n",buf+1);
	printf("\n");
}
