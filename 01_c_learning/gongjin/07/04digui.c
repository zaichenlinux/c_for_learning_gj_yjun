#include <stdio.h>
/*
递归函数:
直接或者间接调用自己的函数.

递归函数必须满足两个条件:
1.下一次的调用必须是规模更小的自己
2.递归函数要有返回

递归函数在时间和空间的开销都会增大,唯一的好处代码缩短,有时增强代码的可读性.

*/

//n! = n*(n-1) *......1
//5 = 5 * 4 * 3 *2 * 1
long func(int n)
{
	if(n == 1) return 1;
	return n * func(n-1);
}

void e(int n)
{
	if( n > 0) {
		e(--n);
		printf("%d\n", n);
		e(--n);
	}
}

int main(int argc, char const *argv[])
{
	int a = 3;
	e(a);
	//printf("\n");
	return 0;
}
