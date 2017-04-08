#include <stdio.h>

/*
	什么是指针：表示内存中某个数据的地址
	作用：
		1> 共享数据
		2> 避免副本

	指针 和 指针变量
	整型变量：保存整型的变量
	指针变量：保存指针（地址）的变量

	C中的函数参数的传递，都是值传递：传递的其实是实参的值的副本。

	获得一个变量的地址：& 取地址运算符
	&a ： 获得了a这个变量的地址

	直接访问：直接通过变量名进行访问
	间接访问：通过这个变量的地址进行的访问

	间接访问运算符：* 
	间接访问：*指针变量 （也称为解引用指针）


	int a = 10, *p = &a;
	你需要知道的：
		指针变量的值: p 或者 &a 
		指针变量指向的变量的值: *p 或者 a
		指针变量的类型: int *
		指针变量指向的变量的类型: int
*/

void ptr()
{
	int a = 10; // 定义一个int类型的变量
	int *p = &a; // 定义一个int*类型的指针变量，这里的*号仅仅说明p这个变量是一个指针变量，没有别的意思
	// 从28行的声明中，我们可以知道：p指针变量的类型是int*, p变量指向的变量的类型是int
	// 指针变量的类型：变量声明中去掉变量名后剩余的部分
	// 指针变量指向的变量的类型：变量声明中去掉变量名和前面的一个*号，剩余的部分

	int *p1;
	p1 = &a; // 28行等价于33,34两行

	// 任何类型的指针变量在64位机器上都占据8个字节
	printf("指针变量占据的内存字节数：%lu\n", sizeof(p));

	printf("直接访问：a = %d\n", a); 
	printf("间接访问：a = %d\n", *&a); // *和&是可以抵消的
	printf("间接访问：a = %d\n", *p); //这里的*号，表示间接访问 

	// 表示a的地址的方式：
	printf("%p\n", p); 
	printf("%p\n", &a); 

	// 表示指针变量p本身占据的内存地址：
	printf("%p\n", &p);

	// 表示a的值的方式：
	printf("%d\n", *p); // *pa 是 a 变量的别名
	printf("%d\n", a);

	// 改变a所在的那个地址中的值：
	a = 100;
	*p = 200;
}

// 指针之间的赋值
void ptr_assignment()
{
	int a = 10, *p = &a;
	int *q;
	q = p; // 指针之间的赋值 （q保存了p所保存的地址）相当于 q = &a;

	int b = 20;
	p = &b;
	*q = *p;

	printf("a = %d\n", a);
}

void swap(int aa, int bb) // int aa = 3, bb = 5
{
	int tmp = aa;
	aa = bb;
	bb = tmp;
	printf("%s, aa = %d, bb = %d\n", __func__, aa, bb);
}

void swap_ptr(int *pa, int *pb) // int *pa = &a, *pb = &b
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

int main()
{
	int a = 3, b = 5;
	printf("交换之前，a = %d，b = %d\n", a, b);
	swap(a, b);
	//swap_ptr(&a, &b);
	printf("交换之后，a = %d，b = %d\n", a, b);

	{
	//	ptr();
		ptr_assignment();
	}

	return 0;
}
