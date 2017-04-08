#include<stdio.h>
struct foo1{
	char c;
	char *p;
};
struct foo
{
	char c;
	struct foo1 foo1;
	long double ld;//64位下为16个字节；32位下为12个字节
	char *p;
};
int main(int argc,char const *argv[])
{
	struct foo foo;
	printf("sizeof(struct foo)=%lu\n",sizeof(struct foo));
	printf("foo对齐方式：%li\n",__alignof__(struct foo));
	printf("foo1对齐方式：%li\n",__alignof__(struct foo1));
	long double ld;
	printf("long double的字节=%lu\n",sizeof(ld));
	return 0;
}
/*
输出结果为：
sizeof(struct foo)=64 //嵌套的结构体的对齐方式是8个字节，补全后为16个字节，变成1,16,16,8再进行结构体存储；即
foo对齐方式：16
foo1对齐方式：8
long double的字节=16

*/
