/*########################################################
##File Name: N96Factory.cpp
##Created Time:2016年01月11日 星期一 16时25分24秒
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
#include "N96Factory.h"
#include<iostream>
using namespace std;

CN96Factory::CN96Factory(void){

}

CN96Factory::~CN96Factory(void){

}

CNokia* CN96Factory::CreateNokiaMobile(void){
    return new CN96();
}
