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
    cJSON* headitem,*bodyitem,*bodyitem1,*bodyitem2,*bodyitem3,*bodyitem4;

    headnode = didi_getjson_node(&root,"head");
    headitem = didi_getitem_node(&headnode,"packtype");
    if((headitem->valueint) == PACKTYPE_RESPONE){
        headitem = didi_getitem_node(&headnode,"event");
        switch(headitem->valueint){
            case EVENT_REGISTER:
                bodynode = didi_getjson_node(&root,"body");
                bodyitem = didi_getitem_node(&bodynode,"recode");
                if((bodyitem->valueint) == USER_EXIST ){
                    printf("此用户已被注册!1秒后返回主界面!\n");
                } else if((bodyitem->valueint) == REQUER_SUCCESS){
                    printf("此用户注册成功!1秒后返回主界面!\n");
                } else {
                    printf("未知错误!1秒后返回主界面!\n");
                }
                break;
            case EVENT_LOGIN:
                bodynode = didi_getjson_node(&root,"body");
                bodyitem = didi_getitem_node(&bodynode,"recode");
                if((bodyitem->valueint) == USER_NOTEXIST ){
                    printf("输入账号不存在!1秒后返回主界面!\n");
                } else if((bodyitem->valueint) == PASSWD_SUCCESS){
                    printf("登录成功!\n");
                    sleep(1);
                    bodyitem = didi_getitem_node(&bodynode,"telphone");
                    strcpy(loginuser,bodyitem->valuestring);
                    showUserMenu();
                } else if((bodyitem->valueint) == PASSWD_ERROR){
                    printf("密码验证失败!1秒后返回主界面!\n");
                } else {
                    printf("未知错误!1秒后返回主界面!\n");
                }
                break;
            case EVENT_LOGOUT:
                printf("退出成功!1秒后返回主界面!\n");
                break;
            case EVENT_MPASSWD:
                bodynode = didi_getjson_node(&root,"body");
                bodyitem = didi_getitem_node(&bodynode,"recode");
                if((bodyitem->valueint) == USER_EXIST ){
                    printf("此用户密码修改失败!1秒后返回用户界面!\n");
                } else if((bodyitem->valueint) == REQUER_SUCCESS){
                    printf("此用户密码修改成功!1秒后返回用户界面!\n");
                } else {
                    printf("未知错误!1秒后返回主界面!\n");
                }
                break;
            case EVENT_ORDER:
                bodynode = didi_getjson_node(&root,"body");
                bodyitem = didi_getitem_node(&bodynode,"recode");
                if((bodyitem->valueint) == ORDER_ERROR ){
                    printf("提交订单失败!1秒后返回用户界面!\n");
                } else if((bodyitem->valueint) == ORDER_SUCCESS){
                    printf("提交订单成功!!\n");
                    printf("请等待司机联系您!\n");
                } else {
                    printf("未知错误!1秒后返回主界面!\n");
                }
                break;
            case EVENT_TAKETOKEN:
                bodynode = didi_getjson_node(&root,"body");
                bodyitem = didi_getitem_node(&bodynode,"recode");
                bodyitem1 = didi_getitem_node(&bodynode,"driverid");
                bodyitem2 = didi_getitem_node(&bodynode,"driverphone");
                bodyitem3 = didi_getitem_node(&bodynode,"drivername");
                bodyitem4 = didi_getitem_node(&bodynode,"drivercarnum");
                if(bodyitem->valueint == TAKETOKEN_SUCCESS){
                    printf("订单被司机:%s 抢到\n",bodyitem3->valuestring);
                    printf("司机工号:%d\n",bodyitem1->valueint);
                    printf("司机电话号码:%s\n",bodyitem2->valuestring);
                    printf("司机车牌号码:%s\n",bodyitem4->valuestring);
                }
                break;
            case EVENT_QUERY:
                bodynode = didi_getjson_node(&root,"body");
                bodyitem = didi_getitem_node(&bodynode,"recode");
                if(bodyitem->valueint == ORDHISTORY_ERROR ){
                    printf("抱歉,您没有历史订单!\n");
                    sleep(1);
                } else if(bodyitem->valueint == ORDHISTORY_SUCCESS){
                    printf("你有历史订单!\n");
                    sleep(1);
                }
                break;
            default:
                break;
        }
    }
    sleep(1);
}

