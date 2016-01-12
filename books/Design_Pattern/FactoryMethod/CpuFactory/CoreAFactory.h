/*########################################################
##File Name: CoreAFactory.h
##Created Time:2016年01月12日 星期二 10时37分46秒
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

#ifndef _COREAFACTORY_H
#define _COREAFACTORY_H
#include "SingleCore.h"
class CCoreAFactory{
public:
    CCoreAFactory();
public:
    virtual ~CCoreAFactory();
public:
    virtual CSingleCore* CreateSingleCore() = 0;
};

#endif
