#include <stdio.h>
#include <stdlib.h>

struct btree_node {
	char data;
	struct btree_node *lchild;
	struct btree_node *rchild;
};

int build_tree(struct btree_node *root)
{
	char c;
	scanf("%c", &c);
	if (c == '*')
		root = NULL;
	else {
		//root = (struct btree_node *)malloc(sizeof(struct btree_node));
		if (!root) 
			return 1;
		root->data = c;
		build_tree(root->lchild);
		build_tree(root->rchild);
	}

	return 0;
}

#if 1
int depth(struct btree_node *root)    
{    
    int ldepth = 0, rdepth = 0;
	if (root == NULL)    
        return 0;    
    else {    
        int ldepth = depth(root->lchild);  //获取左子树深度    
        int rdepth = depth(root->rchild); //获取右子树深度    
        return ldepth > rdepth ? ldepth+1 : rdepth+1 ; //取较大值+1即为二叉树深度        
	}    
}  
#endif

void pre_traverse(struct btree_node *root, void (*visit)(char c))
{
	if (root) {
		visit(root->data);
		pre_traverse(root->lchild, visit);
		pre_traverse(root->rchild, visit);
	}
}

void in_traverse(struct btree_node *root, void (*visit)(char c))
{
	if (root) {
		in_traverse(root->lchild, visit);
		visit(root->data);
		in_traverse(root->rchild, visit);
	}
}

void post_traverse(struct btree_node *root, void (*visit)(char c))
{
	if (root) {
		post_traverse(root->lchild, visit);
		post_traverse(root->rchild, visit);
		visit(root->data);
	}
}

//判断二叉树是否平衡
//一颗平衡的二叉树是指其任意结点的左右子树深度之差不大于1。判断一棵二叉树是否是平衡的，可以使用递归算法来实现。

int is_balanced(struct btree_node * root, int * depth)  
{  
    if(root == NULL)  
    {  
        *depth = 0;  
        return 1;  
    }  
   
    int left, right;  
    if(is_balanced(root->lchild, &left) //左子树平衡  
        && is_balanced(root->rchild, &right)) //右子树平衡  
    {  
        int diff = left - right;  
        if(diff <= 1 && diff >= -1)  
        {  
            *depth = 1 + (left > right ? left : right);  
            return 1;  
        }  
    }  
   
    return 0;  
}  

int is_balance(struct btree_node * root)  
{  
    int depth = 0;  
    return is_balanced(root, &depth);  
}  

void print_tree(char c)
{
	printf("%c", c);
}

int main(void)
{
	struct btree_node *root = (struct btree_node *)malloc(sizeof(struct btree_node));

	printf("请输入二叉树序列（如 AB*C***）：");
	build_tree(root);

	printf("先序递归遍历：");
	pre_traverse(root, print_tree);
	printf("\n中序递归遍历：");
	in_traverse(root, print_tree);
	printf("\n后序递归遍历：");
	post_traverse(root, print_tree);

	printf("\n\n");
	printf("%s平衡树", is_balance(root) ? "是" : "不是");

	printf("\n树的深度为：%d\n", depth(root));
	
	return 0;
}

