/*########################################################
##File Name: nv_cond.c
##Created Time:2015年12月26日 星期六 19时31分47秒
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
#include "../include/chatserver.h"


int init_thread_cond(pthread_cond_t* cond){
    return pthread_cond_init(cond,NULL);
}
