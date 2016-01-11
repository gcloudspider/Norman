/*########################################################
##File Name: N96.h
##Created Time:2016年01月11日 星期一 15时36分16秒
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

#ifndef _N96_H
#define _N96_H
#pragma once
#include "Nokia.h"
/*实际产品*/
class CN96:public CNokia{
public:
    CN96(void);
public:
    virtual ~CN96(void);
public:
    virtual bool MakeCall(const std::string& number)const;
};
#endif
