#include <stdio.h>

//强制inline
#define __inline __attribute__((always_inline))

typedef int elem_t;
__inline static void swap(elem_t *a, elem_t *b)
{
	elem_t tmp = *a;
	*a = *b;
	*b = tmp;
}

//快速排序: 是对冒泡排序的改进
static void quick_sort(elem_t *a, size_t n)
{
	//出口条件
	if (n <= 1) {
		return;
	}

	elem_t *pl = a;
	elem_t *pr = a + n - 1;
	elem_t *p = a + n/2; //指向中值元素的指针
	elem_t save = *p; //记录中值

	//保存即将被擦写掉的pl或pr的值
	for (; pl < p && *pl <= save; pl++) {}
	if (pl < p) {
		*p = *pl;
	}
	while (1) {
		for (; pl < pr && *pr >= save; pr--) {}//从中值右边找一个小于中值的元素，将其扔到中值左侧
		if (pl < pr) {
			*pl = *pr;
			pl++;
		} else {break;}
		for (; pl < pr && *pl <= save; pl++) {}//从中值左边找一个大于中值的元素，将其扔到中值右侧
		if (pl < pr) {
			*pr = *pl;
			pr--;
		} else {break;}
	}
	*pl = save; //pl和pr相遇的位置就是中值p应该插入的位置

	quick_sort(a, pl - a);//中值左边元素递归
	quick_sort(pl + 1, n - 1 - (pl - a));//中值右边元素递归
}

//归并排序
static void merge_sort(elem_t *a, size_t n)
{
	int m = n/2;
	int l = 0, r = m;

	if (m > 1) {
		merge_sort(a, m); //前 m 个元素递归排序(下标从0到m-1)
		merge_sort(a + m, n - m); //后 n - m 个元素递归排序
	}

	int i = 0;
	elem_t b[n]; //变长数组，用于存放a数组值中已经排好序的元素
	while(l<m && r<n) {
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

	for (i=0; i<n; i++) {
		a[i] = b[i];
	}
}

int main(void)
{
	elem_t a[] = {6,-2,3,5,7,9,8};
	size_t n = sizeof(a)/sizeof(*a);
	//quick_sort(a, n);
	merge_sort(a, n);

	int i = 0;
	for (; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

