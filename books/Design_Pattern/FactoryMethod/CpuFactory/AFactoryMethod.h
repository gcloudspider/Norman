/*########################################################
##File Name: AFactoryMethod.h
##Created Time:2016年01月12日 星期二 10时43分43秒
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

#ifndef _AFACTORYMETHOD_H
#define _AFACTORYMETHOD_H
#include "CoreAFactory.h"
#include "SingleCoreA.h"

class CAFactoryMethod:public CCoreAFactory{
public:
    CAFactoryMethod();
public:
    virtual ~CAFactoryMethod();
public:
    virtual CSingleCore* CreateSingleCore();
};
#endif
