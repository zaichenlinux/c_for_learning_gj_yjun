#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct f1 {
	char *s;
	int a;
};

struct f2 {
	char s[20];
	int a;
};

int main()
{
	int a[2];
	printf("%d\n", a[0]);
	//a = 

	struct f1 f11 = {"hello", 100};
	//f11.s = "hello";

	//printf("size = %lu\n", sizeof(struct f2));

	struct f2 f22 = {"hello", 100};
	//char s[] = "hello";

	puts("-------------------------------------------");

	struct f1 f111;
	f111.s = "hello";

	struct f2 f222;
	// f222.s = "hello"; // 错误
	
	puts("-------------------------------------------");

	// 动态内存分配\申请: 在程序运行过程中，在需要的时候，动态申请内存空间的操作，就称为动态内存分配
	/*
		申请堆内存的函数有：
			malloc
			calloc 申请的内存会被自动清0
			realloc
		在内存申请成功之后，这些函数会返回申请的内存的首地址
		
		释放堆内存的函数：	
			free  // 释放之前通过内存申请函数申请的堆内存，参数必须是之前通过内存申请函数申请到的堆内存的首地址
		
			
		动态内存申请和释放的好处：
			推迟了需要使用的内存的开辟的时间，占用内存的时间尽量减少
			做到需要用的时候才开辟空间，不用就及时释放空间

		内存泄露：
			没有释放之前申请的堆内存

		内存使用问题：
			1, 只申请堆内存，但没有释放
			2, 释放不是申请的堆内存
			3, 只释放了之前申请的堆内存的一部分
			4, 多次释放同一块堆内存
	   */

	struct f1 f1111;
	//strcpy(f1111.s, "hello"); // f1111.s指针是野指针，指向的内存空间我们无权使用


	//f1111.s = malloc(sizeof("hello")); // 通过malloc函数申请的内存是堆内存
	//memset(f1111.s, 0, sizeof("hello"));

	f1111.s = calloc(6, sizeof(char));
	if (f1111.s) { // 判断是否申请成功
		strcpy(f1111.s, "hello"); 
		printf("f1111.s = %s\n", f1111.s);
	}
	
	f1111.s = realloc(f1111.s, 12); // 重新申请空间
	if (f1111.s) { // 判断是否申请成功
		strcat(f1111.s, " world"); 
		printf("f1111.s = %s\n", f1111.s);
	}

	free(f1111.s); 
	//free(f1111.s); 

	//struct f2 f2222;
	//strcpy(f2222.s, "hello");

	return 0;
}
