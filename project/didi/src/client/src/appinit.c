/*########################################################
##File Name: appinit.c
##Created Time:2016年01月06日 星期三 17时01分39秒
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

int init_socket(){
    int ret,len;

    struct sockaddr_in sin;
    struct sockaddr_in cin;
    void* rret;


    sfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == sfd){
        perror("socket");
        return -1;
    }

    sin.sin_family = AF_INET;
    sin.sin_port = htons(8081);

    if(inet_pton(AF_INET,"127.0.0.1",&sin.sin_addr.s_addr)<=0){
        perror("inet_pton");
        return -1;
    }

    ret = connect(sfd,(const struct sockaddr*)&sin,(socklen_t)sizeof(sin));
    if(-1 == ret){
        perror("connect");
        return -1;
    }
    printf("connect successfuly!\n");

    return 0;
}
