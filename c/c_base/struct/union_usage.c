#include <stdio.h>

unsigned long a=0x12345678;

union A {
	unsigned int a;
	char m[4];
};


int main() {
	union A k;
	k.a = 0x12345678;

	if(k.m[0] == 0x78)
		printf("little endian!\n");
	else
		printf("Big endian!\n");
	return 0;
}
