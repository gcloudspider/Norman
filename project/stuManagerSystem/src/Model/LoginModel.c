/*########################################################
##File Name: LoginModel.c
##Created Time:2015年11月29日 星期日 10时02分01秒
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
#include "LoginModel.h"
#include "../utils/DataConst.h"
#include "../utils/DataStruct.h"
#include "../utils/global.h"
#include "../DataManage/LinkListManage.h"

int onAuthenticationStudentUserId(int userid) {
    STU* pn;
    pn = onSearchStudentLinkList(g_pstudent,userid);
    if(pn == NULL) {
        return -1;
    }

    return 0;
}

int onAuthenticationTeacherUserId(int userid) {
    TEA* pn;
    pn = onSearchTeacherLinkList(g_pteacher,userid);
    if(pn == NULL) {
        return -1;
    }

    return 0;
}

int onAuthenticationAdminUserId(int userid) {
    ADMIN* pn;
    pn = onSearchAdminLinkList(g_padmin,userid);
    if(pn == NULL) {
        return -1;
    }

    return 0;
}

int onAuthenticationStudentPasswd(int userid,char *passwd) {
    STU *pn;
    pn = onSearchStudentLinkList(g_pstudent,userid);
    if(pn == NULL) {
        return -1;
    }
    printf("%p\t%s\n",pn,pn->passwd);

    if(strcmp(pn->passwd,passwd)!=0) {
        return -1;
    }

    return 0;
}

int onAuthenticationTeacherPasswd(int userid,char *passwd) {
    TEA *pn;
    pn = onSearchTeacherLinkList(g_pteacher,userid);
    if(pn == NULL) {
        return -1;
    }
    
    if(strcmp(pn->passwd,passwd)!=0) {
        return -1;
    }

    return 0;
}


int onAuthenticationAdminPasswd(int userid,char *passwd) {
    ADMIN *pn;
    pn = onSearchAdminLinkList(g_padmin,userid);
    if(pn == NULL) {
        return -1;
    }
    
    if(strcmp(pn->passwd,passwd)!=0) {
        return -1;
    }

    return 0;
}
