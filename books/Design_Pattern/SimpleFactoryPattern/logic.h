/*########################################################
##File Name: logic.h
##Created Time:2016年01月10日 星期日 19时39分44秒
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

#ifndef _LOGIC_H
#define _LOGIC_H
#pragma once
#include "string"
#include <iostream>
using namespace std;

class CalLogic{
public:
    CalLogic(double num1,double num2){
        _num1 = num1;
        _num2 = num2;
        _result = 0;
    }

    virtual void calResult() = 0;
    double getResult();
    double getNum1();
    double getNum2();
    void setResult(double result);

protected:

private:
    double _num1;
    double _num2;
    double _result;
};

class AddCal:public CalLogic{
public:
    void calResult();
    AddCal(double num1,double num2):CalLogic(num1,num2){}
};

class SubCal:public CalLogic{
public:
    void calResult();
    SubCal(double num1,double num2):CalLogic(num1,num2){}
};

class MulCal:public CalLogic{
public:
    void calResult();
    MulCal(double num1,double num2):CalLogic(num1,num2){}
};

class DivCal:public CalLogic{
public:
    void calResult();
    DivCal(double num1,double num2):CalLogic(num1,num2){}
};
#endif
