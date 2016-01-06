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



void didi_adduser_cache(int cfd,int usertype,const char* telphone){
    didi_online_t *online_user;

    online_user = malloc(sizeof(didi_online_t));
    online_user->fd = cfd;
    strcpy(online_user->telphone,telphone);
    switch(usertype){
        case PERSONAL_USER: {
                zlog_info(c,"online user=%p personal user head=%p tail=%p",online_user,didi_user_head,didi_user_tail);
                if(didi_user_head){
                    online_user->next = NULL;
                    online_user->pre = didi_user_tail;
                    didi_user_tail->next = online_user;
                } else {
                    online_user->next = didi_user_head;
                    online_user->pre = didi_user_head;
                    didi_user_head = online_user;
                }
                didi_user_tail = online_user;
            break;
            }
        case DRIVERS_USERS:{
                zlog_info(c,"online user=%p driver user head=%p tail=%p",online_user,didi_driver_head,didi_driver_tail);
                if(didi_driver_head){
                    online_user->next = NULL;
                    online_user->pre = didi_driver_tail;
                    didi_driver_tail->next = online_user;
                } else {
                    online_user->next = didi_driver_head;
                    online_user->pre = didi_driver_head;
                    didi_driver_head = online_user;
                }
                didi_driver_tail = online_user;
            break;
            }
        default:
            break;
    }
}
