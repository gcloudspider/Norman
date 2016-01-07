/*########################################################
##File Name: print.c
##Created Time:2016年01月06日 星期三 16时59分45秒
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
#include"../include/user.h"

void print_message_body(cJSON* root){
    cJSON* headnode,*bodynode;
    cJSON* headitem,*bodyitem;

    headnode = didi_getjson_node(&root,"head");
    headitem = didi_getitem_node(&headnode,"packtype");
    if((headitem->valueint) == PACKTYPE_RESPONE){
        headitem = didi_getitem_node(&headnode,"event");
        switch(headitem->valueint){
            case EVENT_REGISTER:
                bodynode = didi_getjson_node(&root,"body");
                bodyitem = didi_getitem_node(&bodynode,"recode");
                if((bodyitem->valueint) == USER_EXIST ){
                    printf("此用户已被注册!3秒后返回主界面!\n");
                } else if((bodyitem->valueint) == REQUER_SUCCESS){
                    printf("此用户注册成功!3秒后返回主界面!\n");
                } else {
                    printf("未知错误!3秒后返回主界面!\n");
                }
                break;
            case EVENT_LOGIN:
                bodynode = didi_getjson_node(&root,"body");
                bodyitem = didi_getitem_node(&bodynode,"recode");
                if((bodyitem->valueint) == USER_NOTEXIST ){
                    printf("输入账号不存在!3秒后返回主界面!\n");
                } else if((bodyitem->valueint) == PASSWD_SUCCESS){
                    printf("登录成功!\n");
                    sleep(3);
                    bodyitem = didi_getitem_node(&bodynode,"telphone");
                    strcpy(loginuser,bodyitem->valuestring);
                    showUserMenu();
                } else if((bodyitem->valueint) == PASSWD_ERROR){
                    printf("密码验证失败!3秒后返回主界面!\n");
                } else {
                    printf("未知错误!3秒后返回主界面!\n");
                }
                break;
            case EVENT_LOGOUT:
                printf("退出成功!3秒后返回主界面!\n");
                break;
            case EVENT_MPASSWD:
                bodynode = didi_getjson_node(&root,"body");
                bodyitem = didi_getitem_node(&bodynode,"recode");
                if((bodyitem->valueint) == USER_EXIST ){
                    printf("此用户密码修改失败!3秒后返回用户界面!\n");
                } else if((bodyitem->valueint) == REQUER_SUCCESS){
                    printf("此用户密码修改成功!3秒后返回用户界面!\n");
                } else {
                    printf("未知错误!3秒后返回主界面!\n");
                }
                break;
            case EVENT_ORDER:
                bodynode = didi_getjson_node(&root,"body");
                bodyitem = didi_getitem_node(&bodynode,"recode");
                if((bodyitem->valueint) == ORDER_ERROR ){
                    printf("提交订单失败!3秒后返回用户界面!\n");
                } else if((bodyitem->valueint) == ORDER_SUCCESS){
                    printf("提交订单成功!3秒后返回用户界面!\n");
                    printf("请等待司机联系您!\n");
                } else {
                    printf("未知错误!3秒后返回主界面!\n");
                }
                break;
            default:
                break;
        }
    }
    
    sleep(3);
}

