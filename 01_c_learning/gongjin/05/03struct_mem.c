/*
申请和释放空间
申请空间  malloc
void *  malloc(size_t size);
调用malloc calloc realloc 申请的空间都是在堆中

void free(void *ptr);

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct foo
{
	char *p;
	int a;
};

int main(int argc, char const *argv[])
{
	#if  1
	struct foo *pfoo; //定义了一个结构体的指针
	//pfoo野指针

	pfoo = (struct foo *)malloc(sizeof(struct foo));
	//pfoo = (struct foo *)calloc(1, sizeof(struct foo));
	//申请空间之后,立即判断malloc函数申请空间是否成功.
	if(pfoo == NULL) {
		printf("%s, %s, %d\n", __func__, __FILE__, __LINE__);
		return 0;
	}
	/*
	pfoo->a = 100;
	pfoo->p = "hello"; //字符串常量,ro_data区域
	strcpy(pfoo->p, "world");  //修改ro_data
	*/

	pfoo->a = 100;
	//pfoo->p = "hello"; 

	pfoo->p = (char *)malloc(sizeof("world"));
	strcpy(pfoo->p, "world");  //段错误,虽然给pfoo分配了空间
	//但是pfoo->p 指向的空间不明确,也就是野指针.


	printf("%d, %s\n",pfoo->a,  pfoo->p );

	//free(pfoo); //mallo没有free  内存泄露
	#endif

	struct foo f1={"hello", 100};
	struct foo f2 = f1; //结构体可以直接赋值

	int arr[5] = {1, 2, 3, 4, 5};
	//int brr[5] = arr;  //数组不能直接赋值
	//if(f1 == f2) { //结构体可以进行整体赋值,但是不能整体进行比较
		//结构体和结构体实体无法比较,   结构体指针可以比较

	//}

	printf("%d, %s\n", f2.a, f2.p);


	return 0;
}
