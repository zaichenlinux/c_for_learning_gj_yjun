/*
枚举
一一列举,和#define 类似
1.r如果枚举类型成员,没有赋值,默认,第一个成员的值为0,后面的成员在前面的成员基础上加1
2.enum枚举类型的大小是固定的4个字节,不是所有的成员之和.
3.不能对枚举类型成员进行赋值
4.day枚举类型,存储是int类型,虽然也可以对其进行直接赋值,如果对枚举型直接赋值,失去其枚举型的意义.枚举型赋值一般是赋值其中的成员.
5.多个枚举类型成员不能重名.
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
	enum day
	{
		Sun = 55, Mon, Zhouer, zhousan=-1, zhousi, zhouwu, zhouliu,
	};



/*
#define Sun  55
#define Mon 56
...
*/
	enum  day  day; //定义一个枚举类型,对枚举类型赋值,把枚举类型成员赋值给day
	day = Sun;
	day = 100;
	//Sun = 100;
	printf("day = %d\n",day );
	printf("%d\n",Sun );
	printf("%d\n",Mon );
	printf("%d\n", Zhouer);
	printf("%d\n", zhousan);
	printf("%d\n", zhousi);
	printf("%d\n", zhouwu);
	printf("%d\n",zhouliu );

	//printf("%lu\n", sizeof(enum day)); //4个字节
	//printf("%lu\n", sizeof(Mon));   //int 类型
	return 0;
}