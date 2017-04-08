#include <stdio.h>
/*static*/ int c = 99;

/*static*/ void static_test()
{
	int a = 10;  //非静态的局部变量
	static int b = 10; //静态的局部变量

	a++;
	b++;
	printf("a = %d, b = %d\n",a, b );
}