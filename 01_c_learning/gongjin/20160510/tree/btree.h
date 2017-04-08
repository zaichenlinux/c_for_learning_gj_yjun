#pragma once
#include "list.h"

#if 0
	根据节点所处于的位置，分为：根节点，中间节点，叶子节点
	完全二叉树：严格区分左右孩子，并且如果某节点存在右孩子，则必然存在左孩子的二叉树
	平衡二叉树：它是一 棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。
	满二叉树：节点的个数是2的层数次方－1的完全二叉树
	排序二叉树：任何子树的左孩子节点的值小于父节点，右孩子节点的值大于父节点的二叉树
	树的深度：左右子树层数的较大值

//遍历：
	先序遍历：先遍历根节点，然后是左子树，最后是右子树
	中序遍历：先遍历左子树，然后是根节点，最后是右子树
	后序遍历：先遍历左子树，然后是右子树，最后是根节点
	层序遍历：从顶层开始一层一层（从左向右）向下遍历

	节点的度：一个节点含有的子树的个数称为该节点的度；
	叶节点或终端节点：度为0的节点称为叶节点；
	非终端节点或分支节点：度不为0的节点；
	双亲节点或父节点：若一个节点含有子节点，则这个节点称为其子节点的父节点；
	孩子节点或子节点：一个节点含有的子树的根节点称为该节点的子节点；
	兄弟节点：具有相同父节点的节点互称为兄弟节点；
	树的度：一棵树中，最大的节点的度称为树的度；
	节点的层次：从根开始定义起，根为第1层，根的子节点为第2层，以此类推；
	树的高度或深度：树中节点的最大层次；
	堂兄弟节点：双亲在同一层的节点互为堂兄弟；
	节点的祖先：从根到该节点所经分支上的所有节点；
	子孙：以某节点为根的子树中任一节点都称为该节点的子孙。
	森林：由m（m>=0）棵互不相交的树的集合称为森林；


#endif

struct btree_node {
	struct btree_node *parent; //父节点
	struct btree_node *lchild; //左孩子节点
	struct btree_node *rchild; //右孩子节点
};

struct btree {
	//属性 
	struct btree_node *root; //树根节点

	//方法
	int (*is_empty)(struct btree *); //判断该树是否为空
	void (*build)(struct btree *, struct btree_node *, 
			int (*cmp)(struct btree_node *, struct btree_node *)); //建立树
	void (*bnode_init)(struct btree_node *); //初始化节点

	//遍历二叉树(递归)
	void (*preorder)(struct btree_node *, void (*)(struct btree_node *)); //前序遍历（先序遍历）
	void (*inorder)(struct btree_node *, void (*)(struct btree_node *)); //中序遍历
	void (*postorder)(struct btree_node *, void (*)(struct btree_node *)); //后序遍历
	
	struct btree_node *(*search)(struct btree *, struct btree_node *, int (*)(struct btree_node *, struct btree_node *)); //查找节点
	struct btree_node *(*search_min)(struct btree *); //查找树上值最小的节点
	struct btree_node *(*search_max)(struct btree *); //查找树上值最大的节点
	
	void (*del)(struct btree *, struct btree_node *); //删除节点
	//遍历二叉树(非递归)
	//前序
	void (*norec_preorder)(struct btree *, 
			void (*)(struct btree_node *));
	//中序
	void (*norec_inorder)(struct btree *, 
			void (*)(struct btree_node *));
	//后序
	void (*norec_postorder)(struct btree *, 
			void (*)(struct btree_node *));
	void (*level_order)(struct btree *, 
			void (*)(struct btree_node *)); //层序遍历
	size_t (*depth)(struct btree *); //求树的深度
};

void btree_init(struct btree *);
void btree_destroy(struct btree *);
