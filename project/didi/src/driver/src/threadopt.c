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
        //printf("%s\n",buf);
        root = didi_convert_string(buf);
        break;
    }
    print_message_body(root);
    return argv;
}

void* thread_write(void* argv){
    return argv;
}

