/*
明确目标:
	1.对字符串进行左移多少位
	2.对字符串进行右移多少位

分析:
	1.给出字符串指针地址起始地址
		1.1:遍历指针到\0 获取字符串长度
	2.根据缩进多少位遍历多少次
	3.获取第一个字符记录到变量
	4.遍历将后一位赋值给前一位。
	4.继续遍历后面字符将后一位赋值给前一位直到左移个数


*/


#include <stdio.h>

char* str_left_ring(char*s,int left) {
	printf("%s\n",s);
	char tmp;
	int i,j,k=0;
	char *ps,*pn;

	while(*ps !='\0'){
		k++;
		*ps++;
	}

	for(i=0;i<left;i++) {
		tmp = *s;
		pn = s;
		j=0;
		while(j<k && *pn){
			*pn = *(pn+1);
			*pn++;
			j++;
		}
		*pn = tmp;
	}

	return s;
}

char* str_right_ring(char*s ,int right) {
	printf("%s\n",s);
	char tmp;
    char *pn;
	char *ps = s;
	int i,j,k=0;

    //printf("%s\n",ps);
	while(*ps) {
		k++;
		*ps++;
	}
	*ps--;

    //printf("%s\n",ps);

	for(i=0;i<right;i++) {
        pn=ps;
		tmp = *pn;
		j=0;
		while(j<k-1 && *pn) {
			*pn = *(pn-1);
			*pn--;
			j++;
		}
		*pn = tmp;
	}

	return s;
}


int main() {
	int i;
	char s[] = "123456";
	
	for(i=0;i<sizeof(s)-1;i++) {
		printf("s[%d]=%c\n",i,*(s+i));
	}

	printf("please input ring string(left=1/right=0) and move n \n");
	int m,n;
	scanf("%d%d",&m,&n);

	if(m>1) {
		printf("error:please input 1 or 0\n");
		return -1;
	}

	if(m) {
		printf("left ring=%s\n",str_left_ring(s,n));
	} else {
		printf("right ring=%s\n",str_right_ring(s,n));
	}

	return 0;
}
