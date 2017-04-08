#include <stdio.h>

char *str()
{
	static char s[] = "123"; // 没加static的话，这个数组就是一个局部变量，在函数返回之后，空间就被回收了，返回被回收空间的地址是没有任何意义的。
	return s;
}

int main()
{
	char *t = str();
	printf("t = %s\n", t);

	return 0;
}
