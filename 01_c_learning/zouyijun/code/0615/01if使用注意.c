#include <stdio.h>

int main()
{
	int a = 10;
	//if (a = 0) {
	//if (0 = a) { // 在判断值时，容易遗漏一个=号，建议将数值放在==号前面
	if (0 == a) {
		printf("A\n");
	} else {
		printf("B\n");
	}

	/* //错误写法
	if (a == 10)
		int b = 20; // 编译器对于变量的作用域不明确的情况直接报错
	printf("b = %d\n", b); 
	*/

	// 编译器检查变量的作用范围只看它所处于的一对{}

	if (a == 10) {
		int a = 20; // 这里的a和上面的a的作用范围互相不影响，所以ok
		printf("a1 = %d\n", a);
	}
	printf("a2 = %d\n", a);

	return 0;
}
