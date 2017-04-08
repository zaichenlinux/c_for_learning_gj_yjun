/*
库文件：
静态的库与动态库：动态库  .so 结尾   静态库  .a
linux下的库命名规范    lib库名称.a.版本号


静态库：当链接一个静态库时，连接器会找出程序所需要的函数，然后将对应的函数部分直接拷贝到执行的文件，由于这种拷贝是一种完整的拷贝，所以一旦链接成功，静态库就不再需要了。


*/

#include <stdio.h>
#include "/home/candle/c_languae/20160419/09/01lib.a/include/test.h"

// "test.h"从当前目录下找对应头文件

int main(int argc, char const *argv[])
{
	/* code */
	test();
	return 0;
}