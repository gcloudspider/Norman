/*########################################################
##File Name: systree.c
##Created Time:2015年12月09日 星期三 17时38分50秒
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
#include"head.h"
char dirname[1024] = {0};


int filter(const struct dirent *d){
    if(strcmp(d->d_name,".")==0||(strcmp(d->d_name,"..")==0))
        return 0;
    return 1;
}

int mytestree(const char* dir){
    struct dirent **m;
    int i,cout;
    cout = scandir(dir,&m,filter,alphasort);
    for(i=0;i<cout;i++){
        struct stat buf;
        int ret;
        ret = lstat(m[i]->d_name,&buf);
        if(-1 == ret){
            perror("error");
            return -1;
        }
        if(S_ISDIR(buf.st_mode)){
            mytestree(m[i]->d_name);
        }
        printf("%s\n",m[i]->d_name);
    }
}

int mytree(char* dir){
    int ret;
    struct dirent **m;
    struct stat buf;
    char lbuf[1024]={0};
    int i,cout;

    cout=scandir(dir,&m,filter,alphasort);
    for(i=0;i<cout;i++){
        strcpy(dirname,dir);
        strcat(dirname,"/");
        strcat(dirname,m[i]->d_name);
        ret = lstat(m[i]->d_name,&buf);
        if(-1 == ret){
            perror("error");
            //printf("%s\n",m[i]->d_name);
            return -1;
        }
        switch(buf.st_mode & S_IFMT) {
            case S_IFBLK:
                break;
            case S_IFCHR:
                break;
            case S_IFDIR:
                strcat(dirname,m[i]->d_name);
                mytree(dirname);
                break;
            case S_IFIFO:
                break;
            case S_IFLNK:
                readlink(m[i]->d_name,lbuf,1024);
                printf("%s -> %s\n",m[i]->d_name,lbuf);
                break;
            case S_IFREG:
                printf("%s\n",m[i]->d_name);
                break;
            case S_IFSOCK:
                break;
            default:
                break;
        }
    }
}


int main(int argc,char *argv[]){
    
    if(argc ==1){
        mytree("./");
        //mytestree("./");
    }

    return 0;
}
