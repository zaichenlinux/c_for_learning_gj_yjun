#include <stdio.h>

//##和#只能出现在预处理指令中

int main()
{
	//## 拼接符: 将宏的多个参数拼接为一个标识符
	#define CONNECT(a, b) a##b
	printf("%d\n", CONNECT(1, 2));
	//printf("%s\n", CONNECT("hello", "world"));
	// "helloworld" 这一对双引号只有在程序运行过程中，才能将%s这个占位符替换掉。对于预处理来说，不是一个合法的标记。
	
	#define CONNECTION(a, b) a## e ##	b
	printf("%d\n", (int)CONNECTION(1, 2)); //1e2

	printf("hello" "world" "123\n"); // printf函数，在参数时多对连续的双引号引起来的字符串时，会自动将其合并为一对双引号引起来的字符串

	#define ARG(a, b, c) a##b##c
	printf("%d\n", ARG(1,2,3));
	printf("%d\n", ARG(1,2,));
	printf("%d\n", ARG(1,,3));
	printf("%d\n", ARG(,,3));
	//printf("%d\n", ARG(,,)); // 错误，必须至少提供一个参数
	// ## 只能出现在宏定义中，而且当传递的参数不够时，会自动将多余的,号删除掉

	puts("-----------------------------------");
	// # 称为字符串化符 (#abc --> "abc")
	#define STRLIZE(s) #s
	printf("%s\n", STRLIZE(hello));

	#define STR(s, t) #s #t
	printf("str: %s\n", STR(hello, world));

	return 0;
}
