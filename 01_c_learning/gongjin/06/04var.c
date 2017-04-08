/*
可变参数函数
不规则参数函数:参数的个数和类型是不确定

int printf(const char *restrict format, ...);
第一个参数  const char *
函数声明中如果参数出现 ...,说明该函数是可变参数的函数,可变参数的函数必须至少要有一个固定参数. 

可变参数的函数的定义
#include <stdarg.h>

void va_start(va_list ap, last);
type va_arg(va_list ap, type);
void va_end(va_list ap);



void test(int a, int b , int c, ...);
va_start(ap, c);
使用步骤:
1.首先在函数中定义一个va_list类型变量ap, 这个变量是指向函数参数的指针,void *.这个指针为后面的宏va_start() va_arg() va_end()使用
2.调用va_start宏初始化ap指针,该宏第二个参数是第一个可变参数的前一个参数,或者说是固定参数的最后一个参数.
3.调用va_arg宏,第二个参数是数据类型,该宏可以返回可变的参数.
由于字对齐,va_arg(ap, type),type数据类型只有三种
int ,  double , char *
4.va_end 销毁指针.

*/
//实现一个可变参数的函数,可变的参数相加,一直遇到0为止
//可变参数函数.类型都是int ,个数不确定

#include <stdio.h>
#include <stdarg.h>


int sum(int n , int m, ...)
{
	va_list ap; //1
	int sum =  0;
	int tmp;
	va_start(ap, m);//2
	while(tmp = va_arg(ap, int)){ //3
		sum += tmp;
	}
	va_end(ap);//4
	return sum;
}

void test(int n, ...)
{
	va_list ap; //1
	va_start(ap, n);
	printf("%c\n",  (char)va_arg(ap, int));
	printf("%s\n", va_arg(ap, char *));
	printf("%d\n", va_arg(ap, int));
	printf("%f\n",(float)va_arg(ap, double) );
}

//个数固定,参数类型不确定
int main(int argc, char const *argv[])
{
	//printf("sum = %d\n",sum(10, 10,  3, 4, 5, 0) );

	//test(10, 'a', "hello", 100, 1.200);//调用test函数,把后面4个参数挨个打印出来,printf.

	
	return 0;
}