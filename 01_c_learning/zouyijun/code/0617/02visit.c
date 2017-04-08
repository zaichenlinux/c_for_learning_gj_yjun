#include <stdio.h>

extern int a; // 告诉编译器将会使用到一个外部变量，这个外部变量如果不是在当前文件的下面定义的，那么就是在其他文件中的

extern int sa; // 

void visit()
{
	printf("打印\"02内存段.c\"这个文件内的全局变量a: \n\
a = %d\n", a);
	
	//printf("打印\"02内存段.c\"这个文件内的静态全局变量sa: \n\
sa = %d\n", sa);

	int foo(int, char);
	printf("::foo, %d\n", foo('a', 'b'));
}

int a = 999;
