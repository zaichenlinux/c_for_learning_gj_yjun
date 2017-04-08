#include <stdio.h>

/*
	指针为什么有类型：
		指针进行算术运算，是由他指向的变量的类型来决定的

	指针分类：
		1, 野指针：指针在定义时，指向的内存未知。野指针指向的内存因为不是程序分配给我们的，所以我们应该是无权使用的。所以对野指针进行间接访问没有意义。野指针应该在使用之间指向我们可以使用的内存。
		2, 空指针: 赋值为 NULL 或者 0 的指针
		3, 通用指针: void *类型的指针
		通用指针出现最多的地方，就是函数的参数的位置

	void 可以出现在的位置：
		1, 函数的返回值类型：表示函数不返回任何值
		2, 函数的参数：表示函数不接受参数
   */

// 野指针
void wild_ptr()
{
	int *p; // 野指针
	//printf("%d\n", *p); // 错误

	int a = 10;
	p = &a; 
	printf("%d\n", *p);
}

// 空指针
void empty_ptr()
{
	// #define NULL (void *)0
	// NULL 值虽然是0，但是指针赋值为NULL，表示这个指针不指向任何的内存空间，仅仅一旦对空指针进行间接访问就报错的一个值而已
	int *p = NULL; // 这里仅仅是声明了一个空指针，并不是说这个指针赋值了
	// printf("%d\n", *p); // 空指针在使用之间，必须进行赋值
	int a;
	p = &a;
	printf("%d\n", *p);
}

// void*指针
void void_star_ptr()
{
	int a = 10, *p;
	//void v; // void表示无类型，编译器也不知道占几个字节

	void *pv = &a; // void*指针可以指向任何类型的变量
	char *pc = pv; // C编译器完全没有警告，C++编译器直接报错

	// 非void*类型的指针，在C中，可以平滑的接收void*类型指针的值

	printf("a = %d\n", a);
	printf("a = %d\n", *pc); // *pc类型是char

	//void *类型指针在间接访问之前，必须先强转为需要的指针类型，之后才能进行间接访问
	printf("a = %d\n", *((int *)pv)); // *pv类型是void
	
	pv = &p;
}

int main()
{
	//empty_ptr();
	
	void_star_ptr();
	return 0;
}
