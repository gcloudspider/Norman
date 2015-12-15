/*########################################################
##File Name: message_send.c
##Created Time:2015年12月15日 星期二 19时23分59秒
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

struct msgbuf{
    long type;
    char buf[1020];
};

int main(int argc,char* argv[]){
    int id;
    key_t key=5000;
    struct msgbuf m;
    m.type = 0x1000;
    strcpy(m.buf,argv[1]);
    id = msgget(key,IPC_CREAT|0666);    //创建一个消息队列
    if(-1 == id){
        perror("msgget");

    }

    msgsnd(id,&m,sizeof(struct msgbuf)-4,0);  //将消息发送到内核消息队列中
    return 0;
}
