/*########################################################
##File Name: Factory.cpp
##Created Time:2016年01月10日 星期日 17时46分51秒
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
#include "Product.h"
#include<iostream>
using namespace std;

Factory::Factory(){

}

Factory::~Factory(){

}

ConcreteFactory::ConcreteFactory(){
    cout<<"ConcreteFactory......"<<endl;
}

ConcreteFactory::~ConcreteFactory(){

}

Product* ConcreteFactory::CreateProduct(){
    return new ConcreteProduct();
}

