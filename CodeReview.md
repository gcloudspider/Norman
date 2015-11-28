###################################################
## Create Date:2015年11月27日 星期五 10时31分04秒<br />
##
##Author:Norman<br />
## 代码审查之道<br />
##Description:  Code Review<br />
###################################################

Upsource 审查工具:简单的审查<br />
  1.格式<br />
  2.风格:变量<br />
  3.命名<br />
  4.覆盖测试<br />

SOLID原则:<br />
  SRP  --The Single Responsibility Principle  单一责任原则(一个类只做一种类型责任)<br />
  OCP  --The Open Closed Principle  开放封闭原则(可扩展,不可修改)<br />
  LSP  --The Liskov Substitution Principle 里氏替换原则 (子类能替换其超类实例 is-A)<br />
  DIP  --The Dependency Inversion Principle 依赖倒置原则 (高层模块不应该依赖低层模块,二者都应该依赖于抽象，抽象不依赖细节--细节依赖于抽象)<br />
  ISP  --The Interface Segregation Principle 接口分离原则(多个专门接口比单一总接口要好)<br />
 
 
1.设计<br />
  1.1:与整体架构匹配<br />
  1.2:遵循SOLID原则 ----SOLID 面向对象设计和编程中编码原则<br />
  1.3:代码能否复用<br />
  1.4:代码是否包含冗余,(重构)<br />


2.可维护性,可读性<br />
  2.1: 命名(字段 变量 参数 函数以及类是否能代表的事物)<br />
  2.2: 阅读代码即理解代码<br />
  2.3: 异常错误消息易理解<br />
  2.4: 难理解代码段备注 评论<br />

3.功能<br />
  3.1: 代码符合预期。<br />


4.其他<br />
  4.1: 安全问题<br />
  4.2: 满足规范要求<br />
  4.3: 存在导致产品崩溃的明显错误<br />
