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

int didi_cache_init(MYSQL *db,zlog_category_t **c){

}

int didi_cache_release(zlog_category_t **c){
    zlog_info(*c,"didi release cache success!\n");
}
