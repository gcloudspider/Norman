/*########################################################
##File Name: fldup.c
##Created Time:2015年12月14日 星期一 10时03分04秒
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
#include "head.h"

int main(int argc ,char *argv[]){
    int fd,fd2,new_fd;
    int ret;
    if(argc< 2) return -1;

    fd = open(argv[1],O_RDWR);          
    fd2 = open("bb.txt",O_RDWR);
    if(-1 == fd){
       perror("open");
        return fd;
    }
    //new_fd=dup(fd);      //dup 复制文件描述符结构体
    //printf("fd=%d\tnew_fd=%d\n",fd,new_fd);

    //dup2(fd,STDOUT_FILENO);   //将标准输出到显示器的指向文件(相当于重定向 ehco > aa.txt)
    ret=dup2(fd,fd2);           //将新的数组元素文件描述符结构体地址指向旧的地址
    if(-1 == ret){
        perror("dup2");
        printf("fd2=%d\n",fd2);
    }
    printf("fd=%d\tfd2=%d\n",fd,fd2);

    ret = write(fd2,"0298112345",5);
    if(-1 == ret){
        perror("write");
        return ret;
    }

    close(fd);
    //close(new_fd);
    //close(STDOUT_FILENO);  //记得要关闭 (在结构体中使用引用计数器+1,所以要释放结构体为0时才销毁结构体)
    close(fd2);

    return 0;
}
