#include <stdio.h>

int main() {
	char src[] = "abcdw";
	char dst[] = "abcdw";
	
	char *pSrc = src;
	char *pDst = dst;
	
	int isEqual=1;
	/*
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
	}*/

	while(*pSrc++ && *pDst++) {
		if(*pDst != *pSrc){
			isEqual = 0;
			printf("src=%c\tdst=%c\n",*pSrc,*pDst);
		}
		//printf("src=%c\tdst=%c\n",*pSrc,*pDst);
	}

	if(!isEqual) {
		printf("src != dst\n");
	} else {
		printf("src == dst\n");
	}

	return 0;
}
