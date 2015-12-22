
1.宏定义
#define LIST_HEAD_INIT(name)\
	{&(name),&(name)}    //初始化

#define LIST_HEAD(name)\
struct list_head name=LIST_HEAD_INIT(name)   //定义时初始化

static inline void list_add() //在链表头插入,实现栈功能
static inline void list_add_tail() //在链表尾插入实现队列功能
