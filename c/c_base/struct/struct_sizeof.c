#include <stdio.h>

struct A {
	int a;
};

struct B {
	char a;
};

struct C {
	char a[3];
};

struct D {
	char *p;
};

struct E {
	char a;
	int m;
};

struct F {
	short a;
};

struct G {
	double a;
};

struct H {
	char a;
	double m;
};

struct I {
	char a;
	int b;
	double c;
	char d[5];
};

struct J {
	char* a;
	char **pp;
	char d[5];
};

struct K {};

int main() {
	printf("sizeof(struct A)=%d\n",sizeof(struct A));
	printf("sizeof(struct B)=%d\n",sizeof(struct B));
	printf("sizeof(struct C)=%d\n",sizeof(struct C));
	printf("sizeof(struct D)=%d\n",sizeof(struct D));
	printf("sizeof(struct E)=%d\n",sizeof(struct E));
	printf("sizeof(struct F)=%d\n",sizeof(struct F));
	printf("sizeof(struct G)=%d\n",sizeof(struct G));
	printf("sizeof(struct H)=%d\n",sizeof(struct H));
	printf("sizeof(struct I)=%d\n",sizeof(struct I));
	printf("sizeof(struct J)=%d\n",sizeof(struct J));
	printf("sizeof(struct K)=%d\n",sizeof(struct K));

	return 0;
}
