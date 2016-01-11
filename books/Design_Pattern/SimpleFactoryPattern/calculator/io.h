/*########################################################
##File Name: SimpleFactory2.cpp
##Created Time:2016年01月10日 星期日 19时24分58秒
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
#include"logic.h"
#include<iostream>
using namespace std;

class CalIO{
public:
    double getNum1();
    double getNum2();
    void printResult();
    char getOperator();
    void setNum1();
    void setNum2();
    void setResult(double result);
    void setOperator();

    CalIO(){
        _num1 = 0;
        _num2 = 0;
        _result = 0;
    }

private:
    double _num1;
    double _num2;
    double _result;
    char _operator;
};
