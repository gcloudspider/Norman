/*########################################################
##File Name: n_functionbind.cpp
##Created Time:2015年12月05日 星期六 20时54分27秒
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
using namespace std;

void func() {
    
}

struct Foo{
    void operator()(){

    }
};

struct Bar {
    using fr_t = void(*)(void);
    static void func(void){

    }
    operator fr_t(){
        return func;
    }
};

struct A{
    int a_;
    void mem_func(void){

    }
};

int main(){
    void (*func_ptr)(void) = &func;
    func_ptr();

    Foo foo;
    foo();

    Bar bar;
    bar();

    void (A::*mem_func_ptr)(void)
        = &A::mem_func;

    int A::*mem_obj_ptr
        = &A::a_;
    A aa;
    (aa.*mem_func_ptr)();
    aa.*mem_obj_ptr = 123;

    return 0;
}
