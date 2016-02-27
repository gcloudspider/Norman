/*########################################################
##File Name: udp_broadcast_server.c
##Created Time:2015年12月28日 星期一 21时42分01秒
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
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>
#include<netdb.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

using namespace std;
const char* msg = "hello";

int main(int argc,char* argv[]){
    setvbuf(stdout,NULL,_IONBF,0);
    fflush(stdout);
    if(argc<2){
        
    } else {
        msg = argv[1];
    }

    int sock = -1;
    if((sock = socket(AF_INET,SOCK_DGRAM,0))== -1){
        cout << "socket error"<<endl;
        return false;
    }

    const int opt = 1;
    int nb = 0;
    nb = setsockopt(sock,SOL_SOCKET,SO_BROADCAST,(char*)&opt,sizeof(opt));
    if(-1 == nb){
        cout<<"set socket error...."<<endl;
        return false;
    }

    struct sockaddr_in addrto;
    bzero(&addrto,sizeof(struct sockaddr_in));
    addrto.sin_family = AF_INET;

    addrto.sin_addr.s_addr = htonl(INADDR_BROADCAST);
    addrto.sin_port = htons(6000);
    int nlen = sizeof(addrto);
    while(1){
        sleep(1);

        int ret = sendto(sock,msg,strlen(msg),0,(sockaddr*)&addrto,nlen);
        if(ret <0){
            cout<<"send error...."<<ret <<endl;
        } else {
            printf("send broadcast to client data:%s\n",msg);
        }
    }
    return 0;
}

