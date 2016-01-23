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
            2.1:malloc函数
            在内存的动态存储区中分配长度为"size"字节的连续区域,返回该区域首地址
            2.2:calloc函数
            按所给数据个数和每个数据所占字节数开辟存储空间
            2.3:realloc函数
            重新开辟内存空间的大小,
            2.4:free函数
            将开辟内存空间释放.

    C++动态内存分配:
        C++用new和delete来动态申请和释放内存

    区别:
        1.malloc与free是C++/C语言标准库函数
          new/delete是C++的运算符

        2.内存泄漏malloc和new都可以检查出来.new可以指明是哪个文件哪一行,而malloc没有


