/*
指针数组:本质是一个数组,数组的元素都是指针类型.
*/
#include <stdio.h>
//当数组作为函数参数,传递的是这个数组的首个元素的地址
//void  test(int arr[10])
void test(int * arr)
{
	printf("sizeof(arr) = %lu\n",  sizeof(arr));
}

// int main() 不带参数
//int main(int argc, char  *argv[])  带参数的main
//argc  argv  用来管理传递进来参数
//argc 是传递进来的参数的个数
//argv 指针数组,存放是参数的地址
int main(int argc, char  *argv[])
{
//	int arr[10];
//	test(arr);
//	char  *arr[5] ={"hello", "OK", "aaaa", "bbb", "cccc"}; 
	for(argc--;argc >=0; argc--) 
		printf("argv[%d] = %s\n", argc, argv[argc] );	
	return 0;
}