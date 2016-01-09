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

}
