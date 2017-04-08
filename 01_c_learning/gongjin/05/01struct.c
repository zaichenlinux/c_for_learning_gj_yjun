/*
结构体:数据类型不一定相同的元素的集合
struct 
为了提高存取效率,大部分编译器都会对结构体字对齐存储方式.

偏移量:结构体的成员的地址距离结构体首地址地址之差.

结构体字对齐的规则(64位)
1.结构体变量中成员的偏移量必须是该成员的整数倍.(0被认为是任何数的整数倍)
2.结构体大小必须是所有成员大小的整数倍


结构体字对齐的规则(32位)
1.结构体变量中成员的偏移量必须是该成员大小和4个字节两者中较小的整数倍(0被认为是任何数的整数倍).
2.结构体大小必须是所有成员大小和4个字节两者中较小的整数倍.
3.嵌套的struct,展开后,结构体的第一个成员的偏移量必须是该结构体成员最大的成员和4个字节两者较小的整数倍.

64位机下安装32位动态库
sudo apt-get install gcc-multilib g++-multilib  libc6-dev-i386 
    libzip-dev
lib32z1 lib32ncurses5


*/

#include <stdio.h>
//#pragma pack(n)  该预处理指令强行改变结构体字对齐方式.
//n 必须是2的幂
//#pragma pack(1)    //以1字节对齐方式存储,
//__alignof__

struct foo1{
	char c;
	char *p;
};

struct  foo {
	char c;
	struct foo1 foo1;
	long double ld;
	char *p;
};


int main(int argc, char const *argv[])
{
	/* code */
	struct foo1 foo1;
	printf("sizeof(struct foo1) = %lu\n", sizeof(struct foo1));
#if 0
	struct foo foo;
	printf("sizeof(struct foo) = %lu\n", sizeof(struct foo));

	printf("foo 对齐方式: %d\n", __alignof__(struct foo));
#endif
	return 0;
}
