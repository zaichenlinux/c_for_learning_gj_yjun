#include <stdio.h>
#include "btree.h"

typedef int elem_t;
struct node {
	elem_t data;
	struct btree_node bnode;
};

static inline int cmp_data(struct btree_node *a, struct btree_node *b)
{
	struct node *pa = container_of(a, struct node, bnode);
	struct node *pb = container_of(b, struct node, bnode);
	return pa->data - pb->data;
}

static inline void print_node(struct btree_node *node)
{
	printf("%d ", container_of(node, struct node, bnode)->data);
}

int main(void)
{
	struct btree btree;
	btree_init(&btree);

#if 1
	struct node s[] = {
		{6}, {3}, {-2}, {7}, {2},
		{11}, {0}, {5}, {25}, {13}, {20},
	};
#endif

	//struct node s[] = {{5}, {0}, {-3}, {3}, {8}};
	int n = sizeof(s)/sizeof(struct node);
	int i = 0;
	for (; i < n; i++) {
		btree.bnode_init(&(s + i)->bnode);
		btree.build(&btree, &(s + i)->bnode, cmp_data);
	}
	printf("递归前序遍历：");
	btree.preorder(btree.root, print_node);
	printf("\n递归中序遍历：");
	btree.inorder(btree.root, print_node);
	printf("\n递归后序遍历：");
	btree.postorder(btree.root, print_node);
	printf("\n");
	printf("非递归前序遍历：");
	btree.norec_preorder(&btree, print_node);
	printf("\n非递归中序遍历：");
	btree.norec_inorder(&btree, print_node);
	printf("\n非递归后序遍历：");
	btree.norec_postorder(&btree, print_node);

	printf("\n层序遍历：");
	btree.level_order(&btree, print_node);
	printf("\n");

	printf("树的深度 ＝ %lu\n", btree.depth(&btree));




	btree_destroy(&btree);

	return 0;
}
