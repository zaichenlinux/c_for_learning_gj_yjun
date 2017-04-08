#include <stdio.h>

/*
	回调函数：
		一个不会被直接调用的函数，只能通过这个函数的地址进行间接调用的函数，就是回调函数

	回调函数就是函数指针的一个应用，作用是用来在函数间进行数据传递的

	作用：
		当想要通过一个统一的接口实现不同的内容时，回调函数是一个很好的选择 
		回调函数实现了调用和被调用层的分离，调用层根本无关知道被调用者是谁，它只需要知道：有一个函数，具有特定的限制，我可以去调用它
 	
 */

// 回调函数
static void new_toy(void *a, void *b)
{
	printf("%s, 请看一下我的%s\n", (char *)a, (char *)b);
}

static void tv_channel(void *a, void *b)
{
	printf("%s, 正在放映：%s\n", (char*)a, (char*)b);
}

void score(void *a, void *b) // void *b = 100
{
	printf("这次%s考试，我考了%d分\n", (char*)a, *((int*)(&b)));
}

void show(void (*)(void*, void*), void*, void*);
int main()
{
	show(new_toy, "hello", "新玩具"); 
	show(tv_channel, "cctv-6", "卧虎藏龙"); 
	//int s = 100;
	//show(score, "数学", (void *)(&s));
	show(score, "数学", (void *)100);

	return 0;
}
