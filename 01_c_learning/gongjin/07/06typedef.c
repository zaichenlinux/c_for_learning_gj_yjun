/*
typedef 关键字 作用:给一个数据类型定义一个新的名字.

typedef用处
1.给一个数据类型起一个简单易懂的名字.
2.简化一些比较复杂的数据类型.

size_t
typedef unsigned int  size_t; 

typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t
       handler);


void (*signal(int signum, void (*handler)(int)))(int)

第二个参数和返回值都是 void (*)(int)
typedef void(*sighandler_t)(int)
sighandler_t signal(int signum, sighander_t hander)

typedef void (*)(int)   sighandler_t;  

*/
#include <stdio.h>


//typedef简化下面的类型
//int (*)[2]
typedef  int (*Canshu1)[2] ;

typedef  int (*Canshu2_1)(int,   int);

typedef    Canshu1 (*Canshu2)(Canshu2_1, Canshu1);

typedef  Canshu1 (*func)(Canshu1, Canshu2);


//int (*func(int (*)[2], int (*(*)(int (*)(int,  int), int (*)[2]))[2]))[2];

//u8  u32  u16
//s8  s16  s32
typedef void (*sighandler_t)(int);  
sighandler_t my_signal(int signum, sighandler_t hander);

typedef struct foo{
	int a;
	char *p;
} *pfoo;

//展开之后
/*
struct foo{
	int a;
	char *p;
} ;

typedef struct foo * pfoo;
*/


int sum(int a, int b)
{
	return a+b;
}


int main(int argc, char const *argv[])
{
	/* code */

	typedef int s32;
	typedef unsigned char u8;
	//定义一个函数指针pt1,指向sum;
	typedef int (*pt1)(int a, int b);
	//pt1是一种数据类型,不是该类型的变量
	pt1 ps;//ps才是pt1类型的变量
	ps = sum;


	//u8  c;  //  == unsigned char c;

	pfoo pt;


	return 0;
}
