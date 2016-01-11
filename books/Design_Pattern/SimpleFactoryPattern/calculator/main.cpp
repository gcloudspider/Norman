/*########################################################
##File Name: main.cpp
##Created Time:2016年01月10日 星期日 19时55分00秒
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
#include "logic.h"
#include "factory.h"
#include <stdlib.h>
#include<iostream>
using namespace std;

int main(){
    CalIO* calIO = new CalIO();
    calIO->setNum1();
    calIO->setNum2();
    calIO->setOperator();

    CalLogic* calLogic = OperatorFactory::createCalLogic(calIO->getOperator(),calIO->getNum1(),calIO->getNum2());
    calLogic->calResult();
    calIO->setResult(calLogic->getResult());
    calIO->printResult();

}

