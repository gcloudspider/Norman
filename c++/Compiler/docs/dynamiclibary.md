####Create Date: 2016年1月15号 19:39
####Author:Norman
####Descript:

####动态载入库
	1.共享库动态加载 意味着最终链接操作可以延迟到程序真正运行时
		UNIX:	
			dlopen():可能同时触发多个其他共享库载入
			dlopen() 提供两种机制:
				1.1:一次性解决导入库所有未定义符号(RTLD_NOW) ---需要等待相当长时间
				1.2:按遇到的顺序一个个解决未定义符号(RTLD_LAZY)
				----冒一定风险,运行过程中,突然发现某个未定义符号无法解决,将导致程序崩溃
			dlsym()
				dlsym()调用时,需要传入一个string类型的参数,表示要查找的符号的名称,返回该符号所在地址的指针
		Windows:
			LoadLibrary():获取共享库名称,并将其载入运行程序的地址空间
			GetProcAddress()
			
	2.动态载入与C++特性的交互:
		2.1:修改后的变量名,当调用dlsym时,它接收一个包含符号名的字符串,这里的符号名必须是链接器可识别的名字
		2.2:最好办法是只使用唯一一个常用的入口点extern "C" 它可以已经调用过dlsym  这个入口点可以是一个工厂函数,返回一个指向C++对象的指针,它允许访问所有的C++精华
		2.3:构造函数和析构函数
			UNIX:
				_init 和_fini
				__attribute_((constructor))
				__attribute_((destructor))
			Windows:
				DLL_PROCESS_ATTACH
				DLL_PROCESS_DETACH 参数的DLLMain函数
		2.4:动态加载可以很好地例用"折叠重复"
			