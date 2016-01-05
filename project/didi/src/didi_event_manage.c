/*########################################################
##File Name: didi_event_manage.c
##Created Time:2016年01月05日 星期二 14时26分49秒
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

void* didi_event_register(void *argv,void* argv2){
    int ret;
    cJSON* root,*bodynode;
    cJSON* item,*item2;
    int cfd = (int)argv;
    char buf[1024];
    strcpy(buf,(char*)argv2);
    zlog_info(c,"ready to read body cfd=%d buf=%s!",cfd,buf);
    
    didi_convert_string(&root,buf);
    zlog_info(c,"root=%p",root);
    bodynode = didi_getjson_node(root,"body");
    zlog_info(c,"body node=%p",bodynode);
    item = didi_getitem_node(bodynode,"username");
    zlog_info(c,"bodynode username=%s",item->valuestring);
}

void* didi_event_login(void *argv){

}

void* didi_event_logout(void *argv){

}

void* didi_event_query(void *argv){

}
