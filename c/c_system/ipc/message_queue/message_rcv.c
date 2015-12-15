/*########################################################
##File Name: message_rcv.c
##Created Time:2015年12月15日 星期二 19时31分38秒
##Author: Norman 
##Description: 
##
##Issue: 
##
##Analyze: 1.内核维护着消息队列
##          2.当内核消息队列中消息数为0时，再接收消息发生阻塞，当队列中有消息立即可接收到
##          3.内核消息队列为链表实现，在每创建一个节点需要malloc所以很消耗
##
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>
#include"head.h"

struct msgbuf{
    long type;
    char buf[1020];
};

int main(){
    int id;
    key_t key = 5000;
    struct msgbuf m;
    id = msgget(key,IPC_CREAT|0666);

    msgrcv(id,&m,sizeof(struct msgbuf)-4,0x1000,0);
    printf("message:%s\n",m.buf);
}
