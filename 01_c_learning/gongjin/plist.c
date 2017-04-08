/*
链表
根据是否带头
带头链表
不带头链表

根据是否循环
循环链表
单向链表

linux  带头双向循环链表

*/

//插入操作
//头插
static void list_add_head(struct plist * plist, int data)
{
	//1.通过传递过来的数据生成节点
	struct  node * node = (struct node *)malloc(sizeof(struct node));
	assert(node);
	//对节点初始化
	node->data = data;
	node->next = node;
	struct node *cur = plist->head;  //定义中间节点变量，用于循环找到最后一个节点
	//2.当这个链表为空时候
	if(NULL == plist->head) {
		plist->head = node;
	} else {
		node->next  = plist->head;
		for(;cur->next != plist->head;cur=cur->next);
		plist->head = node;
		cur->next = plist->head;
	}
}

//尾插：
//尾插:把节点插入到最后一个节点的后面
static void list_add_tail(struct plist * plist, int data)
{
		//1.通过传递过来的数据生成节点
	struct  node * node = (struct node *)malloc(sizeof(struct node));
	assert(node);
	//对节点初始化
	node->data = data;
	node->next = node;
	struct node *cur = plist->head;  //定义中间节点变量，用于循环找到最后一个节点
	//2.当这个链表为空时候
	if(NULL == plist->head) {
		plist->head = node;
	} else {
		for(;cur->next != plist->head;cur=cur->next);
		cur->next = node;
		node->next = plist->head;
	}
}


//遍历：
//遍历:逐个打印每个数据
//逐个访问每个节点,然后对对应的节点进行操作.
//挨个打印每个节点的值
void list_for_each(struct plist *plist)
{
	//如果该链表为空
	if(NULL == plist->head) {
		printf("%s, %s, %d:链表为空\n", __func__, __FILE__, __LINE__);
		return ;
	}

	//定义一个中间变量cur 用于逐个打印
	struct node * cur = plist->head;

	for(;cur->next != plist->head;cur=cur->next){
		printf("%d   ", cur->data);
	}
	//该循环出来之后  cur是指向链表中最后一个节点
	//但最后一个节点由于不满足循环的条件，直接退出
	//最后一个节点尚未处理

	printf("%d\n", cur->data);
}

//删除：
//删除节点:按节点删除,第二个参数是struct node *
static void list_del(struct plist * plist, struct node * node)
{
	if(NULL == plist->head) {
		printf("%s, %s, %d:链表为空\n", __func__, __FILE__, __LINE__);
		return ;
	}
	struct node *cur = plist->head;
	//通过遍历 找到链表中对应的节点
	//1.删除的这个链表只有一个节点
	if((node->next == plist->head) && (plist->head == node)){
		plist->head = NULL;
		free(node);
		node = NULL;
		return ;
	}

	for(;cur->next != node  ;cur=cur->next){
		if(cur->next == plist->head) {
			printf("该节点不存在\n");
		}
	}
	//该链表不为空，并且要删除的节点是该链表中第一个节点
	if(plist->head == node){
		plist->head = node->next;
	}

	cur->next = node->next;
	free(node);
	node = NULL;
}

//查找：
//查找:按数据找位置
//返回-1表示没有找数据
static int list_search(struct plist * plist, int data)
{
	//判断该链表是否为空
	if(NULL == plist->head) {
		printf("%s, %s, %d:链表为空\n", __func__, __FILE__, __LINE__);
		return ;
	}
	int i = 1;
	//定义cur节点用于遍历
	struct node *cur = plist->head;

	for(;cur->next != plist->head;cur=cur->next,i++) {
		if(data == cur->data)
			return i;
	}

	if(data == cur->data) return i;
	else return -1;
}

//打印





