/*
零长数组:
长度为0数组,零长数组一般不单独使用.一般用于结构体中,用于对结构体的扩充.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct foo{
	int a;
	int c;
	//char *p;
	char p[]; //零长数组,用于结构体最后一个元素,
//1.零长数组不占结构体的大小,把零长数组去掉
//2.零长数组指向上一个成员最后一个地址的下一个地址
};

int main(int argc, char const *argv[])
{
	//int arr[0];
	//printf("sizeof(arr) = %lu\n", sizeof(arr));
	//printf("arr = %p\n",arr);
	printf("sizeof(struct foo) = %lu\n",sizeof(struct foo) );
	struct foo * foo = (struct foo *)malloc(sizeof(struct foo)+10);

	printf("a = %p\n", &foo->a);
	printf("c = %p\n", &foo->c);
	printf("p = %p \n", foo->p);

	foo->a = 100;
	strcpy(foo->p, "hello");
	printf("%d, %s\n",foo->a, foo->p );

	//printf("%s\n", );
	return 0;
}