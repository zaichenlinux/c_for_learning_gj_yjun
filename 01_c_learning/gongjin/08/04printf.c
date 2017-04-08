/*
条件打印宏：
用于调试阶段,用于帮助程序员调试代码。
在程序调试期间，总是不可避免打印出中间的变量，并且要区分调试打印和系统打印，在调试结束时候，调试打印要关闭掉。
手动去除，有可能遗漏或者弄错。此时就可以用条件打印宏。

*/
#include <stdio.h>

//#define DEBUG
#ifdef   DEBUG
#define  DBG_printf(fmt, args...)  \
		printf(fmt, ##args)
//##用于拼接参数，当传入参数不足时候，它会删除前面的 ，号
#else
#define DBG_printf(fmt, args...) 
#endif


int main(int argc, char const *argv[])
{
	int i = 0;
	DBG_printf("i = %d\n",i );
	for(;i<10;i++)
	{
		//xxxxxx
		DBG_printf("i = %d\n",i );
	}

	printf("OVER\n");
	return 0;
}
