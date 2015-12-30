/*########################################################
##File Name: test_database.c
##Created Time:2015年12月30日 星期三 10时56分53秒
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
#include <mysql/mysql.h>

#define USERNAME "dadabus"
#define PASSWD   "dada123456"
#define DBNAME   "dadabus"


int main(int argc,char* argv[]){
    MYSQL my_connection;
    char *sql;
    int res;

    mysql_init(&my_connection);
    if(mysql_real_connect(&my_connection,"localhost",USERNAME,PASSWD,DBNAME,0,NULL,0)){
        printf("connection success\n");
        sql = "INSERT INTO dadauser(userid,username,nickname,passwd,telphone)values(1001,'遝','norman','123456','15012960449')";
        res = mysql_query(&my_connection,sql);
        if(!res){
            printf("Inserted %lu rows\n",(unsigned long)mysql_affected_rows(&my_connection));
        } else {
            fprintf(stderr,"Insert error %d:%s\n",mysql_errno(&my_connection),mysql_error(&my_connection));
        }
        mysql_close(&my_connection);
    } else {
        fprintf(stderr,"connect failed!\n");
        if(mysql_error(&my_connection)){
            fprintf(stderr,"connection error %d:%s\n",mysql_errno(&my_connection),mysql_error(&my_connection));
        }
    }
}

