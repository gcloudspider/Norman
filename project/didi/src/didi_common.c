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
