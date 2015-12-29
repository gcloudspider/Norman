/*########################################################
##File Name: udp_multicast_server.cpp
##Created Time:2015年12月29日 星期二 08时25分23秒
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

#include<iostream>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<netinet/in_systm.h>
#include<netinet/ip.h>
#include<netinet/ip_icmp.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<sys/un.h>
using namespace std;

#define MCAST_PORT 8888
#define MCAST_ADDR "244.0.0.100"
#define MCAST_DATA "DEGUB MULTICAST TEST DATA"
#define MCAST_INTERVAL 1

char buf[1024];

int main(int argc,char* argv[]){
    int s;
    struct sockaddr_in mcast_addr;
    s = socket(AF_INET,SOCK_DGRAM,0);
    if(s == -1){
        perror("socket()");
        return -1;
    }
    //初始化IP多播地址
    memset(&mcast_addr,0,sizeof(mcast_addr));
    //设置协议
    mcast_addr.sin_family = AF_INET;
    mcast_addr.sin_addr.s_addr = inet_addr(MCAST_ADDR);
    mcast_addr.sin_port = htons(MCAST_PORT);

    printf("输入要组播的数据: ");
    int i=0;
    memset(buf,0,sizeof(buf));
    while((buf[i]=getchar())!= '\n')
        i++;
    buf[i] = 0;

    while(1){
        int n = sendto(s,buf,sizeof(MCAST_DATA),0,(struct sockaddr*)&mcast_addr,sizeof(mcast_addr));
        if(n<0){
            perror("sendto()");
            return -2;
        }
        sleep(MCAST_INTERVAL);
    }
    return 0;
}

