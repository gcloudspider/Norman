/*########################################################
##File Name: N96.cpp
##Created Time:2016年01月11日 星期一 15时37分33秒
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
#include"N96.h"
#include<iostream>
using namespace std;

CN96::CN96(void){
    cout<<"生产一部N96"<<endl;
}

CN96::~CN96(void){

}

bool CN96::MakeCall(const std::string & number) const{
    cout<<"我在用N96,拔打号码是:"<<number.c_str()<<endl;
    return false;
}
