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

void swap_mn(int *m,int *n,int len) {
	int tmp;
	int i=0;
	while(i<len) {
		tmp=*m;
		*m = *n;
		*n =tmp;
		*m++;
		*n++;
		i++;
	}
}

void printfmn(int *m,int *n,int len) {
	int i;
	printf("m=");
	for(i=0;i<len;i++) {
		printf("%d ",*m++);
	}
	printf("\n");

	printf("n=");
	for(i=0;i<len;i++) {
		printf("%d ",*n++);
	}
	printf("\n");
}


int* getmax(int a,int b) {					
	int c;
	c = a>b?a:b;
	return &c;
}

int main() {
	int a = 10,b = 20;
	int get_max,get_min;
	int m[] = {1,3,5,7,9};
	int n[] = {2,4,6,8,10};
	int len =5;

	printf("sum=%d\n",add(a,b));

	printf("min=%d\n",max(a,b));

	printf("min=%d\n",min(a,b));

	get_max_min(a,b,&get_max,&get_min);

	printf("max=%dmin=%d\n",get_max,get_min);

	printf("m=%p\tn=%p\n",&m,&n);

	printf("Before Exchange:\n");
	printfmn(m,n,len);

	swap_mn(m,n,len);
	
	printf("After Exchange:\n");
	printfmn(m,n,len);

	printf("%d\n",*getmax(a,b));

	return 0;
}
