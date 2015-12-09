/*########################################################
##File Name: sysmerge.c
##Created Time:2015年12月08日 星期二 20时23分08秒
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
#include<getopt.h>

#define MAXLEN 10
#define VERSION "1.0"

void usage(){
    fprintf(stderr,"Usage: sysmerge <dst filename> <src filename> -n[pos] -t[end] -f[first]\n");
    exit(2);
}

void merge(char* dst,const char* src,int n){
    int fd,fs;
    int ret,wet;
    char buffer[MAXLEN] = {0};

    fs = open(src,O_RDONLY);
    if(-1 == fs){
        perror("error");
        return ;
    }

    fd = open(dst,O_WRONLY);
    if(-1 == fd){
        perror("error");
        return ;
    }
    
    if(n==0){
        ret = lseek(fd,0,SEEK_CUR);
    } else if(n == -1){
        ret = lseek(fd,0,SEEK_END);
    } else {
        ret = lseek(fd,n,SEEK_SET);
    }
 
    if(-1 == ret){
        perror("error");
        return;
    }

    while(1){
        ret = read(fs,buffer,MAXLEN);
        if(-1 == ret){
            perror("error");
            return ;
        }
        
        if(ret < MAXLEN){
            break;
        }
        
        wet = write(fd,buffer,MAXLEN);
        if(-1 == wet){
            perror("error");
            return ;
        }
    }

    if(ret >0){
        buffer[ret] = 0;
        wet = write(fd,buffer,MAXLEN);
        if(-1 == wet){
            perror("error");
            return ;
        }
    }
    close(fs);
    close(fd);

}

int main(int argc,char *argv[]) {
    int ch,n;
    char *src;
    char *dst;
    src = argv[2];
    dst = argv[1];

    while((ch = getopt(argc,argv,"hvn:ft"))!= EOF){
        switch(ch){
            case 'h':
                usage();
                break;
            case 'v':
                printf("%s Version:%s\n",argv[1],VERSION);
                exit(0);
                break;
            case 'n':
                n = atoi(optarg);
                merge(dst,src,n);
                break;
            case 'f':
                merge(dst,src,0);
                break;
            case 't':
                merge(dst,src,-1);
                break;
            default:
                usage();
                break;
        }
    }

    if(argc== 1){
        usage();
    }

    if(argc > 1 && argc < 3){
        usage();
    }


    return 0;
}
