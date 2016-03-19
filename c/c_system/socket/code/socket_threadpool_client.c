/*########################################################
##File Name: socket_client.c
##Created Time:2015年12月21日 星期一 15时49分12秒
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
#include<netinet/in.h>

typedef enum {false = 0, true = 1} bool;

struct sockaddr_in sin;
int sfd;

void usage(char *argv[]){
    fprintf(stderr,"Usage: %s [-h serverip] [-p port] [-w wchat <string>] [-u upload] [-d download] [filename]\n",argv[0]);
    exit(2);
}

int connect_to_server(const char* server_ip,int server_port){
    int ret;

    sfd = socket(AF_INET,SOCK_STREAM,0);
    if(sfd == -1){
        perror("socket");
        return -1;
    }

    sin.sin_family = AF_INET;
    sin.sin_port = htons(server_port);

    printf("%s\n",server_ip);
    if(inet_pton(AF_INET,server_ip,&sin.sin_addr.s_addr)<=0){
        perror("inet_pton");
        return -1;
    }

    ret = connect(sfd,(const struct sockaddr*)&sin,(socklen_t)sizeof(sin));
    if(ret == -1){
        perror("connect");
        return -1;
    }

    printf("connect OK!\n");

    return 0;
}

int main(int argc,char *argv[]){
    int ret;
    char buf[1024]= {0};
    int ch;
    char* server_ip;
    int server_port;
    bool isupload,download,wchat;

    if(argc < 2){
        usage(argv);
    }

    while((ch=getopt(argc,argv,"d:h:p:u:w:"))!=EOF){
        switch(ch){
            case 'd':
                download = true;
                break;
            case 'h':
                server_ip = argv[1];
                break;
            case 'p':
                server_port = atoi(argv[2]);
                break;
            case 'u':
                isupload = true;
                break;
            case 'w':
                wchat = true;
                break;
            default:
                usage(argv);
                break;
        }
    }

    ret = connect_to_server(server_ip,server_port);
    if(-1 == ret){
        printf("connect to server failed!\n");
        return -1;
    }
    
    if(download){
        printf("download file!\n");   
    }
    if(isupload){
        printf("upload file!\n");
    }
    if(wchat){
        while(1){
            printf("input:\n");
            ret = read(0,buf,1024);
            buf[ret] = 0;
            printf("send to \n");
            write(sfd,buf,ret);
        }
    }

    close(sfd);

    return 0;
}
