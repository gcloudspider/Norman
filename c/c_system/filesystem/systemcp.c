/*########################################################
##File Name: systemcp.c
##Created Time:2015年12月08日 星期二 14时02分59秒
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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define MAXLEN 10

int mycp(const char* dst,const char* src){
    int fs,fd;
    char buffer[MAXLEN] = {0};
    int ret,rew;

    fs = open(src,O_RDONLY);
    if(-1 == fs){
        perror("error");
        printf("in %d\n",__LINE__);
        return fs;
    }

    fd = open(dst,O_WRONLY|O_CREAT|O_TRUNC,0666);
    if(-1 == fd){
        perror("error");
        printf("in %d\n",__LINE__);
        return fd;
    }


    while(1){
        ret = read(fs,buffer,MAXLEN);
        if(ret<MAXLEN){
            break;
        }
        rew = write(fd,buffer,strlen(buffer));
        if(-1 == rew){
            perror("error");
            printf("in %d\n",__LINE__);
            return rew;
        }
    }

    if(ret >0) {
        buffer[ret] = 0;
        rew = write(fd,buffer,strlen(buffer));
        if(-1 == rew){
            perror("error");
            printf("in %d\n",__LINE__);
            return rew;
        }   
    }

    close(fs);
    close(fd);
    
    return 0;
}

int main(int argc,char* argv[]){
    if(argc < 3) {
        printf("Usage: cp dst src\n");
        return -1;
    }
    int ret;
    char *src = argv[2];
    char *dst = argv[1];
    ret = mycp(dst,src);

    if(-1 == ret){
        printf("copy failed!\n");  
    } else {
        printf("copy success!\n");
    }
    return 0;
}


