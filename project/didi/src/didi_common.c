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


char* create_respon_package(int status,didi_repack_t* res_pack){
    char buf[1024];
    cJSON* root;
    char *res;

    switch(status){
        case REQUER_SUCCESS:
            sprintf(buf,"status: %d",REQUER_SUCCESS);
            strcpy(res_pack->repackbody.reg_spond.recode,buf);
            sprintf(buf,"register user successfuly!");
            strcpy(res_pack->repackbody.reg_spond.remsg,buf);
            zlog_info(c,"respond code:%s",res_pack->repackbody.reg_spond.recode);
            break;
        case SERVER_REFUSE:
            sprintf(buf,"status: %d",SERVER_REFUSE);
            strcpy(res_pack->repackbody.reg_spond.recode,buf);
            sprintf(buf,"register user failed!");
            strcpy(res_pack->repackbody.reg_spond.remsg,buf);
            zlog_info(c,"respond code:%s",res_pack->repackbody.reg_spond.recode);
            break;
        case USER_EXIST:
            sprintf(buf,"status: %d",USER_EXIST);
            strcpy(res_pack->repackbody.reg_spond.recode,buf);
            sprintf(buf,"user exist!");
            strcpy(res_pack->repackbody.reg_spond.remsg,buf);
            zlog_info(c,"respond code:%s",res_pack->repackbody.reg_spond.recode);
            break;
        default:
            break;
    }

    didi_create_respone(&root,res_pack);
    zlog_info(c,"%p",root);

    res = didi_ufconvert_json(root);

    return res;
}