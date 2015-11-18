#include <stdio.h>
#include <string.h>

int main() {
	char str[8][9]={"CHINA","JAPAN","KOREA","INDIA","CANADA","AMERICAN","ENGLAND","FRANCE"};
	char temp[9];

	int i,j;
	//打印数组
	for(i=0;i<8;i++) {
		for(j=0;j<9;j++) {
			printf("%c",str[i][j]);
		}
			printf("\n");
	}

	printf("Dict for Sort:\n");

	int k,l;
	for(k=0;k<8;k++)
		for(l=k+1;l<8;l++) {
			if(strcmp(str[k],str[l])>0) {
				strcpy(temp,str[k]);
				strcpy(str[k],str[l]);
				strcpy(str[l],temp);
			}
		}
		for(i=0;i<8;i++)
			printf("%s\n",str[i]);

	return 0;
}
