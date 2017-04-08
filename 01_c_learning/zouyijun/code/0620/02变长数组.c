#include <stdio.h>

//变长数组 VLA: variable length array （C99才有的语法）
// 1, 变长数组不能在声明的同时进行初始化的
// 2, 不能定义静态的或者全局的变长数组

int a = 3;
//int arr[a];

int main()
{
	int n = 3;
	/*static*/ int a[n] /*= {1,2,3}*/; // 变长数组：数组的元素个数是变量，而不是常量，这样的数组就称为变长数组。但并不是说数组的长度，可以随着元素个数的这个变量值的变化而发生变化。
	printf("size a = %lu\n", sizeof(a));

	n = 5;
	printf("size a = %lu\n", sizeof(a));

	int b[n+1][n]; // 二维变长数组，每一个[]中的值都不能省略
	printf("size b = %lu\n", sizeof(b));

	return 0;
}
