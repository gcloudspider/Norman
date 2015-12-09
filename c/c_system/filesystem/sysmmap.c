/*########################################################
##File Name: sysmmap.c
##Created Time:2015年12月09日 星期三 12时31分45秒
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
#include"head.h"

int main(){
    char *p;
    int fd;

    fd = open("a.txt",O_RDWR);
    p = mmap(NULL,10,PROT_WRITE,MAP_SHARED,fd,0);
    close(fd);

    strcpy(p,"aaaaaaa");
    munmap(p,10);
    
    return 0;
}
