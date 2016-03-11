/**
* Create Date:2016年03月11日星期五 10:49:15
* 
* Author:Norman
* 
* Description: 
*/

####单一的一般继承:
####![](../image/ObjectMemory1.jpg)
    1.父类 子类 孙子类都有自己成员变量
    2.子类覆盖了父类的f()方法
    3.孙子类覆盖了子类的g_child()及其超类的f()
####[源码验证](../SingleInherit.cpp)
####![](../image/OMemory1.jpg)
    1.虚函数表在最前面的位置
    2.成员变量根据其继承和声明顺序依次放在后面
    3.在单一继承中,被overwrite的虚函数在虚函数表中得到了更新
