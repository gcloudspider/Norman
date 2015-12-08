/*########################################################
##File Name: systemaccess.c
##Created Time:2015年12月08日 星期二 16时20分00秒
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
#include<unistd.h>

int myaccess(const char* str,int mode){
    int ret;
    ret = access(str,mode);
    return ret;
}

int main(){
    int ret;
    ret = myaccess("aa.txt",F_OK);
    if(0==ret) {
        printf("file exist\n");
    } else {
        printf("file not exist\n");
    }

    ret = myaccess("a.txt",R_OK);
    if(0==ret) {
        printf("file readed\n");
    } else {
        printf("file not readed\n");
    }

    ret = myaccess("a.txt",W_OK);
    if(0==ret) {
        printf("file writed\n");
    } else {
        printf("file not writed\n");
    }
    
    ret = myaccess("a.txt",X_OK);
    if(0==ret) {
        printf("file ex\n");
    } else {
        printf("file not ex\n");
    }
    return 0;
}
