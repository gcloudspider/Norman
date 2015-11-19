/*
函数指针用途:
	1.判断int类型 使用函数指针可以方便更改支持char 等其他数据类型的	 类似template
*/


#include <stdio.h>

typedef int(*COMPARE)(int,int);

int compare(int a,int b) {
	return a<b?1:0;
}


void sort(int* m,int len,COMPARE comp) {
//void sort(int* m,int len) {
	int i,j,tmp,flag;

	for(i=1;i<len;i++) {
	
		flag =0;
		for(j=0;j<len-i;j++) {
			if(compare(m[j],m[j+1])) {
				tmp = m[j];
				m[j] = m[j+1];
				m[j+1] = tmp;
				flag = 1;
			}
		}

		if(flag == 0) {
			break;
		}
		
	}
}


int main() {
	int m[] = {1,3,2,5,4,6,6};
	int i,j,k;
	int tmp;
	int flag = 0;
	for(i=0;i<7;i++) {
		printf("%d ",m[i]);
	}
	printf("\n");

	sort(m,7,compare);
	//sort(m,7);
	
	for(i=0;i<7;i++) {
		printf("%d ",m[i]);
	}

	printf("\n");

	return 0;
}
