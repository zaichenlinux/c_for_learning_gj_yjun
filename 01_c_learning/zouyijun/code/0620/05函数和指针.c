#include <stdio.h>

#if 0
// 数组中的元素不能是：函数类型
// foo函数试图返回 int [3] 数组类型
// 但是C语言规定：函数不能返回数组，不能返回函数
int foo()[3]
{
	int *p = (int [3]){1,2,3};
	int a[3];
	//return (int [3]){1,2,3};
	return a;
}
#endif

/* int f(int);
	int (*pf)(int) = f;
   */

// max函数的类型：int (int, int)
int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}

void function_ptr()
{
	printf("max = %d\n", max(3, 5)); // 直接调用

	printf("函数的地址：%p\n", &max);
	printf("函数的地址：%p\n", max); // 函数名在表达式中，就表示函数的起始地址

	int (*pm)(int, int); // 函数指针pm, 类型是：int(*)(int,int)
	pm = &max;
	pm = max;

	// 间接调用函数
	printf("间接调用：max = %d\n", (*pm)(3, 5));	
	printf("间接调用：max = %d\n", pm(3, 5));
	printf("间接调用：max = %d\n", 
			((int(*)(int,int))0x400526)(3, 5));	// 这里的地址值，请查看自己电脑上实际的地址值			
}

void fun_ptr_arr()
{
	// 函数指针数组：
	int (*arr[])(int, int) = {max, min};
	printf("max = %d\n", arr[0](3, 5));
	printf("min = %d\n", arr[1](3, 5));

	// arr的类型：int (*[2])(int, int)
	// arr中的元素的类型：int (*)(int, int)
	// arr中的元素指向的函数的类型：int (int, int)

	// parr是函数指针数组指针
	int (*(*parr)[2])(int, int) = &arr;
	// 通过parr来调用max和min函数
	printf("parr, max = %d\n", (*parr)[0](3, 5));
	printf("parr, max = %d\n", (**parr)(3, 5));
	printf("parr, min = %d\n", (*(*parr + 1))(3, 5));
}

int main()
{
	function_ptr();
	return 0;
}

void string()
{
	char *str(char *);
	char s1[] = "hello";
	char *s2 = "hello";
	printf("%s\n", str(s1));
	printf("%s\n", str(s2));

	printf(":: %c\n", "world"[4]);
	printf(":: %s\n", "world" + 2); 
	// "world" + 2 == 2 + "world"
    // *("world" + 2) == *(2+"world")
    // "world"[2] == 2["world"]	

	printf("%c\n", 3["world"]);
}

// 返回指针的函数
char *str(char *s)
{
	return s + 2;
}
