/*########################################################
##File Name: NodiaSimpleFactory.h
##Created Time:2016年01月11日 星期一 13时33分40秒
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

#ifndef _NODIASIMPLEFACTORY_H
#define _NODIASIMPLEFACTORY_H
#pragma once
#include "N96.h"
#include "N95.h"
#include "N85.h"
#include "N81.h"
#include <cassert>

class CNokiaSimpleFactory{
public:
    CNokiaSimpleFactory(void);
public:
    ~CNokiaSimpleFactory(void);
public:
    static CNokia *CreateNokia(const std::string &model);
};
#endif
