/*
位运算：
|
&
～ 
>>
<<
^   按位异或  相异为1 相同为0

*/
//1.交换两个变量的值，不能使用中间变量
//int tmp
#include <stdio.h>

//缺点：两个参数进行相加，有可能超过int类型所允许的范围，溢出，导致结果不正确
void swap1(int *a, int *b)
{
	*a  = *a + *b;
	*b	= *a - *b;
	*a = *a - *b;
}

void swap2(int *a, int *b)
{
	*a  = *a ^ *b;
	*b = *a ^  *b;
	*a = *a ^ *b;
}

//写一个函数，判断这个数是否是2次幂
//    2次幂   16     1 0000  9     1001
//1001 & 1000 = 1000
// n & (n-1)
void is_2_mi(int n)
{
	return n&(n-1)
}


int main(int argc, char const *argv[])
{
	int  a = 3, b = 4;
	printf("a = %d, b = %d\n",a, b );

	swap2(&a, &b);
	printf("a = %d, b = %d\n",a, b );
	return 0;
}