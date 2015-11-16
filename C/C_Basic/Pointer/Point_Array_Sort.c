#include <stdio.h>

int main() {

	char s[][10]={
		"words","books",
		"colors","students",
		"apples","car"
	};

	int i,j,k;
	char *s1,*s2;
	char tmp;
	//printf("sizeof(s)=%d\n",sizeof(s));
	//printf("sizeof(s[0])=%d\n",sizeof(s[0]));

	int len = sizeof(s)/sizeof(s[0]);

	for(i=0;i<len;i++) {
		printf("s[%d] = \"%s\"\t%p\n",i,s[i],s[i]);
	}

	printf("sorting....\n\n");

	for(i=0;i<len;i++) {
		for(j=0;j<len-i-1;j++) {
			s1=s[j];
			s2=s[j+1];
			while(*s1 && *s1==*s2) {
				*s1++;
				*s2++;
			}
			if(*s1>*s2) {
				for(k=0;k<sizeof(s[0]);k++){
					tmp=s1[k];
					s1[k]=s2[k];
					s2[k] = tmp;
				}
			}
		}
	}

	for(i=0;i<len;i++)
		printf("s[%d] = \"%s\"\t%p\n",i,s[i],s[i]);

	return 0;
}
