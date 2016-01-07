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

didi_online_t* didi_find_linklist(didi_online_t *head,const char* telphone){
    didi_online_t *pn;

    while(head){
        if(strcmp(head->telphone,telphone)==0){
            pn = head;
        }
        head = head->next;
    }
    zlog_info(c,"find node=%p",pn);
    return pn;
}

int didi_del_linklist(didi_online_t *pn,didi_online_t *head){
    if(pn){
        if(pn == head){
            zlog_info(c,"is first?");
            if(pn->next){
                pn->next->pre = NULL;
                head = pn->next;
                zlog_info(c,"pn is first!but have another!");
            } else {
                head = NULL;
                zlog_info(c,"delete linklist head = NULL");
            }
        } else {
            if(pn->next){
                pn->next->pre = pn->pre;
                pn->pre->next = pn->next;
            } else {
                pn->pre->next = pn->next;
            }
        }
    } else {
        return -1;
    }
    return 0;
}

int didi_del_cache(int usertype,const char* telphone){
    zlog_info(c,"didi_user_head=%p didi_driver_head=%p",didi_user_head,didi_driver_head);
    int ret=0;
    didi_online_t *pn;

    switch(usertype){
        case PERSONAL_USER:
            zlog_info(c,"didi user head=%p",didi_user_head);
            pn = didi_find_linklist(didi_user_head,telphone);
            zlog_info(c,"didi pn=%p",pn);
            ret = didi_del_linklist(pn,didi_user_head);
            break;
        case DRIVERS_USERS:
            zlog_info(c,"didi user head=%p",didi_driver_head);
            pn = didi_find_linklist(didi_driver_head,telphone);
            zlog_info(c,"didi pn=%p",pn);
            ret = didi_del_linklist(pn,didi_driver_head);
            break;
        default:
            break;
    }

    return ret;
}

int didi_add_queue(const char* userphone,const char* starting,const char* destination,const char* starttime){
    didi_order_t *pn;
    pn = malloc(sizeof(didi_order_t));
    strcpy(pn->userphone,userphone);
    strcpy(pn->starting,starting);
    strcpy(pn->destination,destination);
    strcpy(pn->starttime,starttime);
    
    zlog_info(c,"add order %p",pn);
    if(didi_order_tail){
        zlog_info(c,"order has something no handle!");
        didi_order_tail->next = pn;
        pn->pre = didi_order_tail;
        pn->next = NULL;
        didi_order_tail = pn;
    } else {
        zlog_info(c,"order tail NULL!");
        didi_order_tail = pn;
        didi_order_head = pn;
        didi_order_head->next = NULL;
        didi_order_head->pre = NULL;
    }
    zlog_info(c,"didi order head=%p tail=%p",didi_order_head,didi_order_tail);
    return 0;
}

int didi_create_order(int usertype,const char* userphone,const char* starting,const char* destination,const char* starttime){
    int ret;
    ret = didi_add_queue(userphone,starting,destination,starttime);
    return ret;
}
