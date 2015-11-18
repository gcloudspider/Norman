#include <stdio.h>

int main() {
	char src[1024] = "NorMan";
	char dst[1024] = ".li";

	char *pSrc = src;
	char *pDst = dst;

	printf("src=%s\n",src);
	printf("dst=%s\n",dst);
	
	printf("before Move pSrc=%p\n",pSrc);
	printf("before Move pSrc=%c\n",*pSrc);
	while(*pSrc != '\0')
		*pSrc++;
		printf("After Move pSrc=%p\n",pSrc);
		printf("After Move *pSrc=%s\n",pSrc);

	while(*pSrc++ = *pDst++)
		printf("Append Src:%p\n",pSrc);
		printf("Append pDst:%c to pSrc\n",*pDst);

	int i;
	for(i=0;i<10;i++) {
		printf("src=%c\n",src[i]);
	}
	printf("\n");
	printf(" spliced src+dst=: %s\n",src);
}
