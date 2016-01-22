/**
* Create Date:2016年01月22日 星期五 09时43分24秒
* 
* Author:Norman
* 
* Description: 堆
*/

####堆:
    C++ 用new操作符分配动态内存
    堆由new 分配内存块,释放由自己控制，需要new一个对象后自己delete清除,否则内存泄漏。在程序结束后操作系统会自动回收

    C实现动态内存分配:
        1.利用含指针成员的结构体
        2.标准库函数(alloc.h 或malloc.h 或stdlib.h)
            2.1:malloc
