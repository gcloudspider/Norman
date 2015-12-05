/*########################################################
##File Name: newfeature.cpp
##Created Time:2015年12月05日 星期六 09时02分39秒
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
struct Foo{int x;};

int getflie() {
    return 0;
}

auto x = 5;
auto pi = new auto(1);
const auto *v = &x,u=6;
static auto y = 0.0;

int n = 0;
decltype(n) m =1;
/*函数调用*/
decltype(getflie()) c = 10;
/*带括号表达式和加法运算表达式*/
const Foo foo = Foo();
decltype(foo.x) a =20;
decltype((foo.x)) b = a;        //类访问表达式

decltype(n+=m) d = c;
/*error*/
//auto int r;       
//auto s;           auto为占位符,声明变量必须马上初始化

int& food(int& i);
float food(float& f);
template <typename T>
/*返回值类型后置语法:为了解决函数返回值类型依赖于参数而导致难以确定返回值类型的问题*/
auto func(T& val) -> decltype(foo(val)) {
    return foo(val);
}

int main() {
    printf("%p\t%d\n",&x,x);
    printf("%p\t%d\n",pi,*pi);
    printf("%p\t%d\n",v,*v);
    printf("%p\t%d\n",&u,u);
    printf("%p\t%d\n",&m,m);
    printf("%p\t%d\n",&c,c);
    printf("%p\t%d\n",&a,a);
    printf("%p\t%d\n",&b,b);
    return 0;
}
