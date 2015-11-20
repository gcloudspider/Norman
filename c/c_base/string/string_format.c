#include <stdio.h>

int main (){
	char s[] = "12k3";
	int m=0;
	int sum = 0;

	int i=0;

	while(s[i]) {
		if(s[i]<'0'||s[i]>'9')
			break;
		//printf("s[%d]=%d\n",i,s[i]);
		sum = sum*10+s[i] -'0';
		//printf("sum=%d\n",sum);
		i++;
	}
	m = sum;
	printf("m=%d\n",m);

	return 0;
}
