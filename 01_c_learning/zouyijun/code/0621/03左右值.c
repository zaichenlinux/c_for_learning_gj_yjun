#include <stdio.h>

/*
	lvalue 左值：存储于内存中的对象\变量，而不是常量或表达式的结果。左值只能是能被修改变量。
	通常来说，凡是放在 = 左边的就是左值
	= 符号的左边必须是左值

	左值不能强转

	想改变一个变量的值，只有两个运算符可以做到：=, ++\--

	
	rvalue 右值，放在 = 右边的就是右值，右值可以是常量，变量，表达式
   */

int main()
{
	int a = 10; // 10 是 rvalue
	int b;

	b = a; // a是rvalue
	b = a + 10; // a + 10 是rvalue

	//a + b = 100; // error
	//3 = a; // error

	return 0;
}
