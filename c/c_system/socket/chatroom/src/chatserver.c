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
#include"../include/chatserver.h"

int main(int argc,char *argv[]){
    SEVCF cf;
    USERINFO uinfo;
    USERINFO *uhead=NULL;
    int ret;

    //初始化配置文件
    ret = init_conf(&cf,DEFAULT_CFGPATH);
    if(-1 == ret){
        fprintf(stderr,"load %s conf error!\n",DEFAULT_CFGPATH);
        exit(2);
    }
    
    //printf("loaded conf successfuly!\n");
    //TODO:初始化数据库
    ret = init_db(&uinfo,&uhead,cf.dbpath);
    if(-1 == ret){
        fprintf(stderr,"init db error!\n");
        exit(2);
    }
    printf("init db successfuly!\n");



    //TODO:创建SOCK服务器

    //TODO:初始化线程池

    //TODO:初始化互斥锁

}


