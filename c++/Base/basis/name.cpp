#include <stdio.h>
#include <stdlib.h>

struct Person {
	char name[20];
	int old;
};

namespace ShangHai {
	Person person;
}
namespace ShenZhen {
	Person person;
}



void selectType()
{
	printf("   1.输入\n");
	printf("   2.输出\n");
	printf("   3.退出\n");
	printf("请选择: ");
}
void selectArea()
{
	system("clear");
	printf("   1.上海\n");
	printf("   2.深圳\n");
	printf("请选择: ");
}

void input(int cmd)
{
	Person temp;
	switch (cmd) {
	case 1:
		printf("姓名 : ");
		scanf("%s", temp.name);
		printf("年龄 : ");
		scanf("%d", &temp.old);
		ShangHai::person = temp;
		break;
	case 2:
		printf("姓名 : ");
		scanf("%s", temp.name);
		printf("年龄 : ");
		scanf("%d", &temp.old);
		ShenZhen::person = temp;
		break;
	}
}
void output(int cmd)
{
	switch (cmd) {
	case 1:
		printf("姓名 : %s\n", ShangHai::person.name);
		printf("年龄 : %d\n", ShangHai::person.old);
		break;
	case 2:
		printf("姓名 : %s\n", ShenZhen::person.name);
		printf("年龄 : %d\n", ShenZhen::person.old);
		break;
	}
}

int main()
{
	int cmd = 0;
	system("clear");
label:
	selectType();
	scanf("%d", &cmd);
	switch (cmd) {
	case 1:
		selectArea();
		scanf("%d", &cmd);
		input(cmd);
		goto label;
		break;
	case 2:
		selectArea();
		scanf("%d", &cmd);
		output(cmd);
		goto label;
		break;
	case 3:
		return 0;
	default:
		printf("选择错误，重新选择...\n");
		goto label;
		break;
	}
	return 1;
}
