#include <stdio.h>

/*
	typedef: type definition 类型定义
 	给已经存在的类型定义一个新的名字，也就是定义一个类型的别名
 
 	格式：
		基本类型：
			typedef 原有类型名 新类型名;
 
 		组合类型：
			typedef int array[3]; // 定义int[3]类型的别名array
			typedef struct stu student; // 定义struct stu类型的结构体的类型的别名student
 
	typedef 的好处：
		1, 增强代码的可读性
		2, 简化复杂类型（简化定义变量时类型的部分）
	系统默认带有_t的类型，是系统用typedef定义过的类型
	//size_t
	//ssize_t 

	typedef void (*sighandler_t)(int);
    sighandler_t signal(int signum, sighandler_t handler);

	void (*signal(int signum, void (*handler)(int)))(int);
 */

// 基本类型
void base_type()
{
	int a;
	typedef int INT;
	INT b, c; // 通过int类型的别名INT来定义变量
}

// 组合类型
void combination_type()
{
	puts("-------一维数组-------");
	int a[3];
	typedef int array[3];	
	array b = {1,2,3};
	
	puts("-------二维数组-------");
	char s[2][6];
	typedef char arrays[2][6];
	arrays t = {{"hello"}, {"world"}};
	typedef typeof(s) arrays; // 更简单的方式定义类型别名

	
	puts("------结构体-------");
	struct stu {
		char *name;
		int age;
	};
	typedef struct stu student; 
	student st = {"tim", 20};

	
	puts("------结构体数组------");
	student stus[3];
	typedef student student_type[3]; // student_type是结构体数组类型
	student_type person = {{"tim", 20}};

	puts("------结构体数组指针------");
	typedef student_type* ptr_type;

	puts("------函数指针------");
	int max(int a, int b) // 函数的嵌套定义(在某些编译器下是不允许的)
	{
		return a > b ? a : b;
	}

	//size_t // 系统自带的类型，如果以_t结尾，那么通常这个类型是被typedef过的
	typedef int (*pmax)(int,int);
	//typedef typeof(max) pmax; // 定义函数类型的别名，没意义

	pmax pm = max;
	printf("max = %d\n", pm(1,2));
}

void ptr_type()
{
	char *p = "hello";

	typedef char * ptr;

	ptr p1 = "123", p2 = "456";

	//char* s1, s2;
}

//enum sex {MAN, WOMAN};
typedef enum {MAN, WOMAN} SEX;

typedef struct {
	char *name;
	int age;
	SEX sex;
} stu; // typedef 给没有标签的结构体变量定义类型别名stu


int main()
{
	//combination_type();
	//ptr_type();

	stu s1, s2; // 定义结构体变量时，就不需要前面加上struct了

	return 0;
}
