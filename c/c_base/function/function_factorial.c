#include <stdio.h>

int get_times(int n) {
//	printf("%s\t%p\t%d\n",__func__,&n,n);
	if(n == 1) {
		return n;
	} else {
//		int(*pg)(int) = get_times;
//		printf("%p\n",pg);
	    return get_times(n-1)*n;
	}
}

int main() {
	
	int n;
	scanf("%d",&n);
	
	if(n >0)
		printf("get_times=%d\n",get_times(n));
	else
		printf("please input int!\n");
	return 0;
}
