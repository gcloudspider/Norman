#include <stdio.h>
#include <string.h>

char* my_strchr(const char *s, int c) {
	if(s == NULL)
		return NULL;

	while(*s) {
		if(*s == c)
			break;
		*s++;
	}

	return (char*)s;
}


int main() {
	char src[] = "hjkljjk";
	char c;

	scanf("%c",&c);

	char* tmp = strchr(src,c);
	printf("C Library strchr=%s\n",tmp);

	printf(" my_strchr=%s\n",my_strchr(src,c));
	

	return 0;
}
