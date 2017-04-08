/*
函数:自带声明和语句的程序块

函数类型: 函数类型 != 函数的返回值类型
函数的类型
1.函数的返回值的类型
2.函数的参数的个数
3.每个参数的类型

函数的分类
1.int main(int argc, char const *argv[])
主函数,入口函数.一个工程只能有一个main函数
2.printf();
库函数,
3.test();
用户自定义的函数

函数的好处
1.减少重复劳动
2.实现代码的复用性
3.隐藏代码的实现细节
4.........

void test(int a, int b)

*/

//test1参数类型为空,可以传递参数,但是对传递的参数不做任何的处理
void test1()
{

}

//参数的类型是void类型,明确告诉编译器,不能传任何的参数
//只要参数,就报语法错误.
void test2(void)
{

}

//1. test1 test2
int main(int argc, char const *argv[])
{
	test1(10, 11);
	//test2(10, 11);
	return 0;
}