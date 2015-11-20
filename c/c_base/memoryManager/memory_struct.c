#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	int stu_no;
	char stu_name[64];
	int stu_age;
	int stu_score;
}stu;

int main() {

	int m;
	int i;
	printf("please input student sum:");
	scanf("%d",&m);
	
	stu a; 
	
	stu *pn=malloc(m*sizeof(a));
	if(pn == NULL)
		return 0;
	
	printf("%p\n",pn);

	printf("number\tuser\tage\tsorce\n");
	for(i=0;i<m;i++) {
		scanf("%d%s%d%d",
			&pn[i].stu_no,
			pn[i].stu_name,
			&pn[i].stu_age,
			&pn[i].stu_score
		);
	}

	printf("\n");
	printf("number\tuser\tage\tsorce\n");
	for(i=0;i<m;i++) {
		printf("%d\t%s\t%d\t%d\n",
			pn[i].stu_no,
			pn[i].stu_name,
			pn[i].stu_age,
			pn[i].stu_score
		);
	}

	free(pn);

	printf("%p\n",pn);

	return 0;
}
