###################################################
#### Create Date:2016年01月16日 星期六 20时20分02秒
####
####Author:Norman
####
####Description: 单例模式
###################################################

####单例模式:
    单例模式:在应用程序中保持一个唯一的实例(如IO处理,数据库操作等)
    由于这些对象都要占用重要的系统资源,所以必须限制这些实例的创建或始终使用一个公用的实例


    单例模式:保证一个类仅有一个实例,并提供一个访问它的全局访问点

####主要特点:
    不是根据用户程序调用生成一个新的实例,而是控制某个类型的实例唯一性,通过上图我们知道它包含的角色只有一个
    它拥有一个私有构造函数,确保用户无法通过new直接实例它,除此之外,该模式中包含一个静态私有成员变量instance与静态公有方法Instance 
    Instance()方法负责检验并实例化自己,然后并存储在静态成员变量中,以确保只有一个实例被创建

####实现方式:
    1.有一个私有的无参构造函数,可以防止其他类实例化它,而且单例类也不应该被继承,如果单例类允许继承那么每个子类都可以创建实例,违背了singleton模式"唯一实例初衷"
    2.单例类被定义为sealed 该类定义成不允许派,但没有要求一定要这样定义
    3.一个静态的变量用来保存单实例的引用
    4.一个公有静态方法用来获取单实例的引用,如果实例为null即创建一个