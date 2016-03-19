/**
* Create Date:2016年03月04日 星期五 20时26分40秒
* 
* Author:Norman
* 
* Description: 
*/

####单向链表
    1.单向链表迭代器是属于正向迭代器
    2.SGI STL中stl_slist.h定义单向链表slist

####slist节点结构:
    1.slist节点结构只有存储节点数据和指向下一个节点的指针

####slist迭代器:
    1.slist单向链表,只提供正向迭代器.若要查找指定节点的前一个节点时.operator--不能使用
    2.只能从头遍历 但是可以operator++ operator*操作


####slist数据结构:
    slist单向链表只需给出该链表头部head 以便可以通过head->next遍历该链表
