/*########################################################
##File Name: factory.cpp
##Created Time:2016年01月10日 星期日 19时51分26秒
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
#include "factory.h"
#include<iostream>
using namespace std;

CalLogic* OperatorFactory::createCalLogic(char calOperator,double num1,double num2){
    CalLogic* calLogic;
    switch(calOperator){
        case '+':
            calLogic = new AddCal(num1,num2);
            break;
        case '-':
            calLogic = new SubCal(num1,num2);
            break;
        case '*':
            calLogic = new MulCal(num1,num2);
            break;
        case '/':
            calLogic = new DivCal(num1,num2);
            break;
        default:
            cout<<"出现未知运算符号"<<endl;
            break;
    }
    return calLogic;
}

