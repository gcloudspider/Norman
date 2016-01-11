/*########################################################
##File Name: N81.h
##Created Time:2016年01月11日 星期一 15时32分21秒
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

#ifndef _N81_H
#define _N81_H
#pragma once
#include "Nokia.h"

class CN81:public CNokia{
public:
    CN81(void);
public:
    virtual ~CN81(void);
public:
    virtual bool MakeCall(const std::string& number) const;
};
#endif
