/*########################################################
##File Name: FactoryMethod.h
##Created Time:2016年01月11日 星期一 16时28分58秒
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

#ifndef _FACTORYMETHOD_H
#define _FACTORYMETHOD_H
#pragma once
#include "Nokia.h"
class CFactoryMethod{
public:
    CFactoryMethod(void);
public:
    virtual ~CFactoryMethod(void);
public:
    virtual CNokia* CreateNokiaMobile(void) =0;
};
#endif
