/*########################################################
##File Name: model.c
##Created Time:2016年01月06日 星期三 16时55分54秒
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

    s= didi_ufconvert_json(&root);
    printf("%s\n",s);
    write(sfd,s,strlen(s));

    handle_message();
}   


void logout(){
    didi_packmsg_t pg;
    cJSON* root;
    char *s;
    char guid[37];
    random_uuid(guid);

    pg.packbody.signout.usertype = PERSONAL_USER;
    strcpy(pg.packbody.signout.telphone,loginuser);
    
    pg.packtype = PACKTYPE_REQUEST;
    pg.event = EVENT_LOGOUT;
    strcpy(pg.version,"1.0");
    strcpy(pg.reqId,guid);
    didi_create_regmsg(&root,pg);

    s= didi_ufconvert_json(&root);
    printf("%s\n",s);
    write(sfd,s,strlen(s));

    handle_message();
}

void modifypasswd(){
    didi_packmsg_t pg;
    cJSON* root;
    char *s;
    char guid[37];
    random_uuid(guid);
    printf("请输入新密码:");
    scanf("%s",pg.packbody.mpasswd.newpasswd);

    pg.packbody.mpasswd.usertype = PERSONAL_USER;
    strcpy(pg.packbody.mpasswd.telphone,loginuser);
    
    pg.packtype = PACKTYPE_REQUEST;
    pg.event = EVENT_MPASSWD;
    strcpy(pg.version,"1.0");
    strcpy(pg.reqId,guid);
    didi_create_regmsg(&root,pg);

    s= didi_ufconvert_json(&root);
    printf("%s\n",s);
    write(sfd,s,strlen(s));

    handle_message();
}

void addorder(){
    didi_packmsg_t pg;
    cJSON* root;
    char s[32];
    char *req;
    char guid[37];
    random_uuid(guid);
    generate_curtime(s);
    printf("请输入起始地:");
    scanf("%s",pg.packbody.order.starting);
    printf("请输入目的地址:");
    scanf("%s",pg.packbody.order.destination);
    
    pg.packbody.order.usertype = PERSONAL_USER;
    strcpy(pg.packbody.order.userphone,loginuser);
    strcpy(pg.packbody.order.starttime,s);
    
    pg.packtype = PACKTYPE_REQUEST;
    pg.event = EVENT_ORDER;
    strcpy(pg.version,"1.0");
    strcpy(pg.reqId,guid);
    didi_create_regmsg(&root,pg);

    req= didi_ufconvert_json(&root);
    printf("%s\n",req);
    write(sfd,req,strlen(req));

    handle_order();

}

void query_order(){
    didi_packmsg_t pg;
    cJSON* root;
    char s[32];
    char *req;
    char guid[37];
    random_uuid(guid);
    generate_curtime(s);
    
    pg.packbody.query.usertype = PERSONAL_USER;
    strcpy(pg.packbody.query.telphone,loginuser);
    pg.packtype = PACKTYPE_REQUEST;
    pg.event = EVENT_QUERY;
    strcpy(pg.version,"1.0");
    strcpy(pg.reqId,guid);
    didi_create_regmsg(&root,pg);

    req= didi_ufconvert_json(&root);
    printf("%s\n",req);
    write(sfd,req,strlen(req));

    handle_message();
}
