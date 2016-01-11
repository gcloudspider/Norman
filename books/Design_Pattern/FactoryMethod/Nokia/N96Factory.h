/*########################################################
##File Name: N96Factory.h
##Created Time:2016年01月11日 星期一 16时25分20秒
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

#ifndef _N96FACTORY_H
#define _N96FACTORY_H
#pragma once
#include "FactoryMethod.h"
#include "N96.h"

/*生产N96具体工厂类*/
class CN96Factory:public CFactoryMethod{
public:
    CN96Factory(void);
public:
    virtual ~CN96Factory(void);
public:
    virtual CNokia* CreateNokiaMobile(void);
};
#endif
