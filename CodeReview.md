###################################################
## Create Date:2015年11月27日 星期五 10时31分04秒
##
##Author:Norman
## 代码审查之道
##Description:  Code Review
###################################################

Upsource 审查工具:简单的审查
 1.格式
 2.风格:变量
 3.命名
 4.覆盖测试

SOLID原则:
    SRP  --The Single Responsibility Principle  单一责任原则(一个类只做一种类型责任)
    OCP  --The Open Closed Principle  开放封闭原则(可扩展,不可修改)
    LSP  --The Liskov Substitution Principle 里氏替换原则 (子类能替换其超类实例 is-A)
    DIP  --The Dependency Inversion Principle 依赖倒置原则 (高层模块不应该依赖低层模块,二者都应该依赖于抽象，抽象不依赖细节--细节依赖于抽象)
    ISP  --The Interface Segregation Principle 接口分离原则(多个专门接口比单一总接口要好)
  
1.设计
 1.1:与整体架构匹配
 1.2:遵循SOLID原则 ----SOLID 面向对象设计和编程中编码原则
 1.3:代码能否复用
 1.4:代码是否包含冗余,(重构)


2.可维护性,可读性
  2.1: 命名(字段 变量 参数 函数以及类是否能代表的事物)
  2.2: 阅读代码即理解代码
  2.3: 异常错误消息易理解
  2.4: 难理解代码段备注 评论

3.功能
  3.1: 代码符合预期。


4.其他
  4.1: 安全问题
  4.2: 满足规范要求
  4.3: 存在导致产品崩溃的明显错误
