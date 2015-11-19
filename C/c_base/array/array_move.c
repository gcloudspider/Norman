#include <stdio.h>

int main() {
	int i,j;
	int m[5]={1,0,2,0,3};
	
	for(i=0,j=0;i<5&&j<5;) {
		if(m[i]) {
			i++;
			j++;
		} else {
			j++;
		}
	}


	return 0;
}
