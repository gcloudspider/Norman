####线程组
    线程组对象thread_group来组织它们
    thread_group对象可以使用多种方法管理线程
    1.使用一个指向动态创建的线程对象的指针来作为参数调用add_thread方法
    2.将这个线程加入线程组(或直接使用线程组类的create_thread方法,可不先创建线程而直接把线程加入到线程组中)
    3.线程组对象的析构函数被调用时,它将删除所有这些通过add_thread方法加入的线程指针.所以只能将堆上的线程对象指针通过add_thread方法加入线程组
    4.remove_thread方法从线程组删除某个线程的指针.仍需要负责把线程本身内存释放
