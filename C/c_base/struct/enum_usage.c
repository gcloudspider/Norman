#include <stdio.h>

enum color {
	red,
	yellow,
	blue,
	green
};

enum b{false,true};
typedef enum b bool;

int main() {

	enum color A;
	printf("sizeof(A)=%d\n",sizeof(A));

	A = red;
	printf("color=%d\n",A);

	return 0;
}
