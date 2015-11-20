#include <stdio.h>


char* my_strncat(char *dest,char* src,int len) {

	if((dest == NULL)||(src == NULL))
		return NULL;

	char* strdest = dest;
	
	while(*dest != '\0')
		*dest++;
	
	if(len >0)
		while(len--&&(*dest++=*src++));

	*dest++ = '\0';

	return strdest;

}


int main() {
	char src[] = "abcdefg";
	char dest[] = "hello";

	int len;

	scanf("%d",&len);

	printf("%s\n",my_strncat(dest,src,len));
	
	return 0;
}
