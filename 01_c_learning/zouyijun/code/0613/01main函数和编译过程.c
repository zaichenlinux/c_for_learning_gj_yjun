
//注释： 
/* 
	注释掉的部分 
	注释掉的部分 
	注释掉的部分 
 */
//  单行注释
#if 0
	注释掉的部分 
	注释掉的部分 
#endif

// C标准：ANSI C (C89 --> C99 --> C11 (GNU C))

/*
	C编译器：gcc(GNU C compiler  --> GNU compiler collection) 
	-o 可以用来指定生成的文件名

	C编译的过程：
		1，预处理：(cpp预处理器完成，将所有的预处理指令进行处理）
			gcc -E 01.c > 01.i
		2，编译：（ccl编译器完成，将预处理之后的文件做语法分析，词法分析，语义处理，代码优化）
			gcc -S 01.i  (生成01.s汇编文件)
		3，汇编：（as汇编器完成，将汇编指令和机器指令一一对照进行翻译）
			gcc -c 01.s (生成01.o目标文件)
		4，链接：（ld链接器完成，将目标文件和与之相关的所有的库文件在内存中进行动态链接）
			ld: link dynamic
			gcc 01.o [-o b.out] // 默认生成a.out可执行文件
   */

#include <stdio.h>
//#include <stdlib.h>

int main()
{ // 函数体开始
	// 转义 \ ：将普通字符转为具有特殊含义的字符
	// \/ 将具有特殊含义的字符变成本身具有的含义

	printf("hello world!\n"); // \n 表示换行

	return 0; // 0表示执行成功，1表示失败
	//return EXIT_SUCCESS; 
	/* 宏定义 #define EXIT_SUCCESS 0
			  #define EXIT_FAILURE 1
	*/
} // 函数体的结束
