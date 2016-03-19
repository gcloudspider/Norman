/**
* Create Date:2016年03月05日 星期六 09时37分59秒
* 
* Author:Norman
* 
* Description: 
*/

####hashset容器:
    1.hash table在查找 删除和插入节点是常数时间，优于RB-tree红黑树
    2.SGI STL提供底层机制基于hash table 的hash_set容器
    3.hash_set与set类似 但是不同点hash_set容器中的元素是没有排序的
    4.hash table没有提供排序功能
    5.源码<stl_hash_set.h>

####hash_set源码剖析:

