#include <stdio.h>

// foo 是结构体的标签
struct foo {
	char *s;
	char c;
}; // 自定义类型：struct foo

// 下面是定义了没有标签的类型
struct {
	char *s;
	char c;
}; // 自定义的类型：struct { char *s; char c; };

int main()
{
	struct foo f1, f2;

	struct {
		char *s;
		char c;
	} s1, s2;

	return 0;
}
