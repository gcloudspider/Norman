/*########################################################
##File Name: point_malloc.c
##Created Time:2015年11月22日 星期日 10时57分19秒
##Author: Norman 
##Description: 
##
##Issue: 
##
##Analyze: 
##
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>
#include<stdlib.h>

int main() {

    int *pn,*pm;
    pn = (int*) malloc(sizeof(int));
    *pn = 100;

    printf("%p\t%d\t%x\n",pn,*pn,*pn);              //堆管理器返回的地址是最低字节的地址
    printf("%p\t%d\t%x\n",pn+1,*pn+1,*pn+1);
 
    pm = malloc(sizeof(-1));
    if(pm == NULL) {
        printf("malloc error!\n");
        return -1;
    }

    char* name;                                     //name所引用的内存,实际内存还没有分配,用free就出错
    printf("Enter a name: ");
    scanf("%s",name);

    //static int *pi = malloc(sizeof(int)); 静态变量不能直接调用malloc分配内存
    //可用以下避免
    static int *pi;
    pi = malloc(sizeof(int));

    free(pn);
    free(pm);
    //free(name);

    printf("%p\t%c\n",pn,*pn);
    printf("%p\t%c\n",pm,*pm);
    
    return 0;
}
