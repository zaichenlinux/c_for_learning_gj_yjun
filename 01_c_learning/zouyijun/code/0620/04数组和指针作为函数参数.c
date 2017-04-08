#include <stdio.h>

void foo(char *s)
{
	printf("%s\n", s);
}

#include <string.h>
void foos(char *s, int n)
{
	char t[n+1];
	memset(t, 0, n+1);
	char *pt = t;
	while(n--) {
		*pt = *s;
		pt++;
		s++;
	}
	printf("t: %s\n", t);
}

void test(char s[]) //数组型形式参数，被编译器视为指向数组中的首元素的指针类型 这里就是char*
{
	printf("size s = %lu\n", sizeof(s)); // 这里编译有警告，打印的是char*类型的长度
}

void f(int n) // int n = 10
{
	n = 100;
}

int main()
{
	int a = 10;
	f(a);

	char *s = "12345";
	foo(s + 1);

	char st[] = "12345";
	foos(st + 1, 3); // 数组名在表达式中，或者在函数的参数中时，类型已经退化为指针类型了：char *
	/* 数组类型作为函数的参数，类型会自动转为指针类型，好处：
	   1, 不必将整个数组的副本传递给函数，这样开销才会比较小，因为作为指针传递，只是传递一个4字节或8字节的地址值
	   2, 如果不转为指针类型，那么就真的传递的是数组的副本，那么意味着函数内对形参数组的修改不会影响到实参数组
	   3, 传递一个大的数组，对效率没有影响（因为只传递了这个数组的首元素的地址）
	   4, 可以传递数组的一个连续的片段（也就是传递数组的一部分）
	 */

	test(st);

	return 0;
}
