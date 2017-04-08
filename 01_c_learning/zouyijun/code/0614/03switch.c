#include <stdio.h>

/*
	提示用户输入一个分数，打印相应的等级：
	A：90-100
	B：80-89
	C：60-79
	D：0-59
*/

/*
	switch (整型数值) {
		case 整型常量：
			语句
			break;
		case 整型常量：
			....
		default:
			....
	}
*/

void score_1()
{
	int score; // 保存分数
	printf("请输入一个分数：");
	scanf("%d", &score);
	//if ((90 <= score) <= 100) {
	if (score >= 90 && score <= 100) {
		printf("A\n");
	}
	if (score >= 80 && score <= 89) {
		printf("B\n");
	}
	if (score >= 60 && score <= 79) {
		printf("C\n");
	}
	if (score >= 0 && score <= 59) {
		printf("D\n");
	}
	if (score > 100 || score < 0) {
		printf("输入错误，分数范围是：0～100\n");
	}
}

void score_2()
{
	int score; // 保存分数
	printf("请输入一个分数：");
	scanf("%d", &score);

	if (score >= 90 && score <= 100) {
		printf("A\n");
	} else {
		if (score >= 80 && score <= 89) {
			printf("B\n");				
		} else {
			if (score >= 60 && score <= 79) {
				printf("C\n");
			} else {
				if(score >= 0 && score <= 59) {
					printf("D\n");
				} else {
					printf("输入错误\n");
				}
			}
		}
	}	
}

void score_3()
{
	int score; // 保存分数
	printf("请输入一个分数：");
	scanf("%d", &score);

	if (score >= 90 && score <= 100) {
		printf("A\n");
	} else if (score >= 80 && score <= 89) {	
		printf("B\n");
	} else if (score >= 60 && score <= 79) {
		printf("C\n");
	} else if (score >= 0 && score <= 59) {
		printf("D\n");
	} else {
		printf("输入错误！\n");
	}
}

void switch_score()
{
	int score; // 保存分数
	printf("请输入一个分数：");
	scanf("%d", &score);
	
/*
	int a = 10;
	switch (a) {
		case a: // 错误，a是一个变量，不是整型常量
			printf("ok\n");
	}
*/

	switch (score) {
		int abc = 100;
		case 90 ... 100: {
			int e = 200; // 在某个case下面定义变量，需要明确告诉编译器这个变量的作用范围，所以需要将这个case用一对{}括住，以界定变量的范围
			printf("A，abc = %d, e = %d\n", abc, e);
			break;
		}
		case 80 ... 89:
			printf("B\n"); break;
		case 60 ... 69:
		case 70 ... 79: 
			printf("C\n"); break;
		case 0 ... 59:
			printf("D\n"); break;
		default:
			printf("输入错误！\n");
	}

	// printf("abc = %d\n", abc); // abc的作用范围在switch的一对{}之间
}

int main()
{
	//score_3();
	switch_score();

	return 0;
}
