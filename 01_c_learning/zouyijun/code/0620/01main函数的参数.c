#include <stdio.h>

// 如果需要通过命令行传递参数给main函数，main函数必须是有两个参数的写法
/* arg: argument  
argc:arg count 参数个数
argv:arg vector 存放指向参数的指针的数组
*/
int main(int argc, char *argv[])
{
	printf("argc = %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	printf("%p\n", *argv); // 打印的是argv[0]这个元素指向的那个字符的地址
	printf("%s\n", *argv); 

	printf("&argv: %p\n", &argv); // 打印的是argv这个数组中的首元素(也就是argv[0]这个元素)的地址
	printf("argv: %p\n", argv); // 打印的是argv这个数组中的首元素(也就是argv[0]这个元素)的地址
	printf("argv[0]的地址：%p\n", &argv[0]); 

	printf("ccccc: %c\n", *argv[0]);
	printf("ccccc: %c\n", *(argv[0]+0));
	printf("ccccc: %c\n", argv[0][0]);

	printf("%p\n", argv+1); // 数组中的第二个元素的地址
	printf("%s\n", *(argv+1)); // 数组中的第二个元素指向的字符的地址
	printf("%s\n", *argv+1); // 第一个元素指向的那个字符的下一个字符的地址

	// 试图修改第一个参数中的第0个字符
	printf("1:: %c\n", **(argv + 1));
	**(argv + 1) = 'X'; // 这一行本应该在运行时报错，但编译器没有报错，很遗憾！
	printf("2:: %s\n", *(argv + 1));

	char *s = "hello";
	*s = 'X'; //这里运行时报错，是正确的
	printf("%s\n", s);

	return 0;
}
