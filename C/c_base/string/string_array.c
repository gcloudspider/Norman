#include <stdio.h>

int main() {
	char buff[1024] = {0};
	
	//printf("before buff=%s\n",buff);

	int i=0;

	//while((buff[i++] = getchar()) !='\n');
	//buff[i-1] = 0;

	for(;i<20;) {
		buff[i] = getchar();		//getchar 
		printf("%c",buff[i]);
		if(buff[i] == '\n') {
			break;
		} 
		i++;
	}
	buff[i-1] = '0';
	printf("\n");

	printf("After buff=%s\n",buff);

	return 0;
}
