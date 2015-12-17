/*########################################################
##File Name: thread_robot.c
##Created Time:2015年12月17日 星期四 21时41分09秒
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
#include "head.h"

void usage(const char* proname){
    fprintf(stderr,"Usage:%s [-s server] [-c client]",proname);
    exit(2);
}

//创建监听收到的数据


//服务端模式
void server_mode(){

}

//客户端模式
void client_mode(){

}


int main(int argc,char* argv[]){
    char ch;
    if(argc<2){
        useage(argv[0]);
    }

    while((ch=getopt(argc,argv,"sc"))!=EOF){
        switch(ch){
            case 's':
                server_mode();
                break;
            case 'c':
                client_mode();
                break;
            default:
                break;
        }

    }
    return 0;
}
