/*########################################################
##File Name: socket_getnetdevice.c
##Created Time:2015年12月29日 星期二 20时15分07秒
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
#include<sys/types.h>
#include<ifaddrs.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

int main(int argc,const char* argv[]){
    struct ifaddrs * ifAddrStruct = NULL;

    void *tmpAddrPtr = NULL;

    getifaddrs(&ifAddrStruct);

    while(ifAddrStruct != NULL){
        if(ifAddrStruct->ifa_addr->sa_family == AF_INET){   //IPv4
            tmpAddrPtr=&((struct sockaddr_in *)ifAddrStruct->ifa_addr)->sin_addr;
            char addressBuffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET,tmpAddrPtr,addressBuffer,INET_ADDRSTRLEN);
            printf("%s IP Address %s\n",ifAddrStruct->ifa_name,addressBuffer);
        } else if(ifAddrStruct->ifa_addr->sa_family == AF_INET6){  //IPv6
            tmpAddrPtr =&((struct sockaddr_in *)ifAddrStruct->ifa_addr)->sin_addr;
            char addressBuffer[INET6_ADDRSTRLEN];
            inet_ntop(AF_INET6,tmpAddrPtr,addressBuffer,INET6_ADDRSTRLEN);
            printf("%s IP Address %s\n",ifAddrStruct->ifa_name,addressBuffer);
        }

        ifAddrStruct = ifAddrStruct->ifa_next;
    }

    return 0;

}
