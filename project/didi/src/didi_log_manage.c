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

int didi_log_init(zlog_category_t **c,const char* logpath){
    int rc;
    rc = zlog_init(logpath);
    if(rc){
        fprintf(stderr,"init failed!\n");
        return -1;
    }

    *c = zlog_get_category("didi");
    if(!c) {
        fprintf(stderr,"get didi failed!\n");
        zlog_fini();
        return -2;
    }
    return 0;
}

int didi_log_release(){
    zlog_fini();
    return 0;
}
