/*########################################################
##File Name: didi_log_manage.c
##Created Time:2015年12月30日 星期三 08时13分59秒
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

int didi_log_init(const char* logpath){
    
    int rc;
    zlog_category_t *c;
    rc = zlog_init(logpath);

    return 0;
}
