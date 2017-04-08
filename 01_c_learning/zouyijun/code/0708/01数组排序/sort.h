#pragma once
#include <stdio.h>

typedef int elem_t;

typedef struct sort {

	void (*swap)(elem_t *, elem_t *);
	void (*bubble)(elem_t *, size_t); // 冒泡排序
	void (*select)(elem_t *, size_t); // 选择排序
	void (*insert)(elem_t *, size_t); // 插入排序

} SORT;

void init_sort(SORT *);
