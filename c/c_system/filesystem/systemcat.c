/*########################################################
##File Name: systemopen.c
##Created Time:2015年12月08日 星期二 10时28分10秒
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
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#define MAXLEN 10
#define VERSION "1.0"

void mycat(int fd){
    char buffer[MAXLEN] = {0};
    int ret;
    int i;

    while(1){
        ret = read(fd,buffer,MAXLEN);
        if(ret < MAXLEN){
            break;
        }
        printf("%s",buffer);
    }

    if(ret >0) {
        buffer[ret] = 0;
        printf("%s",buffer);
    }
}

int isHere(const char* filename){
    int fd;
    fd = open(filename,O_RDONLY);
    if(-1 == fd){
        printf("errno=%d\n",errno);
        perror("error:");
        return fd;
    }
    //printf("%d\n",fd);    0:stdin  1:stdout  2: stderr
    //close(fd);
    return fd;
}

void usage(){
    fprintf(stderr,"Usage: systemcat <filename>\n");
    exit(2);
}

int main(int argc,char *argv[]){
    int ret;
    int ch;
    while((ch =getopt(argc,argv,"hV"))!=EOF){
        switch(ch){
            case 'h':
                usage();
                break;
            case 'V':
                printf("%s Version:%s\n",argv[1],VERSION);
                exit(0);
                break;
            default:
                usage();
                break;
        }
    }

    if(argc == 1){
        usage();
    }

    if(argc >1){
        char *str = argv[1];
        ret = isHere(str);
        if(-1==ret){
            printf("file not exist!\n");
        } else {
            mycat(ret);
            close(ret);
        }
    }

    return 0;
}
