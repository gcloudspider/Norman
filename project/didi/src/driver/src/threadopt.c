/*########################################################
##File Name: threadopt.c
##Created Time:2016年01月06日 星期三 17时09分12秒
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
void* thread_read(void* argv){
    int ret;
    char buf[1024] = {0};
    cJSON* root;

    while(1){
        ret = read(sfd,buf,1024);
        root = didi_convert_string(buf);
        break;
    }
    print_message_body(root);
    return argv;
}

void* thread_write(void* argv){
    return argv;
}

void* take_token(void* argv){
    int ret;
    char buf[1024] = {0};
    cJSON* root;
    char ch;

    while(1){
        ret = read(sfd,buf,1024);
        if(ret != -1){
            root = didi_convert_string(buf);
            print_token_body(root);
        }
        /*
        while((ch=getchar())!='\n');
        printf("是否继续接单!请输入yes/no:");
clear_enter:
        ch = getchar();
        if(ch == 'y'|| ch=='Y'||ch=='\n'){
            continue;
        } else if(ch == 'n'||ch == 'N'){
                break;
        } else {
            goto clear_enter;
        }*/
    }
    return argv;
}

