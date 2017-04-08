#include <stdio.h>

/*
	预处理：在程序编译之前进行的操作

	处理所有的预处理指令

	在C语言中，#开头的行，被成为预处理指令
	#开头的行，必须占据独立的一行

	预处理指令分为：
		1）文件包含 
			#include <系统的头文件>
			默认头文件所在的目录：
			/usr/include 系统安装好之后，头文件默认在的目录
			/usr/local/include 安装第三方软件后，如果有头文件就会存在于此目录
			#include "自己的头文件"

			"" 和 <> 差异：
			""表示从当前源文件所在目录开始查找头文件，如果没有找到，还会继续去系统头文件所在目录进行查找，至此依然未找到，就会报错退出
			<>表示直接去系统头文件(先/usr/local/include,再/usr/include)所在目录查找，如果没找到，就报错退出
			如果找到了，就将指定的头文件内容包含进来

		当编译时，如果头文件和源文件不在同一个目录，在编译时会报错，需要在编译时用"-I头文件所在目录"选项指定需要包含的头文件所在的目录


		2）宏定义
			宏定义：是C语言中的一种替换机制，用来将指定部分替换为字符串
			1> 无参宏
				#define 宏名 替换列表 
			无参宏定义的好处：
				增强代码的可读性
				使得代码易于维护
				
				2> 有参宏
				#define 宏名(参数名称列表) 替换列表 

			宏的特点：
				宏名通常大写
				宏定义必须处于独立的一行，如果因为可读性的原因，需要分写在多行，需要在每一行的最后用 \ 来续行
				宏定义可以和注释处于同一行
				宏定义不是编译指令，所以不能在最后加;号
				宏参数是无类型的，所以只需要在参数位置写上参数名称即可
				宏定义中的替换列表，应该用一对()括住
				宏定义中的替换列表中的每一个参数都必须用一对()括住
		

		宏定义和inline函数的异同：
			相同点：都是在调用处直接展开
					都使得可执行文件的尺寸变大了
			不同点：宏参数是无类型的，inline函数的参数是有类型的
					宏定义是在预处理阶段替换展开的，inline函数是在程序运行时调用展开的
					在程序运行过程中，可以对inline函数进行调试，不能对宏进行调试（因为在预处理完毕之后，宏已经被删除了）


		3）条件编译	

			形式1：
			#if ONE
				语句1
				语句2
			#elif TWO
				语句
			#else
				语句	
			#endif

			#if 0/1
				这里的代码可以通过#if后面的值的真假来觉得是否启用
			#endif


			形式2：
			#ifndef 宏1   <==>   #if ! defined 宏1
			#elif ! defined 宏2
			#else
			#endif


			形式3：
			#ifdef 宏1   <==>   #if defined 宏1
			#elif defined 宏2
			#else
			#endif

 */

void no_arg_macro()
{
	#define ARR_CNT 20 //20这类幻数，不要随便出现在程序中
	char s[ARR_CNT] = {0};

	//ARR_CNT = 30; //错误

	#undef ARR_CNT  //取消宏定义
	//int a = ARR_CNT;

	//#define LENGTH 10; // 错误
	//int k = LENGTH;
	//printf("%d\n", LENGTH);

	#define ADD (3 + 5)
	printf("%d\n", ADD * ADD);
}

void have_arg_macro()
{
	//#define MUL(a, b) (a * b) // 错误写法 
	#define MUL(a, b) ((a) * (b)) 
	printf("和 = %d\n", MUL(1+2, 3+4));
	// MUL(1+2, 3+4) --> (1+2 * 3+4) --> 11

	
	//#define MAX(a, b) ((a) > (b) ? (a) : (b))
	#define MAX(a, b) ({int m = a, n = b; \
			m > n ? m : n;}) // 当传递有副作用的参数时，标准C是不能解决的，需要使用GNU C

	int a = 10, b = 20;
	printf("max = %d\n", MAX(a++, b++));
	
}

int main()
{
	for (int i = 0; i < 2; i++) {} // C89不支持的语法：变量的定义放在for语句的初始化部分;C99完全支持这种语法

	//no_arg_macro();
	have_arg_macro();
	return 0;
}
