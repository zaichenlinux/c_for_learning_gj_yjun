/*
动态的库：.so
当链接动态库的时候，并不会把库中的内容拷贝到代码中，而且跳转到动态库去执行内部函数。整个程序运行期间，动态库都不能删除。

动态库不需要先编译生成目标文件

gcc  -shared   -fPIC   test.c  -o  库名
-shared  共享，生成一个动态库
-fpic  是输出的对象模块按照  可重定位的地址方式生成。

由于动态库是动态的链接，需要配置一个环境变量

./a.out: error while loading shared libraries: libmytest.so: cannot open shared object file: No such file or directory

动态库在程序运行期间动态加载进内存，程序在执行过程需要通过LD_LIBRARY_PATH 环境变量去找到对应的动态库。
LD_LIBRARY_PATH

gcc main.c -L ~/lib -lmytest -o a.out
~/lib   有libmytest.a   libmytest.so
-l库名   会优先选择动态库
-lmytest     先链接libmytest.so 如果libmytest.so没有 那么才链接libmytest.a


比较动态库和静态库
1.
2.

ldd  查看动态的链接

linux-vdso.so.1 =>  (0x00007fff463bf000)
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fb0abf7e000)
/lib64/ld-linux-x86-64.so.2 (0x00007fb0ac367000)


*/
#include <stdio.h>

void test()
{
	printf("hello wrold\n");
}