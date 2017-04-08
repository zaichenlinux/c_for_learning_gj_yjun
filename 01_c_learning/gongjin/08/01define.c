/*
预处理指令：
在C中，凡是以#开头的行，都是预处理指令。所谓预处理在编译之前进行的操作就是预处理。

文本文件  --->  二进制
1.预处理    2.编译   3.汇编  4.链接

: error: ld returned 1 exit status  链接失败

预处理指令包括
1.宏定义（#define）:是一种替换机制
格式：
1)不带参数的宏    #define  宏名     宏体（替换序列）
2)带参数的宏  #define  宏名（参数） 替换序列

2.条件编译
对代码选择性的编译
#if 0/1
#elif  标识符
#endif
#ifdef
#ifndef
#else

3.系统指令
#include 头文件包含

*/
//12345678  8   4
/*
宏定义：宏就是一种替换机制。
宏调试比较麻烦,宏在预处理阶段之后就被替换成宏体，以后这个宏名不存在。
调试宏只能gcc -E 让.c文件在预处理阶段停下来，观察宏是否展开正确。
*/
#include <stdio.h>

//#define CNT  5;
#define CNT   5
#define  M   (10+20) //宏中如果是一个表达式，要用（）扩起来防止产生歧义。
//宏当中一般不在末尾加;
//宏末尾加；不是该宏的语法错误，如果出现语法错误，是由于展开出现的错误所致。
//定义一个宏，输出一年有多少秒，忽略闰年
#define SECOND_PER_YAER (365u*24*60*60)
//不带参数的宏
//1.用一个简单易懂的宏替换常量，提高代码的可读性。
//2.用一个宏替换一个标志，增加代码的可维护性。


//flag  0开  1关  2....
//if(FLAG_ON == flag)
//#define FLAG_ON   0
//#dfine FLAG_OFF  1

/*
带参数的宏
写一个宏，有两个参数，输出较大的那个数
宏中的参数没有类型
#define Max( a, b)


*/

//使用带参数的宏，每个参数都需要用()扩起来
//01define.c:64:17: error: macro parameters must be comma-separated
//带参数的宏，不能有数据类型
//#define MAX(int a, int b)   ((a)>(b) ? (a):(b))

// \  在宏中称为续行符，是将该行的内容延续到下一行。
#define MAX(a, b)    \
((a)>(b) ? (a):(b))

#define MAX_GNU(a, b)  \
({int m = (a), n = (b);m>n ? m:n;})

int max(int a, int b)
{
	return a > b ? a:b;
}

int main(int argc, char const *argv[])
{
	//test();
	//CNT = 6;  宏不是变量，只是一种替换机制。
	int arr[CNT] = {1, 2, 3, 4, 5};
	printf("arr[4] = %d\n", arr[CNT-1]);
#undef  CNT   //取消CNT这个宏
	int a = SECOND_PER_YAER;

	printf("a = %d\n",a );

	printf("%d\n",MAX(3, 4));
	printf("%d\n", MAX("hello", "hallo"));
	printf("%f\n",MAX(3.1, 4.2));
	//“hello”  "hallo"  两个字符串的首地址进行的比较
	//strcmp  

/*
#define MAX(a, b)    ((a)>(b) ? (a):(b))
#define MAX_GNU(a, b)  ({int m = (a), n = (b);m>n ? m:n;})
int max(int a, int b)
{
	return a > b ? a:b;
}
带参数的宏和函数比较
1.带参数的宏，降低程序的运行的开销。但增大了代码的尺寸
2.带参数的宏，比较通用（宏的参数是无类型），但躲过编译器对参数的检查，给调试带来不变。并且宏参数可能在宏替换的时候，执行了很多次。
3.带参数的宏的缺点，在程序运行期间，无法对其进行调试。因为在预处理之后，宏定义就已经被替换，替换宏就会被删除。所以调试宏只能在预处理阶段调试，gcc -E ,然后展开，查看对应的宏展开之后是不是需要的宏。

*/


	int i = 0;
	printf("MAX = %d\n", MAX(i++, i++));
	printf("i = %d\n",i );
	i = 0;
	printf("MAX_GNU = %d\n", MAX_GNU(i++, i++));
	printf("i = %d\n",i );
	i = 0;
	printf("max = %d\n", max(i++, i++));
	printf("i = %d\n",i );

	return 0;
}