#include <stdio.h>

void pptr()
{
	int a = 10;
	int *p; // 一级指针
	p = &a;

	int **pp; // 二级指针 (从这个声明中，我们可以知道：pp指针变量本身的类型是int**, pp指向的变量的类型int*)
	pp = &p;

	// 打印a的值：
	printf("%d\n", a);
	printf("%d\n", *p);
	printf("%d\n", **pp); // **pp == *(*pp)

	// 打印a的地址：
	printf("\n%p\n", &a);
	printf("%p\n", p);
	printf("%p\n", *pp);

	// 打印p变量的地址：
	printf("\n%p\n", &p);
	printf("%p\n", pp);

	// 打印pp变量的地址：
	printf("\n%p\n", &pp);
}

int main()
{
	pptr();
	return 0;
}
