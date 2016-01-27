/**
* Create Date:2016年01月27日 星期三 15时54分36秒
* 
* Author:Norman
* 
* Description: 
*/

####分析:
    内部状态存储于flyweight中,包含独立于flyweight场景信息.如字符代码,字符大小

    外部状态取决于flyweight场景,并根据场景而变化,因此不可共享,用户对象负责在必要时候将外部状态传递给flyweight 如字符位置 字符颜色....
