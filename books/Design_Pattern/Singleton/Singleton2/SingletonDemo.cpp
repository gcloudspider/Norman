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
#include <iostream>
using namespace std;

class Singleton{
public:
    static Singleton *GetInstance(){
        return m_Instance;
    }

    int GetTest(){
        return m_Test;
    }
private:
    Singleton(){m_Test = 10;}
    static Singleton *m_Instance;
    int m_Test;

    class GC{
        public:
            ~GC(){      //程序运行结束时,系统会调用Singleton静态成员GC的析构函数
                if(m_Instance != NULL){
                    cout <<"Here is the test"<<endl;
                    delete m_Instance;
                    m_Instance = NULL;
                }
            }
    };
    static GC gc; //静态变量和全局变量 在内存中,都存储在静态存储区,在析构时同等对待
};

//静态初始化在程序开始时,在进入主函数前由主线程以单线程方式完成初始化
//静态初始化实例保证了线程安全性,在性能要求比较高时,可以使用这种形式,避免频繁加锁和解锁造成的资源浪费
Singleton *Singleton::m_Instance = new Singleton();
Singleton::GC Singleton::gc;
//原理:
//在程序结束时,系统会自动析构所有全局变量.实际上,系统民会析构所有类的静态成员变量
int main(int argc,char *argv[]){
    Singleton *singletonObj = Singleton::GetInstance();
    cout<<singletonObj->GetTest()<<endl;

    return 0;
}
