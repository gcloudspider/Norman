/*########################################################
##File Name: FactoryB.h
##Created Time:2016年01月12日 星期二 13时16分33秒
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

#ifndef _FACTORYB_H
#define _FACTORYB_H
#include "CoreFactory.h"
class CFactoryB:public CCoreFactory{
public:
    CFactoryB();
public:
    ~FactoryB();
public:
    CSingleCore* CreateSingleCore();
    CMultiCore* CreateMultiCore();
};
#endif
