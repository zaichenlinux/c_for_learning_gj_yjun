#include <stdio.h>

int binary_search(int *a, int start, int end, int num)
{
	if (!a) {
		printf("数组为空，无法查找！\n");
		return -1;
	}
	if (start > end) {
		return -1;
	}

	int mid = (start + end)/2;
	printf("mid = %d\n", mid);

	if (num == a[mid]) {
		return mid; //返回找到的元素的下标
	} else if (num < a[mid]) {
		end = mid - 1;
		return binary_search(a, start, end, num);
	} else {
		start = mid + 1;
		return binary_search(a, start, end, num);
	}
}

int main(void)
{
	int a[] = {1,3,5,6,7,8,12};

	int i = binary_search(a, 0, sizeof(a)/sizeof(*a) - 1, 12);
	if (i < 0) {
		printf("没找到！\n");
	} else {
		printf("找到了，值 = %d\n", a[i]);
	}
	return 0;
}
