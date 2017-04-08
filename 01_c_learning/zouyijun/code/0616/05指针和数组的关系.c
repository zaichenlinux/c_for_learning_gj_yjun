#include <stdio.h>

void ptr_arr()
{
	int *p; // p指向int类型变量
	char *ps; // ps指向char类型变量

	char s[] = {'w', 'o', 'r', 'l', 'd'};

	//ps = &s[2]; // &*(s+2) == s+2
	ps = s + 2; // ps指向s[2]这个元素
	// 数组名只要出现在表达式中，就表示其中首个元素的地址

	printf("*ps = %c\n", *ps);

	// 定义一个指针，指向整个s这个一维数组
	//char *parr[5]; // 字符指针数组parr: 其类型是char*[5] 

	char (*parr)[5]; // parr指针变量的类型是:char (*)[5], parr指向的变量的类型是：char[5]
	parr = &s;

	printf("&s = %p\n", &s); // &s是整个数组的首地址
	printf("s = %p\n", s); // s是整个数组中的首元素的地址

	printf("xx = %c\n", *(*parr + 1)); // *parr == *&s
	printf("yy = %c\n", (*parr)[1]);
}

#include <string.h>
// 字符串：C中没有字符串这种类型 “world”
void string()
{
	char s[5] = {'w', 'o', 'r', 'l', 'd'}; // s仅仅是字符数组
	printf("size s = %lu\n", sizeof(s));

	// '\0'是字符串结束的标志
	char t[] = {'w', 'o', 'r', 'l', 'd'};
	printf("size t = %lu\n", sizeof(t));

	// 字符串的简单表示形式：
	char st[] = {"world"};
	char st2[] = "world";
	printf("size st2 = %lu\n", sizeof(st2));

	printf("字符串的有效长度: %lu\n", strlen(s)); //strlen从s表示的地址开始，直到遇到第一个'\0'，会将'\0'之前的所有字符作为字符串的有效长度

	//数组越界访问，C编译器不阻止，但是需要程序员自己注意不要越界
	//printf("s[7] = %d\n", s[7]);
	//printf("s[8] = %d\n", s[8]);
	printf("t[5] = %d\n", t[5]);
}

int main()
{
	//ptr_arr();
	//string();
	ptr_arr_arr();

	return 0;
}
