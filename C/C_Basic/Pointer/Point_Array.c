#include <stdio.h>

int main() {
	int i;
	char * ps[3];
	printf("%p\n",ps);
	
	char* p1 = "123";
	char* p2 = "456";
	char* p3 = "789";

	printf("%p\t%s\n",p1,p1);
	printf("%p\t%s\n",p2,p2);
	printf("%p\t%s\n",p3,p3);

	ps[0] = p1;
	ps[1] = p2;
	ps[2] = p3;

	printf("%p\t%s\n",ps[0],ps[0]);
	printf("%p\t%s\n",ps[1],ps[1]);
	printf("%p\t%s\n",ps[2],ps[2]);

	for(i=0;i<3;i++) {
		printf("%s\n",ps[i]);
	}

	char* pd[3] = {
		"abc","def",
		"ghi"
	};

	printf("%p\n",pd);
	
	for(i=0;i<3;i++) {
		printf("%s\n",pd[i]);
	}
	
	printf("%p\n",pd+1);

	return 0;
}
