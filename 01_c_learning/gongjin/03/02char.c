/*
字符数组:数组,数组中元素都是字符类型
字符串:本质也是字符数组,但是字符串结尾'\0'
'\0' 哨兵元素
*/
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	//char str1[6] = "hello";
	//"hello"  字符串常量,  字符串常量放在ro-data区
    // 'h' 'e' 'l' 'l' 'o'  '\0'
	//strlen 计算字符串的有效长度,不包括'\0'
	char str1[] = {'h', 'e', 'l', 'l', 'o'};
	char str2[5] = "hello";
	char str3[] = "hello";
//sizeof(str1)  str2 str3 ??
//strlen(str1) strlen(str2)  str3 ??
	printf("sizeof(str1)  = %lu\n", sizeof(str1));
	printf("sizeof(str2)  = %lu\n", sizeof(str2));
	printf("sizeof(str3)  = %lu\n", sizeof(str3));
	printf("strlen(str1)  = %lu\n", strlen(str1)); //随机
	printf("strlen(str2)  = %lu\n", strlen(str2)); //随机
	printf("strlen(str3)  = %lu\n", strlen(str3)); //5

	return 0;
}