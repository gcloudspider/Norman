##############################################################
##Embedded System Develop
##
##Create Date:2015-11-11
##Author:Norman
##
##Time:three month
##最终目标:敏捷开发
##1.代码规范
##2.养成思路分析  2.1:明确问题  2.2:分析 2.3:归纳 2.4:总结
##3.高效率(程序能申请少内存则少申请,能不用申请就不用申请)
##4.养成自己code review 将代码优化(重构)
##5.流程图
##6.任务表
##############################################################
#C/C++ Senior
#Git 工具忽略文件:https://github.com/github/gitignore
#
代码规范:

	1.局部变量: (小写开头)

	2.全局变量: g_**

	3.成员变量: m_**

	4.函数方法: isHeader()

	5.指针变量:	p_**
	
	6.宏,枚举全部使用大写

	7.定义名称必须有意义

	8.不清楚的暂时写注释
	
	9.类中的成员变量都放在private

	10.类中的公有对外的接口函数放在public

	11.类内部的函数放在private中

	12.含STL命名规范:
	vector: vect_**
	map:	map_**
	set:	set_**
	list:	list_**

	13.得到字符串不要去改变他本身

	13.语法格式:
	if else格式:
	if() {
	
	} else if() {
				
	} else {
	
	}

	switch case格式:

	switch(type) {
		case 1:
			break;
		case 2:
			break;
		default:
			break;
	}
