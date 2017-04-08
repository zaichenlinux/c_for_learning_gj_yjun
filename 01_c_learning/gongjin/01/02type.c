/*
数据类型:
1.基本类型
char int float double
unsigned signed long short
size_t  和CPU字长有关
32  size_t == unsigned int
64  size_t == unsigned long int

ssize_t
32   == int
64  == long int

u8   -->  unsigned char
u16
s32 --> int 

2.构造类型
数组      int arr[10]
结构体  struct foo {}
联合体  union ufoo
枚举     enum day

3.指针类型

4.空类型(通用类型)
*/

#include <stdio.h>

//sizeof 用来计算数据类型在内存中占有的字节数
//sizeof 是一个运算符
//sizeof (变量名/数据类型)
//sizeof 变量名
//sizeof  数据类型
/*
deb
sudo dpkg -i vim*****.deb

sudo apt-get install vim
/var/cache/apt/archives  
该目录存放由apt-get install 下载的安装包

*/
int main()
{

	//如果在64下编译生成32位的可执行程序,需要安装32的包,
	char c;  // 1 1
	int i;    // 4 4
	float f; // 4 4
	double d; // 8 8 
	printf("sizeof(c) = %lu\n", sizeof(c));
	printf("sizeof(i) = %lu\n", sizeof(i));
	printf("sizeof(f) = %lu\n", sizeof (f));
	printf("sizeof(d) = %lu\n", sizeof (d));

	//long char lc;  // 1 1 
	long int li;    // 4 8
	//long float lf; // 4 4
	long double ld; // 12 16 
	//printf("sizeof(lc) = %lu\n", sizeof(lc));
	printf("sizeof(li) = %lu\n", sizeof(li));
	//printf("sizeof(lf) = %lu\n", sizeof (lf));
	printf("sizeof(ld) = %lu\n", sizeof (ld));

	//short char sc;  // 1 1 
	short int si;    // 2 2
	//short float sf; // 4 4
	//short double sd; // 12 16 
	//printf("sizeof(lc) = %lu\n", sizeof(lc));
	printf("sizeof(si) = %lu\n", sizeof(si));
	//printf("sizeof(lf) = %lu\n", sizeof (lf));
	//printf("sizeof(ld) = %lu\n", sizeof (ld));

	unsigned char uc;  // 1 1 
	unsigned int ui;    // 2 2
	//unsigned float uf; // 4 4
	//unsigned double ud; // 12 16 
	printf("sizeof(uc) = %lu\n", sizeof(uc));
	printf("sizeof(ui) = %lu\n", sizeof(ui));
	//printf("sizeof(lf) = %lu\n", sizeof (lf));
	//printf("sizeof(ld) = %lu\n", sizeof (ld));

//	1.235  1235 * 10^-3
	signed char sic;  // 1 1 
	signed int sii;    // 4 4
//	signed float sif; // 4 4
//	signed double sid; // 12 16 
	printf("sizeof(sic) = %lu\n", sizeof(sic));
	printf("sizeof(sii) = %lu\n", sizeof(sii));
	//printf("sizeof(lf) = %lu\n", sizeof (lf));
	//printf("sizeof(ld) = %lu\n", sizeof (ld));

	unsigned   unsi;
	signed   sig;
	long   lo;
	short  sho;
	printf("sizeof(unsi) = %lu\n", sizeof(unsi));
	printf("sizeof(sig) = %lu\n", sizeof(sig));
	printf("sizeof(lo) = %lu\n", sizeof (lo));
	printf("sizeof(sho) = %lu\n", sizeof (sho));

	long long int  lli;  //8 8
	printf("sizeof(lli) = %lu\n", sizeof(lli));

	size_t  st;
	printf("sizeof(st)  = %lu\n", sizeof(st));

	int *p;
	printf("sizeof(p)  = %lu\n", sizeof(p));

	//void  v;  //err,一个变量的类型不能是空类型
	void *vp;  //vp 
	return 0;
}
