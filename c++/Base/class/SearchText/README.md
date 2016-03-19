/**
* Create Date:2016年03月18日星期五 13:07:02
* 
* Author:Norman
* 
* Description: 
*/

####文本查询程序（ksd）
	1.用户在一个给定文件中查询单词。
	2.查询结果是单词在文件中出现的次数及其所在行的列表，如果一个单词在一行中出现多次，此行只列出一次。
	3.行按照升序输出。
	
	在一个文件中的内容如下：
		Alice Emma has long flowing red hair.
		Her Daddy says when the wind blows
		through her hair it looks almost alive,
		like a friery bird in flight
		A beautiful fiery bird, he tells her,
		magical but untamed.
		“Daddy, shush, there is no such thing,”
		she tells him, at the same time wanting
		him to tell her more.
		Shyly, she asks, “I mean, Daddy, is there?”
－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－

####程序支持如下查询形式。
	1.单词查询，用于得到匹配某个给定string的所有行：
		Executing Query for: Daddy
		Daddy occurs 3 times
		(line  2) Her Daddy says when the wind blows
		(line  7) "Daddy, shush, there is no such thing,"
		(line 10) Shyly, she asks, "I mean, Daddy, is there?"

	2.逻辑非查询， 运用～运算符得到不匹配查询条件的所有行：
		Executing Query for: ~(Alice)
		~(Alice) occurs 9 times
		(line  2) Her Daddy says when the wind blows
		(line  3) through her hair, it looks almost alive,
		(line  4) like a fiery bird in flight.

	3.逻辑或查询， 使用 ｜ 运算符返回匹配俩个条件中任意一个的行：
		Executing Query for: (hair | Alice)
		(hair | Alice) occurs 2 times
		(line  1) Alice Emma has long flowing red hair.
		(line  3) throught her hair, it looks almost alive,

####4.逻辑与查询， 使用 & 运算符返回匹配全部两个条件的行：
		Executing Query for: (hair & Alice)
		(hair & Alice) occurs 1 time
		(line  1) Alice Emma has long flowing red hair.

####5.混合查询， 比如：
		Executing Query for: ((fiery & bird) | wind)
		((fiery & bird) | wind) occurs 3 times
		(line  2) Her Daddy says when the wind blows
		(line  4) like a fiery bird in flight.
		(line  5) A beautiful fiery bird, he tells her,


#####由上面得知：我们可以将几种不同的查询建模成独立的类，这些类共享一个公共基类：
		WordQuery               // 单词查询
		NotQuery                // 逻辑非查询
		OrQuery                 // 逻辑或查询
		AndQuery                // 逻辑与查询

####类设计结果：
	                         QueryBase
	                        /    |    \
	                       /     |     \
	                      /      |      \
	                     /       |       \
	             WordQuery    NotQuery    BinaryQuery
	                                       /       \
				                          /         \
				                         /           \
				                        /             \
				                    AndQuery        OrQuery



####程序可能用到的类：
	TextQuery         该类读入给定的文件并建立一个查找图，单词包含的行号和对应文本保存在TextQuery类里。
		  这个类包含一个query函数，

	QueryResult       该类保存一个query的操作结果，表达查询的结果


	Query             该类是一个接口类，指向QueryBase派生类的对象