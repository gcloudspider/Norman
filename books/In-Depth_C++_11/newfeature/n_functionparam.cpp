/*########################################################
##File Name: n_functionparam.cpp
##Created Time:2015年12月06日 星期日 10时30分16秒
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

#include<iostream>
#include<functional>
using namespace std;

void call_when_even(int x,const function<void(int)>& f){        //参数2 以function作为函数指针
    if(!(x& 1)){
        f(x);           //function 比普通函数指针更灵活和便利
    }
}

void output(int x){
    cout<<x<<" ";
}

int main(){
    for(int i=0;i<10;++i){
        call_when_even(i,output);
    }
    cout<<endl;
    return 0;
} 
