/*########################################################
##File Name: sysgetinfo.c
##Created Time:2015年12月09日 星期三 09时08分24秒
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


void usage(){
    fprintf(stderr,"Usage: sysgetinfo <filename> [-s size] [-b hblock] [-i I/O block] [-l hardlink] [-p pro] [-u uid] [-g git] [-m modifytime] [-a accesstime] [-c chmodtime]\n");
    exit(2);
}

int getfileinfo(const char* str,struct stat *fileinfo){
    
    stat(str,fileinfo);

}

int main(int argc,char* argv[]){
    int ch;
    int ret;

    if(argc <2){
        usage();
    }
    struct stat finfo;
    getfileinfo(argv[1],&finfo);

    while((ch=getopt(argc,argv,"abcghilmpsuv"))!=EOF){
        switch(ch){
            case 'a':
                printf("Access Time: %u\n",(unsigned int)finfo.st_atime);
                break;
            case 'b':
                break;
            case 'c':
                break;
            case 'g':
                break;
            case 'h':
                usage();
                break;
            case 'i':
                break;
            case 'l':
                break;
            case 'm':
                break;
            case 'p':
                break;
            case 's':
                printf("Size:%u\n",(unsigned int)finfo.st_size);
                break;
            case 'u':
                break;
            case 'v':
                break;
            default:
                usage();
                break;
        }
    }

}
