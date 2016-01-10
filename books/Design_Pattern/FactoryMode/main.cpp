/*########################################################
##File Name: main.cpp
##Created Time:2016年01月10日 星期日 17时49分05秒
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
#include"Factory.h"
#include"Product.h"
#include<iostream>
using namespace std;

int main(int argc,char* argv[]){
    Factory* fac = new ConcreteFactory();
    Product* p = fac->CreateProduct();

    return 0;
}

