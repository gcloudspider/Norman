/*########################################################
##File Name: ReleaseAppModel.c
##Created Time:2015年11月30日 星期一 08时36分30秒
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
#include "../utils/global.h"
#include "../utils/DataStruct.h"
#include "ReleaseAppModel.h"
#include "../DataManage/FileManage.h"
#include "../DataManage/LinkListManage.h"

void ReleaseAllModel() {
    size_t s_ret,t_ret,a_ret;
    size_t s_retu,t_retu,a_retu;

    STU* pstu = g_pstudent;
    TEA* ptea = g_pteacher;
    ADMIN* padmin = g_padmin;
    //printf("%p\n",pstu);
    //printf("%p\n",ptea);
    //printf("%p\n",padmin);

    //TODO:将链表内容回写文件
    s_ret = WriteDataToStudentFile(&pstu);
    if(s_ret == 0) {
        printf("write student file sucessful!\n");    
    } else {
        printf("write student file failed!\n");    
    }

    t_ret = WriteDataToTeacherFile(&ptea);
    if(t_ret == 0) {
        printf("write teacher file sucessful!\n");    
    } else {
        printf("write teacher file failed!\n");    
    }

    a_ret = WriteDataToAdminFile(&padmin);
    if(a_ret == 0) {
        printf("write admin file sucessful!\n");    
    } else {
        printf("write admin file failed!\n");    
    }


    //TODO:释放链表
    if(!s_ret && !t_ret && !a_ret) {
        s_retu = ReleaseStudentLinkList(pstu);
        if(s_retu == 0) {
            printf("release student link list successful!\n");
        } else {
            printf("release student link list failed!\n");
        } 

        t_retu = ReleaseTeacherLinkList(ptea);
        if(t_retu == 0) {
            printf("release teacher link list successful!\n");
        } else {
            printf("release teacher link list failed!\n");
        }

        a_retu = ReleaseAdminLinkList(padmin);
        if(a_retu == 0) {
            printf("release admin link list successful!\n");
        } else {
            printf("release admin link list failed!\n");
        }
        //printf("release double link list!\n");
    }
    printf("release app finished !\n");
    return ;
}
