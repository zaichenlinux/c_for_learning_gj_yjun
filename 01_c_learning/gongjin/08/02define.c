/*
只能用在宏替换序列
##  表示将多个宏参数拼接成一个符号
#  字符串化，用于将宏的参数字符串
*/
#include <stdio.h>
#define CONECT(a, b)     a##b
//#define CONECT(a, b)     a##e##b
#define STR(a)   #a

#define A(a)   #a
//A不是嵌套宏
#define B(a)  A(a)   //嵌套宏
//嵌套宏展开的时候，内部的参数的宏也是一同展开
int main(int argc, char const *argv[])
{
	int a = 345;
	//printf("%d\n",CONECT(2, 4) );
	//printf("%s\n", STR(123));
	//printf("%s\n",#a );
	printf("A(B(a)) = %#define B(a)  A(a)   //嵌套宏
//嵌套宏展开的时候，内部的参数的宏也是一同展开s\n", A(B(123)));
	//#B(123)   ==>   "B(123)"
	printf("B(A(a)) = %s\n", B(A(123)));
     //A(#123)   ==> A("123")  => "\"123\""      "123"
	return 0;
}