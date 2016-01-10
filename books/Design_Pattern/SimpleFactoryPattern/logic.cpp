/*########################################################
##File Name: logic.cpp
##Created Time:2016年01月10日 星期日 19时46分12秒
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

double CalLogic::getResult(){
    return _result;
}

double CalLogic::getNum1(){
    return _num1;
}

double CalLogic::getNum2(){
    return _num2;
}

void CalLogic::setResult(double result){
    _result = result;
}

void AddCal::calResult(){
    setResult(getNum1()+getNum2());
}

void SubCal::calResult(){
    setResult(getNum1()-getNum2());
}

void MulCal::calResult(){
    setResult(getNum1()*getNum2());
}

void DivCal::calResult(){
    if(getNum2() != 0){
        setResult(getNum1()/getNum2());
    } else {
        cout <<"被除数为0,错误"<<endl;
    }
}

