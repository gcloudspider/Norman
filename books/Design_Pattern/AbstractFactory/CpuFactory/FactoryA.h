/*########################################################
##File Name: FactoryA.h
##Created Time:2016年01月12日 星期二 13时11分54秒
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

#ifndef _FACTORYA_H
#define _FACTORYA_H
#include "CoreFactory.h"

class CFactoryA:public CCoreFactory{
public:
    CFactoryA();
public:
    ~CFactoryA();
public:
    CSingleCore* CreateSingleCore();
    CMultiCore* CreateMultiCore();
};
#endif
