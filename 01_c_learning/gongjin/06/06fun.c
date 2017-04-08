/*
值传递
*/

//不能交换,函数传参是一种值传递
//值传递:实参把值传递给形参
//实参:
//形参:
#include <stdio.h>
#include <stdlib.h>
void swap1(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void swap2(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//C++ 中, 引用
//C中没有引用
//void swap3(int &a, int &b)
//{

//}


void test(int **p)
{
	*p = (int *)malloc(4);
}
int main(int argc, char const *argv[])
{
	/*
	int a = 3, b = 4;
	printf("1.a = %d, b = %d\n",a, b );
	swap2(&a, &b);
	printf("2.a = %d, b = %d\n",a, b );
	*/

	int *p; //p 野指针
	test(&p);
	*p = 10;
	printf("*p = %d\n", *p);
	return 0;
}