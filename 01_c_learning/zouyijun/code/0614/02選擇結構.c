#include <stdio.h>

// 程序員的妻子打電話給程序員，說：回來的路上買3個包子，如果看見了賣西瓜的，賣1個。於是程序員帶着1個包子回家了。程序員的妻子大怒，爲什麼只買了一個包子？程序員說因爲看到了賣西瓜的。

#if 0
void wife()
{
	買3個包子
	if (有看到賣西瓜的)
		買1個西瓜
}

void husband()
{
	if (有看到賣西瓜的)
		買1個包子
	else
		買3個包子
}
#endif

/*
	流程控制：
		分支結構
			if ...
			if ... else ...
			if ... else if ... else ... 
			
			switch ... case

		重復結構
			while (条件) {
				条件为真，执行的代码
			} 
			do ... while
			for (初始化部分; 條件; 修改增量)

		跳轉結構
			return
			break
			continue
			goto
*/

// 猜數字遊戲
/*
	改進：
		1, 如果猜錯了，提示是大了，還是小了
		2, 程序至少让用户有5次猜测的机会
		3, 正確答案是一個隨機數（10以內的數字）
*/
void guess_num()
{
	int target_num = 8;
	printf("請猜一下我心裏想的那個數字：");
	int num;
	scanf("%d", &num);
	if (num == target_num) {
		printf("猜對了，咱真是心有靈犀呀！\n");
	} else {
		printf("猜錯了，看來咱倆心沒靈犀呀!\n");
	}
	printf("遊戲結束了...\n");
}

// 如果猜錯了，提示是大了，還是小了
void guess_num_2()
{
	int target_num = 8;
	printf("請猜一下我心裏想的那個數字：");
	int num;
	scanf("%d", &num);
	if (num == target_num) {
		printf("猜對了，咱真是心有靈犀呀！\n");
	} else {
		if (num > target_num) {
			printf("太大了～\n");
		} else {
			printf("太小了～\n");
		}
	}
	printf("遊戲結束了...\n");
}

//程序直到用户猜测正确为止
void guess_num_3()
{
	int target_num = 8;
	printf("請猜一下我心裏想的那個數字：");
	int num;
	scanf("%d", &num);

	while (num != target_num) {
		printf("猜错了，请再猜测一次吧：");
		scanf("%d", &num);
		if (num == target_num) {
			printf("猜對了，咱真是心有靈犀呀！\n");
		} else {
			if (num > target_num) {
				printf("太大了～\n");
			} else {
				printf("太小了～\n");
			}
		}
	}
	printf("遊戲結束了...\n");
}

// break用来跳出它所在的那一层循环
void break_use()
{
	int a = 10;
	/*
	if (a > 0) {
		break;
	} */

	while (1) {
		if (a > 0) {
			break; // 跳出所在循环
		}
		printf("ok\n");
	}
	printf("end!\n");
}

#include <stdlib.h>
#include <time.h>
//程序至少让用户有5次猜测的机会
void guess_num_4()
{
	//int target_num = 8, num;
	
	srand(time(NULL));
	int num, target_num = rand()%10; 

	int count = 5; // 计数器

	while (count > 0) {
		count--;
		printf("請猜一下我心裏想的那個數字：");
		scanf("%d", &num); //6
		if (num == target_num) {
			printf("猜對了, 确实是%d，咱真是心有靈犀呀！\n", target_num);
			break;
		} else {
			//printf("猜错了，请再猜测一次吧：");
			//scanf("%d", &num);
			if (num > target_num) {
				printf("太大了～\n");
			} else {
				printf("太小了～\n");
			}
		}
	}
	printf("遊戲結束了...\n");
}

void get_random_num() // 获得随机数
{
	// 获得方式1
	// t时间值是从 1970-1-1 00:00:00 开始计算的秒数
	time_t t = time(NULL);
	printf("t = %ld\n", t); 
	srand(t);
	printf("rd1: %d\n", rand()%100);

	// 获得方式2
	srandom(time(NULL));
	printf("rd2: %ld\n", random()%100);	
}

int main()
{
	//int a; // -Wall (warning all) 開啓編譯器的警告
	//guess_num_4();
	//break_use();

	get_random_num();
}
