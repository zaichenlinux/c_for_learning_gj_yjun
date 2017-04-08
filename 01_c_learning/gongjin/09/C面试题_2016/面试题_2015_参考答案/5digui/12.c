
//用递归实现链表逆序

#include <stdio.h>
#include <stdlib.h>

#define M 10
struct node {
	int data;
	struct node *next;
};

void add_elem(struct node **head, int data)
{
	struct node *tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = data;
	tmp->next = *head;
	*head = tmp;
}

void print_list(struct node *head)
{
	while (head) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void reverse_list(struct node **head)
{
	if(!*head)//如果(*head)==NULL
		return;
	struct node *p1,*p2;
	p1 = *head;
	p2 = (*head)->next;
	if (!p2)//如果没有下一个节点
		return;
	reverse_list(&p2);//同时存在两个节点就要进行翻转，主要是要保证第一个节点指向NULL
	p1->next->next = p1;
	p1->next = NULL;
	*head = p2;
}

int main(void)
{
	struct node *head = NULL;
	
	int i;
	for(i=0; i<M; i++)
		add_elem(&head, rand()%100);
	print_list(head);
	reverse_list(&head);
	print_list(head);
	
	return 0;
}

