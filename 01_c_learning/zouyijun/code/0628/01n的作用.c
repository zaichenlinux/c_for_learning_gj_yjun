#include <stdio.h>

int main()
{
	int *p = NULL; // 指针定义时，如果暂时不清楚该指向哪里，请赋值为空

	// 断错误：segmentaion fault  
	// 导致断错误的原因是：访问了没有权利访问的东西

	printf("hello world"); // \n可以刷新输出缓冲区。在进程遇到了一个错误时，会使得进程被迫终止，所有的缓冲区的数据都来不及刷新，所以无法输出。在printf中加上\n就可以在进程发生错误时，依然可以刷新输出缓冲区。

//	printf("hello world\n");
	//fflush(stdout); // 刷新输出缓冲区
	int a;
	scanf("%d", &a); // 输出语句之后，就跟上输入语句，也可以刷新输出缓冲区
	*p = 100;

	return 0;
}
