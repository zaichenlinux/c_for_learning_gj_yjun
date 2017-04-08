#include <stdio.h>

/*
	结构体：存放任意类型的数据的一种数据结构

	struct 结构体类型名 {成员列表};

	结构体中的每一个数据通常称为成员	
*/

enum sex {
	MALE, FEMALE, UNKOWN,
};

// user 是结构体类型名
struct user {
	char name[20];
	int age;
	enum sex sex;
}; // 自定义数据类型

#include <string.h>
// 结构体赋值
void struct_var_assign()
{
	int a[3] = {1,2};
	//a = {1,2,3}; // 错误的

	// 定义了一个结构体类型的变量u
	// 依次赋值
	struct user u = {"tim", 20, MALE};
	//u = {"tim"}; // 错误的，结构体变量同样不能在声明之后，整体赋值

	// 分量赋值方式（表示给指定的成员赋值）
	struct user u2 = {"tim", .sex = MALE, .age = 20};
	printf("age = %d\n", u2.age); // .是成员运算符 或 分量运算符
	u2.age = 21; 

	//struct user uu = {name: "tim"}; // 过时的赋值方式

	struct user u3; // 在声明之后，再赋值
	strcpy(u3.name, "tom");
	u3.sex = FEMALE;
	printf("%d\n", u3.age);
}

struct foo {
	short b; // 2
	char c; // 1+1
	int a; // 4
	short s; // 2+2
} f = {10,'a',3}; // 定义了一个全局变量f，同时进行赋值

/* 结构体内存对齐(因系统平台而异):
	1, 结构体中的每一个成员的大小必须：能被它之前所有的成员占据内存的字节数的总和整除
 	2, 结构体中的所有成员占据内存的总和必须能被其中占据内存最大的那个成员整除（结构体中的最后一个成员之后可能留空位）
 */

int main()
{
	printf("size f = %lu\n", sizeof(f));
	return 0;
}
