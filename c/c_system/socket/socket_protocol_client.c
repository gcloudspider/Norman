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

/*协议*/
typedef unsigned char u8;
typedef unsigned char u16;
typedef unsigned char u32;

enum msgtype{
    LOGINTYPE = 1,
    TEXTTYPE = 2,
    FILETYPE = 3,
    IMAGETYPE = 4
};

struct msghead{
    u8  msgtype;
    u8  version;
    u16 length;
};

struct chat{
    char msgbody[1024];
};

struct login{
    char name[64];
    char passwd[128];
};

struct file{
    char filename[64];
    char filemd5[128];
};

struct image{
    char imagename[64];
    char imagemd5[128];
};

union body{
    struct login login;
    struct chat wchat;
    struct file file;
    struct image image;
};

struct package{
    struct msghead msghead;
    union body body;
};

/////////////////////////////

void usage(char *argv[]){
    fprintf(stderr,"Usage:%s [-t text] [-l login] [-f file] [-i image]",argv[0]);
}


int main(int argc,char* argv[]){
    int sfd,ret;
    struct sockaddr_in sin;
    struct sockaddr_in cin;
    int len;
    char buf[1024]= {0};
    char ch;
    struct package p;

    if(argc<2){
        usage(argv);
    }
    
    while((ch=getopt(argc,argv,"filt"))!=EOF) {
        switch(ch){
            case 'f':
                p.msghead.msgtype = FILETYPE;
                break;
            case 'i':
                p.msghead.msgtype = IMAGETYPE;
                break;
            case 'l':
                p.msghead.msgtype = LOGINTYPE;
                break;
            case 't':
                p.msghead.msgtype = TEXTTYPE;
                break;
            default:
                break;
        }
    }

    sfd = socket(AF_INET,SOCK_STREAM,0);
    if(sfd == -1){
        perror("socket");
        return -1;
    }

    sin.sin_family = AF_INET;
    sin.sin_port = htons(5002);

    if(inet_pton(AF_INET,"127.0.0.1",&sin.sin_addr.s_addr)<=0){
        perror("inet_pton");
        return -1;
    }

    ret = connect(sfd,(const struct sockaddr*)&sin,(socklen_t)sizeof(sin));
    if(ret == -1){
        perror("connect");
        return -1;
    }

    printf("connect OK!\n");
    while(1){
        printf("input:\n");
        ret = read(0,buf,1024);
        buf[ret] = 0;
        printf("send to \n");
        write(sfd,buf,ret);
    }
    close(sfd);

    return 0;
}
