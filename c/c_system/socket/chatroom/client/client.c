/*########################################################
##File Name: client.c
##Created Time:2015年12月26日 星期六 21时34分56秒
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
#include "../include/chatserver.h"
int sfd;
struct package p;

void* thread_read(void* argv){
    int ret;
    char buf[1024] = {0};
    while(1){
        ret = read(sfd,&p.head,sizeof(p.head));
        if(p.head.type == 1){
            ret = read(sfd,&p.body,sizeof(p.body));
            if(p.body.signin.logined == 1){
                write(1,"登陆成功!",strlen("登录成功!"));
            }
        } else {
            printf("error format!\n");
            break;
        }
    }
    return argv;
}

void* thread_write(void* argv){
    write(sfd,&p.head,sizeof(p.head));
    write(sfd,&p.body,sizeof(p.body));
    return argv;
}

void handle_message(){
    pthread_t ttid01,ttid02;
    void* rret;

    pthread_create(&ttid01,NULL,thread_read,(void*)sfd);
    pthread_create(&ttid02,NULL,thread_write,(void*)sfd);
    pthread_join(ttid01,&rret);
    pthread_join(ttid02,&rret);
}

void register_user(){
    char username[64];
    char passwd[128];

    printf("请输入用户名:");
    scanf("%s",username);
    printf("\n");
    printf("请输入密码:");
    scanf("%s",passwd);
    printf("user=%spasswd=%s\n",username,passwd);
    
    memcpy(p.body.signin.username,username,sizeof(username));
    memcpy(p.body.signin.passwd,passwd,sizeof(passwd));
    //p.body.signup.username = username;
    //p.body.signup.passwd = passwd;

    p.head.type = SIGNUP;
    p.head.version = 0;

    handle_message();

}

void login(){
    char username[64];
    char passwd[128];

    printf("请输入登陆用户名:");
    scanf("%s",username);
    printf("\n");
    printf("请输入登陆密码:");
    scanf("%s",passwd);
    printf("user=%spasswd=%s\n",username,passwd);
    
    memcpy(p.body.signin.username,username,sizeof(username));
    memcpy(p.body.signin.passwd,passwd,sizeof(passwd));

    //p.body.signin.username = username;
    //p.body.signin.passwd = passwd;
    p.head.type = SIGNIN;
    p.head.version = 1;

    handle_message();
    
}

void logout(){
    
}

void showMenu(){
    char ch;
    while(1){
        system("clear");
        printf("##########################################\n");
        printf("##              1.用户注册              ##\n");
        printf("##                                      ##\n");
        printf("##              2.用户登录              ##\n");
        printf("##                                      ##\n");
        printf("##              3.退出程序              ##\n");
        printf("##########################################\n");
        printf("请输入选择:");
        ch = getchar();
        switch(ch){
            case '1':
                register_user();
                break;
            case '2':
                login();
                break;
            case '3':
                close(sfd);
                exit(0);
                break;
            default:
                break;
        }
    }
}

int init_socket(){
    int ret,len;

    struct sockaddr_in sin;
    struct sockaddr_in cin;
    void* rret;


    sfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == sfd){
        perror("socket");
        return -1;
    }

    sin.sin_family = AF_INET;
    sin.sin_port = htons(8081);

    if(inet_pton(AF_INET,"127.0.0.1",&sin.sin_addr.s_addr)<=0){
        perror("inet_pton");
        return -1;
    }

    ret = connect(sfd,(const struct sockaddr*)&sin,(socklen_t)sizeof(sin));
    if(-1 == ret){
        perror("connect");
        return -1;
    }
    printf("connect successfuly!\n");

    return 0;
}

int main(){
    init_socket();
    showMenu();
}


