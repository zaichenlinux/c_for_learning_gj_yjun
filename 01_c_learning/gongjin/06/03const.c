/*
const应用场景
*/
//const char *s const修饰*s 一般用于函数参数传参
#include <stdio.h>
#include <string.h>
void test(char s[])
{
	printf("strlen s = %d\n", strlen(s));
	printf("sizeof s = %d\n", sizeof(s));
}

int main(int argc, char const *argv[])
{
	/*
	int *p;
	printf("hello world"); //带有缓存
	//刷新缓存
	//1.程序执行完毕
	//2.\n 会触发刷新
	//3.通过 fflush() 函数刷新
	*p = 10;
	*/
/*
void test(char s[])
{
	printf("strlen s = %d\n", strlen(s)); //5
	printf("sizeof s = %d\n", sizeof(s)); //4
}
*/
	char t[10] = {4, 1, 2, 3,0 }; //'\0'  == 0  '0' 
	char s[] = "hello";
	printf("strlen t = %d\n", strlen(t));//0  5
	printf("sizeof t = %d\n", sizeof(t)); //10
	printf("strlen s = %d\n", strlen(s));//5
	printf("sizeof s = %d\n", sizeof(s));//6
	test(s);
	return 0;
}