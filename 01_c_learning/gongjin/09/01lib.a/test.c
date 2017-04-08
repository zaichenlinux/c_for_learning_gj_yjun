#include <stdio.h>
/*
静态库，需要先编译。
1.gcc -c  test.c -o test.o
生成目标文件

ar    r(插入) c（创建） s（建立索引）  库的名称    目标文件
2.ar   rcs  libmytest.a   test.o

3.链接静态库
gcc  main.c  libmytest.a  -o a.out

libytest.a  libytest.so
-L  找到库的路径  -l 库的名称（去掉lib前缀和.a或者.so的后缀，gcc -l会自动补全）
gcc main.c -L  -l


gcc -I（头文件的目录）
*/


void test()
{
	printf("helllo  world\n");
}

