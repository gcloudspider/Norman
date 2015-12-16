/*########################################################
##File Name: semapha_park.c
##Created Time:2015年12月15日 星期二 21时07分30秒
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
int seminit(key_t key){
    int id;
    int ret;

    id = semget(key,1,IPC_CREAT|0666);
    if(-1 == id){
        perror("semget");
        return id;
    }
    ret = semctl(id,0,SETVAL,30);
    if(-1 == ret){
        perror("semctl");
        return ret;
    }
    printf("初始化信号量%d成功!\n",key);
    return id;
}

int getvalue(key_t key){
    int id;
    int ret;
    id = semget(key,1,IPC_CREAT|0666);
    if(-1 == id){
        perror("semget");
        return id;
    }
    ret = semctl(id,0,GETVAL);
    if(-1 == ret){
        printf("资源不足,请等待...\n");
    }
    printf("信号量队列中还有%d资源可分配!\n",ret);
    return ret;
}

void usage(const char* pname){
    fprintf(stderr,"Usage: %s [-d Init] [-o out] [-i in] [-l list]\n",pname);
    exit(2);
}

int getsem(int key,int i){
    int id;
    int ret;
    char name[20];
    struct sembuf s;
    id = semget(key,1,IPC_CREAT|0666);
    if(-1 == id){
        perror("semget");
        return id;
    }
    
    s.sem_num = 0;
    s.sem_op = -1;
    s.sem_flg = 0;
    semop(id,&s,1);
    printf("申请1个资源成功!\n");
    
    sprintf(name,"file_%d",i);
    ret = creat(name,O_RDWR);
    if(-1 == ret){
        perror("creat");
        return ret;
    }

    printf("创建文件%s成功!!\n",name);
}

int semrelease(int key,int i){
    int id;
    int ret,num;
    char name[20];
    struct sembuf s;
    id = semget(key,1,IPC_CREAT|0666);
    if(-1 == id){
        perror("semget");
        return id;
    }
    num = getvalue(key);
    if(num < 30){
        s.sem_num = 0;
        s.sem_op = 1;
        s.sem_flg = 0;
        semop(id,&s,1);
        printf("释放1个资源成功!\n");
        sprintf(name,"file_%d",i);
        ret = remove(name);
        if(-1 == ret){
            perror("remove");
            return ret;
        }
        printf("删除文件%s成功!\n",name);
    } else {
        printf("资源到达上限,无需再释放!");
    }

}

int main(int argc,char* argv[]){
    int id;
    int ret;
    int i;
    key_t key = 8000;
    int ch;

    if(argc <2){
        usage(argv[0]);
    }

    while((ch = getopt(argc,argv,"dilo"))!=EOF){
        switch(ch){
            case 'd':
                id = seminit(key);
                break;
            case 'i':{
                for(i=0;i<30;i++){
                sleep(1);
                getsem(key,i);
                }
            }
                break;
            case 'o':
                for(i=0;i<30;i++){
                    sleep(2);
                    semrelease(key,i);   
                }
                break;
            case 'l':
                getvalue(key);
                break;
            default:
                break;
        }
    }

    return 0;
}
