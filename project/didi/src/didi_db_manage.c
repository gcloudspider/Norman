/*########################################################
##File Name: didi_database_manage.c
##Created Time:2015年12月29日 星期二 20时53分42秒
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

int didi_db_init(MYSQL *db,didi_mysql_t didimysql){
    char *sql;
    int res;
    mysql_init(db);
    if(mysql_real_connect(db,didimysql.hostname,didimysql.username,didimysql.passwd,didimysql.dbname,0,NULL,0)){
        zlog_info(c,"didi connection db success!");
        mysql_query(db,"SET NAMES UTF8");
    } else {
        zlog_error(c,"didi connect db failed!");
        if(mysql_error(db)){
            zlog_error(c,"connect error %d:%s",mysql_errno(db),mysql_error(db));
            zlog_error(c,"error: main process exit!");
            exit(2);
        }
    }
}

int didi_db_release(MYSQL *db){
    mysql_close(db);
    zlog_info(c,"didi release db success!");
}

//
//
int query_user_exist(MYSQL *db,const char* telphone){
    char sql[1024];
    MYSQL_FIELD *field;
    MYSQL_RES *ptr;
    MYSQL_ROW result;
    int ret,row,column;
    int i,j;
    sprintf(sql,"select telphone from didiuser where telphone=%s",telphone);
    zlog_info(c,"%s",sql);
    ret = mysql_query(db,sql);
    if(ret != 0){
        zlog_error(c,"query failed!,sql:%s",sql);
        zlog_error(c,"%s",mysql_error(db));
    } else {
        zlog_info(c,"query successful.");
        ptr = mysql_store_result(db);
        if(ptr != NULL){
            row = mysql_num_rows(ptr);
            column = mysql_num_fields(ptr);
            zlog_info(c,"row=%d column=%d",row,column);
            if(row == 0){
                return -1;
            }
            mysql_free_result(ptr);
        }
    }
    return 0;
}

int didi_insert_user(MYSQL* db,didi_user_t user){
    char sql[1024];
    int res;

    mysql_query(db,"SET NAMES UTF8");
    sprintf(sql,"INSERT INTO didiuser(userid,username,nickname,passwd,telphone)values(%d,'%s','%s','%s','%s')",user.userid,user.username,user.nickname,user.passwd,user.telphone);
    zlog_info(c,"%s",sql);
    res = mysql_query(db,sql);
    if(!res){
        zlog_info(c,"insert %lu rows",(unsigned long)mysql_affected_rows(db));
    } else {
        zlog_info(c,"insert error %d:%s",mysql_errno(db),mysql_error(db));
        return -1;
    }
    return 0;
}

void query_online_user(){

}

void query_online_driver(){

}
