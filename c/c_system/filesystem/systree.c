/*########################################################
##File Name: systree.c
##Created Time:2015年12月09日 星期三 17时38分50秒
##Author: Norman 
##Description: 实现tree 程序功能打印目录结构
##
##Issue: 
##
##Analyze: 
##          1.打印方法
##              1.1:打印普通文件,同级目录下的(├── 文件名)
##              2.1:打印最后一个文件或目录(└── 文件名/目录)
##              3.1:遍历数组若是1则打印(|    )
##              4.1:若是0 则打(    )
##          2.遍历目录
##              2.1:用数组记录当前是目录还是文件(目录则format[deep++]=1)
##              2.2:deep 记录目录深度(目录则deep++)
##              2.3:组合目录或文件名(全路径)
##              2.4:迭代函数遍历目录判断文件
##                  2.4.1:是目录则继续迭代
##                  2.4.2:文件则打印
##                  2.4.3:软链接打印软链接
##
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>
#include"head.h"
int deep = 0;
char format[1024];

int filter(const struct dirent *d){
    if(strcmp(d->d_name,".")==0||(strcmp(d->d_name,"..")==0))
        return 0;
    return 1;
}

void print_file(const char* path,int last) {
    int i;
    for(i=0;i<deep;i++){
        if(format[i]){
            printf("│   ");
        } else {
            printf("    ");
        }
    }
    if(last){
        printf("└── ");
    } else {
        printf("├── ");
    }
    printf("%s\n",path);
}

int mytree(char* dir){
    int ret,r;
    struct dirent **m;
    struct stat buf;
    char dirname[1024] = {0};
    char lbuf[1024]={0};
    int i,cout;

    cout=scandir(dir,&m,filter,alphasort);
    if(cout < 0){
        perror("scandir");
    } else {
        for(i=0;i<cout;i++){
            strcpy(dirname,dir);
            strcat(dirname,"/");
            strcat(dirname,m[i]->d_name);
            ret = lstat(dirname,&buf);
            if(-1 == ret){
                perror("error");
                return -1;
            }
            switch(buf.st_mode & S_IFMT) {
                case S_IFBLK:
                    print_file(m[i]->d_name,(i==cout-1));
                    break;
                case S_IFCHR:
                    print_file(m[i]->d_name,(i==cout-1));
                    break;
                case S_IFDIR:
                    print_file(m[i]->d_name,(i==cout-1));
                    if(i == cout-1){
                        format[deep++]=0;
                    } else {
                        format[deep++]=1;
                    }
                    mytree(dirname);
                    deep--;
                    break;
                case S_IFIFO:
                    print_file(m[i]->d_name,(i==cout-1));
                    break;
                case S_IFLNK:
                    r=readlink(dirname,lbuf,1024);
                    if(-1==r){
                        perror("readlink");
                    }
                    strcpy(dirname,m[i]->d_name);
                    strcat(dirname," -> ");
                    strcat(dirname,lbuf);
                    print_file(dirname,(i==cout-1));
                    break;
                case S_IFREG:
                    print_file(m[i]->d_name,(i==cout-1));
                    break;
                case S_IFSOCK:
                    print_file(m[i]->d_name,(i==cout-1));
                    break;
                default:
                    break;
            }
        }
        
    }
}


int main(int argc,char *argv[]){
    char *path;
    if(argc ==1){
        path = "./";
    } else {
        path = argv[1];
    }

    mytree(path);


    return 0;
}
