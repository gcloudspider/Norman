/*########################################################
##File Name: udp_multicast_client.cpp
##Created Time:2015年12月29日 星期二 08时36分51秒
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
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in_systm.h>
#include<netinet/ip.h>
#include<netinet/ip_icmp.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<sys/un.h>

using namespace std;

#define MCAST_PORT 8888
#define MCAST_ADDR "224.0.0.100"

#define MCAST_INTERVAL 1
#define BUFF_SIZE 256

int main(int argc,char* argv[]){
    int s;
    struct sockaddr_in local_addr;
    int err = -1;
    s = socket(AF_INET,SOCK_DGRAM,0);
    if(s == -1){
        perror("socket()");
        return -1;
    }

    memset(&local_addr,0,sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    local_addr.sin_port = htons(MCAST_PORT);

    err = bind(s,(struct sockaddr*)&local_addr,sizeof(local_addr));
    if(err < 0){
        perror("bind()");
        return -2;
    }

    int loop = 1;
    err = setsockopt(s,IPPROTO_IP,IP_MULTICAST_LOOP,&loop,sizeof(loop));
    if(err < 0){
        perror("setsockopt():IP_MULTICAST_LOOP");
        return -3;
    }

    struct ip_mreq mreq;
    mreq.imr_multiaddr.s_addr = inet_addr(MCAST_ADDR);
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);

    err = setsockopt(s,IPPROTO_IP,IP_ADD_MEMBERSHIP,&mreq,sizeof(mreq));
    if(err <0){
        perror("setsockopt():IP_ADD_MEMBERSHIP");
        return -4;
    }

    int times = 0;
    socklen_t addr_len = 0;
    char buff[BUFF_SIZE];
    int n = 0;
    for(times = 0;times<10;times++){
        addr_len = sizeof(local_addr);
        memset(buff,0,BUFF_SIZE);
        n= recvfrom(s,buff,BUFF_SIZE,0,(struct sockaddr*)&local_addr,&addr_len);
        if(-1 == n){
            perror("recvfrom()");
        }
        printf("Recv %d st message from server:%s\n",times,buff);
    }

    err = setsockopt(s,IPPROTO_IP,IP_DROP_MEMBERSHIP,&mreq,sizeof(mreq));
    close(s);
    return 0;
}

