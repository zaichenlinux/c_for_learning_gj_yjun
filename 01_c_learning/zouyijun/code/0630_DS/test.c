#include <stdio.h>

void test(char *argv[])
{
	printf("test, argv = %p\n", argv);
	printf("test, &argv = %p\n", &argv);
}

void foo(char s[]) // s的类型是char*
{
	//printf("sizeof s = %lu\n", sizeof(s)); // 8
}

int main(int argc, char *argv[]) // argv中的元素的类型是：char *
{
	//char t[] = "hello";
	//foo(t);

	printf("main, argv = %p\n", argv); // char**
	printf("main, &argv = %p\n", &argv); // char ***

	char *s[] = {"hello", "world"}; 
	test(s);

	return 0;
}

