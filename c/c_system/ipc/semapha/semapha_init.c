/*########################################################
##File Name: semapha_op.c
##Created Time:2015年12月15日 星期二 16时26分45秒
##Author: Norman 
##Description: 
##
##Issue: 
##
##Analyze: 
##
##      权限                value | value | value |
##      一维数组指针  ----> 0     |  3    |  5    |
##      个数 3
##
##
##
##
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>
#include "head.h"
int semget(key_t key,int nsems,int semflg);


int main(){
    int id;
    int ret;
    key_t key =3000;

    /*
    * key 信号量的共享键值
    * nsems 含多少个数组()
    * semflg IPC_CREAT 若没有则创建 0666权限
    * semget 没有则创建，有则获取返回id号
    * */
    id = semget(key,2,IPC_CREAT|0666);
    if(id == -1){
        perror("semget 2000");
        return -1;
    }
    ret = semctl(id,1,SETVAL,4);
    if(-1 == ret){
        perror("semctl");
        return -1;
    }

    return 0;
}
