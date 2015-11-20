#include <stdio.h>

char* my_strcpy(char* dst, const char* src) {
	if(dst ==NULL || src==NULL) {
		return NULL;
	}

	char * strdest = dst;
	if(dst != src)
		while(*dst++=*src++);

	return strdest;

}


int main() {
	char src[] = "abcdefg";
	char dst[1024]={0};
	printf("%s\n",my_strcpy(dst,src));

	printf("printf end\n");
	return 0;
}
