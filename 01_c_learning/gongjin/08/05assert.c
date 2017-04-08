/*
assert() 
断言宏，调试用的宏

#include <assert.h>
void assert(scalar expression);


assert原理：根据条件表达式的真假，来决定是否调用断言宏
如果条件表达式为假，那么首先向标准输出输出错误信息()
a.out: 05assert.c:18: main: Assertion `p' failed.
然后调用abort函数，放弃CPU，终止该进程。

#include <stdlib.h>
void abort(void);

assert:一般用于检测指针，特别用来检测函数传递过来的指针

*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	/*
	int *p = NULL;  //野指针
	assert(p  != NULL); 
	*p = 10;
	*/
	int *p = (int *)malloc(10);  //malloc之后调用assert
	//或者用if判断
	assert(p);
	/*
	if(p == NULL){
		printf("err\n");
		return ;
	}
	*/


	return 0;
}
