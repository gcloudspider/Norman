/*########################################################
##File Name: client.c
##Created Time:2016年1月4日 星期一 14时50分56秒
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
#include "../include/user.h"
#include "../include/cjson.h"

int sfd;

void showUserMenu(){
    char ch;
    while(1){
        system("clear");
        printf("##########################################\n");
        printf("##              1.我的订单              ##\n");
        printf("##                                      ##\n");
        printf("##              2.发起订单              ##\n");
        printf("##                                      ##\n");
        printf("##              3.退出登陆              ##\n");
        printf("##########################################\n");
        
        while((ch=getchar())!='\n');
        printf("请输入选择:");
        
        ch = getchar();
        switch(ch){
            case '1':
                
                break;
            case '2':
                break;
            case '3':
                //logout();
                break;
            default:
                break;
        }
    }
}

void print_message_body(cJSON* root){
    cJSON* headnode,*bodynode;
    cJSON* headitem,*bodyitem;

    headnode = didi_getjson_node(&root,"head");
    headitem = didi_getitem_node(&headnode,"packtype");
    if((headitem->valueint) == PACKTYPE_RESPONE){
        headitem = didi_getitem_node(&headnode,"event");
        switch(headitem->valueint){
            case EVENT_REGISTER:
                bodynode = didi_getjson_node(&root,"body");
                bodyitem = didi_getitem_node(&bodynode,"recode");
                if((bodyitem->valueint) == USER_EXIST ){
                    printf("此用户已被注册!3秒后返回主界面!\n");
                } else if((bodyitem->valueint) == REQUER_SUCCESS){
                    printf("此用户注册成功!3秒后返回主界面!\n");
                } else {
                    printf("未知错误!3秒后返回主界面!\n");
                }
                break;
            case EVENT_LOGIN:
                bodynode = didi_getjson_node(&root,"body");
                bodyitem = didi_getitem_node(&bodynode,"recode");
                if((bodyitem->valueint) == USER_NOTEXIST ){
                    printf("输入账号不存在!3秒后返回主界面!\n");
                } else if((bodyitem->valueint) == PASSWD_SUCCESS){
                    printf("登录成功!\n");
                    sleep(3);
                    showUserMenu();
                } else if((bodyitem->valueint) == PASSWD_ERROR){
                    printf("密码验证失败!3秒后返回主界面!\n");
                } else {
                    printf("未知错误!3秒后返回主界面!\n");
                }
                break;
            default:
                break;
        }
    }
    
    sleep(3);
}

void* thread_read(void* argv){
    int ret;
    char buf[1024] = {0};
    cJSON* root;

    while(1){
        ret = read(sfd,buf,1024);
        printf("%s\n",buf);
        root = didi_convert_string(buf);
        break;
    }
    print_message_body(root);
    return argv;
}

void* thread_write(void* argv){
    return argv;
}

void handle_message(){
    pthread_t ttid01,ttid02;
    void* rret;

    pthread_create(&ttid01,NULL,thread_read,(void*)sfd);
    //pthread_create(&ttid02,NULL,thread_write,(void*)sfd);
    pthread_join(ttid01,&rret);
    //pthread_join(ttid02,&rret);
}

void register_user(){
    didi_packmsg_t pg;
    cJSON* root;
    char *s;
    char guid[37];
    random_uuid(guid);
    pg.packbody.signup.usertype = PERSONAL_USER;
    printf("请输入手机号码:");
    scanf("%s",pg.packbody.signup.telphone);
    printf("请输入昵称:");
    scanf("%s",pg.packbody.signup.nickname);
    printf("请输入真实姓名:");
    scanf("%s",pg.packbody.signup.username);
    printf("请输入密码:");
    scanf("%s",pg.packbody.signup.passwd);
    //printf("user=%spasswd=%s\n",pg.packbody.signup.username,pg.packbody.signup.passwd);

    pg.packtype = PACKTYPE_REQUEST;
    pg.event = EVENT_REGISTER;
    strcpy(pg.version,"1.0");
    strcpy(pg.reqId,guid);

    didi_create_regmsg(&root,pg);
    s = didi_ufconvert_json(&root);
    write(sfd,s,strlen(s));
    //printf("%s\n",s);
    handle_message();
    

}

void login(){
    didi_packmsg_t pg;
    cJSON* root;
    char *s;
    char guid[37];
    random_uuid(guid);

    pg.packbody.signup.usertype = PERSONAL_USER;
    printf("请输入手机号:");
    scanf("%s",pg.packbody.signin.telphone);
    printf("请输入登陆密码:");
    scanf("%s",pg.packbody.signin.passwd);
    //printf("user=%spasswd=%s\n",pg.packbody.signin.telphone,pg.packbody.signin.passwd);
    
    pg.packtype = PACKTYPE_REQUEST;
    pg.event = EVENT_LOGIN;
    strcpy(pg.version,"1.0");
    strcpy(pg.reqId,guid);
    
    didi_create_regmsg(&root,pg);
    s = didi_ufconvert_json(&root);
    //printf("%s\n",s);
    write(sfd,s,strlen(s));

    handle_message();
    
}

void logout(){
    
}

void showMenu(){
    char ch;
    while(1){
        system("clear");
        printf("##########################################\n");
        printf("##              个人用户端              ##\n");
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
    int ret;
    ret = init_socket();
    if(-1 == ret){
        return -1;
    }
    showMenu();
}


