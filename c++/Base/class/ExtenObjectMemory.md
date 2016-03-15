/**
* Create Date:2016年03月11日星期五 10:37:58
* 
* Author:Norman
* 
* Description: 
*/

####对象影响因素:
    1.成员变量
    2.虚函数(虚函数表)
    3.单一继承(只继承于一个类)
    4.多重继承(继承多个类)
    5.重复继承(继承多个父类中其父类有相同的超类)
    6.虚拟继承(virtual方式继承,保证继承后父类的内存布局只存一份)

####C++对象模型内存布局(以下几种情况分析):

####[单一的一般继承(带有成员变量,虚函数 虚函数覆盖)](./Document/SingleInherit.md)

####[多重继承(带有成员变量,虚函数 虚函数覆盖)](./Document/MultiInherit.md)
    
####[单一的虚拟继承(带有成员变量,虚函数 虚函数覆盖)](./Document/SingleVirInherit.md)
    
####[重复多重继承(带有成员变量,虚函数 虚函数覆盖)](./Document/RepeatedInheritance.md)
    
####[钻石型的虚拟多重继承(带有成员变量,虚函数 虚函数覆盖)](./Document/DiamondMInherit.md)
    
