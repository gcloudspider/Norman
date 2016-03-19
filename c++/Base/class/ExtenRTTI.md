/**
* Create Date:2016年03月13日星期日 08:04:20
* 
* Author:Norman
* 
* Description: 
*/

####RTTI实现原理:
    RTTI是运行时类型识别!
    C++引入这个机制是为了让程序在运行时能根据基类的指针或引用来获得该指针或引用所指的对象的实际类型
    
    RTTI还能通过typeid操作符识别出所有基本类型(int 指针等)的变量对应的类型

####操作RTTI方法:
    1.typeid运算符,该运算符返回其表达式或类型名的实际类型.
        1.1:typeid操作符结果是名为type_info的标准库类型的对象引用
        1.2:
    2.dynamic_cast运算符,该运算符将基类的指针或引用安全地转换为派生类类型的指针或引用
    

####[typeid运算符实现方式](./Typeid_RTTI.cpp)
