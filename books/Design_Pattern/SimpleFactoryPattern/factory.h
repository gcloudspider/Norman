/*########################################################
##File Name: factory.h
##Created Time:2016年01月10日 星期日 19时50分20秒
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

#ifndef _FACTORY_H
#define _FACTORY_H
#include "logic.h"

class OperatorFactory{
public:
    static CalLogic* createCalLogic(char calOperator,double num1,double num2);
};
#endif
