#include <stdio.h>

/*

*/

int main(){
	char tmpChar[] = "-123";
	int m = 0;
	int i = 0;
	int isNegative = 0;		//标记是否为负数

	if(tmpChar[i] == '-') {
		isNegative = 1;
		i++;
	}else {
		if(tmpChar[i]<'0' || tmpChar[i] > '9') {
			printf("format error!\n");
			return -1;
		}	
	}

	for(;tmpChar[i];i++) {
		if(tmpChar[i] >= '0' && tmpChar[i] <= '9') {
			m = m*10+tmpChar[i] -'0';
		}else {
			break;
		}
	}

	if(isNegative)
		m = -m;

	printf("m=%d\n",m);
	return 0;
}
