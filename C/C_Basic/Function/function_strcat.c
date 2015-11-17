#include <stdio.h>

char* my_strcat(char* dest,const char* src) {
	if((dest == NULL)|| (src== NULL))
		return NULL;
	
	char *strdest = dest;
	
	while(*dest !='\0')
		*dest++;

	while(*dest++=*src++);
	
	return strdest;
}


int main() {

	char src[] = "12345664";
	char dest[] = "abcdefg";


	printf("%s\n",my_strcat(dest,src));


	return 0;
}
