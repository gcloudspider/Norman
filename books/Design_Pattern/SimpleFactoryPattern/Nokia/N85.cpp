/*########################################################
##File Name: N85.cpp
##Created Time:2016年01月11日 星期一 15时33分54秒
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
#include "N85.h"
#include<iostream>
using namespace std;

CN85::CN85(void){
    cout<<"生产一部N85"<<endl;
}

CN85::~CN85(void){

}

bool CN85::MakeCall(const std::string& number) const{
    cout<<"我在用N85，拔打号码是:"<<number.c_str()<<endl;
    return false;
}
