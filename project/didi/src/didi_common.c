/*########################################################
##File Name: didi_common.c
##Created Time:2016年01月05日 星期二 20时17分48秒
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

int didi_generate_userid(){
    struct tm *p;
    time_t second;
    time(&second);
    p = localtime(&second);
    char buf[100] = {0};
 
    sprintf(buf, "%d%d%d%d%d",1+p->tm_mon, p->tm_mday,p->tm_hour, p->tm_min, p->tm_sec);
  
    return atoi(buf);
}


char* create_respon_package(int status,didi_repack_t* res_pack,const char* telphone){
    char buf[1024];
    cJSON* root;
    char *res;

    switch(status){
        case REQUER_SUCCESS:
            res_pack->repackbody.reg_spond.recode = REQUER_SUCCESS;
            sprintf(buf,"request successfuly!");
            strcpy(res_pack->repackbody.reg_spond.remsg,buf);
            strcpy(res_pack->repackbody.reg_spond.telphone,telphone);
            zlog_info(c,"respond code:%d",res_pack->repackbody.reg_spond.recode);
            break;
        case SERVER_REFUSE:
            res_pack->repackbody.reg_spond.recode = SERVER_REFUSE;
            sprintf(buf,"request failed!");
            strcpy(res_pack->repackbody.reg_spond.remsg,buf);
            strcpy(res_pack->repackbody.reg_spond.telphone,telphone);
            zlog_info(c,"respond code:%d",res_pack->repackbody.reg_spond.recode);
            break;
        case USER_EXIST:
            res_pack->repackbody.reg_spond.recode = USER_EXIST;
            sprintf(buf,"user exist!");
            strcpy(res_pack->repackbody.reg_spond.remsg,buf);
            strcpy(res_pack->repackbody.reg_spond.telphone,telphone);
            zlog_info(c,"respond code:%d",res_pack->repackbody.reg_spond.recode);
            break;
        case USER_NOTEXIST:
            res_pack->repackbody.reg_spond.recode = USER_NOTEXIST;
            sprintf(buf,"user not exist!");
            strcpy(res_pack->repackbody.reg_spond.remsg,buf);
            strcpy(res_pack->repackbody.reg_spond.telphone,telphone);
            zlog_info(c,"respond code:%d",res_pack->repackbody.reg_spond.recode);
            break;
        case PASSWD_ERROR:
            res_pack->repackbody.reg_spond.recode = PASSWD_ERROR;
            sprintf(buf,"passwd auth failed!");
            strcpy(res_pack->repackbody.reg_spond.remsg,buf);
            strcpy(res_pack->repackbody.reg_spond.telphone,telphone);
            zlog_info(c,"respond code:%d",res_pack->repackbody.reg_spond.recode);
            break;
        case PASSWD_SUCCESS:
            res_pack->repackbody.reg_spond.recode = PASSWD_SUCCESS;
            sprintf(buf,"passwd auth successful!");
            strcpy(res_pack->repackbody.reg_spond.remsg,buf);
            strcpy(res_pack->repackbody.reg_spond.telphone,telphone);
            zlog_info(c,"respond code:%d",res_pack->repackbody.reg_spond.recode);
            break;
        default:
            break;
    }

    didi_create_respone(&root,res_pack);
    zlog_info(c,"%p",root);

    res = didi_ufconvert_json(root);

    return res;
}

char* create_ordspond_package(int status,didi_repack_t* res_pack,const char* telphone,int orderid,const char* starting,const char* destination){
    char buf[1024];
    cJSON* root;
    char *res;

    switch(status){
        case ORDER_SUCCESS:
            res_pack->repackbody.ord_spond.recode = ORDER_SUCCESS;
            sprintf(buf,"order successful!");
            strcpy(res_pack->repackbody.ord_spond.remsg,buf);
            res_pack->repackbody.ord_spond.orderid = orderid;
            strcpy(res_pack->repackbody.ord_spond.telphone,telphone);
            strcpy(res_pack->repackbody.ord_spond.starting,starting);
            strcpy(res_pack->repackbody.ord_spond.destination,destination);
            zlog_info(c,"respond code:%d",res_pack->repackbody.ord_spond.recode);
            break;
        case ORDER_ERROR:
            res_pack->repackbody.ord_spond.orderid = orderid;
            res_pack->repackbody.ord_spond.recode = ORDER_ERROR;
            sprintf(buf,"order failed!");
            strcpy(res_pack->repackbody.ord_spond.remsg,buf);
            strcpy(res_pack->repackbody.ord_spond.telphone,telphone);
            strcpy(res_pack->repackbody.ord_spond.starting,starting);
            strcpy(res_pack->repackbody.ord_spond.destination,destination);
            zlog_info(c,"respond code:%d",res_pack->repackbody.ord_spond.recode);
            break;
        default:
            break;
    }
    
    didi_create_ordspond(&root,res_pack);
    zlog_info(c,"%p",root);

    res = didi_ufconvert_json(root);

    return res;
}

char* create_takespond_package(int status,didi_repack_t* res_pack,const char* telphone,int orderid){
    char buf[1024];
    cJSON* root;
    char *res;

    switch(status){
        case TAKETOKEN_SUCCESS:
            res_pack->repackbody.ord_spond.recode = TAKETOKEN_SUCCESS;
            sprintf(buf,"take token successful!");
            strcpy(res_pack->repackbody.ord_spond.remsg,buf);
            strcpy(res_pack->repackbody.ord_spond.telphone,telphone);
            res_pack->repackbody.ord_spond.orderid = orderid;
            zlog_info(c,"respond code:%d",res_pack->repackbody.ord_spond.recode);
            break;
        case TAKETOKEN_ERROR:
            res_pack->repackbody.ord_spond.recode = TAKETOKEN_ERROR;
            sprintf(buf,"take token failed!");
            strcpy(res_pack->repackbody.ord_spond.remsg,buf);
            strcpy(res_pack->repackbody.ord_spond.telphone,telphone);
            res_pack->repackbody.ord_spond.orderid = orderid;
            zlog_info(c,"respond code:%d",res_pack->repackbody.ord_spond.recode);
            break;
        default:
            break;
    }
    
    didi_create_takespond(&root,res_pack);
    zlog_info(c,"%p",root);

    res = didi_ufconvert_json(root);

    return res;
}

void didi_order_broadcast(const char* res_package){
    if(didi_driver_head == NULL){
        zlog_warn(c,"no driver online order hangup!");
        return;
    }
    zlog_info(c,"have driver onlline head=%p",didi_driver_head);
    didi_online_t *pn;
    pn = didi_driver_head;
    while(pn){
        write(pn->fd,res_package,strlen(res_package));
        zlog_info(c,"write to driver %d",pn->fd);
        pn= pn->next;
    }
    
}


char* create_drispond_package(int status,didi_repack_t *res_pack,didi_online_t* pn){
    char buf[1024];
    cJSON* root;
    char *res;

    switch(status){
        case TAKETOKEN_SUCCESS:
            res_pack->repackbody.dri_spond.recode = TAKETOKEN_SUCCESS;
            sprintf(buf,"take token successful!");
            strcpy(res_pack->repackbody.dri_spond.remsg,buf);
            strcpy(res_pack->repackbody.dri_spond.drivername,pn->online_user.driver.drivername);
            strcpy(res_pack->repackbody.dri_spond.driverphone,pn->online_user.driver.drivertelphone);
            strcpy(res_pack->repackbody.dri_spond.drivercarnum,pn->online_user.driver.drivercarnum);
            res_pack->repackbody.dri_spond.driverid = pn->online_user.driver.driverid;
            zlog_info(c,"respond code:%d",res_pack->repackbody.dri_spond.recode);
            break;
        default:
            break;
    }
    
    didi_create_drispond(&root,res_pack);
    zlog_info(c,"%p",root);

    res = didi_ufconvert_json(root);

    return res;
}

int didi_create_orderhistory(int orderid,const char* payment,const char* arrivaltime){
    int ret;
    didi_order_t *historyorder;
    //将字段填入链表节点中
    historyorder = didi_fillorder_node(orderid,payment,arrivaltime);
    if(historyorder == NULL){
        return -1;   
    }else {
        //将节点字段写入数据库
        ret = didi_insert_historyorder(&db,historyorder);
        if(ret == -1){
            return -1;
        }
        historyorder = NULL;
    }
    return 0;
}

char* didi_respond_history(didi_repack_t *res_pack,int usertype,const char* telphone){
    char buf[1024];
    cJSON* root;
    char *res;
    int ret;
    
    //查询数据库填充字段
    ret = didi_query_order(&db,usertype,telphone);
    if(-1 == ret){
        zlog_info(c,"haven't this user history!");
        res_pack->repackbody.ordhistory.recode = ORDHISTORY_ERROR;
        sprintf(buf,"query order history failed!");
        strcpy(res_pack->repackbody.ordhistory.remsg,buf);
        didi_create_noordhistory(&root,res_pack);
    } else {
        res_pack->repackbody.ordhistory.recode = ORDHISTORY_SUCCESS;
        sprintf(buf,"query order history successful!");
        strcpy(res_pack->repackbody.ordhistory.remsg,buf);
        if(usertype == PERSONAL_USER){
            res_pack->repackbody.ordhistory.orderid = atoi((char*)didi_fetch_ordhistory(&db,"orderid",telphone,usertype));
            strcpy(res_pack->repackbody.ordhistory.starting,(char*)didi_fetch_ordhistory(&db,"starting",telphone,usertype));
            strcpy(res_pack->repackbody.ordhistory.destination,(char*)didi_fetch_ordhistory(&db,"destination",telphone,usertype));
            strcpy(res_pack->repackbody.ordhistory.driverphone,(char*)didi_fetch_ordhistory(&db,"driverphone",telphone,usertype));
            strcpy(res_pack->repackbody.ordhistory.payment,(char*)didi_fetch_ordhistory(&db,"payment",telphone,usertype));
            strcpy(res_pack->repackbody.ordhistory.starttime,(char*)didi_fetch_ordhistory(&db,"starttime",telphone,usertype));
            strcpy(res_pack->repackbody.ordhistory.arrivaltime,(char*)didi_fetch_ordhistory(&db,"arrivaltime",telphone,usertype));
            didi_create_uordhistory(&root,res_pack);
        } else if(usertype == DRIVERS_USERS){
            res_pack->repackbody.ordhistory.orderid = atoi((char*)didi_fetch_ordhistory(&db,"orderid",telphone,usertype));
            strcpy(res_pack->repackbody.ordhistory.starting,(char*)didi_fetch_ordhistory(&db,"starting",telphone,usertype));
            strcpy(res_pack->repackbody.ordhistory.destination,(char*)didi_fetch_ordhistory(&db,"destination",telphone,usertype));
            strcpy(res_pack->repackbody.ordhistory.driverphone,(char*)didi_fetch_ordhistory(&db,"userphone",telphone,usertype));
            strcpy(res_pack->repackbody.ordhistory.payment,(char*)didi_fetch_ordhistory(&db,"payment",telphone,usertype));
            strcpy(res_pack->repackbody.ordhistory.starttime,(char*)didi_fetch_ordhistory(&db,"starttime",telphone,usertype));
            strcpy(res_pack->repackbody.ordhistory.arrivaltime,(char*)didi_fetch_ordhistory(&db,"arrivaltime",telphone,usertype));
            didi_create_dordhistory(&root,res_pack);
        }
        zlog_info(c,"respond code:%d",res_pack->repackbody.ordhistory.recode);
    }
    res = didi_ufconvert_json(root);
    return res;
}
