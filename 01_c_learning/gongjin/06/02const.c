/*
const  常量,    修饰一个变量,表示该变量的类型是read-only
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a  = 10;
	/*const*/ int b = 10;  //不是在ro_data区域,还是在栈区
	int *p = &b; //会产生一个警告,类型的不匹配
/*
02const.c:11:11: warning: initialization discards ‘const’ qualifier from pointer target type
*/
	//printf("1.b = %p\n", &b);
	printf("1.b = %d\n", b);
//只读类型的变量在声明的同时要进行初始化,否则后面可能无法对其进行赋值.

	a = 11;
	*p = 11;//通过一个指针间接修改只读变量,如果忽略匹配不兼容的警告,确实可以通过指针修改
	//那么失去只读类型的意义
	printf("2.b = %d\n", b);
	//b = 11;
//02const.c:13:4: error: assignment of read-only variable ‘b’
 // b = 11;
	int const *p1 = &b;
//const 修饰 *p1    p1指针指向的地址的值不能修改
	p1 = &a;
	//*p1 = 100;

	int * const p2  = &b;
//const 修饰p2, p2指针指向的地址不能修改
//	p2 = &a;
	*p2 = 100;

	const int * p3 = &b; //同p1指针
	p3 = &a;
	//*p3 = 100;	

	int  const * const p4 = &b;
	//p4 = &a;
	//*p4 = 100;	

	int *p5 = &b;//int a  = 10;  //int *p = &b
	int * const * const p6 = &p5;
	//p6 = &p;
	//*p6 = &a;
	**p6 = 100;
	
	int const ** const p7 = &p5;
	//p7 = &p;
	*p7 = &a;
	//**p7 = 100;


	
	int const *const * p8 = &p5;
	p8 = &p;
	//*p8 = &a;
	//**p8 = 100;
	

	return 0;
}