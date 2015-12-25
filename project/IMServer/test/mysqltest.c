/*########################################################
##File Name: mysqltest.c
##Created Time:2015年12月25日 星期五 13时42分03秒
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
#include<stdlib.h>

#include "mysql/mysql.h"

int main(){
    const char *host = "127.0.0.1";
    const char *user = "root";
    const char *pass = "ak476660685";
    const char *db = "mysql";

    MYSQL mysql;
    MYSQL_RES *rs;
    MYSQL_ROW row;
    mysql_init(&mysql);

    if(!mysql_real_connect(&mysql,host,user,pass,db,0,NULL,0)){
        printf("数据库连接失败:%s\n",mysql_error(&mysql));
    } else {
        printf("数据库连接成功!\n");
    }

    char *sql = "select host,user from user order by rand()";
    if(mysql_query(&mysql,sql)!=0){
        printf("%s",mysql_errno(&mysql),mysql_error(&mysql));
    }
    rs = mysql_store_result(&mysql);
    while((row= mysql_fetch_row(rs))){
        printf("%s----%s\n",row[0],row[1]);
    }
    mysql_free_result(rs);
    mysql_close(&mysql);
    return 1;
}
