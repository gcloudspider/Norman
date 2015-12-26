/*########################################################
##File Name: chatserver.c
##Created Time:2015年12月25日 星期五 17时04分03秒
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
#include"chatserver.h"

int parser_cfg(SEV_CF *cf,const char* cpath){
    int fd,ret;
    char buf[1024];
    fd=open(cpath,O_RDONLY);
    if(-1 == fd){
        perror("open");
        return fd;
    }

    ret = read(fd,buf,1024);
    if(-1 == ret){
        perror("read");
        return ret;
    }
    
    int len = strlen(buf);
    while(len--){
    }
    printf("%s\n",buf);

}

int main(int argc,char *argv[]){
    SEV_CF cf;

    //解析配置文件
    parser_cfg(&cf,DEFAULT_CFGPATH);
    
    //TODO:加载数据库


    //TODO:创建SOCK服务器

    //TODO:初始化线程池

    //TODO:初始化互斥锁

}


