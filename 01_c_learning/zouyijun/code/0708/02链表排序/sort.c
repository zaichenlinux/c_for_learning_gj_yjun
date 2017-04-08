#include "sort.h"

static void swap_node(list_head *a, list_head *b)
{
	//list_head tmp = *b;
	list_head tmp;
	__add(&tmp, b, b->next);
	list_del_init(b);
	__add(b, a->prev, a);
	list_del_init(a);
	__add(a, tmp.prev, &tmp);
	list_del_init(&tmp);
}

static void bubble_sort(list_head *head, int (*cmp)(list_head *, list_head *))
{
	list_head *cur, *tmp;
	for (cur = head->next; cur != head->prev; cur = cur->next) {
  		for (tmp = head->prev; tmp != cur; tmp = tmp->prev) {
			if (cmp(tmp, tmp->prev) < 0) {
				swap_node(tmp, tmp->prev); // 当两个节点交换之后，指针的指向也交换了，所以当cur和tmp相遇时，cur的指向也改变了，所以cur需要复位
				tmp = tmp->next;
				if (cur == tmp) {
					cur = cur->prev;
				}
			}
		}
	}
}

static void select_sort(list_head *head, int (*cmp)(list_head *, list_head *))
{
	struct list_head *cur, *tmp;
	struct list_head *save; // 用来记录值最小的节点的地址
	for (cur = head->next; cur != head->prev; cur = cur->next) {
		for (save = cur, tmp = cur->next; tmp != head; tmp = tmp->next) {
			if (cmp(tmp, save) < 0) {
				save = tmp;
			}
		}
		if (save != cur) {
			swap_node(save, cur);
			cur = save; // 交换之后，指针需要复位
		}
	}
}
static void insert_sort(list_head *head, int (*cmp)(list_head *, list_head *))
{
	list_head *cur, *tmp;
	list_head *save;
	for (cur = head->next->next; cur != head; cur = cur->next) {
		for (save = cur, tmp = cur->prev; tmp != head; tmp = tmp->prev) {
			if (cmp(tmp, save) > 0) {
				// 可以用55和56行的做法，也可以用58行的做法
				//list_del_init(tmp); // 删除tmp指向的节点，插入到save之后
				//__add(tmp, save, save->next);

				swap_node(tmp, save);
				//tmp = tmp->prev;
			}
		}
	}
}

void init_sort(SORT *sort)
{
	sort->swap = swap_node;
	sort->bubble = bubble_sort;
	sort->select = select_sort;
	sort->insert = insert_sort;
}

