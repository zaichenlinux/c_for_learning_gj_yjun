/*
头文件包含
include

头文件一般存放：
1.类型声明
2.函数的声明
3.宏定义
4.类型的定义 typedef

宏不能夸文件使用，宏的作用范围只能在本文件中。
*/
#include <stdio.h>
//所谓的包含头文件，就是把头文件内容复制过来
//头文件不需要编译，头文件是被包含的关系
#include "test.h"
//<>  z在系统中的库去搜索    
//""  在当前的目录去搜索
//gcc 06include.c


int main(int argc, char const *argv[])
{
	test();

	printf("CNT = %d\n",CNT );
	return 0;
}