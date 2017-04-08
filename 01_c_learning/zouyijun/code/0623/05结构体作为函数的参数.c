#include <stdio.h>

struct stu {
	char *name;
	int age;
};

struct stu *test1(struct stu s)
{
	struct stu t = {s.name, s.age};

	return &t; // 返回一个局部变量地址，没有意义
}

// 结构体变量作为参数，仅仅传递的是实参的值的拷贝，所以形参接收到的这份拷贝的改变，是不会影响到实参的值的。所以将结构体变量作为函数的参数基本没可能，这样的后果是将拷贝整个结构体，开销是非常大的，所以一般不会这么做。

struct stu test2(struct stu s)
{
	s.name = "jim"; // 这里修改的仅仅是test2函数内的s, 不会影响到main函数内的s
	struct stu t = {s.name, s.age};

	return t; // 返回一个局部变量地址，没有意义

	//int a = 100;
	//return a;
}

void test3(struct stu *ps)
{
	ps->name = "rose";
}

int main()
{
	struct stu s = {"tim", 20}, t = s;
	printf("t.name = %s\n", t.name);

	// 结构体变量名，在表达式中并不表示结构体变量的首地址; 结构体变量的首地址必须是"&结构体变量名"
	printf("%p\n", &s);

	printf("name:%s, age:%d\n", test2(s).name, test2(s).age);
	printf("s.name = %s\n", s.name);

	test3(&s);
	printf("test3, s.name = %s\n", s.name);

	/*
	// 结构体不能整体判等
	if (t == s) {
		printf("ok\n");
	} else {
		printf("no\n");
	}*/

	/*
	int a = 10, b = a;
	if (a == b) {
		printf("==\n");
	}*/

	return 0;
}
