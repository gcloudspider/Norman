/*########################################################
##File Name: CpuSimpleFactory.h
##Created Time:2016年01月12日 星期二 09时03分28秒
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

#ifndef _CPUSIMPLEFACTORY_H
#define _CPUSIMPLEFACTORY_H
#include "SingleCoreA.h"
#include "SingleCoreB.h"
class CCpuSimpleFactory{
public:
    CCpuSimpleFactory(void);
public:
    ~CCpuSimpleFactory(void);
public:
    static CSingleCore* CreateSingleCore(enum CTYPE ctype);
};
#endif
