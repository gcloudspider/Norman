/**
* Create Date:2016年03月05日 星期六 09时26分38秒
* 
* Author:Norman
* 
* Description: 
*/

####hash func:
    1.SGI STL中hash表实现是采用拉链法。其中用到哈希函数
    2.哈希函数作用:把元素键值映射到对应的桶子里面,一般哈希值是键值对桶子数取余
    3.SGI STL提供哈希函数是有限的.只支持特定的元素类型,
    4.若用户需要使用其他类型的哈希函数,必须自行定义
    5.源码位于<stl_hash_fun.h>

####自定义哈希函数:
    1.使用struct 然后重载operator()
    2.返回是size_t
    3.参数是你要hash的key类型
    4.函数是const类型
