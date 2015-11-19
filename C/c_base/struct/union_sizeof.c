#include <stdio.h>
union a {
	int a;
	char* p;
	char b[45];
};


int main() {
	printf("%d\n",sizeof(union a));

	return 0;
}
