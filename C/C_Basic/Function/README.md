###############################################
##
##Create Data:2015-11-17
##Author:Norman
##
##
###############################################

编译器工作原理:
	编译器将源程序作为输入,翻译产生使用目标语言的等价程序

编译器工作流程:
	源代码(sourcecode)--->预处理器(preprocessor)---->编译器(compiler)---->汇编程序(assembler) --->目标代码(objectcode) --->连接器(Linker) --->可执行程序(executables)

反编译器:
	1.将高级语言生成的低级语言代码重新生成高级语言代码的编译器
	2.将一种高级语言生成另一种高级语言的编译器
	3.生成需要进一步处理中间代码的编译器


	预处理器:通过代入预定义等程序段将源程序补充完整
	
	编译器前端:负责解析输入的源程序，由词法分析器和语法分析器协同工作
		词法分析器:负责把源程序中(单词)Token找出。
		语法分析器:负责把分散的单词按预先定义好的语法组装成有意义的表达式,语句,函数等

	编译器后端:
		负责分析 优化中间代码 以及生成机器代码

	编译器分析 优化 变型分为:
		1.函数内
		2.函数之间进行

优化范围:
	全局:该优化需要使用到全局的数据流和控制流信息 
	局部:指导优化的信息来自基本块


编译器分析:
	1.前端生成并传递过来的中间代码

	高层的中间代码：接近输入的源程序的格式，与输入语言相关包含更多的全局性的信息和源程序的结构;
	中层的中间代码:与输入语言无关
	低层的中间代码:与机器语言类似

	常见编译分析:
		1.函数调用树(call tree)
		2.控制流程图(Control flow graph)
		3.变量定义-使用,使用-定义链(define-use/use-define or u-d/d-uchain)
		4.变量别名分析(alias analysis)
		5.指针分析(pointer analysis)
		6.数据依赖分析(data dependence analysis)

	分析结果:是优化(compiler optimization)和程序变形(compiler transformation)前提条件

	优化，更新:
		1.函数内嵌(inlining)
		2.无用代码删除(Dead code elimination)
		3.标准化循环结构(loop normalization)
		4.循环体展开(loop unrolling)
		5.循环体合并,分裂(loop fusion loop fission)
		6.数组填充(array padding)
		优化和变形目的减少代码长度,提高内存 缓存的使用率 减少读写磁盘,访问网络数据的频率，
		高级优化--可以反列化的代码(serial code)变成并行运算.多线程的代码(parallelized， multi-threaded code)
