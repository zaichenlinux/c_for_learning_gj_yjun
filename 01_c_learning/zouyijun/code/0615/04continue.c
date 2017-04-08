#include <stdio.h>
#include <stdbool.h>

/* continue 跳转语句，只能用在循环中。作用是：跳出本次循环，进入下一次循环的判断，根据判断条件的真假，决定是否进入循环

	break 跳转语句。作用1：用来跳出他所在的那一层循环
					作用2：跳出整个switch
*/

void have_lunch()
{
	printf("吃货的梦想就是天天有的吃～\n");
}

void continue_use()
{
/*
	switch (1) {
		case 1:
			printf("ok\n");
			continue; // 错误
	}
*/

	bool has_not_lunch_time = true;  // bool型变量的取值只有两种，true和false，他们的值分别是1和0
//	printf("%d\n", has_not_lunch_time);
	bool feel_hungry = true;
	int count = 0;

	while (has_not_lunch_time && (count != 10)) {
		if (feel_hungry) {
			printf("已经饿了～\n");
			count++;
			continue; // continue之后的代码不会被执行
		}
		// 
		if (count == 10) {
			have_lunch(); // 吃饭
		}
		//
	}
	printf("end\n");
}

int main()
{
	continue_use();
	return 0;
}
