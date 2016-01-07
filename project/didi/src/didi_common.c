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
            sprintf(buf,"register user successfuly!");
            strcpy(res_pack->repackbody.reg_spond.remsg,buf);
            strcpy(res_pack->repackbody.reg_spond.telphone,telphone);
            zlog_info(c,"respond code:%d",res_pack->repackbody.reg_spond.recode);
            break;
        case SERVER_REFUSE:
            res_pack->repackbody.reg_spond.recode = SERVER_REFUSE;
            sprintf(buf,"register user failed!");
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
