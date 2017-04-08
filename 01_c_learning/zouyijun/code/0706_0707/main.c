#include <stdio.h>
#include "btree.h"

typedef struct node {
	int data;
	BTNODE tree_node;
} BNODE;

static void print_node(BTNODE *bnode)
{
	printf("%d ", container_of(bnode, BNODE, tree_node)->data);
}

static int compare_data(BTNODE *a, BTNODE *b)
{
	BNODE *ba = container_of(a, BNODE, tree_node);
	BNODE *bb = container_of(b, BNODE, tree_node);
	return ba->data - bb->data;
}

int main()
{
	BTREE tree;
	init_btree(&tree);

	int arr[] = {5,9,0,3,7,100 /*,4,6,1,3,2,87, -1, 8, -3*/};
	int n = sizeof(arr)/sizeof(int);
	BNODE nodes[n];
	for (int i = 0; i < n; i++) {
		(nodes + i)->data = *(arr + i);
		tree.bnode_init(&(nodes + i)->tree_node);
		tree.insert(&tree, &(nodes + i)->tree_node, compare_data);
	}
#if 1
	printf("\n      中序遍历：");
	tree.in(&tree, print_node);
	printf("\n非递归中序遍历：");
	tree.in_norec(&tree, print_node);

	printf("\n      先序遍历：");
	tree.prev(&tree, print_node);
	printf("\n非递归先序遍历：");
	tree.prev_norec(&tree, print_node);
	
	printf("\n      后序遍历：");
	tree.post(&tree, print_node);
	printf("\n非递归后序遍历：");
	tree.post_norec(&tree, print_node);
	
	printf("\n\n层序遍历: ");
	tree.level(&tree, print_node);
	printf("\nafter reverse, 层序遍历：");
	tree.reverse(&tree);
	tree.level(&tree, print_node);
	printf("\n");

	printf("树的深度是：%d\n", tree.depth(&tree));

	printf("%s是平衡二叉树.\n", tree.is_balance(&tree) ? "":"不");

	destroy_btree(&tree);

#endif

#if 0
	printf("查找：\n");
	BTNODE *find = tree.search(&tree, &(nodes - 1)->tree_node, compare_data);
	if (find) {
		printf("找到了，节点的值为：%d\n", 
				container_of(find, BNODE, tree_node)->data);
	} else {
		printf("没找到！\n");
	}

	printf("二叉树上值最小的节点值是：%d\n",
			container_of(tree.search_min(&tree), BNODE, tree_node)->data);
	printf("二叉树上值最大的节点值是：%d\n",
			container_of(tree.search_max(&tree), BNODE, tree_node)->data);

	printf("删除节点后，中序：");
	tree.del(&tree, &(nodes + 2)->tree_node);
	tree.in(&tree, print_node);
	printf("\n");
#endif

	return 0;
}
