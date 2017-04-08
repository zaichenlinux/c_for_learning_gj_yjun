/*
函数指针
() [] . ->     *
*/

//int*   sum(int a, int b); //sum 是一个函数,返回值是int *
//int (*sum)(int a, int b); //sum 是一个指针,指向是一个函数,函数指针

//[] ()  *
#include <stdio.h>
int add(int a, int b)  //  int (int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a - b;
}

//回调函数
int main(int argc, char const *argv[])
{	
	int a = add(3, 4);
	printf("%d\n", a);
	//add  函数名代表该函数的入口地址
	//&add 也是表示该函数入口地址
	printf("%p\n", add);
	printf("%p\n", &add);

	//pf函数指针,int (int, int)
	int (*pf)(int , int );
	pf  = add;

	printf("%d\n",  (*pf)(4, 5) );//1.

	pf = &add;
	printf("%d\n",  pf(4, 5) ); //2.通过函数指针,间接调用函数方法,推荐这种写法.

	int (*func_arr[2])(int , int ) ;
	func_arr[0] = add;
	func_arr[1] = sub;

	printf("%d\n", func_arr[1](10, 5));
	return 0;
}