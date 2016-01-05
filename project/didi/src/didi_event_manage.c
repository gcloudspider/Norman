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
    int ret,userid;
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
    item = didi_getitem_node(bodynode,"telphone");
    item2 = didi_getitem_node(bodynode,"usertype");
    zlog_info(c,"bodynode telphone=%s",item->valuestring);
    ret = query_user_exist(&db,item->valuestring);
    //判断用户是否存在
    if(-1 == ret){
        zlog_info(c,"%s user not exist!",item->valuestring);
        userid = didi_generate_userid();
        zlog_info(c,"%s user id=%d!",item->valuestring,userid);
        //插入用户
        if(item2->valueint == PERSONAL_USER){
            didi_user_t user;
            user.userid = userid;
            strcpy(user.telphone,item->valuestring);
            item = didi_getitem_node(bodynode,"username");
            strcpy(user.username,item->valuestring);
            item = didi_getitem_node(bodynode,"nickname");
            strcpy(user.nickname,item->valuestring);
            item = didi_getitem_node(bodynode,"passwd");
            strcpy(user.passwd,item->valuestring);
            ret = didi_insert_user(&db,user);
            if(-1 == ret){
                //失败

            } else {
                //成功
            }
        } else {
            //didi_insert_driveruser(&db);
        }

    } else {
        zlog_info(c,"%s user exist!",item->valuestring);
        //用户存在
        //组包返回
    }
}

void* didi_event_login(void *argv,void* argv2){

}

void* didi_event_logout(void *argv,void* argv2){

}

void* didi_event_query(void *argv,void* argv2){

}
