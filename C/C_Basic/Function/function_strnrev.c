#include <stdio.h>

char* my_strnrev(char *s,int n) {
	if(s== NULL)
		return NULL;
	int i=1,j=0;
	int tmp;
	char *pm,*pn;
	char* dest = s;
	printf("before rev:%s\n",s);

	while(*s != '\0') {
		*s++;
		j++;
	}

	if(n>0)
		while((i<j)&&(i!=n+1)) {
			pm = s-i;
			pn = s-j;
			tmp = *pn;
			*pn = *pm;
			*pm = tmp;
			j--;
			i++;
		}

	return dest;
}


int main() {
	char str[] = "zxcvbnm,.aiscokqwasdfghjklertyuiop[e";
	
	int len;
	scanf("%d",&len);

	printf("After rev:%s\n",my_strnrev(str,len));
	
	return 0;
}
