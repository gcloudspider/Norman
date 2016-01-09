/*########################################################
##File Name: print.c
##Created Time:2016年01月06日 星期三 17时10分53秒
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
#include "../include/user.h"
void print_message_body(cJSON* root){
    cJSON* headnode,*bodynode;
    cJSON* headitem,*bodyitem,*bodyitem1,*bodyitem2,*bodyitem3;
    char ch;

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
                bodyitem = didi_getitem_node(&bodynode,"starting");
                bodyitem1 = didi_getitem_node(&bodynode,"orderid");
                bodyitem2 = didi_getitem_node(&bodynode,"destination");
                bodyitem3 = didi_getitem_node(&bodynode,"telphone");
                printf("附近有一单!");
                printf("始发地:%s  目的地:%s\n",bodyitem->valuestring,bodyitem2->valuestring);
                printf("联系人电话:%s\n",bodyitem3->valuestring);
                while((ch=getchar())!='\n');
                printf("是否抢单(输入Y/N):\n");
                scanf("%c",&ch);
                if(ch == 'y'||ch == 'Y'||ch == '\n'){
                    start_take(bodyitem1->valueint);
                } else {
                    printf("放弃该单!回到主界面\n");
                    sleep(1);
                }
                break;
            default:
                break;
        }
    }
    
    sleep(1);
}


void print_token_body(cJSON* root){
    cJSON* headnode,*bodynode;
    cJSON* headitem,*bodyitem,*bodyitem1,*bodyitem2,*bodyitem3;
    char ch;
    char* ret;

    headnode = didi_getjson_node(&root,"head");
    headitem = didi_getitem_node(&headnode,"packtype");
    if((headitem->valueint) == PACKTYPE_RESPONE){
        headitem = didi_getitem_node(&headnode,"event");
        switch(headitem->valueint){
            case EVENT_ORDER:
                bodynode = didi_getjson_node(&root,"body");
                bodyitem = didi_getitem_node(&bodynode,"starting");
                bodyitem1 = didi_getitem_node(&bodynode,"orderid");
                bodyitem2 = didi_getitem_node(&bodynode,"destination");
                bodyitem3 = didi_getitem_node(&bodynode,"telphone");
                printf("附近有一单!");
                printf("始发地:%s  目的地:%s\n",bodyitem->valuestring,bodyitem2->valuestring);
                printf("联系人电话:%s\n",bodyitem3->valuestring);
                while((ch=getchar())!='\n');
                printf("是否抢单(输入Y/N):\n");
                scanf("%c",&ch);
                if(ch == 'y'||ch == 'Y'||ch == '\n'){
                    start_take(bodyitem1->valueint);
                } else {
                    printf("放弃该单!回到主界面\n");
                    sleep(1);
                }
                break;
            case EVENT_TAKETOKEN:
                bodynode = didi_getjson_node(&root,"body");
                bodyitem = didi_getitem_node(&bodynode,"recode");
                bodyitem1 = didi_getitem_node(&bodynode,"orderid");
                if(bodyitem->valueint == TAKETOKEN_SUCCESS){
                    printf("抢单成功!\n");
                } else {
                    printf("单已被抢!继续抢单!\n");
                }
                break;
            default:
                break;
        }
    }
}
