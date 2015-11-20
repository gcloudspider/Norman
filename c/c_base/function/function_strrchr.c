#include <stdio.h>
#include <string.h>

char* my_strrchr(const char* s,int c) {
	
	//printf("%p\t%c\n",s,*s);

	while(*s++ !='\0');
	
	s--;
	//printf("%p\t%c\n",s,*--s);

	while(*--s) {
		if(*s == c)
			break;
	}

	return (char*) s;

}

int main() {

	char src[] = "fghjkltyuiofghjk";

	char c;

	scanf("%c",&c);

	printf("C library strrchr:%s\n",strrchr(src,c));
	
	printf("my_strrchr:%s\n",my_strrchr(src,c));
	return 0;
}
