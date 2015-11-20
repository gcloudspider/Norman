#include <stdio.h>

#define C_MASK(n) (~(1<<5))			//位5清零后取反
#define S_MASK(n) ((1<<n))			//位n 清零
#define SET_N(d,n)(d=d|(1<<n))

int main() {
	
	unsigned a;
	char s[10];

	scanf("%d",&a);

	printf("%d Hex=0x%x\t\n",a,a);

	printf("Bin=");
	decToBin(a,2);
	printf("\n");
	//a = a&(~(1<<5));
	
	a=a&C_MASK(5);		//位5清零

	printf("%d Hex=0x%x\n",a,a);
	printf("Bin=");
	decToBin(a,2);
	printf("\n");


	SET_N(a,6);

	printf("a=0x%x\n",a);
	printf("Bin=");
	decToBin(a,2);
	printf("\n");

	return 0;
}
