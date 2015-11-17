#include <stdio.h>

int my_strncmp(char* s1,char* s2,int len) {
	int i;

	if(len>0)
		while((len--)&&!(i=(*(s1++)-*(s2++))&&(*s1++)&&(s2++)));

	return i;
}


int main() {

	char s1[] = "abcdhelloclie";

	char s2[] = "abcfehiwhello";

	int len,i;

	scanf("%d",&len);

	i = my_strncmp(s1,s2,len);
	
	//printf("%d\n",i);

	if(i<0) {
		printf("s1<s2\n");
	} else if (i==0) {
		printf("s1=s2\n");
	} else if(i>0) {
		printf("s1>s2\n");
	}


	return 0;
}
