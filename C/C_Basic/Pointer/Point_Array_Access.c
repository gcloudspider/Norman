#include <stdio.h>

int main() {

	int i,j;
	/*
	char s[][5] = {
		"123","456",
		"789"
	};

	printf("%p\n",s);
	printf("%p\n",s+1);
	printf("sizeof(s)=%d\n",sizeof(s));


	int c[] = {1,2,3,2,1,3};
	double c1[] = {1,2,3,2,1,3};
	printf("sizeof(c)=%d\n",sizeof(c));
	printf("sizeof(c)=%d\n",sizeof(c[0]));
	printf("sizeof(c)=%d\n",sizeof(c1));
	printf("sizeof(c)=%d\n",sizeof(c1[0]));

	printf("sizeof(s)=%d\n",sizeof(s));
	printf("sizeof(s[0])=%d\n",sizeof(s[0]));
*/
	int n[3][5]={
		{1,2,3},{4,5,6},
		{7,8,9}
	};
	
	printf("%p\n",n);
	printf("%p\n",n+1);
	printf("%p\n",n+2);

	for(i=0;i<3;i++) {
		for(j=0;j<5;j++) {
			printf("%d",n[i][j]);
		}
		printf("\n");
	}

	int (*ppn)[5] = n;

	printf("ppn=%p\n",ppn);
	printf("*ppn=%p\n",*ppn);
	printf("**ppn=%d\n",**ppn);

	for(i=0;i<3;i++) {
		for(j=0;j<5;j++) {
			printf("%d",ppn[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<3;i++) {
		printf("%d\n",**ppn);
		printf("%p\n",*ppn++);
	}

}
