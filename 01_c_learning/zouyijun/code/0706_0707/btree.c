#include <stdio.h>
#include "btree.h"
#include "queue.h"
#include "stack.h"

static BTNODE *bnode_init(BTNODE *bnode)
{
	bnode->parent = NULL;
	bnode->lchild = NULL;
	bnode->rchild = NULL;
	return bnode;
}

static int __btree_is_empty(BTREE *tree)
{
	return !tree->root; // 空返回1
}

static void insert_node(BTREE *tree, BTNODE *node, 
		int (*cmp)(BTNODE *, BTNODE *))
{
	// 判断树是否为空，如果空，说明插入的第一个节点，将会作为根节点
	if (__btree_is_empty(tree)) {
		tree->root = node; // 根节点
	}

	BTNODE *parent = NULL;

	BTNODE *cur = tree->root; // 用来遍历二叉树的，以确定将来插入节点的位置
	int compare = 0; // 用来比较节点的值的大小的
	while (cur) {
		parent = cur;
		compare = cmp(node, cur);
		if (compare < 0) {
			cur = cur->lchild;
		} else if (compare > 0) {
			cur = cur->rchild;
		} else { // 不允许插入值相同的节点
			return;
		}
	}

	// 插入node节点到二叉树
	if (compare < 0) { // 插入到左子树上
		parent->lchild = node;
	} else {
		parent->rchild = node;
	}
	node->parent = parent;
}

static void __prev_order(BTNODE *node, void (*todo)(BTNODE *))
{
	if (node) {
		todo(node);
		__prev_order(node->lchild, todo);
		__prev_order(node->rchild, todo);
	}
}
static void prev_order(BTREE *tree, void (*todo)(BTNODE *))
{
	__prev_order(tree->root, todo);	
}

static void __in_order(BTNODE *node, void (*todo)(BTNODE *))
{
	if (node) {
		__in_order(node->lchild, todo);
		todo(node);
		__in_order(node->rchild, todo);
	}
}
static void in_order(BTREE *tree, void (*todo)(BTNODE *))
{
	__in_order(tree->root, todo);	
}

static void __post_order(BTNODE *node, void (*todo)(BTNODE *))
{
	if (node) {
		__post_order(node->lchild, todo);
		__post_order(node->rchild, todo);
		todo(node);
	}
}
static void post_order(BTREE *tree, void (*todo)(BTNODE *))
{
	__post_order(tree->root, todo);	
}

static BTNODE *search_node(BTREE *tree, BTNODE *node, int (*cmp)(BTNODE *, BTNODE *))
{
	BTNODE *cur = tree->root; // 用来遍历二叉树的
	int cmp_value = 0;
	while (cur) {
		cmp_value = cmp(node, cur);
		if (cmp_value == 0) {
			return cur;
		} else if (cmp_value < 0) {
			cur = cur->lchild;
		} else {
			cur = cur->rchild;
		}
	}

	return NULL;
}

static BTNODE *search_min(BTREE *tree)
{
	BTNODE *cur = tree->root;
	while (cur->lchild) {
		cur = cur->lchild;
	}
	return cur;
}

static BTNODE *search_max(BTREE *tree)
{
	BTNODE *cur = tree->root;
	while (cur->rchild) {
		cur = cur->rchild;
	}
	return cur;
}

static void del_node(BTREE *tree, BTNODE *node)
{
	typedef enum NODE_TYPE {
		ROOT, LCHILD, RCHILD,
	} TYPE; // 节点类型

	// 判断节点的类型（根节点，某节点的左孩子，某节点的右孩子）
	TYPE type;
	if (!node->parent) { // 节点是根节点
		type = ROOT;
	} else if (node == node->parent->lchild) { // 节点是某个节点的左孩子
		type = LCHILD;
	} else if (node == node->parent->rchild) { // 节点是某个节点的右孩子
		type = RCHILD;
	}

	if (!node->lchild && !node->rchild) { // 要删除的节点是叶子节点（没有左右孩子）
		switch (type) {
		case ROOT:
			//node->parent = NULL;
			tree->root = NULL;
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

	} else if (node->lchild && !node->rchild) { // 要删除的节点只有左孩子，没有右孩子
		
		switch (type) {
		case ROOT:
			tree->root = node->lchild;
		   	node->lchild = NULL;
			tree->root->parent = NULL;	
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
	} else if (!node->lchild && node->rchild) { // 要删除的节点只有右孩子，没有左孩子
		switch (type) {
		case ROOT:
			tree->root = node->rchild;
		   	node->rchild = NULL;
			tree->root->parent = NULL;	
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
	
	} else { // 要删除的节点有左右两个孩子
		// 能顶替要删除掉的节点的节点可以是：
		// 1, 要删除的节点的左孩子的最右边的孩子
		// 或者
		// 2, 要删除的节点的有孩子的最左边的孩子
		// 下面以1来做

		//1> 先找到能顶替删除的节点的那个节点
		BTNODE *cur = node->lchild;
		while (cur->rchild) { // 如果有右孩子，从这个循环出来之后，cur就指向了这个右孩子
			cur = cur->rchild;
		}

		//2> 判断cur节点是cur的父亲节点的左孩子还是右孩子
		if (cur == cur->parent->lchild) { //cur是它父亲的左孩子 
			cur->parent->lchild = cur->lchild;
		} else { // cur是它父亲的右孩子
			cur->parent->rchild = cur->lchild;
		}
		if (cur->lchild) { // 能顶替的节点的左孩子存在
			cur->lchild->parent = cur->parent;
		}

		// 删除掉能代替的节点(cur指向的节点)
		bnode_init(cur);

		switch (type) { 
			case ROOT:
				tree->root = cur;
				break;
			case LCHILD:
				node->parent->lchild = cur;
				break;
			case RCHILD:
				node->parent->rchild = cur;
				break;
		}

		// cur接收node节点的所有关系
		cur->parent = node->parent;
		cur->lchild = node->lchild;
		cur->rchild = node->rchild;
		if (cur->lchild) {
			cur->lchild->parent = cur;
		}
		cur->rchild->parent = cur;

		// 删除节点
		bnode_init(node);

#if 0
		switch (type) {
		case ROOT:
			btree->root = cur;
			if (cur->lchild) {
				cur->lchild->parent = cur->parent;
				cur->parent->rchild = cur->lchild;
			}
			cur->lchild = node->lchild;
			break;
		case LCHILD:
			cur->parent = node->parent;
			cur->rchild = node->rchild;
			node->rchild->parent = cur;
			node->parent->lchild = cur; //
			bnode_init(node);

			break;
		case RCHILD:
			cur->parent = node->parent;
			cur->rchild = node->rchild;
			node->rchild->parent = cur;
			node->parent->rchild = cur; //
			bnode_init(node);
			break;
		}
#endif
	
	}
}

static void level_order(BTREE *tree, void (*todo)(BTNODE *))
{
	QUEUE queue; // 创建队列
	init_queue(&queue); // 初始化队列
	
	BTNODE *cur = tree->root; // cur用来遍历二叉树
	queue.push(&queue, cur); // 将根节点无条件入队
	
	while (!queue.is_empty(&queue)) { // 判断队列是否为空，只要不为空，将队头节点出栈，将队头节点的左右孩子入队
		cur = queue.pop(&queue);
		todo(cur); 
		if (cur->lchild) {
			queue.push(&queue, cur->lchild);
		} 
		if (cur->rchild) {
			queue.push(&queue, cur->rchild);
		}
	}

	destroy_queue(&queue);
}

static void __reverse(BTNODE *node)
{
	if (!node || !(node->lchild) && !(node->rchild)) {
		return;
	}

	BTNODE *tmp = node->lchild;
	node->lchild = node->rchild;
	node->rchild = tmp;
		
	__reverse(node->lchild);
	__reverse(node->rchild);
}

static void reverse(BTREE *tree)
{
	__reverse(tree->root);
}

static int __depth(BTNODE *node)
{
	int ldepth = 0, rdepth = 0; // 分别记录左右子树的深度
	if (node) {
		ldepth = __depth(node->lchild);
		rdepth = __depth(node->rchild);
		return ldepth > rdepth ? ldepth + 1 : rdepth + 1;
	}
	return 0; // 树为空，深度为0
}

static int depth(BTREE *tree)
{
	return __depth(tree->root);
}

static int __is_balance(BTNODE *node) // 平衡二叉树：-1<=左右子树深度差<=1
{
	if (!node) { // 树为空，视为平衡二叉树
		return 1;
	}

	int ldepth, rdepth; // 分别记录左右子树的深度
	int tmp;
	if (__is_balance(node->lchild) && __is_balance(node->rchild)) {
		ldepth = __depth(node->lchild);
		rdepth = __depth(node->rchild);
		tmp = ldepth - rdepth;
		if ((tmp >= -1) && (tmp <= 1)) { // 是平衡二叉树
			return 1;
		}
	}

	return 0;
}

static int tree_is_balance(BTREE *tree)
{
	return __is_balance(tree->root);
}

// 递归遍历二叉树
static void prev_order_norec(BTREE *tree, void (*todo)(BTNODE *))
{
	STACK stack; 
	init_stack(&stack);

	BTNODE *cur = tree->root;

	while (!stack.is_empty(&stack) || cur) { // 如果这个条件不满足了，说明所有的节点已经遍历完毕
		if (cur) {
			todo(cur);
			stack.push(&stack, cur);
			cur = cur->lchild;
		} else {
			cur = stack.pop(&stack);
			cur = cur->rchild;
		}
	}

	destroy_stack(&stack);
}

static void in_order_norec(BTREE *tree, void (*todo)(BTNODE *))
{
	STACK stack; 
	init_stack(&stack);

	BTNODE *cur = tree->root;

	while (!stack.is_empty(&stack) || cur) { // 如果这个条件不满足了，说明所有的节点已经遍历完毕
		if (cur) {
			stack.push(&stack, cur);
			cur = cur->lchild;
		} else {
			cur = stack.pop(&stack);
			todo(cur);
			cur = cur->rchild;
		}
	}

	destroy_stack(&stack);
}

static void post_order_norec(BTREE *tree, void (*todo)(BTNODE *))
{
	STACK stack; 
	init_stack(&stack);

	BTNODE *cur = tree->root;
	BTNODE *tmp = NULL; // 用来记录cur的右边节点存在，并且之前有没有被todo过
	while (!stack.is_empty(&stack) || cur) { // 如果这个条件不满足了，说明所有的节点已经遍历完毕
		if (cur) {
			stack.push(&stack, cur);
			cur = cur->lchild;
		} else {
			cur = stack.top(&stack);
			cur = cur->rchild;
			if (cur && (tmp != cur)) { // 如果栈顶节点的右孩子存在, 并且之前没有被todo过的话
				stack.push(&stack, cur);
				cur = cur->lchild;
			} else {
				cur = stack.pop(&stack);
				todo(cur);
				tmp = cur;
				cur = NULL;
			}
		}
	}

	destroy_stack(&stack);
}

void init_btree(BTREE *tree)
{
	tree->root = NULL;

	tree->bnode_init = bnode_init; 
	tree->insert = insert_node;
	tree->in = in_order;
	tree->prev = prev_order;
	tree->post = post_order;
	tree->level = level_order;
	
	tree->prev_norec = prev_order_norec;
	tree->in_norec = in_order_norec;
	tree->post_norec = post_order_norec;

	tree->search = search_node;
	tree->search_min = search_min;
	tree->search_max = search_max;

	tree->del = del_node;
	tree->reverse = reverse;
	tree->depth = depth;

	tree->is_balance = tree_is_balance;
}

void __destroy_tree(BTNODE *node)
{
	if (node) {
		__destroy_tree(node->lchild);
		__destroy_tree(node->lchild);
		bnode_init(node);
	}
}

void destroy_btree(BTREE *tree)
{
	__destroy_tree(tree->root);
}
