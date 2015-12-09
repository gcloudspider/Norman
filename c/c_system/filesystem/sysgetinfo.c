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
    fprintf(stderr,"Usage: sysgetinfo <filename> [-s size] [-b hblock] [-i I/O block] [-l hardlink] [-p pro] [-u uid] [-g gid] [-m modifytime] [-a accesstime] [-c chmodtime]\n");
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
                printf("hardlink:%u\n",(unsigned int)finfo.st_nlink);
                break;
            case 'c':
                printf("laster modify time:%ld\n",finfo.st_ctime);
                break;
            case 'g':
                printf("GUID:%u\n",(unsigned int)finfo.st_gid);
                break;
            case 'h':
                usage();
                break;
            case 'i':
                printf("I/O block:%u\n",(unsigned int)finfo.st_blksize);
                break;
            case 'l':
                printf("link:%u\n",finfo.st_nlink);
                break;
            case 'm':
                printf("Modify time:%ld\n",finfo.st_mtime);
                break;
            case 'p':
                printf("file mode:%u\n",finfo.st_mode);
                break;
            case 's':
                printf("Size:%u\n",(unsigned int)finfo.st_size);
                break;
            case 'u':
                printf("UID:%u\n",finfo.st_uid);
                break;
            case 'v':
                break;
            default:
                usage();
                break;
        }
    }

}
