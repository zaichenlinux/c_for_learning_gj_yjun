#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 零长数组：长度为0的数组
struct foo {
	int a;
	char *c;
	char arr[]; 
	/*零长数组:
	  	1,只能出现在结构体中作为最后一个成员
		2,不占结构体变量的大小的
		3,它的存在，是为了扩展结构体变量的空间的
	  */
};

struct f {
	char s[0]; // 零长数组，作为结构体唯一成员存在，0是不能省略的
};


void test()
{
	//int a[0];

	printf("%lu\n", sizeof(struct foo));

	struct foo *pf = malloc(sizeof(struct foo) + 4); 
	if (!pf) {
	//	fprintf(stderr, "申请堆内存失败!\n"); // stderr 和 stdout 默认输出的位置都是屏幕
		perror("申请堆内存失败!");
		abort(); // 让程序非正常终止
	}
	pf->a = 10;
   	pf->c = "hello";
	strcpy(pf->arr, "123");
	printf("arr: %s\n", pf->arr);

	/*
	FILE *fp = fopen("./abc.txt", "r");
	if (!fp) {
		perror("打开文件失败!");
		exit(1);
	}
	printf("ok\n");
	*/

	free(pf);
}

struct g {
	int a;
	short s;
	//char t[0]; 
	int t[0];
} g;

int main()
{
	printf("s: %p\n", &(g.s));
	printf("t: %p\n", g.t);

	return 0;
}
