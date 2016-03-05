/**
* Create Date:2016年03月05日 星期六 07时51分11秒
* 
* Author:Norman
* 
* Description: 
*/

####map容器:
    1.底层实现机制是RB-Tree 因为map操作RB-Tree都能实现
    2.map容器键值key和实值value是不相同的。
    3.键值key和实值value比较函数也是不同的
    4.容器里元素是根据元素的键值自动排序的
    5.不能修改map容器的键值,可以修改容器的实值
    6.map所有节点元素都是pair pair有两个成员变量 first second
    7.第一个first是键值key 第二个second 是实值value
    8.SGI STL源码<stl_map.h>文件

####map容器剖析:


