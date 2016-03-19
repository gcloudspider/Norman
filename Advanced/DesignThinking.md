/**
* Create Date:2016年03月10日星期四 08:01:06
* 
* Author:Norman
* 
* Description: 
*/

####项目设计(过程):
    总体描述:
        一家"野狼牌"汽车经销店,购进5台汽车,有3个销售员,上班开始首先统计一下本店的库存信息和销售信息,然后开始正常营业,接待客户对车辆的咨询,付款,提车,等工作,以下业务要求,基于面向对象思考,用控制台程序编程模拟

    业务要求:
    1.厂家根据要求生产5台汽车,并送至经销商库存
    2.上班开始要求显示库存车辆信息和销售员信息
    3.客户进入商店对汽车相关信息进行咨询,比如汽车价格等问题
    4.销售员根据客户要求回答问题,并帮助客户完成付款,提车等工作
    5.客户提车回家
    6.销售员按照以上流程继续接待其他客户,直到下班为止
    7.下班时要求统计今日销售信息和库存信息等
        

    1.根据项目如何找到类?
        通过项目概述分析,看有哪些对象(实体)参与整个业务流程 (类似于分析记叙文中的一个段落)
        
        分析方法:名称分析法+头脑风暴法

        分析结果:汽车类,销售员,客户 库存 经销店 营业额 工厂类

        结果筛选:要求所选择类(对象),必须和当前业务"强相关",这个对象必须有对象的特征(属性,方法)

        所以:库存 营业额 工厂类去掉

        核心类:汽车 销售员 客户 经销店


    2.所找到的类如何设计?
        类的设计根本:设计属性和方法

        类的详细设计需要参考具体的需求来定

        汽车类: 品牌 配置  价格 颜色 发动机编号 (行为:启动 开动车辆,停车)
        销售员类: 姓名 年龄 工号 职位(行为:问候 询问 回答)
        客户类:姓名 性别 联系电话(行为:询问 回答)
        经销店:名称, 仓库(包含多种汽车) 销售员列表(包含多个销售员) 销售数量 销售单 
        
        经验:设计类时先从简单类(没有依赖的开始设计)
            其次设计复杂的有关联的类

        如:设计数据库表,先设计简单的表
            其次设计有主键关系的表




    3.所设计的类(对象)之间如何确定关系?
        1.如果一个对象和另一个对象之间是一对一的关系,则一个对象作为另一个对象的属性
        2.如果一个对象包含若干个其他对象,则其他对象,在当前对象中以"集合"形式存在
        如果对象的获取没有什么限制可以直接使用list集合
        如果对象的获取获取根据名称得到使用dictionar<k,v>集合
    4.程序实现
    5.测试