#include <stdio.h>

char* my_strrev(char* str) {
	int i=1,j=0;
	char *pm,*pn;
	char tmp;
	
	char * strdest = str;

	while(*str !='\0'){
		*str++;
		j++;
	}
	printf("i=%dj=%d\n",i,j);
	

	while(i<j){
		pm = str-i;
		pn = str-j;
		tmp = *pn;
		*pn = *pm;
		*pm = tmp;
		j--;
		i++;
	}
	
	return strdest;
}


int main() {

	char str[] = "abcdefg";

	printf("%s\n",my_strrev(str));

	return 0;
}
