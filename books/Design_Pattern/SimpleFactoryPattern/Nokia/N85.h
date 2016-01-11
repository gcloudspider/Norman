/*########################################################
##File Name: N85.h
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

#ifndef _N85_H
#define _N85_H
#pragma once
#include "Nokia.h"

class CN85:public CNokia{
public:
    CN85(void);
public:
    virtual ~CN85(void);
public:
    virtual bool MakeCall(const std::string& number) const;
};
#endif
