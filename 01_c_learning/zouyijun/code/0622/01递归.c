#include <stdio.h>

/*
	递归：自己直接或者间接调用自己
	recursive 
	利用选择结构完成

	递归必备：
		1> 每一次的递归，都更靠近基线条件
		2> 结束条件（基线条件）

	迭代（循环）

	递归 vs 循环
		1, 采用的结构：递归利用选择结构; 循环利用循环结构
		2, 完成机制：递归是通过不断的调用函数完成的; 循环通过反复的执行同一段代码完成的
		3, 都需要进行检测，是否会出现无限执行的情况。递归在每一次的递归并不是在逐渐的靠近基线条件时，会出现无限递归; 在判断条件永远不会为假时，会出现无限循环的情况
		4, 递归相对于循环，效率是比较低的。因为递归是通过调用函数来完成的，所以不可避免有入栈和出栈的开销。
		5, 一个问题，如果可以用递归解决，一定可以用循环解决; 反之不一定。
		如果都可以解决问题，那么就看注重哪个方面。如果更关注效率，那么请用循环; 如果更关注可读性，那么推荐使用递归。
   */

// 计算一个数的阶乘（n! = n*(n-1)*(n-2)*....*1）
/*
	3! = 3*2!
	2! = 2*1!
	1! = 1
   */
int factorial(int n)
{
	if (n == 1)
		return 1;
	return n * factorial(n-1);
}

// 用递归来判断一个数组是否是递增数组
int is_increment_arr(int *a, int n)
{
	if (n == 1) {
		return 1;
	}
	// 前面一个元素的值 < 后面一个元素的值
	// 并且，前n-1个元素组成的数组也是递增的
	return (a[n-2] < a[n-1]) && (is_increment_arr(a, n-1));
}

// 利用递归反向打印字符串 “1234”
void reverse_print_str(const char *s)
{
	if (!(*s)) {
		return;
	} else {
		reverse_print_str(s+1);
		printf("%c", *s);
	}
}

int main()
{
	int a[] = {1,2,3,4,6,8};
	is_increment_arr(a, sizeof(a)/sizeof(int)) ? printf("是\n") : printf("不是\n");

	char *s = "1234";
	reverse_print_str(s);
	printf("\n");

	return 0;
}
