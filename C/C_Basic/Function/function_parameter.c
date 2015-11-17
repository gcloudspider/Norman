#include <stdio.h>


int add(int a,int b) {
	return a+b;
}

int max(int a,int b) {
	return a>b?a:b;
}

int min(int a,int b) {
	return a<b?a:b;
} 

void get_max_min(int a,int b,int* get_max,int *get_min) {
	
	*get_max = a>b?a:b;
	*get_min = a<b?a:b;
}

int main() {
	int a = 10,b = 20;
	int get_max,get_min;

	printf("sum=%d\n",add(a,b));

	printf("min=%d\n",max(a,b));

	printf("min=%d\n",min(a,b));

	get_max_min(a,b,&get_max,&get_min);

	printf("max=%dmin=%d\n",get_max,get_min);

	return 0;
}
