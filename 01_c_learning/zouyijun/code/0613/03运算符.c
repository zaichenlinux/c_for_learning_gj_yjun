#include <stdio.h>

/*
	运算符：
		赋值运算符：=
		算术运算符：+ - * / %取余
		sizeof 运算符
		() 强制类型转换符
		关系运算符：> >= < <= == !=
		逻辑运算符：&& || !
		位运算符：& | ^ ~ << >>
		自增运算符：++ --
		条件运算符：?: （是C中的唯一一个三目运算符）
 		逗号运算符：,  
		typeof 运算符

	typedef unsigned int size_t; // 32位平台
	typedef unsigned long size_t; // 64位平台

	typedef signed int ssize_t; // 32位平台
	typedef signed long ssize_t; // 64位平台
 */

// 賦值運算符
void assignOPr()
{
	int a, b, c, d;
	a = (b = (c = (d = 10)));

	a += b; // 復合賦值 等價與 a = a + b
}

// sizeof运算符：计算变量，常量，表达式的字节数，结果是无符号整型（size_t，值只能是大于等于0的数）
// 无符号：数据的最高位是否当做符号位来看待，如果要视为符号位，那么这个数据就是有符号数据；不要，就视为无符号数，视为数据的有效部分。
void sizeofOpr()
{
	printf("size double = %lu\n", sizeof(10.0));
	printf("size int = %lu\n", sizeof(3));

	int a = 3;
	double b = 3.0;
	printf("size = %lu\n", sizeof(a + b));

	// sizeof运算符的结果是在编译之后，值已经确定下来了，++运算是在运行期间才会执行的
	printf("size ++ = %lu\n", sizeof(a++ + ++a));
	printf("last, a = %d\n", a);
}

// 算术运算符
void arithmeticOpr()
{
	int a = -10 % 3; // %结果的正负取决于%之前的表达式的正负

	// 隐式类型转换：C语言允许不同类型的变量参与运算，会自动进行隐式转换（原则是：将类型范围比较小的转换为类型范围比较大的）
	// a = 10.0 % 3; // 10.0 % 3.0  %符号左右两侧的表达式只能是整型值
	printf("a = %d\n", a);
}

// 关系运算符：结果只有两种：真（非0）和假（0）
void relationOpr()
{
	int a = 10, b = 10;
	int c = (a == b); // = 赋值运算符 == 判等运算符

	c = a == c;
	printf("c = %d\n", c);
}

// 逻辑运算符
void logicOpr()
{
	int a = 10, b = 10;
	int c = a + b || a - b; // 逻辑或短路：||之前的表达式结果如果为真，就不会继续计算||之后的表达式的值
	a = 0, b = 0; // 逻辑与短路：&&之前的表达式结果如果为假，就不会继续计算&&之后的表达式的值
	c = a + b && a - b;
	c = !!a;
	printf("c = %d\n", c);
}

// 自增运算符
void incrementOpr()
{
	int a = 10;
	printf("a = %d\n", a++); // a, a+1  10, a=11
	printf("a = %d\n", ++a); // a=12 12
	++a; // a=13
	printf("a = %d\n", --a); // a=12 12
	printf("a = %d\n", a--); // 12 a=11

	a = 10;
	// 不同平台上的处理结果不同：大部分的平台上参数入栈的顺序是从后往前入栈，出栈顺序是从前往后出栈
	//printf("%d, %d, %d\n", a++, ++a, a++); //10,12,12
	printf("%d, %d, %d, %d, %d\n", 
			a++, a++, ++a, a, a++); //13,12,14,14,10

	// ++a, --a, a 表示a本身占据的那块内存，a--，a++ 临时的表达式
}

// 条件运算符
void conditionOpr()
{
	// expr1 ? expr2 : expr3
	// 如果 expr1 表达式结果为真，整个表达式的结果就是expr2表达式的结果；否则就是expr3表达式的结果
	printf("max = %d\n", 4 > 3 ? 4 : 3);
}

// 逗号运算符: ,表达式的结果是最后一个表达式的结果
void commaOpr()
{
	int a, b = 4;
	a = 3, b;

	// b = (b+1) + (b=1); // 在同一个表达式中，既访问一个变量的值，又改变这个变量的值是不合理的，所以不要写出这样的代码 
	a = (3, b, a+b);
	printf("a = %d, b = %d\n", a, b);
}

// typeof运算符
void typeofOpr()
{
	int a;
	typeof(a) b = 10; // 用来取出变量的类型，是 GNU C 对于标准C的扩展
	printf("b = %d\n", b);

	char arr[] = "hello";
	typeof(arr) brr = "world";
	printf("brr = %s\n", brr);
}

int main()
{
	relationOpr();
/*
	arithmeticOpr();
	relationOpr();
	logicOpr();
*/

//	incrementOpr();
	//conditionOpr();
	//commaOpr();
	//typeofOpr();

	return 0;
}
