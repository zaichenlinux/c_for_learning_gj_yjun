#pragma once
#include "list.h"

/*
	树上的每一个节点，按照处于的位置，分为3种：
		根节点 （没有父亲的节点）
		中间节点 （有父亲节点，也有孩子节点）
		叶子节点 （有父亲节点，没有孩子节点）

	二叉树分类：
	完全二叉树：如果一个节点，有右孩子，一定存在左孩子，这样的二叉树称为完全二叉树
	满二叉树：除了最后一层的节点没有孩子外，其他每一层都有左右两个孩子的二叉树（也就是说，满足“节点个数=2的层数次方 - 1”的二叉树）
	排序二叉树：一个节点的左子树中的每一个节点的值都比这个这个节点的值小，他的右子树中的每一个节点的值都比这个节点的值大，这样的二叉树称为排序二叉树

	遍历方式：
		先序遍历（前序遍历）：根 --> 左 --> 右
		中序遍历：左 --> 根 --> 右
		后序遍历：左 --> 右 --> 根

		层序遍历：从第一层开始，一层一层向下遍历
   */

// 描述插入到二叉树上的节点
typedef struct btree_node {
	struct btree_node *parent; // 指向父亲节点的指针
	struct btree_node *lchild; // 指向左孩子节点的指针
	struct btree_node *rchild; // 指向右孩子节点的指针
} BTNODE;

// 描述二叉树
typedef struct btree {
	BTNODE *root; // 指向根节点的指针

	BTNODE *(*bnode_init)(BTNODE *); // 初始化树上的节点

	void (*insert)(struct btree *, BTNODE *, 
			int (*cmp)(BTNODE *, BTNODE *)); // 插入节点（建立二叉树的过程）
	void (*prev)(struct btree *, void (*)(BTNODE *)); // 前序遍历二叉树
	void (*in)(struct btree *, void (*)(BTNODE *)); // 中序遍历二叉树
	void (*post)(struct btree *, void (*)(BTNODE *)); // 后序遍历二叉树
	BTNODE *(*search)(struct btree *, BTNODE *, 
			int (*cmp)(BTNODE *, BTNODE *)); // 查找节点
	BTNODE *(*search_min)(struct btree *); // 查找值最小的节点
	BTNODE *(*search_max)(struct btree *); // 查找值最大的节点
	void (*del)(struct btree *, BTNODE *); // 删除节点
	
	void (*level)(struct btree *, void (*)(BTNODE *)); // 层序遍历
	
	void (*reverse)(struct btree *); // 镜面反转整个二叉树
	
	int (*depth)(struct btree *); // 计算数的深度
	int (*is_balance)(struct btree *); // 判断二叉树是否是平衡二叉树（左右子树深度差<=1）
	
	// 非递归的前中后三种遍历
	void (*prev_norec)(struct btree *, void (*)(BTNODE *));
	void (*in_norec)(struct btree *, void (*)(BTNODE *));
	void (*post_norec)(struct btree *, void (*)(BTNODE *));

} BTREE;

void init_btree(BTREE *);
void destroy_btree(BTREE *);
