/*########################################################
##File Name: AppController.c
##Created Time:2015年11月30日 星期一 08时44分18秒
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
#include "AppController.h"
#include "../Model/InitAppModel.h"
#include "../Model/ReleaseAppModel.h"

void InitAppController() {
    InitStudentModel();
    InitTeacherModel();
    InitAdminModel();
    return ;
}

void ReleaseAppController() {
    ReleaseAllModel();
    return ;
}

