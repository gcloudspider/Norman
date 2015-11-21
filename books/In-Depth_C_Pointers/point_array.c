/*########################################################
##File Name: point_array.c
##Created Time:2015年11月21日 星期六 17时13分58秒
##Author: Norman 
##Description: 
##
##Issue: 
##
##Analyze: 二级指针在内存中布局
##        names[]   |
##        --------------------------
##        0xffffebf1| ----->Miller
##        0xffffebf7| ----->Jones
##        0xffffebfD| ----->Anderson
##Induction:
##
##Summary: 二级指针访问像访问二维数组一样
##
##########################################################*/

#include<stdio.h>

int main() {
    int i,j;
    //char str[] = "abcdef";
    //printf("%s\n",str);
    //printf("%d\n",sizeof(str));

    char * names[] = {"Miller","Jones","Anderson"};

    /*
    *
    * 指针数组:每个元素存放指针地址 
    * 数组指针:指向数组的指针
    * 
    * */

    //指针方式访问
    printf("Pointer Access:\n");
    for(i=0;i<3;) {
        printf("%p\t%s\n",*(names+i),*(names+i));
        j=0;
        while(*(*(names+i)+j)) {
            printf("%c\n",*(*(names+i)+j));
            //*(*(names+i)+j);
            j++;
        }
        i++;
    }
    printf("\n");
    //数组方式访问
    //
    printf("Array Access:\n");
    for(i=0;i<3;){
        printf("%p\t%s\n",names[i],names[i]);
        j=0;
        //printf("%s\n",names[i]);
        //printf("%d\n",sizeof(names[i]));      
        ////由于数组元素为指针,指针sizeof都是4个字节
        //int len = sizeof(names[i])/sizeof(names[i][j]);
        //printf("names[] length=%d\n",len);
        while(*(*(names+i)+j)) {
            printf("%c\n",names[i][j]);
            j++;
        }
        i++;
    }
    
    //printf("%c\n",*(*(names+1)+2)); //指针方式访问
    //printf("%c\n",names[1][2]);     //相当于二维数组,(逻辑)不是真正二维数组

}
