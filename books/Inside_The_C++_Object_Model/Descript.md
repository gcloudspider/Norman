###############################################
##
##Create Date:2015-11-12
##Author:Norman
##
##
################################################


C++对象模型:
	1.关于对象
		程序性:由一组"分布在各个以功能为导向的函数中"的算法所驱动,它们处理的是共同的外部数据
	virtual function 机制用以支持一个有效率的"执行期绑定"
	virtual base class 用以实现"多次出现在继承体系中的base class 有一个单一而被共享的实体"

	C++中,有两种class data members： static 和nonstatic
		  三种class member functions:	static nonstatic 和virtual

	1.1 对象模式:
		简单对象模型
		表格驱动对象模型

