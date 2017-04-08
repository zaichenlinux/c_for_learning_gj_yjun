#include <stdio.h>
#include <stdlib.h>

/*
	return 只有在main函数中，才能使得程序退出；在任何其他函数中，只表示返回
	exit 函数 出现在任何一个函数中，都可以使得程序终止
*/

int foo()
{
	// 下面系统预定义的宏，用于帮助调试程序
	printf("文件名：%s\n", __FILE__);
	printf("函数名：%s\n", __func__);
	printf("函数名：%s\n", __FUNCTION__);
	printf("行号：%d\n", __LINE__);
	printf("日期：%s\n", __DATE__);
	printf("时间：%s\n", __TIME__);
	
	printf("测试编译器是否遵守C89标准：%d\n", __STDC__); // 值为1表示遵守；为0表示不遵守

	//exit(0); // 此行执行完毕，程序已经终止了
	return 0; // 返回0给main函数
}

int main()
{
	int b = foo();
	printf("b = %d\n", b);
	printf("ok1\n");
	return 0; 

	printf("ok\n");
}
