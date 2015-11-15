#include <stdio.h>

int main() {
	char src[1024] = "asewcwerdsf";
	char dst[1024] = {0};

	char* pSrc = src;
	char* pDst = dst;

	printf("%p\n",pSrc);
	printf("%p\n",src);
	printf("%p\n",pDst);
	printf("%p\n",dst);
	
	//while(*pDst++=*pSrc++);
	
	while(*pSrc){
		*pDst=*pSrc;
		*pSrc++;	
		*pDst++;
	}


	printf("%p\n",pSrc);
	printf("%p\n",src);
	printf("%p\n",pDst);
	printf("%p\n",dst);
	
	printf("%s\n",dst);				//由于pDst移动到最后了所以用dst
	return 0;
}
