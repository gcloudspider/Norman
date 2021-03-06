/*########################################################
##File Name: didi_event_manage.c
##Created Time:2016年01月05日 星期二 14时26分49秒
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
#include "../include/didi.h"

void* didi_event_register(void *argv,void* argv2){
    int ret,userid;
    cJSON* root,*bodynode;
    cJSON* item,*item2;
    cJSON *headnode,*reitem;
    int cfd = (int)argv;
    char buf[1024];
    char *res_package;
    didi_repack_t res_pack;

    strcpy(buf,(char*)argv2);
    zlog_info(c,"ready to read body cfd=%d buf=%s!",cfd,buf);
    
    didi_convert_string(&root,buf);
    zlog_info(c,"root=%p",root);
    //响应
    headnode = didi_getjson_node(root,"head");
    res_pack.packtype = PACKTYPE_RESPONE; 
    res_pack.event = EVENT_REGISTER;
    reitem = didi_getitem_node(headnode,"version");
    strcpy(res_pack.version,reitem->valuestring);
    reitem = didi_getitem_node(headnode,"reqId");
    strcpy(res_pack.reqId,reitem->valuestring);

    bodynode = didi_getjson_node(root,"body");
    zlog_info(c,"body node=%p",bodynode);
    item = didi_getitem_node(bodynode,"telphone");
    item2 = didi_getitem_node(bodynode,"usertype");
    zlog_info(c,"bodynode telphone=%s",item->valuestring);
    //判断用户是否存在
    ret = query_user_exist(&db,item->valuestring,item2->valueint);
    if(-1 == ret){
        zlog_info(c,"%s user not exist!",item->valuestring);
        userid = didi_generate_userid();
        zlog_info(c,"%s user id=%d!",item->valuestring,userid);
        if(item2->valueint == PERSONAL_USER){
            didi_user_t user;
            user.userid = userid;
            strcpy(user.telphone,item->valuestring);
            item = didi_getitem_node(bodynode,"username");
            strcpy(user.username,item->valuestring);
            item = didi_getitem_node(bodynode,"nickname");
            strcpy(user.nickname,item->valuestring);
            item = didi_getitem_node(bodynode,"passwd");
            strcpy(user.passwd,item->valuestring);
            ret = didi_insert_user(&db,user);
            if(-1 == ret){
                res_package = create_respon_package(SERVER_REFUSE,&res_pack,user.telphone);
            } else {
                res_package = create_respon_package(REQUER_SUCCESS,&res_pack,user.telphone);
            }
        } else {
            didi_driver_t driver;
            driver.driverid = userid;
            strcpy(driver.drivertelphone,item->valuestring);
            item = didi_getitem_node(bodynode,"username");
            strcpy(driver.drivername,item->valuestring);
            item = didi_getitem_node(bodynode,"passwd");
            strcpy(driver.driverpasswd,item->valuestring);
            item = didi_getitem_node(bodynode,"carnum");
            strcpy(driver.drivercarnum,item->valuestring);
            ret = didi_insert_driveruser(&db,driver);
            if(-1 == ret){
                res_package = create_respon_package(SERVER_REFUSE,&res_pack,driver.drivertelphone);
            } else {
                res_package = create_respon_package(REQUER_SUCCESS,&res_pack,driver.drivertelphone);
            }
        }

    } else {
        zlog_info(c,"%s user exist!",item->valuestring);
        //用户存在
        res_package = create_respon_package(USER_EXIST,&res_pack,item->valuestring);
    }
    zlog_info(c,"%s",res_package);
    write(cfd,res_package,strlen(res_package));
}

void* didi_event_login(void *argv,void* argv2){
    int ret,userid;
    cJSON* root,*bodynode;
    cJSON* item,*item2,*item3;
    cJSON *headnode,*reitem;
    int cfd = (int)argv;
    char buf[1024];
    char *res_package;
    didi_repack_t res_pack;

    strcpy(buf,(char*)argv2);
    zlog_info(c,"ready to read body cfd=%d buf=%s!",cfd,buf);
    
    didi_convert_string(&root,buf);
    zlog_info(c,"root=%p",root);

    headnode = didi_getjson_node(root,"head");
    res_pack.packtype = PACKTYPE_RESPONE; 
    res_pack.event = EVENT_LOGIN;
    reitem = didi_getitem_node(headnode,"version");
    strcpy(res_pack.version,reitem->valuestring);
    reitem = didi_getitem_node(headnode,"reqId");
    strcpy(res_pack.reqId,reitem->valuestring);

    bodynode = didi_getjson_node(root,"body");
    zlog_info(c,"body node=%p",bodynode);
    item = didi_getitem_node(bodynode,"telphone");
    item2 = didi_getitem_node(bodynode,"passwd");
    item3 = didi_getitem_node(bodynode,"usertype");
    zlog_info(c,"bodynode telphone=%s",item->valuestring);
    //查询用户是否存在
    ret = query_user_exist(&db,item->valuestring,item3->valueint);
    if(ret != -1){
        ret = didi_query_passwd(&db,item->valuestring,item2->valuestring,item3->valueint);
        if(-1 == ret){
            zlog_warn(c,"user login failed!");
            res_package = create_respon_package(PASSWD_ERROR,&res_pack,item->valuestring);
        }else {
            zlog_info(c,"user login successful!");
            res_package = create_respon_package(PASSWD_SUCCESS,&res_pack,item->valuestring);
            //添加用户到在线链表
            union online_user user;
            query_user_info(&db,&user,item3->valueint,item->valuestring);
            zlog_info(c,"add user=%d to linklist",user.comuser.userid);
            didi_adduser_cache(cfd,item3->valueint,&user);
        }
    }else {
        zlog_warn(c,"user not exist!");
        res_package = create_respon_package(USER_NOTEXIST,&res_pack,item->valuestring);
    }
    zlog_info(c,"%s",res_package);
    write(cfd,res_package,strlen(res_package));
}

void* didi_event_logout(void *argv,void* argv2){
    int ret,userid;
    cJSON* root,*bodynode;
    cJSON* item,*item2;
    cJSON *headnode,*reitem;
    int cfd = (int)argv;
    char buf[1024];
    char *res_package;
    didi_repack_t res_pack;

    strcpy(buf,(char*)argv2);
    zlog_info(c,"ready to read body cfd=%d buf=%s!",cfd,buf);
    
    didi_convert_string(&root,buf);
    zlog_info(c,"root=%p",root);
    
    headnode = didi_getjson_node(root,"head");
    res_pack.packtype = PACKTYPE_RESPONE; 
    res_pack.event = EVENT_LOGOUT;
    reitem = didi_getitem_node(headnode,"version");
    strcpy(res_pack.version,reitem->valuestring);
    reitem = didi_getitem_node(headnode,"reqId");
    strcpy(res_pack.reqId,reitem->valuestring);

    bodynode = didi_getjson_node(root,"body");
    zlog_info(c,"body node=%p",bodynode);
    item = didi_getitem_node(bodynode,"telphone");
    item2 = didi_getitem_node(bodynode,"usertype");
    zlog_info(c,"bodynode telphone=%s",item->valuestring);
    ret = didi_del_cache(item2->valueint,item->valuestring);
    if(-1 == ret){
        zlog_info(c,"del link list failed!");   
        res_package = create_respon_package(SERVER_REFUSE,&res_pack,item->valuestring);
    } else {
        zlog_info(c,"del link list success!");   
        res_package = create_respon_package(REQUER_SUCCESS,&res_pack,item->valuestring);
    }
    zlog_info(c,"%s",res_package);
    write(cfd,res_package,strlen(res_package));
}

void* didi_event_query(void *argv,void* argv2){
    int ret,userid;
    cJSON* root,*bodynode;
    cJSON* item,*item2,*item3;
    cJSON *headnode,*reitem;
    int cfd = (int)argv;
    char buf[1024];
    char *res_package;
    didi_repack_t res_pack;

    strcpy(buf,(char*)argv2);
    zlog_info(c,"ready to read body cfd=%d buf=%s!",cfd,buf);
    
    didi_convert_string(&root,buf);
    zlog_info(c,"root=%p",root);
    
    headnode = didi_getjson_node(root,"head");
    res_pack.packtype = PACKTYPE_RESPONE; 
    res_pack.event = EVENT_QUERY;
    reitem = didi_getitem_node(headnode,"version");
    strcpy(res_pack.version,reitem->valuestring);
    reitem = didi_getitem_node(headnode,"reqId");
    strcpy(res_pack.reqId,reitem->valuestring);

    bodynode = didi_getjson_node(root,"body");
    zlog_info(c,"body node=%p",bodynode);
    item = didi_getitem_node(bodynode,"telphone");
    item2 = didi_getitem_node(bodynode,"usertype");
    zlog_info(c,"bodynode telphone=%s",item->valuestring);

    res_package = didi_respond_history(&res_pack,item2->valueint,item->valuestring);
    zlog_info(c,"%s",res_package);

    write(cfd,res_package,strlen(res_package));
}

void* didi_event_mpasswd(void *argv,void* argv2){
    int ret,userid;
    cJSON* root,*bodynode;
    cJSON* item,*item2,*item3;
    cJSON *headnode,*reitem;
    int cfd = (int)argv;
    char buf[1024];
    char *res_package;
    didi_repack_t res_pack;

    strcpy(buf,(char*)argv2);
    zlog_info(c,"ready to read body cfd=%d buf=%s!",cfd,buf);
    
    didi_convert_string(&root,buf);
    zlog_info(c,"root=%p",root);
    
    headnode = didi_getjson_node(root,"head");
    res_pack.packtype = PACKTYPE_RESPONE; 
    res_pack.event = EVENT_MPASSWD;
    reitem = didi_getitem_node(headnode,"version");
    strcpy(res_pack.version,reitem->valuestring);
    reitem = didi_getitem_node(headnode,"reqId");
    strcpy(res_pack.reqId,reitem->valuestring);

    bodynode = didi_getjson_node(root,"body");
    zlog_info(c,"body node=%p",bodynode);
    item = didi_getitem_node(bodynode,"telphone");
    item2 = didi_getitem_node(bodynode,"usertype");
    zlog_info(c,"bodynode telphone=%s",item->valuestring);
    item3 = didi_getitem_node(bodynode,"passwd");
    
    ret = didi_update_passwd(&db,item2->valueint,item->valuestring,item3->valuestring);
    if(-1 == ret){
        zlog_info(c,"update user passwd failed!");
        res_package = create_respon_package(SERVER_REFUSE,&res_pack,item->valuestring);
    } else {
        zlog_info(c,"update user passwd successful!");
        res_package = create_respon_package(REQUER_SUCCESS,&res_pack,item->valuestring);
    }
    zlog_info(c,"%s",res_package);
    write(cfd,res_package,strlen(res_package));
}

void* didi_event_order(void* argv,void* argv2){
    int ret,userid;
    cJSON* root,*bodynode;
    cJSON* item,*item2,*item3,*item4,*item5;
    cJSON *headnode,*reitem;
    int cfd = (int)argv;
    char buf[1024];
    char *res_package;
    didi_repack_t res_pack;

    strcpy(buf,(char*)argv2);
    zlog_info(c,"ready to read body cfd=%d buf=%s!",cfd,buf);
    
    didi_convert_string(&root,buf);
    zlog_info(c,"root=%p",root);
    
    headnode = didi_getjson_node(root,"head");
    res_pack.packtype = PACKTYPE_RESPONE; 
    res_pack.event = EVENT_ORDER;
    reitem = didi_getitem_node(headnode,"version");
    strcpy(res_pack.version,reitem->valuestring);
    reitem = didi_getitem_node(headnode,"reqId");
    strcpy(res_pack.reqId,reitem->valuestring);

    bodynode = didi_getjson_node(root,"body");
    zlog_info(c,"body node=%p",bodynode);
    item = didi_getitem_node(bodynode,"userphone");
    item2 = didi_getitem_node(bodynode,"usertype");
    zlog_info(c,"bodynode user phone=%s",item->valuestring);
    item3 = didi_getitem_node(bodynode,"starting");
    item4 = didi_getitem_node(bodynode,"destination");
    item5 = didi_getitem_node(bodynode,"starttime");
    int orderid=didi_generate_userid();

    //创建订单
    ret = didi_create_order(orderid,item->valuestring,item3->valuestring,item4->valuestring,item5->valuestring);

    if(-1 == ret){
        zlog_info(c,"user add order failed!");
        res_package = create_ordspond_package(ORDER_ERROR,&res_pack,item->valuestring,orderid,item3->valuestring,item4->valuestring);
    } else {
        zlog_info(c,"user add order successful!");
        res_package = create_ordspond_package(ORDER_SUCCESS,&res_pack,item->valuestring,orderid,item3->valuestring,item4->valuestring);
    }
    zlog_info(c,"%s",res_package);
    write(cfd,res_package,strlen(res_package));
    //将订单发给每个在线司机
    didi_order_broadcast(res_package);
}


void* didi_event_taketoken(void* argv,void* argv2){
    int ret,userid;
    cJSON* root,*bodynode;
    cJSON* item,*item2,*item3,*item4,*item5;
    cJSON *headnode,*reitem;
    int cfd = (int)argv;
    char buf[1024];
    char *res_package,*res_driver;
    didi_repack_t res_pack;

    strcpy(buf,(char*)argv2);
    zlog_info(c,"ready to read body cfd=%d buf=%s!",cfd,buf);
    
    didi_convert_string(&root,buf);
    zlog_info(c,"root=%p",root);
    
    headnode = didi_getjson_node(root,"head");
    res_pack.packtype = PACKTYPE_RESPONE; 
    res_pack.event = EVENT_TAKETOKEN;
    reitem = didi_getitem_node(headnode,"version");
    strcpy(res_pack.version,reitem->valuestring);
    reitem = didi_getitem_node(headnode,"reqId");
    strcpy(res_pack.reqId,reitem->valuestring);
    
    bodynode = didi_getjson_node(root,"body");
    zlog_info(c,"body node=%p",bodynode);
    item = didi_getitem_node(bodynode,"telphone");
    item2 = didi_getitem_node(bodynode,"usertype");
    zlog_info(c,"bodynode user phone=%s",item->valuestring);
    item3 = didi_getitem_node(bodynode,"orderid");

    ret = didi_getorder_cache(item3->valueint);
    if(-1 == ret){
        zlog_info(c,"order been another taketoken!");
        res_package = create_takespond_package(TAKETOKEN_ERROR,&res_pack,item->valuestring,item3->valueint);
    } else {
        //抢单成功
        zlog_info(c,"taktoken successful!");
        res_package = create_takespond_package(TAKETOKEN_SUCCESS,&res_pack,item->valuestring,item3->valueint);
        //将节点从链表中脱离放入新链表中
        didi_separate_cache(item->valuestring,item3->valueint);
        //通知用户
        int userfd = didi_getcfd_cache(PERSONAL_USER,item3->valueint);
        zlog_info(c,"user fd = %d",userfd);
        //获取司机的信息
        didi_online_t *pn;
        pn = didi_getdriver_cache(item->valuestring);
        zlog_info(c,"didi driver online info=%p",pn);
        res_driver = create_drispond_package(TAKETOKEN_SUCCESS,&res_pack,pn);
        zlog_info(c,"%s",res_driver);
        write(userfd,res_driver,strlen(res_driver));
    }
    zlog_info(c,"%s",res_package);
    write(cfd,res_package,strlen(res_package));

}

void* didi_event_ordfin(void* argv,void* argv2){
    int ret,userid;
    cJSON* root,*bodynode;
    cJSON* item,*item1,*item2;
    cJSON *headnode,*reitem;
    int cfd = (int)argv;
    char buf[1024];
    char *res_package,*res_driver;
    didi_repack_t res_pack;

    strcpy(buf,(char*)argv2);
    zlog_info(c,"ready to read body cfd=%d buf=%s!",cfd,buf);
    
    didi_convert_string(&root,buf);
    zlog_info(c,"root=%p",root);
    
    headnode = didi_getjson_node(root,"head");
    res_pack.packtype = PACKTYPE_RESPONE; 
    res_pack.event = EVENT_ORDFIN;
    reitem = didi_getitem_node(headnode,"version");
    strcpy(res_pack.version,reitem->valuestring);
    reitem = didi_getitem_node(headnode,"reqId");
    strcpy(res_pack.reqId,reitem->valuestring);
    
    bodynode = didi_getjson_node(root,"body");
    zlog_info(c,"body node=%p",bodynode);
    item = didi_getitem_node(bodynode,"orderid");
    item1 = didi_getitem_node(bodynode,"payment");
    item2 = didi_getitem_node(bodynode,"arrivaltime");
    
    ret = didi_create_orderhistory(item->valueint,item1->valuestring,item2->valuestring);

    if(-1 == ret){
        zlog_info(c,"create order history failed!");   
    } else {
        zlog_info(c,"create order history successfuly!");
    }
}
