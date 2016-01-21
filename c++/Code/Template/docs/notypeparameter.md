/**
* Create Date:2016年01月20日 星期三 13时31分02秒
* 
* Author:Norman
* 
* Description: 
*/

####非类型形参:
    1.非类型形参:模板的非类型形参也就是内置类型形参 如template <class T,int a> class B{}; 其中int a就是非类型的模板形参

    2.非类型形参在模板定义的内部是常量值,也就是说非类型形参在模板的内部是常量

    3.非类型模板的形参只能是整形,指针和引用(像double string String**这种类型不允许)
    但是:double &, double* 对象的引用或指针是正确的

    4.调用非类型模板形参的实参必须是一个常量表达式

    5.任何局部对象,局部变量 局部对象的地址 局部变量的地址都不是一个常量表达式
    *都不能用作非类型模板形参的实参
    全局指针类型 全局变量全局对象也不是常量表达式
    *不能用作非类型模板形参的实参

    6.全局变量的地址或引用，全局对象的地址或引用const 类型变量是常量表达式
    可以用作非类型模板形参的实参

    7.sizeof表达式的结果是一个常量表达式,也能用作类型模板形参的实参

    8.当模板的形参是整型时调用该模板时的实参必须是整型的,且在编译期间是常量。
    比如template<class T,int a> class A{};
        如果有int b 这时A <int,b>m ;将出错 ----因为b不是常量
        如果const int b 这时A<int,b> m;就正确 ----因为这时b是常量
    
    9.非类型形参一般不应用于函数模板中
        如:有函数模板template<class T,int a> void h(T b){}
        若使用h(2) 调用会出现无法为非类型形参a推演出参数的错误,
            对这种模板函数可以用显示模板实参来解决:
        如用h<int,3>(2)这样就把非类型形参a设置为整数3 

    10.非类型模板形参的形参和实参间所允许的转换
        10.1:允许从数组到指针,从函数到指针的转换 
            如template<int *a> class A{}; int b[1]; A<b> m;
            即数组到指针的转换
        10.2:const修饰符的转换。
            如:template<const int *a>class A{}; int b; A<&b> m;
            即从int* 到const int*的转换
        10.3:提升转换 
            如:template<int a> class A{}; const short b=2; A<b> m;
            即从short到int的提升转换
        10.4:整值转换
            如:template<unsigned int a>class A{}; A<3> m;
            即从int 到unsigned int的转换
        10.5:常夫转换

