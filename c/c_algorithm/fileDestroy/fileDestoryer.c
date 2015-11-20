/*
*
*	File Destoryer
*	Copyright()2015 
*
*
*/

#include "fileDestoryer.h"

void notice(int i,char *s) {
	if(i == 1) {
		printf("\n");
	} else {
		fprintf(stderr,"Usage:%s [filename1] <filename2> ...\n",s);
	}
}


int main(int argc,char *argv[]) {
	int i,j;
	char ch;

	FILE *f;

	notice(1,argv[0]);

	if(argc <2) {
		notice(2,argv[0]);
		exit(0);
	}

	return 0;
}
