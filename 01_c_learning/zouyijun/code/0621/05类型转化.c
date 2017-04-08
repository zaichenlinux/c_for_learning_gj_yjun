//#include <stdio.h>

/*
	C语言规定：
		不同类型的变量是不能直接进行运算的，需要转换为相同的类型，之后才能运算

	类型转换：
		隐式类型转换：编译器自己进行的转换，不需要程序员干预
		implicit data type conversion

		显式类型转换：需要程序员自己手工转换的(也称为强制类型转换)
		explicit data type conversion
		强制类型转换符: (type)
   */

#include <stdio.h>
void implicit_conversion()
{
	// 基本原则：进行算术运算时，将占据内存字节数更小的数据类型转为占据字节数更大的
	// 进行赋值运算时，会将=右边的类型转为左边的类型
	int a = 10 + 3.14; // (double)10 + 3.14 == 13.140000 --> (int)13.140000 == 13

	printf("a = %d\n", a);

	int b = -1;
	unsigned int c = 13;
	if (b < c) { // b已经被转为 unsigned int 类型的数据了
		printf("小于\n");
	} else {
		printf("大于\n");
	}

	// 更详细的隐式类型转换见书 《C Primer Plus》 5.5节
}

int foo();

// 强制类型转换（简称：强转）
void explicit_conv()
{
	int a = 256;
	// a: 00000000 00000000 00000001 00000000
	printf("%d\n", *((char *)(&a)));
	printf("%d\n", *(&a));

	char s[] = "12345";
	char (*p)[6] = &s;
	p++;
	//((char *)p) -= 2; // 左值不能强转
	char *q = (char *)p;
	q -= 2;

	printf("*q = %c\n", *q);
}

int main()
{
	//implicit_conversion();
	explicit_conv();

	return 0;
}

int foo()
{
	return 3.14; // 当函数定义中的{}中的返回值类型和函数声明中的返回值的类型不符时，编译器会将函数内返回的值的类型自动转为函数的返回值的类型
	//也就是说 66行 等价于 return (int)3.14;
}
