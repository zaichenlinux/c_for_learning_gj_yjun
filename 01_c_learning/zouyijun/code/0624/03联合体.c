#include <stdio.h>

/*
	共用体（联合体）：
		所有的成员占用同一块内存

	1> 共用体变量的大小，取决于其中最大的那个成员的大小
	2> 在某一时刻，在使用这个变量时，只能作为其中的一个成员的类型来使用
 	3> 共用体变量在赋值时，是按照第一个成员的类型来接收的
	4> 共用体变量的值，是最后一次对这块内存空间所赋的值

	共用体一般不会单独使用，通常作为结构体中的成员存在
 */

union tag {
	int a;
	char c;
	short s;
};

int main()
{
	printf("size: %lu\n", sizeof(union tag));

	union tag t = {0x11223344};
	printf("%#x\n", t.c);
	printf("%#x\n", t.s);

	t.c = 0xff;
	printf("%#x\n", t.a);

	return 0;
}
