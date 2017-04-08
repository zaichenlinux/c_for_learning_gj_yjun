#include <stdio.h>
#include "btree.h"
#include "stack.h"
#include "queue.h"


/*
二叉排序树或者是一棵空树，或者是具有下列性质的二叉树：
（1）若左子树不空，则左子树上所有结点的值均小于它的根结点的值；
（2）若右子树不空，则右子树上所有结点的值均大于它的根结点的值；
（3）左、右子树也分别为二叉排序树；
（4）没有键值相等的节点。
*/

//判断树是否为空
//树的根节点如果为NULL 空树
static inline int btree_is_empty(struct btree *btree)
{
	return !btree->root;
}


//节点初始化
static inline void bnode_init(struct btree_node *bnode)
{
	bnode->parent = NULL;
	bnode->lchild = NULL;
	bnode->rchild = NULL;
}


//创建二叉查找树
//cmp 通过两个二叉树的节点，对btree_node结构体的data进行比较
/*
static inline int cmp_data(struct btree_node *a, struct btree_node *b) 
{
    struct node *pa = container_of(a, struct node, bnode);
    struct node *pb = container_of(b, struct node, bnode);
    return pa->data - pb->data;
}
*/

//插入节点，btree， bnode
//二叉排序树的节点是唯一
static inline void build_tree(struct btree *btree, struct btree_node *bnode, int (*cmp)(struct btree_node *, struct btree_node *))
{
	//判断二叉树是否为空,如果为空,直接把root指针指向bnode
	if (btree->is_empty(btree)) {
		btree->root = bnode;
		return;
	}

	int ret;
	struct btree_node *cur = btree->root; //用来遍历树上的节点的临时变量
	struct btree_node *parent = NULL;  //cur的父节点
	while (cur != NULL) {
		ret = cmp(bnode, cur);
		parent = cur;
		if (ret < 0) {
			cur = cur->lchild;
		} else if (ret > 0) {
			cur = cur->rchild;
		} else {
			return; //不允许插入值相同的节点
		}
	}

	if (ret < 0) {
		parent->lchild = bnode;
	} else {
		parent->rchild = bnode;
	}
	bnode->parent = parent;
}

//以递归的方式实现 前序遍历
/*
todo
static inline void print_node(struct btree_node *node)
{
    printf("%d ", container_of(node, struct node, bnode)->data);
}

*/


//递归的方式实现
static inline void preorder(struct btree_node *root, void (*todo)(struct btree_node *))
{
	struct btree_node *cur = root;
	if (cur) {
		todo(cur);  //根
		preorder(cur->lchild, todo);  //左
		preorder(cur->rchild, todo);  //右
	}
}



static inline void inorder(struct btree_node *root, void (*todo)(struct btree_node *))
{
	struct btree_node *cur = root;
	if (cur) {
		inorder(cur->lchild, todo);
		todo(cur);
		inorder(cur->rchild, todo);
	}
}

static inline void postorder(struct btree_node *root, void (*todo)(struct btree_node *))
{
	struct btree_node *cur = root;
	if (cur) {
		postorder(cur->lchild, todo);
		postorder(cur->rchild, todo);
		todo(cur);
	}
}


//查找二叉树，通过data查找，返回btree_node
//比较node和二叉树中节点的data的数据大小，如果node的节点小于二叉树中节点的data，往左孩子方向继续找，
//否则就是往右。
//
static inline struct btree_node *search_node(struct btree *btree, struct btree_node *node, int (*cmp)(struct btree_node *, struct btree_node *))
{
	struct btree_node *cur = btree->root;
	struct btree_node *tmp = NULL;
	int ret;
	while (cur) {
		ret = cmp(node, cur);
		tmp = cur;
		if (ret < 0) {
			cur = cur->lchild;
		} else if (ret > 0) {
			cur = cur->rchild;
		} else {
			return tmp;
		}
	}

	return NULL;
}

//查找最小值，一直找左孩子节点，一直找到该节点左孩子为空
static inline struct btree_node *search_min(struct btree *btree)
{
	struct btree_node *cur = btree->root;
	while (cur->lchild) {
		cur = cur->lchild;
	}
	return cur;
}

//查找最大值，一直找右孩子节点，一直找到该节点右孩子为空
static inline struct btree_node *search_max(struct btree *btree)
{
	struct btree_node *cur = btree->root;
	while (cur->rchild) {
		cur = cur->rchild;
	}
	return cur;
}


//删除节点，删除某个节点之后，该树还是一个二叉排序树。
static inline void btree_del(struct btree *btree, struct btree_node *node)
{
	//要删除节点的身份
	//表示当前节点的相对父节点的身份，
	enum id_t {
		ROOT, LCHILD, RCHILD,
	} id;

	//判断该节点是什么身份
	if (btree->root == node) { //要删除的节点是根节点
		id = ROOT;
	} else if (node->parent->lchild == node) { //要删除的节点是某节点的左孩子
		id = LCHILD;
	} else { //要删除的节点是某节点的右孩子
		id = RCHILD;
	}

	if (!node->lchild && !node->rchild) { //要删除的节点是叶子节点
		switch (id) {
			case ROOT:
				btree->root = NULL;
				break;
			case LCHILD:
				node->parent->lchild = NULL;
				node->parent = NULL;
				break;
			case RCHILD:
				node->parent->rchild = NULL;
				node->parent = NULL;
				break;
		}
	} else if (node->lchild && !node->rchild) { //要删除的节点只有左孩子，没有右孩子 
		switch (id) {
			case ROOT:
				btree->root = node->lchild;
				node->lchild->parent = NULL;
				node->lchild = NULL; 
				break;
			case LCHILD:
				node->parent->lchild = node->lchild;
				node->lchild->parent = node->parent;
				bnode_init(node);
				break;
			case RCHILD:
				node->parent->rchild = node->lchild;
				node->lchild->parent = node->parent;
				bnode_init(node);
				break;
		}

	} else if (!node->lchild && node->rchild) { //要删除的节点只有右孩子，没有左孩子
		switch (id) {
			case ROOT:
				btree->root = node->rchild;
				node->rchild->parent = NULL;
				node->rchild = NULL; 
				break;
			case LCHILD:
				node->parent->lchild = node->rchild;
				node->rchild->parent = node->parent;
				bnode_init(node);
				break;
			case RCHILD:
				node->parent->rchild = node->rchild;
				node->rchild->parent = node->parent;
				bnode_init(node);
				break;
		}
	} else { //要删除的节点有左右两个孩子
		//满足能顶替要删除节点的节点的条件是以下之一：
		//1、要删除节点的左孩子的最右边的孩子（实质就是找要删除节点的左子树中的值最大的节点）
		//2、要删除节点的右孩子的最左边的孩子（实质就是找要删除节点的右子树中的值最小的节点）
		//我们以1来实现

		//1> 定位到要顶替的节点
		struct btree_node *cur = node->lchild;
		while (cur->rchild) {
			cur = cur->rchild;
		}

		if (cur == cur->parent->lchild) { //如果cur是其父亲节点的左孩子
			cur->parent->lchild = cur->lchild;
		} else { //cur是其父亲节点的右孩子
			cur->parent->rchild = cur->lchild;
		}
		if (cur->lchild) { //如果cur存在左孩子
		   	cur->lchild->parent = cur->parent;	
		}

		switch (id) {
			case ROOT:
				btree->root = cur;
				break;
			case LCHILD:
				node->parent->lchild = cur;
				break;
			case RCHILD:
				node->parent->rchild = cur;
				break;
		}

		//cur接收要删除节点node的所有关系
		cur->parent = node->parent;
		cur->lchild = node->lchild;
		cur->rchild = node->rchild;
		if (cur->lchild) {
			cur->lchild->parent = cur;
		}
		cur->rchild->parent = cur;

		bnode_init(node);
	}
}

//非递归的实现方式，数据结构栈
static inline void norec_preorder(struct btree *btree, 
		void (*todo)(struct btree_node *))
{
	struct stack stack;
	stack_init(&stack);

	struct btree_node *cur = btree->root;
	while (!stack.is_empty(&stack) || cur) {
		if (cur) {
			todo(cur);
			stack.push(&stack, cur);
			cur = cur->lchild;
		} else {
			cur = stack.pop(&stack);
			cur = cur->rchild;
		}
	}

	stack_destroy(&stack);
}

static inline void norec_inorder(struct btree *btree, 
		void (*todo)(struct btree_node *))
{
	struct stack stack;
	stack_init(&stack);

	struct btree_node *cur = btree->root;
	while (!stack.is_empty(&stack) || cur) {
		if (cur) {
			stack.push(&stack, cur);
			cur = cur->lchild;
		} else {
			cur = stack.pop(&stack);
			todo(cur);
			cur = cur->rchild;
		}
	}

	stack_destroy(&stack);
}

static inline void norec_postorder(struct btree *btree, 
		void (*todo)(struct btree_node *))
{
	struct stack stack;
	stack_init(&stack);

	struct btree_node *tmp = NULL; //用来记录cur的右孩子是否被todo过
	struct btree_node *cur = btree->root;
	while (!stack.is_empty(&stack) || cur) {
		if (cur) {
			stack.push(&stack, cur);
			cur = cur->lchild;
		} else {
			cur = stack.top(&stack);
			if ((cur->rchild) && (cur->rchild != tmp)) { //cur的右孩子存在，并且之前没有被todo过
				cur = cur->rchild;
			} else {
				cur = stack.pop(&stack);
				todo(cur);
				tmp = cur;
				cur = NULL;
			}
		}
	}

	stack_destroy(&stack);
}


//层次遍历
static inline void level_order(struct btree *btree, 
		void (*todo)(struct btree_node *))
{
	struct queue queue;
	queue_init(&queue);
	
	struct btree_node *cur = btree->root;
	queue.push(&queue, cur);
	
	while (!queue.is_empty(&queue)) {
		cur = queue.pop(&queue);
		todo(cur);

		if (cur->lchild) 
			queue.push(&queue, cur->lchild);
		if (cur->rchild) 
			queue.push(&queue, cur->rchild);
	}

	queue_destroy(&queue);
}

static inline size_t __depth(struct btree *btree, struct btree_node *node)
{
	int ldepth = 0, rdepth = 0;
	if (node) {
		ldepth = __depth(btree, node->lchild);
		rdepth = __depth(btree, node->rchild);
		
		return ldepth >= rdepth ? ldepth + 1: rdepth + 1;
	}

	return ldepth;
}

static inline size_t depth(struct btree *btree)
{
	return __depth(btree, btree->root);	
}



void btree_init(struct btree *btree)
{
	btree->root = NULL;
	btree->is_empty = btree_is_empty;
	btree->bnode_init = bnode_init;
	btree->build = build_tree;

	btree->preorder = preorder;
	btree->inorder = inorder;
	btree->postorder = postorder;
	
	btree->norec_preorder = norec_preorder;
	btree->norec_inorder = norec_inorder;
	btree->norec_postorder = norec_postorder;
	
	btree->level_order = level_order;

	btree->depth = depth;

	btree->search = search_node;
	btree->search_min = search_min;
	btree->search_max = search_max;

	btree->del = btree_del;

//	btree->is_balance = is_balance;
}

static inline void __destroy(struct btree_node *node)
{
	if (node) {
		__destroy(node->lchild);
		__destroy(node->rchild);
		bnode_init(node);
	}
}

void btree_destroy(struct btree *btree)
{
	__destroy(btree->root);
}
