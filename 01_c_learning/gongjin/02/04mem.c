/*
代码段:存放CPU执行的机器指令,通常,代码区共享,只读.
数据区(data段):存放明确初始化的全局变量,静态变量(包含静态的全局变量和静态的局部变量)
bss段:存放未初始化的全局变量,静态变量,或者初始化为0全局和静态变量.
堆heap:存放由程序员申请空间的变量.
栈stack:由编译器自动分配和释放.函数的参数,非静态的局部变量
*/
#include <stdio.h>
int a1;      //bss
int a2 = 0; //bss
int a3 = 100; //data

//虚拟地址
int main(int argc, char const *argv[])
{
	//%p打印一个指针
	static int b1;          //bss
	static int b2 = 0;    //bss
	static int b3 = 100; //data

	int *p = (int *)malloc(100);
	//指针p 在栈区
	//指针P 指针指向的区域堆区

	printf("a1 = %p\n", &a1);
	printf("a2 = %p\n", &a2);
	printf("a3 = %p\n", &a3);

	printf("b1 = %p\n", &b1);
	printf("b2 = %p\n", &b2);
	printf("b3 = %p\n", &b3);
	return 0;
}