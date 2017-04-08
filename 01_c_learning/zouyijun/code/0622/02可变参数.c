#include <stdio.h>

/*
	可变参数：参数的个数和类型是可以发生变化的
	具有可变参数的函数，称为可变参数函数

	一个函数，如果是有可变参数，那么至少需要有一个固定参数。固定参数是出现在可变参数之前的那些参数。
	... 代表的就是可变参数（也就是说，将来给这些可变参数，可以传递任意个任意类型参数）
 */

#include <stdarg.h>

// sum函数用来将所有的可变参数加起来
int sum(int n, ...)
{
	va_list ap; // 定义一个变量ap，用来遍历可变参数
	va_start(ap, n); // 用来初始化ap变量的，让ap指向最后一个固定参数n


	int sum = 0, ret;
	// va_arg宏在第一次被调用时，会让ap指向第一个可变参数，后续，每调用一次，都将指向下一个可变参数
	while (ret = va_arg(ap, int)) {
		sum += ret;
	}

	va_end(ap); // 清理ap变量，使其不再可用
	return sum;
}

#include <stdbool.h>
void foo(int m, int n, ...)
{
	va_list ap;
	va_start(ap, n);

	// 可变参数列表，能直接识别的参数类型是：int(char,short-->int), long, double(float-->double), char*
	printf("%s\n", va_arg(ap, char *));
	printf("%.2f\n", (float)va_arg(ap, double));
	printf("%c\n", (char)va_arg(ap, int));
	printf("%ld\n", va_arg(ap, long int));
	printf("%hd\n", (short)va_arg(ap, int));
	//printf("%d\n", va_arg(ap, int));

	// 可变参数的遍历，不能跳过其中的某一个可变参数，去访问后一个可变参数
	// 可变参数的遍历，必须从第一个可变参数开始，遍历到某个可变参数，不想继续遍历后续参数是可以的（只要调用va_end就可以了）
	// 多次遍历可变参数也是可以的，必须在重新开始遍历时，再次调用va_start

	va_end(ap);

	va_start(ap, n); // 重新遍历参数列表
	printf("%s\n", va_arg(ap, char *));
	va_end(ap);
}

int main()
{
	//printf(); // 必须给固定参数赋值
	//printf("hello");
	//printf("hello, %s，%d, %f\n", "world", 10, 3.15);

	printf("和=%d\n", sum(100, 'A',20,30,40, 0));
	foo(1,2, "hello", 3.14, 'a', 100, 10, 1);

	return 0;
}
