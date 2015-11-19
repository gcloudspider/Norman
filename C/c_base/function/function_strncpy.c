#include <stdio.h>


char *my_strncpy(char* dest,const char* src,int n) {
	if(src == NULL || dest == NULL)
		return NULL;
	
	char* strdest = dest;
	
	if((n >0) &&(dest != src))
		while(n-- && (*dest++=*src++));

	return strdest;
}

int main() {
	
	char src[] = "abcdefghijklmn";
	char dest[1024] = {0};
	int len = 10;
	
	printf("%s\n",my_strncpy(dest,src,len));

	return 0;
}
