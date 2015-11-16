#include <stdio.h>

int main() {

	int m[6]={0};

	int i;
	for (i=0;i<5;i++) {
		scanf("%d",&m[i]);
	}

	int *pm = m;
	int max1,max2;

	max1 = pm[0];
	//printf("start=%p\t%c\n",pm,pm[0]);
	while(*pm) {
		//printf("%d\n",*pm);
		if((*pm > max1) && (*pm != '\0'))
			max1 = *pm;
		*pm++;
	}
	
	printf("%d\n",max1);

	pm = m;	
	//printf("%p\n",pm);
	while(*pm) {
		if(*pm == max1) {
			continue;
		} else {
			max2 = *pm;
			break;
		}
		*pm++;
	}
	
	pm = m;
	while(*pm) {
		if(*pm !=max1 && *pm > max2 && *pm !='\0') {
			max2 = *pm;
		}
		*pm++;
	}

	//printf("%p\n",pm);
	printf("%d\n",max2);

	

	return 0;
}
