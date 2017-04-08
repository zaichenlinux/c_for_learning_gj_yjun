#include "sort.h"

static void swap(elem_t *a, elem_t *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

// 冒泡排序：相邻两个元素值不满足 从小到到 的关系，就交换
// 将值较小的元素先排在它应该在的位置上
static void bubble_sort_min(elem_t *s, size_t n)
{
	for (size_t i = 0; i < n; i++) {
		for (size_t j = n - 1; j > i; j--) {
			if (s[j] < s[j - 1]) {
				swap(s + j, s + j - 1);
			}
		}
	}
}

// 将值较大的元素先排在它应该在的位置上
static void bubble_sort_max(elem_t *s, size_t n)
{
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n - 1 - i; j++) {
			if (s[j] > s[j + 1]) {
				swap(s + j, s + j + 1);
			}
		}
	}
}

// 选择排序：将其余元素和最开始认为的最小元素值进行比较，如果发现比这个认为的更小的元素的值更小，重新记录最小元素的下标
static void select_sort(elem_t *s, size_t n)
{
	size_t min_index; // 用来记录值最小的元素的下标
	for (size_t i = 0; i < n - 1; i++) {
		min_index = i;
		for (size_t j = i + 1; j <= n - 1; j++) {
			if (s[j] < s[min_index]) {
				min_index = j;
			}
		}
		if (min_index != i) {
			swap(s + min_index, s + i);
		}
	}
}

// 插入排序：将已经排好序的后序元素，依次插入到这个有序序列
static void insert_sort(elem_t *s, size_t n)
{
	elem_t save; // 用来保存可能被覆盖的元素值
	for (int i = 1; i <= n - 1; i++) {
		save = s[i];
		int j;
		for (j = i - 1; (j >= 0) && (s[j] > save); j--) {
			s[j + 1] = s[j];
		}
		s[j + 1] = save;
	}
}

void test()
{
	{
	int a;
	//a = 10, int b; // 错误写法
	}

	//int a = 10, b;
	{
	int a, b;
	a = 10, b;
	}
}

void init_sort(SORT *sort)
{
	sort->swap = swap;
	sort->bubble = bubble_sort_max;
	sort->select = select_sort;
	sort->insert = insert_sort;
}
