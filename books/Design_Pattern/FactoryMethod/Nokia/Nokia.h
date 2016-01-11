/*########################################################
##File Name: Nokia.h
##Created Time:2016年01月11日 星期一 15时39分30秒
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

#ifndef _NOKIA_H
#define _NOKIA_H
#pragma once
#include<string>
#include<iostream>
/*抽象层*/

class CNokia{
public:
    CNokia(void);
public:
    virtual ~CNokia(void);
public:
    virtual bool MakeCall(const std::string& number) const =0;
};
#endif
