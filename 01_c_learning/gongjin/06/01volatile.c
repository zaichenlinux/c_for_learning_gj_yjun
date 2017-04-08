/*
volatile关键字  修饰寄存器变量,防止寄存器被优化
如果对变量进行连续赋值,编译器在编译的时候会有优化,连续赋值的变量,起作用的只有最后一个赋值.加上volatile关键字,
那么该变量就不会被优化.

volatile GPIOA


嵌入式: 32位
1.嵌入式行业,经常需要对一个绝对的地址进行赋值,对一个寄存器地址
0x12345678  赋值成 0xaa;
2.C语言中如果跳转,跳转0x12345678;

1.首先把0x12345678强制转化成指针类型
*(volatile unsigned int  * )0x12345678  = 0xaa;

volatile unsigned int *p;
p = 0x12345678;
*p = 0xaa;

2.	goto err;goto虽然是跳转语句,但是只能跳转到对应的标签,
如果想跳转到某个特定的地址,用函数跳转.
test();  入口地址();
(void (*)())0x12345678();


*/
//
GPIOA  = 0x55 ;
GPIOA  =  0x66 ;
