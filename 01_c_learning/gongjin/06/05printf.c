/*
printf, 带有缓冲
printf返回值,返回输出到标准输出的字符个数
*/
#include <stdio.h>
/*
int putchar(int c);

int puts(const char *s);

*/


int main(int argc, char const *argv[])
{
	/* code */
	//printf("%d", printf("%d", printf("hello world")));
	//hello world112

	//printf("hello  "     " world %p" ," linux ");
	//printf
	putchar('a');//系统调用,系统调用根系统有关
	putchar('\n');//putchar 一次只能输入一个字符到标准输出
	return 0;
}
