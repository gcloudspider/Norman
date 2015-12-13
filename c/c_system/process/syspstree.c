/*########################################################
##File Name: syspstree.c
##Created Time:2015年12月12日 星期六 14时50分31秒
##Author: Norman 
##Description:  实现pstree 
##          struct pronode{
##              struct pronode *parent;
##              struct pronode *child;
##              int pid;
##              int ppid;
##              char pname[100];
##              struct pronode *pre;
##              struct pronode *next;
##          }
##Issue: 
##
##Analyze:  通过扫描/proc文件系统中的status文件来得到
##          1.扫描/proc 得到一个进程信息,将每个进程生成一个链表的节点
##          3.打印链表输出显示
##
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>
#include"head.h"
#define DEFAULTPATH "/proc"
#define DEFAULTFILE "status"

typedef struct ProcNode{
    int pid;
    int ppid;
    char pname[100];
}PN;

int filter(const struct dirent* d){
    if(strcmp(d->d_name,".")==0
       ||(strcmp(d->d_name,"..")==0)
      ||(isalnum(atoi(d->d_name))!=0)){
        return 0;
    }
    return 1;
}

int getpidfromstr(const char* buffer){
    int len;
    char num[10];
    int i,j,ret;

    len = strlen(buffer);
    if(strncmp(buffer,"Pid",3)==0){
        for(i=0;i<len;i++){
            if(buffer[i]>='0'&& buffer[i]<='9') break;
        }
        for(j=0;j<len-1;j++){
            num[j] = buffer[i+j];
            ret = atoi(num);
        }
    } else {
        ret = -1;
    }
    return ret;
}

int getppidfromstr(const char* buffer){
    int len;
    char num[10];
    int i,j,ret;

    len = strlen(buffer);
    if(strncmp(buffer,"PPid",3)==0){
        for(i=0;i<len;i++){
            if(buffer[i]>='0'&& buffer[i]<='9') break;
        }
        for(j=0;j<len-1;j++){
            num[j] = buffer[i+j];
            ret = atoi(num);
        }
    } else {
        ret = -1;
    }
    return ret;
}

void getname(const char* buffer,char *Name){
    int j,k;

    if(strncmp(buffer,"Name",4)==0){
        for(j=4;j<strlen(buffer);j++){
            if(buffer[j]>='a' && buffer[j]<'z')
                break;
        }
        for(k=j;k<strlen(buffer);k++){
            Name[k-j]=buffer[k];
        }
        Name[k-j-1] = '\0';
    }
}


PN* getfileinfo(const char* filepath){
    FILE* fd;
    int ret,size;
    int pid,ppid;
    char buf[1024];
    char Name[1024]={0};
    PN *pro;

    pro = malloc(sizeof(PN));
    if(pro == NULL){
        return NULL;
    }

    fd = fopen(filepath,"r");
    while((fgets(buf,1024,fd))!=NULL){
        getname(buf,Name);
        if(Name != NULL){
            strcpy(pro->pname,Name);
        }
        if((pid = getpidfromstr(buf))!=-1){
           pro->pid = pid; 
        }
        if((ppid = getppidfromstr(buf))!= -1){
            pro->ppid = ppid;
        }
        if((Name !=NULL )&& (pid && ppid) !=0)
            break;
    }
    fclose(fd);

    return pro;
}


int scanprocdir(const char* dir){
    int cout,i;
    char dirpath[256]={0};
    struct dirent **dlist;
    struct stat buf;
    PN *pro[1024];

    cout = scandir(dir,&dlist,filter,alphasort);
    if(cout <0){
        perror("scandir");
    } else {
        for(i=0;i<cout;i++){
            strcpy(dirpath,dir);
            strcat(dirpath,"/");
            strcat(dirpath,dlist[i]->d_name);
            strcat(dirpath,"/");
            stat(dirpath,&buf);
            if(S_ISDIR(buf.st_mode)){
                strcat(dirpath,DEFAULTFILE);
                pro[i] = getfileinfo(dirpath);
            }
        }
        //打印
    }
    return 0;
}

int main(int argc ,char *argv[]) {
    //1.扫描目录得到节点信息
    int ret;
    ret = scanprocdir(DEFAULTPATH);
    return 0;
}



