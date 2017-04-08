#include <stdio.h>

struct foo {
	int a;
	char c;
	char *s;
};


// 下面的宏，用来计算名称为member的成员，距离member成员所在的结构体（类型是type）的首地址的偏移量
// 其中的第1个参数，表示member成员所在的结构体的类型
// 第2个参数，表示以第一个参数为类型的结构体中的一个叫做member的成员
#define my_offsetof(type, member) \
	((size_t)(&((type *)0)->member))

// 13行，是模拟，0地址处有一个结构体，其类型是type, 然后就相当于定义了一个指向这个type类型的结构体的指针(类型是type*),之后通过这个指针取得了它指向的结构体中的叫做member成员的地址，最后将这个地址转换为一个合法的地址值的类型

// 下面的这个宏，用来得到member成员所在的结构体的首地址的
// 其中ptr参数表示，指向member成员的指针
#define container_of(ptr, type, member) \
	((type *)((size_t)(ptr) - my_offsetof(type, member)))

#include <stddef.h>
int main()
{
	printf("s成员距离它所在的结构体的首地址的偏移量：%lu\n", 
			offsetof(struct foo, s));
	
	printf("s成员距离它所在的结构体的首地址的偏移量：%lu\n", 
			my_offsetof(struct foo, s));

	int a = 10;
	printf("&a = %p\n", &a); // 0x7fcc 这样的地址值的类型是size_t 

	struct foo f = {10, 'a', "hello world"};

	printf("访问f中的s成员：%s\n", 
			container_of(&f.a, struct foo, a)->s);

	return 0;
}
