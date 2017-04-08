/*
typeof 获取变量的类型,一般用在宏定义中
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char c;
	typeof(c) cd; //cd就是char类型
	//typeof(c) 获取 变量c的数据类型

	typeof(char  *) p1, p2;
	//相当于 char *p1, *p2; 
	//char *p1, p2;
	static int a = 10;
	typeof(a)  si;
//typeof关键字中的类型不能包含存储类型
//如果变量的类型含有static ....,那么用typeof获取时候,这些类型是无效.
	//static volatile const   

	printf("sizeof(cd) = %lu\n",   sizeof(cd));
	printf("sizeof(p1) = %lu\n", sizeof(p1));
	printf("sizeof(p2) = %lu\n", sizeof(p2));

	printf("a = %p\n", &a);//a = 0x601048,明显在一个非常低的地址
	printf("si = %p\n", &si);//si =0x7fff29197854//明显在一个非常高的地址，未初始化的局部变量在栈区
	return 0;
}
