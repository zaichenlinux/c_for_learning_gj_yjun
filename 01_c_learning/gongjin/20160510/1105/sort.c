#include <stdio.h>
#include "sort.h"

static inline void __swap(elem_t *a, elem_t *b)
{
	elem_t tmp = *a;
	*a = *b;
	*b = tmp;
}

static inline void bubble_sort(elem_t *a, size_t n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j+1]) {
				__swap(a + j, a + j + 1);
			}
		}
	}
}

static inline void select_sort(elem_t *a, size_t n)
{
	int i, j, min;
	for (i = 0; i < n - 1; i++) {
		for (min = i, j = i+1; j <= n - 1; j++) {
			if (a[j] < a[min])
				min = j;
		}
		if (i != min) {
			__swap(a + i, a + min);
		}
	}
}

static inline void insert_sort(elem_t *a, size_t n)
{
	int i, j, save; //save用于保存可能被擦写掉的元素的值
	for (i = 1; i <= n - 1; i++) {
		for (save = a[i], j = i - 1; 
				j >= 0 && a[j] > save; 
				j--) {
			a[j+1] = a[j];
		}
		a[j+1] = save;
	}
}

static inline void quick_sort(elem_t *a, size_t n)
{
	if (n <= 1) { //定义递归的结束条件
		return;
	}

	elem_t *pl = a;
	elem_t *pr = a + n - 1;
	elem_t *p = a + n/2;
	elem_t save = *p; //保存中值
	
	//从左边找到第一个比中值大的元素(如果存在的话)，并保存下来
	for (; (pl < p) && (*pl <= *p); pl++) {}
	if (pl < p) { //找到了
		*p = *pl;
	}

	while (1) { //循环 
		//从右边找第一个比中值小的元素(如果没找到，指针继续向前移动)，然后覆盖掉左边那个比中值大的元素
		for (; (pl < pr) && (*pr >= save); pr--) {} 
		if (pl < pr) {
			*pl = *pr;
			pl++;
		} else {
			break;
		}	
		//然后从左边找第一个比中值大的元素(如果没找到，指针继续向后移动)，然后覆盖掉右边那个比中值小的元素
		for (; (pl < pr) && (*pl <= save); pl++) {}
		if (pl < pr) {
			*pr = *pl;
			pr--;
		} else {
			break;
		}
	}
	*pl = save; //当左边和右边对应的指针相遇了，说明找到了中值应该插入的位置

	quick_sort(a, pl - a); //中值左边剩余元素递归
	quick_sort(pl + 1, n - 1 - (pl - a)); //中值右边剩余元素递归
}

//调整完全二叉树为大根堆
static inline void adjust_tree(elem_t *a, size_t i, size_t n)
{
	size_t j = i * 2 + 1; //j记录i节点左孩子的下标；右孩子的下标是左孩子的下标+1
	while (j < n) { //如果左孩子存在
		if (j + 1 < n) { //判断i节点的右孩子是否存在
			if (a[j] < a[j+1]) { //比较左孩子和右孩子节点的值哪个更大
				j = j+1;
			}
		}

		if (a[i] < a[j]) { //父亲节点的值小于孩子节点中值比较大的节点的值时
			__swap(a + i, a + j);
			i = j;
			j = j*2 + 1;
		} else {
			break;
		}
	}
}

//大根堆（大顶堆）：所有子树都满足根节点的值大于其孩子节点的值
//小根堆（小顶堆）：所有子树都满足根节点的值小于其孩子节点的值
static inline void heap_sort(elem_t *a, size_t n)
{
	//初始建立大根堆（是一个完全二叉树）
	//子节点下标＝父亲节点下标*2+1
	int i = n/2 - 1; //最后一个非叶子节点的下标
	for (; i >= 0; i--) {
		adjust_tree(a, i, n);//调整完全二叉树为大根堆
	}

	for (i = n - 1; i > 0; i--) {
		__swap(a + 0, a + i); //交换根节点和最后一个叶子节点
		adjust_tree(a, 0, i); //中间参数0表示该次调整从树根节点开始，因为在上一次交换过树根节点和最后一个叶子节点之后，唯一可能破坏大根堆性质的只有根节点，所以从它开始调整；第3个参数表示还有多少个元素待排序
	}
}

//缩小增量排序
static inline void shell_sort(elem_t *a, size_t n)
{
	int k = n/2; //k是增量
	int i, j, save; //save用于保存可能被擦写掉的元素的值
	for (; k > 0; k/=2) {
		for (i = k; i <= n - 1; i++) {
			for (save = a[i], j = i - k; 
					j >= 0 && a[j] > save; 
					j-=k) {
				a[j+k] = a[j];
			}
			a[j+k] = save;
			//a[j] = save;
		}
	}
}


static inline void merge_sort(elem_t *a, size_t n)
{
	int m = n/2; //用来分割数组为两部分
	int l = 0; //左半部分最左边元素的下标
	int r = l + m; //右半部分最左边元素的下标

	if (m > 0) {
		merge_sort(a, m); //左半部分递归
		merge_sort(a+r, n - m); //右半部分递归
	}

	elem_t b[n]; //暂存数组中已经排好序的较小元素
	int i = 0;
	while ((l < m) && (r < n)) {
		if (a[l] <= a[r]) {
			b[i++] = a[l++];
		} else {
			b[i++] = a[r++];
		}
	}

	while (l < m) {
		b[i++] = a[l++];
	}
	while (r < n) {
		b[i++] = a[r++];
	}

	for (i = 0; i < n; i++) {
		a[i] = b[i];
	}
}

void sort_init(struct sort *sort)
{
	sort->bubble = bubble_sort;
	sort->select = select_sort;
	sort->insert = insert_sort;
	sort->quick = quick_sort;
	sort->heap = heap_sort;
	sort->shell = shell_sort;
	sort->merge = merge_sort;
}
