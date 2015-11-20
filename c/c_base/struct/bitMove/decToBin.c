#include <stdio.h>

void decToBin(int num,int base){
	int i=0;
	static int s[] = {0};
	if(num>0){
		decToBin(num/base,base);
		s[i] = num%base;
		i++;
	 }
	 printf("%d",s[0]);
}
