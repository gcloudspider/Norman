#include <stdio.h>

int main() {
	char str[] = "abcdefghijklmn";

	char* tmp = str;
	char* tmp1 = str;
	char* tmp2 = str;
	int n=0,m=0,u=0;
	int i;

	while(*tmp++)		//方法1:效率高
		n++;

	printf("str lenght=%d\n",n);

	for(i=0;*(tmp1+i) != '\0';i++)	//方法2:
		m++;

	printf("str lenght=%d\n",m);
	
	while(*tmp2) {					//方法3
		u++;
		*tmp2++;
	}	

	printf("str lenght=%d\n",u);

	return 0;
}
