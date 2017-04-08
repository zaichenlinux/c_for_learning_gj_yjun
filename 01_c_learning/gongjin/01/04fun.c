#include <stdio.h>
//调试打印宏,一般供调试使用
int main(int argc, char const *argv[])
{
	printf("%s\n",__func__);
	//该宏所在的函数名
	printf("%s\n", __FUNCTION__);
	//该宏所在的函数名
	printf("%d\n", __LINE__);
	//该宏所在的行号
	printf("%s\n", __FILE__);
	//该宏所在的文件名
	printf("%s\n",__DATE__);
	//日期
	printf("%s\n", __TIME__);
	//时间  编译的时间
/*
编辑器 vim gedit subl...
编译器  gcc
*/


	return 0;
}