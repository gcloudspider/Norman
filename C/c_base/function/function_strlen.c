#include <stdio.h>

int my_strlen(char *str) {
	int i=0;

	while(*str++)i++;

	return i;
}

int main() {

	char str[]="ahjkopqwertyuiotasdfghjklzxcvbnm";

	printf("%d\n",my_strlen(str));

	return 0;
}
