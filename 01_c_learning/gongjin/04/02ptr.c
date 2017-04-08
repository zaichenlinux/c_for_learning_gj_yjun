/*
野指针:指向的空间不明确
空指针:指向空地址的指针
通用类型的指针:该指针可以指向任何数据类型.
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
	#if 0
//	int a = 10;
	int *p1 ; //声明p1   p1指针指向的地址不明确
	int *p2;
	int *p3;
	int *p4;
	int *p5;
	int *p6;

	printf("p1 = %p\n", p1 );
	printf("p2 = %p\n", p2 );
	printf("p3 = %p\n", p3 );
	printf("p4 = %p\n", p4 );
	printf("p5 = %p\n", p5 );
	printf("p6 = %p\n", p6 );


	*p5 = 10;
	printf("%d\n", *p5);
	#endif

	//#define   NULL ((void *)0)  
	int *p = NULL; //空指针
	//NULL系统和编译器而异,控指针一定不能被访问,一旦访问空指针,造成段错误
	//段错误:访问了无权访问的内存地址.
	//printf("p = %d\n", *p);

	//void v;  //
	int a = 10;
	float b = 10.2;
	void *pv; //数据类型不能是void类型
	//pv是一个指针,(64)指针的大小固定8个字节
	printf("sizeof(pv) %lu\n", sizeof(pv) );

	pv = &b;
	//通用类型指针在使用之前必须强制转换,如果不进行强制转换,
	//系统并不知道对该指针做什么错误.
	printf("%f\n", *(float *)pv);

	return 0;
}