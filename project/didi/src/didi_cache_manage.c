/*########################################################
##File Name: didi_cache_manage.c
##Created Time:2015年1月3日 星期日 00时34分42秒
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
#include "../include/didi.h"

int init_user_linklist(){
    //查询所有在线的用户
    query_online_user();

    return 0;
}

int init_driver_linklist(){
    //查询所有在线的司机
    query_online_driver();
    return 0;
}

int didi_cache_init(MYSQL *db){
    //初始化普通用户
    int ret;

    zlog_info(c,"didi init cache from user!\n");
    
    ret = init_user_linklist();
    if(-1 == ret){
        zlog_info(c,"didi init user linklist failed!\n");
        return ret;
    }
    
    //初始化司机
    zlog_info(c,"didi init cache from driver!\n");
    ret = init_driver_linklist();
    if(-1 == ret){
        zlog_info(c,"didi init driver linklist failed!\n");
        return ret;
    }

    return 0;
}

int didi_cache_release(){
    zlog_info(c,"didi release cache success!\n");
}
