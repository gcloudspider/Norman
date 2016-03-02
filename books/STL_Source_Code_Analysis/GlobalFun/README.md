/**
* Create Date:2016年03月02日 星期三 20时58分40秒
* 
* Author:Norman
* 
* Description: 
*/

####全局函数:
    STL中,实现内存配置跟对象构造行为分离开来.
    STL定义5个基本全局函数:
        1.construct():
            构造工具:在已分配内存上构造对象(stl_construct.h)
        2.destroy():
            析构工具:
        3.uninitialized_copy()
        4.uninitialized_fill()
        5.uninitialized_fill_n()
        未初始化空间中,要对对象进行初始化时，用到以上三个函数<stl_uninitialized.h>


    这五个全局函数中,基本上是Traits和__type_traits技术的作用,方便内存处理,并且提高效率
