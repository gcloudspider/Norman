/*########################################################
##File Name: N95.h
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

#ifndef _N95_H
#define _N95_H
#pragma once
#include "Nokia.h"

class CN95:public CNokia{
public:
    CN95(void);
public:
    virtual ~CN95(void);
public:
    virtual bool MakeCall(const std::string& number) const;
};
#endif
