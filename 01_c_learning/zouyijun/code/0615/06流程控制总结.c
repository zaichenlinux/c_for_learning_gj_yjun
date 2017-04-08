#include <stdio.h>

int main()
{
	/*
	if 和 switch :
		1, 能用switch解决的，一定可以用if解决
		2, 能用if解决的，不见得能用switch解决
	*/
	
	int a = 100;
	if (a >= 10) {
		printf("AA\n");
	}

	/*
	switch (a) {
	case 10 ... 边界值:
	}
	*/

	switch (a) {
		case 100:
			break;
		default:
			; // 空语句用来解决语句的结束
	}

	/*
		循环：
			选择的优先级：for --> while --> do...while
			for 循环特别适用于计算型循环
	*/

	// for使用注意：
	for (int i = 0; i < 5; i++) { // 这里的i作用范围在{}之间和（）之间
		int i = 10; // 这里的i作用范围只在他所在的{}之间
	}
	
	for (int i = 0; i < 5; i++ /*, c++*/) { // c的作用范围只在{}之间，不能在()内被访问
		int c = 10;
	}

	/*
	for (int i = 0; i < 5; i++)
		int a = 100; // a变量的作用域不明确，所以报错
	*/

	for (int i = 10; i < 5; i++); // 这里的;号表示空语句
	{
		printf("ok\n");
	}

	/*
		break 和 continue:
			break 只能用在循环和switch中，用来跳出所在的循环或switch
			continue 只用在循环中，用来结束本次循环（本次循环之后的代码不再被执行），提前进入下一次循环的判断
	*/

	return 0;
}
