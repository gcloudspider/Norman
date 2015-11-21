#include <stdio.h>

int main() {
	int i,j;
	int m[5]={1,0,2,0,3};
	
	for(i=0,j=0;i<5&&j<5;) {
		if(m[j]) {              //判断是否为0
            m[i] = m[j];
			i++;
			j++;
		} else {
			j++;
		}
	}
    for(i;i<5;i++)              //此时i位于m[3]
        m[i] = 0;

    for(i=0;i<5;i++) {
        printf("%d",m[i]);
    }
    printf("\n");

	return 0;
}
