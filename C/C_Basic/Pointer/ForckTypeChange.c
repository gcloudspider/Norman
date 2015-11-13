#include<stdio.h>

int main() {
	
	int a = 20;
	int b = 10;
	int *p = &a;
	int *q = &b;
	printf("a=%d",*p);
	printf("b=%d",*q);
	printf("\n");
	int *c = p;
	p = &b;
	q = &a;

	printf("a=%d",*p);
	printf("b=%d",*q);
	printf("\n");

	int m = 0x424341;
	int *pm = &m;

	printf("'%c'\n",*(char*)&m);

	printf("'%c'\n",*(char*)pm);

	printf("'%c'\n",*(char*)pm+1);

	int n[] = {3,2,1,4,5};
	printf("%d\n",*n);
	int i;
	int *pn = n;
	for(i=0;i<5;i++) {
		printf("%d\n",*pn++);
	}
}
