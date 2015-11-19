#include <stdio.h>

typedef struct student {
	int stu_no;
	int stu_age;
	char* stu_name;
	int stu_score;
}STU;

typedef struct school {
	STU sa[100];
}SCH;

int main() {
	int i;
	int len = 7;

	STU s[] = {
		{1000,20,"norman",100},
		{1001,20,"evely",100},
		{1002,18,"cell",99},
		{1003,19,"cell390",100},
		{1004,23,"lisi",89},
		{1005,22,"wan",98},
		{1006,25,"zhang",95}
		};

	STU* ps = s;
	
	printf("point struct=%d\n",ps->stu_no);
	printf("point struct=%d\n",(*ps).stu_no);

	printf("no\tage\tname\tscore\n");
	
	for(i=0;i<len;i++) { 
		printf("normal=%d\t%d\t%s\t%d\n",s[i].stu_no,s[i].stu_age,
			s[i].stu_name,s[i].stu_score);
	}

	for(i=0;i<len;i++) { 
		printf("point=%d\t%d\t%s\t%d\n",(ps+i)->stu_no,(ps+i)->stu_age,
			(ps+i)->stu_name,(ps+i)->stu_score);
	}

	return 0;

}
