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

int didi_add_queue(int orderid,const char* userphone,const char* starting,const char* destination,const char* starttime){
    didi_order_t *pn;
    pn = malloc(sizeof(didi_order_t));
    pn->orderid = orderid;
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

int didi_create_order(int orderid,int usertype,const char* userphone,const char* starting,const char* destination,const char* starttime){
    int ret;
    ret = didi_add_queue(orderid,userphone,starting,destination,starttime);
    return ret;
}

didi_order_t* find_ordernode_linklist(int orderid){
    didi_order_t *pn;
    pn = didi_order_head;
    while(pn){
        if(pn->orderid==orderid){
            return pn;
        }
        pn = pn->next;
    }
    return NULL;
}

int didi_delnode_linklist(didi_order_t* pn){
    didi_order_t* pb;
    if(didi_order_head == NULL){
        return -1;
    }

    if(didi_order_head == pn){
        if(didi_order_head->next != NULL){
            didi_order_head->next->pre = NULL;
            didi_order_head = didi_order_head->next; 
        }
    } else if(didi_order_tail == pn){
        if(didi_order_tail->pre !=NULL){
            didi_order_tail->pre->next = NULL;
            didi_order_tail = didi_order_tail->pre;
            didi_order_tail->pre = NULL;
        }
    } else {
        pn->pre->next = pn->next;
        pn->next->pre = pn->pre;
        pn->next = NULL;
        pn->pre = NULL;
    }
    return 0;
}

int didi_addnode_overorder(didi_order_t* pn){
    zlog_info(c,"add over order %p",pn);
    if(didi_overorder_tail){
        zlog_info(c,"order has something no handle!");
        didi_overorder_tail->next = pn;
        pn->pre = didi_overorder_tail;
        pn->next = NULL;
        didi_overorder_tail = pn;
    } else {
        zlog_info(c,"order tail NULL!");
        didi_overorder_tail = pn;
        didi_overorder_head = pn;
        didi_overorder_head->next = NULL;
        didi_overorder_head->pre = NULL;
    }
    zlog_info(c,"didi over order head=%p tail=%p",didi_overorder_head,didi_overorder_tail);
    return 0;
}

int didi_separate_cache(const char* telphone,int orderid){
    didi_order_t *pn;
    int ret;
    //找到order节点
    pn = find_ordernode_linklist(orderid);
    if(pn == NULL){
        zlog_warn(c,"pn=%p finded order node",pn);
        return -1;
    }
    //填充节点字段
    strcpy(pn->driverphone,telphone);
    //将节点脱离
    ret = didi_delnode_linklist(pn);
    if(-1 == ret){
        zlog_warn(c,"pn=%p delnode linklist failed!",pn);
        return -1;
    }
    zlog_info(c,"pn=%p delnode linklist successful!",pn);
    //添加到达目的地的链表
    ret = didi_addnode_overorder(pn);
    if(-1 == ret){
        zlog_warn(c,"pn=%p add node linklist failed!",pn);
        return -1;
    }
    zlog_info(c,"pn=%p add node linklist successful!",pn);
    zlog_info(c,"pn->userphone=%s pn->driverphone=%s overorder=%p order=%p add node linklist successful!",didi_overorder_head->userphone,didi_overorder_head->driverphone,didi_overorder_head,didi_order_head);

    return 0;
}

int didi_getorder_cache(int orderid){
    if(didi_order_head == NULL){
        return -1;
    }
    
    if(didi_order_head->orderid != orderid){
        return -1;
    }

    return 0;
}

char* didi_userphone_linklist(int orderid){
    while(didi_overorder_head){
        if(didi_overorder_head->orderid == orderid){
            zlog_info(c,"find user phone=%s",didi_overorder_head->userphone);
            return didi_overorder_head->userphone;
        }
        didi_overorder_head = didi_overorder_head->next;
    }
    return NULL;
}

int didi_getcfd_cache(int orderid){
    char* buf;
    buf = didi_userphone_linklist(orderid);
    if(buf == NULL){
        return -1;
    }

    while(didi_user_head){
        if(strcmp(didi_user_head->telphone,buf)==0){
            zlog_info(c,"get user fd=%d",didi_user_head->fd);
            return didi_user_head->fd;
        }
        didi_user_head = didi_user_head->next;
    }
}
