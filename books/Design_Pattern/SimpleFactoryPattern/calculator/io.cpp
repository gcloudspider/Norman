/*########################################################
##File Name: CalculatorDemo.cpp
##Created Time:2016年01月10日 星期日 19时37分32秒
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
#include "io.h"
#include<iostream>
using namespace std;

double CalIO::getNum1(){
    return _num1;
}

double CalIO::getNum2(){
    return _num2;
}

void CalIO::printResult(){
    cout<<"运算结果为:"<<_result<<endl;
}

char CalIO::getOperator(){
    return _operator;
}

void CalIO::setNum1(){
    cout<<"请输入第一个数:"<<endl;
    cin>>_num1;
}

void CalIO::setNum2(){
    cout<<"请输入第二个数"<<endl;
    cin>>_num2;
}

void CalIO::setResult(double result){
    _result = result;
}

void CalIO::setOperator(){
    cout<<"请输入运算符"<<endl;
    cin>>_operator;
}
