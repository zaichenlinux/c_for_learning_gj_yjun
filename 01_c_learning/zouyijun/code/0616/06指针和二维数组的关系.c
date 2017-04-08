#include <stdio.h>

void ptr_arr_arr()
{
	char t[][6] = {"world", "linux"}; // 二维字符数组

	char *s[] = {"world", "linux"}; // 一维字符指针数组
	printf("s数组的元素个数：%lu\n", sizeof(s)/sizeof(char*));	

	// 定义p1指针，指向数组中的第一个元素中的第二个元素
	char *p1 = s[1] + 2;
	printf("%c\n", *p1);
	printf("%c\n", *(p1 - 5));

	printf("%s\n", s[1]);
	// s中的元素类型是char*, s在表达式中类型是指向其中首元素的指针类型，所以s的类型是char**
	printf("%s\n", *(s + 1));

	// 定义p2指针，指向数组中的第一个元素
	char **p2 = s + 1;
	printf("p2: %s\n", *p2);
	printf("p2: %s\n", *p2 + 2);
	printf("p2: %c\n", *(*p2 + 2));

	// 定义p3指针，指向整个二维数组s
	// s数组的类型是：char *[2]
	char *(*p3)[2] = &s;
	printf("p3: %s\n", **p3);	
	printf("p3: %c\n", ***p3);	
}

int main()
{
	ptr_arr_arr();
	return 0;
}
