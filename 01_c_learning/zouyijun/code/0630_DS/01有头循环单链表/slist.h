
// 链表：用同一种类型的节点连接起来的一种数据结构
// 下面的代码是针对：有头的循环的单向链表
// 头节点：指的是在第一个有效节点（保存有效数据的节点）之前附加的一个节点，称为头节点
// 首元节点：指的是头节点之后的那个节点（如果是无头的链表，那么首元节点之前没有头节点）
// 头指针：指向头节点的指针（如果是无头的链表，那么头指针指向首元节点）

// 循环链表：指的是链表上的最后一个节点指向链表的头节点（如果没有头节点，那么就指向首元节点）
// 非循环链表：指的是链表上的最后一个节点指向NULL

// 对于链表这种数据结构，操作有：建立链表(插入节点)，删除链表，删除节点，查找节点，遍历链表，判断链表是否为空

typedef int elem_t;

// 下面的类型用来描述链表上的节点
typedef struct node {
	elem_t data; // 数据域
	struct node *next; // 指针域
} NODE;	

// 下面的类型用来描述链表
typedef struct list {
	// 成员（属性，行为）
	NODE head; // 头节点

	// 对于链表的操作
	// 插入节点(头部插入，尾部插入)
	// 第1个参数表示要插入到的链表,第2个参数表示插入的节点
	void (*insert_head)(struct list *, NODE *); // 头插: 插入新节点到链表的首元节点的前面
	void (*insert_tail)(struct list *, NODE *); // 尾插: 插入新节点到最后一个节点的后面

	void (*del)(struct list *, NODE *); // 删除节点

	NODE *(*search)(struct list *, NODE *); // 查找节点

	void (*list_for_each)(struct list *); // 遍历链表
	void (*destroy)(struct list *); // 删除链表(销毁整条链表)
} list;

// 初始化链表的函数(用来初始化链表类型的对象的)
void init_list(list *);
