/*########################################################
##File Name: systemgetsize.c
##Created Time:2015年12月08日 星期二 16时28分21秒
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
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

#define VERSION "1.0"
#define COMMON_OPTSTR "h?VQ"

int getsize(const char* str){
    int fd;
    int ret;

    fd = open(str,O_RDONLY);
    if(-1 == fd){
        perror("error");
        return fd;
    }

    ret = lseek(fd,0,SEEK_END);
    if(-1 == ret){
        perror("error");
        return ret;
    }
    
    close(fd);

    return ret;
}

void usage(){
    fprintf(stderr,
    "Usage: sysgetsize <filename> [-h help] [-V VerSion]\n");
    exit(2);
}

int main(int argc,char *argv[]){
    int ret;
    int ch;
    
    while((ch = getopt(argc,argv,"hV"))!=-1){
        switch(ch){
            case 'h':
                usage();
                break;
            case 'V':
                printf("%s Version:%s\n",argv[0],VERSION);
                exit(0);
                break;
            default:
                usage();
        }
    }

    if(argc == 1) {
        usage();
    }

    if(argc >1) {
        char *filename = argv[1];
        ret = getsize(filename);
        printf("%d\n",ret);
    }

    return 0;
}

