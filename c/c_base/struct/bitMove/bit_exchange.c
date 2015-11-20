#include <stdio.h>

int main() {

	int a = 0x12345678;
	int b,c;

	printf("0x%x\n",a);
	printf("Before exchange a Bin=");
	decToBin(a,2);
	printf("\n");
/*		
	int h16 = a& 0xffff0000;
	int l16 = a& 0x0000ffff;

	h16 = h16 >> 16;
	l16 = l16 << 16;

	a = h16 | l16;
*/
	a = a<<16 | a>>16;
	
	//c=rcol(a,4);
	//int x = 0x56781234;

	printf("After exchange a Bin=");
	decToBin(a,2);
	printf("\n");
	
	printf("0x%x\n",a);
	return 0;
}
