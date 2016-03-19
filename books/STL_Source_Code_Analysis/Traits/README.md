/**
* Create Date:2016年02月29日 星期一 21时02分23秒
* 
* Author:Norman
* 
* Description: 
*/

####Traits编程:
    STL编程中,容器和算法是独立设计的.
    数据结构和算法是独立设计的
    连接容器和算法桥梁是迭代器.

####Traits原理:
    1.traits是一种特性萃取技术，在泛型编程中被广泛运用
    2.常被用于不同类型可以用于相同的操作,或针对不同类型提供不同的实现

    实现traits需要特性:
        1.enum:
            用于将不同类型间变化的标示统一成一个,C++中常用于在类中替代define
        2.typedef:
            用于定义模板类支持特性的形式
        3.template(partial) specialization:
            用于提供针对特定类型正确或更合适版本

####[场景1](./codes/traits_example.cpp)
