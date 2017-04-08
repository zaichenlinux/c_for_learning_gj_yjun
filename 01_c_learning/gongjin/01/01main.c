#include <stdio.h>

//C99标准,main函数的标准写法
//int main()
//int main(int argc, char *argv[])

//main()      不标准的写法
//void main()

//linux下的编程风格
//对变量命名的规则
//1.变量名的意思用_分开
// registerI2cCline
// register_i2c_cline  linux习惯的命名的方法
//2.在linux下,除了函数 "{" 另起一行,其他的不另起一行
//	while() {
//	}
//
//  void test() 
//  {
//  }

/*
gcc test.c
预处理:处理预处理指令
gcc -E test.c > test.i
编译:把.c文件编译成汇编语言
gcc -S test.i 
汇编:.s编译生成目标文件
gcc -c test.s
链接:目标文件链接生成可执行的二进制程序
gcc test.o

关键字
标识符
变量
常量
*/
int main()
{
	printf("hello wrold\n");
	return 0;
}
