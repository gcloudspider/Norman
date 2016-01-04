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

int didi_db_init(MYSQL *db,didi_mysql_t didimysql,zlog_category_t **c){
    char *sql;
    int res;
    mysql_init(db);
    if(mysql_real_connect(db,didimysql.hostname,didimysql.username,didimysql.passwd,didimysql.dbname,0,NULL,0)){
        zlog_info(*c,"didi connection db success!\n");
        mysql_query(db,"SET NAMES UTF8");
    } else {
        zlog_info(*c,"didi connect db failed!\n");
        if(mysql_error(db)){
            zlog_info(*c,"connect error %d:%s\n",mysql_errno(db),mysql_error(db));
            zlog_info(*c,"error: main process exit!");
            exit(2);
        }
    }
}

int didi_db_release(MYSQL *db,zlog_category_t **c){
    mysql_close(db);
    zlog_info(*c,"didi release db success!\n");
}

void query_online_user(){

}

void query_online_driver(){

}
