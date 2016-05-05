/**
* Create Date:Thu 05 May 2016 09:02:52 AM CST
* 
* Author:Norman
* 
* Description: 
*/

####函数指针:
    C语言函数指针定义形式:
    int (*pFunction)(float,char,char) = NULL;

    C++函数指针定义形式:
    int (MyClass::*pMemberFunction)(float,char,char) = NULL;

    int (MyClass::*ConstMemberFunction)(float,char,char) const = NULL;

####函数调用规则:
    指函数被调用方式: _stdcall,_fastcall,_pascal,_cdecl等规则
    不同规则在参数压入堆栈顺序不同.同时在有调用者清理压入堆栈的参数还是由被调用者清理压入堆栈的参数上也是不同的。
    没有显式说明调用规则的话,编译器会统一按照_cdecl来处理

####给函数指针赋值和调用
    给函数指针赋值就是为函数指定一个函数名称
    int func1(float f,int a,int b){return f*a/b;}
    int func2(float f,int a,int b){return f*a*b}

    pFunction = func1;
    pFunction = &func2;
    //一个函数指针可以多次赋值
    //取地址符号是可选的,却是推荐使用的

    调用函数
    pFunction(10.0,'a','b');
    (*pFunction)(10.0,'a','b');

    C++中的函数指针赋值和调用(非静态函数成员情况)
    1.对于赋值,必须加"&" 而且必须再次之前已经定义好了一个类实例 取地址符号要操作于这个类实例的对应的函数成员上
    2.使用成员函数的指针调用成员函数时,必须加类实例的名称,然后再使用.*或->*来使用成员函数指针

    MyClass {
        public:
            int func1(float f,char a,char b) {
                return f * a * b;
            }
            int func2(float f,char a,char b) const {
                return f * a / b;
            }
    }

    MyClass mc;
    pMemberFunction = &mc.func1;
    pConstMemberFunction = &mc.func2;

    3.调用函数
    (mc.*pMemberFunction)(10.0,'a','b');
    (mc.*pConstMemberFunction)(10.0,'a','b');

####函数指针作为参数
    函数参数列表中,声明一个函数指针类型的参数即可。然后在调用的时候传给它一个实参
    把函数指针的赋值语句等号换成形参和实参结合的模式

####函数指针作为返回值
    float (*func(char op)) (float,float)
        1.声明名称func 参数个数1个
        2.参数类型 op  -- char
        3.返回变量(函数指针)类型为:float(*)(float,float)

    void (*signal)(int signo,void(*func)(int)))(int);
        1.声明函数名称为:signal
        2.参数个数为2
        3.各个参数类型为:singo -- int  func -- void(*)(int)
        4.返回的变量(函数指针)类型为:void(*)(int)

####函数指针数组
    1.函数指针数组定义
    float (*pFunctionArray[10])(float,float)

####使用typedef
    typedef 简化函数指针定义
    声明新类型:
    typedef float(*fpType)(float,float);
    定义指针变量:
    fpType pFunction;
    定义函数指针数组:
    fpType pFunction[10];
    定义函数指针类型的返回值:
    fpType func(int a);

    void (*signal)(int signo,void (*func)(int)))(int);
    //重新声明
    typedef void (*pSgnType)(int);
    //定义: pSgnType signal(int signo,pSgnType func);

    //也可以定义为以下:
    typedef void SgnType(int)
    声明:
    SgnType *signal(int signo,SgnType *func);
