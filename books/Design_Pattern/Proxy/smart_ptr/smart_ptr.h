/**
*  - version 1.0
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
template <typename T>
class smart_ptr{
public:
    //初始的计数值为1
    smart_ptr(T *p=0):pointee(p),count(new size_t(1)){}

    //拷贝构造函数,计数加1
    smart_ptr(const smart_ptr &rhs):pointee(rhs.pointee),count(rhs.count){++*count}

    //析构,计数减1,减到0时进行垃圾回收,即释放空间
    ~smart_ptr(){decr_count();}

    //重载赋值操作符
    smart_ptr& operator = (const smart_ptr& rhs){
        //组自身赋值也对,因为如果自身赋值,计数器先减1 再加1 并未发生改变
        ++*count;
        decr_count();
        pointee = rhs.pointee;
        count = rhs.count;
        return *this;
    }

    //重载箭头操作符和解引用操作符.未提供指针的检查
    T *operator->(){return pointee;}
    const T *operator->()const {return pointee;}
    T &operator*(){return *pointee;}
    const T &operator*() const {return *pointee;}
    size_t get_refcount(){return *count;}   //获得引用计数器值
private:
    T *pointee;         //实际指针,被代理
    size_t *count;      //引用计数器
    void decr_count(){  //计数器减1
        if(--*count == 0){
            delete pointee;
            delete count;
        }
    }
};
