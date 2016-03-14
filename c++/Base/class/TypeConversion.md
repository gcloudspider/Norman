/**
* Create Date:2016年03月14日星期一 08:22:29
* 
* Author:Norman
* 
* Description: 
*/

####C++类型转换:
    C++引进四个新的类型转换操作符:
    1.static_cast:用来进行非多态的任何转换.拒绝了运行时类型检查 static_cast<type>(object)
    2.const_cast:除去对象的常属性,转换的是表达式而非自身 const_cast<type>(object)
    3.dynamic_cast:运行时转换符,可完成类族中向下类型转换---将父类指针变为子类的指针 dynamic_cast<type>(object)
    4.reinterpret_cast:将一种数据从根本上变为另一种完全不兼容的类型 reinterpret_cast<type>(object)

####[const_cast例子](./Const_cast.cpp)
####Const_cast<type>(object):
    1.该运算符用来修改类型的const或volatile属性 除了const或volatile修饰之外,type_id和expression类型是一样的
    2.常量指针被转化成非常量指针,并且仍然指向原来对象
    3.常量引用被转换成非常量引用,并且仍然指向原来对象

    使用const_cast可以返回一个指向非常量的指针(或引用) 指向原const常量对象,可以通过转换后的指针(引用)对它的成员进行改变

####[static_cast例子](./Static_cast.cpp)
####Static_cast<type>(object):
    该运算符把expression转换为type-id类型,但没有运行时类型检查来保证转换的安全性
    
    主要用法:
        1.用于类层次结构中基类和派生类之间指针或引用转换,进行派生类指针或引用转换成基类表示是安全的
        2.把基类指针或引用转换成派生类表示时,由于没有动态类型检查,所以是不安全的
        3.用于基本类型之间转换,把int转换成char 把int转换成enum 安全性也要开发人员保证
        4.把空指针转换成目标类型的空指针
        5.把任何类型的表达式转换成void类型
    注意:
        static_cast不能转换掉expression的const volatile 或者__unaligned属性
        编译器隐式执行任何类型转换都可以由static_cast显式完成

####[dynamic_cast例子](./Dynamic_cast.cpp)
####Dynamic_cast<type>(object):
    特性:
    1.该运算符把object转换成type类型对象,type必须是类的指针 类的引用或void*
    2.dynamic_cast运算符可以在执行期决定真正的类型
    3.如果downcast是安全的(基类指针或引用指向一个派生类对象,把基类指针或引用转换为派生类指针或引用)这个运算符会传回适当转型过的指针
    4.如果downcast不安全,这个运算符会传回空指针
    5.dynamic_cast主要用于类层次间的上行转换和下行转换,还可以用于类之间的交叉转换
    6.层次间进行上行转换 dynamic_cast和static_cast效果一样
    7.在进行下行转换时,dynamic_cast具有类型检查功能,比static_cast更安全


####reinterpret_cast<type>(object):
    1.type 必须是一个指针 引用 算术类型 函数指针 或成员指针 
    2.它可以把一个指针转换成一个整数
    3.也可以把一个整数转换成一个指针
    4.先把一个指针转换成一个整数,再把整数转换成原类型的指针 还可以得到原先的指针值
    5.操作符修改了操作数类型,但仅仅是重新解释了给出的对象的比特模型而没有进行二进制转换

####C++ static_cast和reinterpret_cast区别:
    1.隐式执行任何类型转换都可由static_cast显式完成
    2.reinterpret_cast通常为操作数的位模式提供较低层的重新解释(将数据以二进制存在形式重新解释)
    3.reinterpret_cast主要是将数据从一种类型转换为另一种类型
