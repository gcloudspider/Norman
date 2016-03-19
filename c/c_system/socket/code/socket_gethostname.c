/*########################################################
##File Name: socket_gethostname.c
##Created Time:2015年12月29日 星期二 20时07分53秒
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
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc,char* argv[]) {
    struct hostent *hent;  //结构体 netdb.h
    int i;

    if(argc < 2){
        printf("Usage:commane argv\n");
        return -1;
    }

    hent = gethostbyname(argv[1]);

    printf("hostname:%s\n address list:\n",hent->h_name);
    for(i=0;hent->h_addr_list[i];i++){
        printf("%s\n",inet_ntoa(*(struct in_addr*)(hent->h_addr_list[i])));
    }
    return 0;
}
