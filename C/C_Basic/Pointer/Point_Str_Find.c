#include <stdio.h>

int main() {
	char src[] = "abcwiqcldilsisoslsosos";
	char findstr[] = "sos";

	char *pSrc = src;
	char *pFindstr = findstr;
	int isSubStr=0;
	
	while(*pSrc){
		printf("%c\n",*pSrc);
		if(*pFindstr==*pSrc){
			*pFindstr++;
			if(*pFindstr == '\0') {
				isSubStr = 1;
			}
		}
		*pSrc++;
	}
	
	if(isSubStr) {
		printf("Sub str:%s in Src:%s\n",findstr,src);
	} else {
		printf("Sub str:%s not in Src:%s\n",findstr,src);
	}



	return 0;
}
