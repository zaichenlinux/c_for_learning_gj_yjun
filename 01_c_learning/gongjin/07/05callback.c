/*
回调函数:函数指针应用


*/

#include <stdio.h>
#include <signal.h>

void PC_show()
{
	printf("PC_show\n");
}

void phone_show()
{
	printf("phone_show\n");
}

void TV_show()
{
	printf("TV_show\n");
}


//可以实现一个回调,实现一个统一的接口
//1.回调函数实现了调用层和被调用曾的分离,使得各层之间联系性降低,仅仅通过以个有限的接口来联系.
//2.回调函数和结构体,来实现面向对象的思想.(数据结构)

void show(void (*ptr)())
{
	ptr();	
}

//void (*signal(int num, void (*handler)(int)))(int)
//返回值类型void (*)(int)
// void (*)(int)

void my_handler(int signum)
{
	printf("%d 信号输入\n", signum);
}



int main(int argc, char const *argv[])
{
	void (*ptr)()  = TV_show;

	show(ptr);
	//PC_show();
	signal(SIGINT, my_handler);
	signal(SIGWINCH, my_handler);
	while(1);
	return 0;
}