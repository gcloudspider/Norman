/*########################################################
##File Name: client.c
##Created Time:2015年12月26日 星期六 21时34分56秒
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



void showMenu(){
    char ch;
    while(1){
        system("clear");
        printf("##########################################\n");
        printf("##              1.用户注册              ##\n");
        printf("##                                      ##\n");
        printf("##              2.用户登录              ##\n");
        printf("##                                      ##\n");
        printf("##              3.退出程序              ##\n");
        printf("##########################################\n");
        printf("请输入选择:");
        ch = getchar();
        switch(ch){
            case '1':
                register_user();
                break;
            case '2':
                break;
            case '3':
                exit(0);
                break;
            default:
                break;
        }
    }
}

int main(){
    showMenu();
}


