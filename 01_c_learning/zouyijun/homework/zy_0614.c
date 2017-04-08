
/*
1，程序运行的时候提示下列信息
 请输入相应数字选择需要执行的运算：
 1 加法
 2 减法
 用户选择运算后，再提示用户输入两个需要进行运算的整数，输入完毕后就输出运算结果


2, 编写一个函数int pieAdd(int n)，计算1!+2!+3!+……+n!的值（n>=1）。
比如pieAdd(3)的返回值是1! + 2! + 3! = 1 + 1*2 + 1*2*3 = 9
*/

// 计算参数表示的
int factorial(int n)
{
	int ret = 1;
	/*
	while (n > 0) {
		ret *= n;
		n--;
	}
	*/

	for (; n > 0; n--) {
		ret *= n;
	}
	return ret;
}

int pieAdd(int n)
{
	// 求和
	int sum = 0;
	/*
	int i = 1;
	while (i <= n) {
		sum += factorial(i);
		i++;
	}*/

	for (int i = 1; i <= n; i++) {
		sum += factorial(i);
	}
	return sum;
}

/*
3, 有一种被称为“双骰子赌博”的投掷骰子的游戏。游戏规则：一个玩家要投掷两个骰子。每个骰子都有6个面，分别标有1，2，3，4，5，6个点。当被投掷的骰子停下来后，要统计两个骰子向上的面上所标的点数之和作为判断输赢的依据。如果第一次投掷两个骰子，得到的点数之和等于7或11，则玩家获胜，游戏结束。如果第一次投掷两个骰子，得到的点数之和等于4，5，6，8，9或10，则将这个数目作为玩家获胜需要掷出的“点数“。为了获胜，玩家必须继续投掷两个骰子，直至一次掷出的点数之和等于这个“点数“，这时游戏结束。但是如果在此之前，掷出的点数之和等于7，则玩家失利，游戏结束。
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int sum_of_dice()
{
	printf("请投掷两次筛子：");
	int point1, point2;
	
	srand(time(NULL));
	point1 = rand()%6 + 1;
	sleep(1);
	point2 = rand()%6 + 1;
	printf("p1=%d, p2=%d\n", point1, point2);

	return point1 + point2;
}

void game()
{
	enum game_state { LOSE, WIN, CONTINUE, } state;

	// 1, 第一次投掷色子，得到点数之和
	int first_points =  sum_of_dice();
	// 2, 根据第一次的点数之和，判断是否进入下一次循环, 如果是，再次投掷
	switch (first_points) {
		case 7:
		case 11:
			state = WIN;
			break;
		case 4 ... 6:
		case 8 ... 10:
			state = CONTINUE;
			break;
		default:
			state = LOSE;
	}

	while (state == CONTINUE) {
		printf("请继续投掷筛子 ...\n");
		int next_points = sum_of_dice();

		if (next_points == 7) {
			state = LOSE;
		} else if (next_points == first_points) {
			state = WIN;
		}
	}

	// 3, 打印结果
	if (state == WIN) {
		printf("玩家获胜！\n");
	} else {
		printf("玩家输了！\n");
	}
}

int main()
{
	//game();
	printf("请输入一个正整数：");
	int n;
	scanf("%d", &n);
	printf("结果：%d\n", pieAdd(n));
}

