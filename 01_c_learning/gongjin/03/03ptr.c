/*
指针:就是地址
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{  
	//int *p = 100;  //p是一个指针,指向int 类型指针
	//*p = 100;
//	int *p;  //野指针 int *  p = 100;   ==  int *p; p=100;
//	*p = 100;

	
	//int ***********p1;
	//int a = 100;
	//p = &a;  //&取地址符,把a的地址赋值给p

	//*p = 99; //间接引用,取地址内容
	//printf("a = %d\n", a);

	//printf("sizeof(p) = %lu\n", sizeof(p));
	//64位 指针占8个字节  32 -->4个字节

	//int a = 10;
	//int *p = &a;
	//int **p1 = &p; //p1二级指针,p1指向指针的指针

 	//*p1 = &a; //p1  int **  &a  int *
 	//03ptr.c:28:6: warning: assignment from incompatible pointer type
 	//指针类型的不兼容仅仅会报一个警告,遇到指针类型不兼容要注意

 	//指针运算
 	//指针 加  p1 + 5=  p1指针的地址 加 5*指针指向数据类型的大小
 	//指针 减  p1  - 5
 	//p1 * 2 指针的运算不能用 * /

 	//指针和指针的运算
 	//指针 - 指针  两个指针类型相同
 	//相减结果是  (p2- p1)/sizeof(*p1)
 	//p1 + 5 * sizeof(*p1) 
 	//指针 -  指针  一般用在数组中

 	//指针 + 指针 不管两个指针类型是否相同都不允许相加操作
	int * p1 = ( int  *)0x100;
	printf("%p\n",p1 - 5 );

	int  *p2 = (int  *)0x114;
	printf("%p\n",p2  + 5 );

	//printf("%lu\n",p2 + p1 );

	char *ch1 = "hello";//"hello" ..地址
	char ch2[] = "hello";

	printf("%s\n",ch2+2);//llo
	printf("%c\n",*(ch2+2));//l
	printf("%c\n",*ch2+2);// h + 2 = j
	//段错误
	//ch1[2]   == *(ch1+2)
	//2[ch1]  ==  *(2 + ch1)
	//ch1[2] = 'b';
	ch2[2] = 'b';

	ch1 = ch2;  //
	//ch2 数组名,代表指向该数组首个元素的地址,并且数组名指向的地址不能改变.
	//ch2 = ch1;

	printf("ch1 = %p\n", ch1);
	printf("%p\n","hello" );

	printf("ch2 = %p\n", ch2);


	return 0;
}
