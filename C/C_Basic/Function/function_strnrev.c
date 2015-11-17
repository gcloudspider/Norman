#include <stdio.h>

char* strnrev(char *s,int n) {
	if(s== NULL)
		return NULL;
	int i=1,j=0;
	int tmp;
	int *pm,pn;
	char* dest = s;

	while(*s != '\0')
		*s++;
		j++;

	if(n>0)
		while((i<j) &&(i != n)) {
			pm = s-i;
			pn = s-j;
			
		}

	return dest;
}


int main() {
	char str[] = "aiscoke";
	
	int len;
	scanf("%d",&len);

	printf("%s\n",my_strnrev(str,len));
	
	return 0;
}
