/*
变量的分类:
根据存储位置
1.全局变量,在函数的外部的变量
2.局部变量, 在函数的内部的变量

生命周期:变量在内存中存在的时间
1.静态的生命周期:在程序编译期间就已经存在,直到整个程序执行完成
全局变量和静态的局部变量
2.自动的生命周期:在其所在{}开始,在}外结束
非静态的局部变量
3.动态的生命周期:该变量的生命周期可以控制
由程序员申请的空间  malloc  free

作用域:变量作用的范围 static
1.文件作用域:全局的静态变量(在本文件能够使用)
全局的非静态变量(整个工程可见)
2.函数的作用域:仅仅在函数内部起作用
局部变量,函数的参数
3.块作用域:在{ }内的作用域,作用的范围仅仅限于该块内

static关键字: 修饰数据类型,该类型就是静态的
1.当static修饰全局变量,改变了该变量的作用域, 从整个工程可见改变成当前文件可见.
2.当static修饰局部变量,改变了该变量的生命周期,
从自动生命周期变成静态的生命周期,该变量只能初始化一次
3.当static修饰函数,改变该函数的作用域,
从整个工程可见变成当前文件可见.

gcc 03.c 03zyy.c  -Wall  把系统警告打印出来
*/
#include <stdio.h>

//老式的函数的声明方式,不建议用这种声明方式去声明函数
//20 ~22 等同于  int sum(int a, int b)
int sum(a,  b)
int a; 
int b;
{
	return a+b;
}


void test()
{
	printf("%s\n", __func__); // test
	//嵌套函数定义

	//定义了一个test1函数,并没有执行该函数
	void test1() 
	{
		printf("%s\n", __func__);  //test1
	}
	test1();

	printf("%d\n",__LINE__ );  //25
}

int b = 10;  //全局变量
int main(int argc, char const *argv[])
{
	int a = 10;//局部变量
	//extern 关键字,说明c变量在下面声明或者是在其他的地方声明
	extern int c;

	{
		int d = 88; //块作用域,范围仅仅在{}内,出了{}变量就被释放
	}

	//printf("d = %d\n", d);
	printf("c = %d\n", c);

	test();

	static_test();
	static_test();
	static_test();

	return 0;
}
