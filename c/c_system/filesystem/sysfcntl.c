/*########################################################
##File Name: sysfcntl.c
##Created Time:2015年12月08日 星期二 20时11分41秒
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
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<getopt.h>

#define VERSION "1.0"

void usage(){
    fprintf(stderr,"Usage: sysfcntl [-b nonblock]\n");
    exit(2);
}

int setBlock(int isblock){
    int fd;
    int ret;
    char buffer[1024] = {0};
    if(isblock){
        int mode;
        mode = fcntl(0,F_GETFL);
        printf("mode=0x%x\n",mode);
        printf("O_NONBLOCK=0x%x\n",O_NONBLOCK);
        printf("mode|O_NONBLOCK=0x%x\n",mode|O_NONBLOCK);
        mode = mode|O_NONBLOCK;
        fcntl(0,F_SETFL,mode);
        sleep(3);
        read(0,buffer,1024);
        printf("buffer=%s\n",buffer);
    } else {
        ret = read(0,buffer,1024);
        buffer[ret-1] = 0;
        printf("ret = %d\n",ret);
        printf("buffer=\"%s\"\n",buffer);
    }
}

int main(int argc,char* argv[]){
    int ch;
    int n;

    while((ch=getopt(argc,argv,"hvb:"))!=EOF){
        switch(ch){
            case 'h':
                usage();
                break;
            case 'v':
                printf("%s VERSION:%s\n",argv[1],VERSION);
                break;
            case 'b':
                n=atoi(optarg);
                setBlock(n);
                break;
            default:
                usage();
                break;
        }
    }

    if(argc == 1){
        usage();
    }
    return 0;
}
