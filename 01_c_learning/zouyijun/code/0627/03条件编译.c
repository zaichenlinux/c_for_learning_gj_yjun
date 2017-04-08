#include <stdio.h>
//#include <assert.h>

// assert断言宏执行的原理：首先判断宏参数所表示的表达式的真假，如果为假，就会向标准错误输出（stderr）输出一条消息，消息内容包括：在哪个文件，第几行，哪个函数，断言参数所表示的表达式失败了;紧接着就会调用系统函数abort，来终止程序的执行。如果判断的表达式为真的话，程序会继续向下执行。

// assert 断言宏 用来帮助程序员在代码调试阶段找到程序中的bug，一旦程序调试通过，就应该关闭这个断言宏。在将来某时需要继续调试代码，需要再次启用下面的断言宏，只需要注释第6行即可。

//#define DEBUG // 这一行用来关闭或打开下面的ASSERT宏

#ifndef DEBUG
#include <stdlib.h>
#define MY_ASSERT(expr) ({ \
		if (!(expr)) { \
			printf("%s: %s:%d: %s: Assertion `" #expr "' failed.\n", argv[0]+2, __FILE__, __LINE__, __func__); \
			abort(); \
		} \
})
#else  
#define MY_ASSERT(expr) // 这一行定义了一个空的宏
#endif

int main(int argc, char *argv[])
{
	int a = 10;
//	assert(a != 10);
	MY_ASSERT(a != 10);

	printf("ok\n");

	return 0;
}
