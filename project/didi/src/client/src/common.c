/*########################################################
##File Name: common.c
##Created Time:2016年01月05日 星期二 08时41分15秒
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
#include<uuid/uuid.h>
#include"../include/user.h"

char *random_uuid(char* buf) {
    uuid_t uuid;
    
    uuid_generate(uuid);
    uuid_unparse(uuid, buf);
              
    return buf;
}
