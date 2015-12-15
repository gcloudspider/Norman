/*########################################################
##File Name: semapha_p.c
##Created Time:2015年12月15日 星期二 16时55分49秒
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
    struct sembuf s;

    key_t key = 3000;

    id = semget(key,1,IPC_CREAT|0666);
    if(id == -1){
        perror("semget");
        return -1;
    }

    s.sem_num = 0;
    s.sem_op = -1;
    s.sem_flg = 0;
    semop(id,&s,1);

    printf("当前可用资源数=%d\n",semctl(id,0,GETVAL));
    return 0;
}
