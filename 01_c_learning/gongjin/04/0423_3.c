#include <stdio.h>

void findMurder(); 
int main()
{
	findMurder();

	return 0;
}

void findMurder() //返回值用来表示是否找到了凶手
{
	int murder = 'A'; //先假定凶手是A
	int flag = 0; //标记是否找到凶手
	for (; murder <= 'A' + 4; murder++) { //穷举：列出所有的情况
		if (3 == (murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D')) {
			printf("找到了，凶手是：%c\n", murder);
			flag = 1;
			break;
		}
	}

	if (!flag) {
		printf("题目有误，没找到凶手！\n");
	}

	//return;
}

