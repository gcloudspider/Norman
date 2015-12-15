/*########################################################
##File Name: semapha_writefile.c
##Created Time:2015年12月15日 星期二 19时12分24秒
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

int main(){
    int id;
    int ret;
    key_t key = 4000;

    //创建信号量
    id = semget(key,1,IPC_CREAT|0666);
    if(-1 == id){
        perror("semget");
        return -1;
    }
    //注册信号中有一个
    ret = semctl(id,0,SETVAL,1);
    if(-1 == ret){
        perror("sectl");
        return -1;
    }

    return 0;
}
