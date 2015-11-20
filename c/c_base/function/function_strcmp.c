#include <stdio.h>

int my_strcmp(const char* s1,const char* s2) {
	
	int i;
	while(!(i=*(s1++)-*(s2++))&&(*s1++) && (*s2++));

	printf("%d\n",i);
		
	return i;
}


int main() {

	char s1[] = "abcedit";
	char s2[] = "abciedit";
	
	int i;

	i = my_strcmp(s1,s2);

	if(i<0) {
		printf("s1<s2\n");
	} else if(i=0) {
		printf("s1=s2\n");
	} else if(i>0) {
		printf("s1>s2\n");
	}
	

	return 0;
}
