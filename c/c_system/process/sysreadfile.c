/*########################################################
##File Name: sysreadfile.c
##Created Time:2015年12月12日 星期六 14时22分56秒
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
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>

void usage(){
    fprintf(stderr,"Usage: sysreadfile <filename>\n");
    exit(2);
}

int main(int argc,char* argv[]){
    int fd,ret;
    char buf[10]={0};
    if(argc <2 ){
        usage();
    }

    fd = fork();    //fork在open前打开则是读取内容相同
    ret = open(argv[1],O_RDONLY);
    if(-1 == ret){
        perror("open");
        return -1;
    }

    //fd = fork();   //fork在open后打开读取内容不相同
    if(fd >0){
        sleep(1);
        read(ret,buf,5);
        printf("parent get buffer=%s\n",buf);
        exit(0);

    } else if(fd ==0){
        sleep(2);
        read(ret,buf,5);
        printf("child get buffer=%s\n",buf);
        exit(0);
        
    } else {
        perror("fork");
        return -1;
    }
    return 0;
}

