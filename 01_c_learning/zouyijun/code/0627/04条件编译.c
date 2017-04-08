#include <stdio.h>

/* gcc编译器的选项：-Wall 开启所有的警告
	-std
	-E -S -o
 */

// 调试打印宏：在程序调试阶段，不可避免有很多中间变量需要进行打印，来验证程序是否按预期在执行; 一旦程序调试通过，这些调试打印宏就应该被关闭
// 如果没有事先布置好这个调试打印宏，而在整个程序中都使用的是printf的打印，那么调试通过之后，那么只有在调试阶段才有必要打印的语句，手工的去删除，显然耗时费力，得不偿失，所以此时调试打印宏就显得非常好用了。

#define DEBUG

#ifdef DEBUG
#define DBG_PRINT(fmt, args...) \
	printf(fmt, ##args)
#else
#define DBG_PRINT(fmt, args...)
#endif

#define LEN 5
int main()
{
	for (int i = 0; i < LEN; i++) {
		if (!(i % 3)) {
			DBG_PRINT("debug, i = %d", i);
		} 
			
		printf("i = %d\n", i);
	}
	DBG_PRINT("over loop!\n"); // ##可以将未传递参数前的多余逗号删除

	return 0;
}
