#include <stdio.h>

int main() {
	char src[] = "abcde";
	char dst[] = "abcde";
	
	char *pSrc = src;
	char *pDst = dst;
	
	int isEqual=1;

	while(*pSrc){
		//printf("%c\n",*pSrc);
		if(*pDst != *pSrc) {
			isEqual = 0;	
		} 
		*pDst++;
		*pSrc++;
	}

	if(!isEqual) {
		printf("src != dst\n");
	} else {
		printf("src == dst\n");
	}
	return 0;
}
