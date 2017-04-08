/*
位域：

*/
#include <stdio.h>

//ch1 表示性别
//ch2 年级 （1~6）
//unsigned char   0000 000 0
/*
1.成员只用到其中几位。由低位到高位依次存储。
2.不能跨自己存储
3.位域数据宽度不能超过数据类型
4.虽然ch1, ch2两个成员在一个字节内存储，本质是两个成员，两个成员之间没有影响。
5.浮点类型不能用位域
6.位域只能用在结构体。
8位

第0位 第1位  配置成0x01
原来寄存器值如果是0x11

GPIO &= ~(0x3 << 0);
GPIO |= (0x1 << 0);

位字段   
*/
struct foo{  
	unsigned char ch1:2;  //位域，ch1 只用到其中的一位
	unsigned char ch2:3;
	unsigned  char ch3:4;
	//float   ch4:2;
};


int main(int argc, char const *argv[])
{
	printf("sizeof(foo) = %lu\n", sizeof(struct foo));
	struct foo foo;

	unsigned int a:4;
	//对一个 |  &  ～
	foo.ch2 = 0x0;
	foo.ch1 = 0x01; //2  0~3；   100
	printf("foo.ch1 = %d\n", foo.ch1);
	printf("foo.ch2 = %d\n", foo.ch2);

	return 0;
}