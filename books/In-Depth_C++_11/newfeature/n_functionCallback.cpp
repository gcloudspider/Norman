/*########################################################
##File Name: n_functionCallback.cpp
##Created Time:2015年12月06日 星期日 10时13分48秒
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

class A{
    function<void()> callback_;
public:
    A(const function<void()>& f)            //function 取代函数指针
        : callback_(f){}

    void notify(){
        callback_();
    }
};

class Foo{
public:
    void operator()(){
        cout<<__FUNCTION__<<endl;
    }
};

int main(){
    Foo foo;
    printf("%p\tsizeof(foo)=%d\n",&(foo),sizeof(foo));
    A aa(foo);
    printf("%p\n",&(aa));
    aa.notify();
    return 0;
}

