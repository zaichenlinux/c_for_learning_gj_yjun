/*
指针的数组
数组的指针
*/
//() [] . ->   大于  *

#include <stdio.h>
int main(int argc, char const *argv[])
{

	int *  arr[10]; //指针数组
	int (*brr)[10];  //数组指针

	//C语言规定:
	//1.数组名代表指向该数组首个元素的地址,但是如果和sizeof运算,那么计算的不是指针的大小,而是整个数组的大小.
	//2.对数组名取地址,arr, &arr,就表示是整个数组的首地址.

	//整个数组的首地址,   数组首个元素的地址

	char s[] = "heabo";
	//通过p1指针打印
	//1.打印字符串 "bo"
	//2.打印 字符 'a'
	char (*p1)[6];  //char [6]
	//char **p2; //二级指针
	p1 = &s;

	printf("%s\n",  *p1 + 3);
	printf("%c\n", *(*p1+2));

	char s1[][7] = {"hello", "world", "liunx"};
	char (*p2)[3][7];
	p2 = &s1;

	 //orld
	 //i  *(p2 + 1)   p2[1] = *(p2 + 1)
	 printf("%s\n", *(*p2+1)+1 );
	 printf("%c\n", *(*(*p2 + 2) +1));

	/*
	printf("sizeof(s) = %lu\n",  sizeof(s));

	printf("s = %p\n", s);
	printf("&s = %p\n", &s);
	*/
	return 0;
}