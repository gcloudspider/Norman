/*########################################################
##File Name: CpuSimpleFactory.cpp
##Created Time:2016年01月12日 星期二 09时03分37秒
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
#include "CpuSimpleFactory.h"
#include<iostream>
using namespace std;

CCpuSimpleFactory::CCpuSimpleFactory(){

}

CCpuSimpleFactory::~CCpuSimpleFactory(){

}

CSingleCore* CCpuSimpleFactory::CreateSingleCore(enum CTYPE ctype){
    if(ctype == COREA){
        return new CSingleCoreA();
    } else if(ctype == COREB){
        return new CSingleCoreB();
    } else {
        return NULL;
    }
}



