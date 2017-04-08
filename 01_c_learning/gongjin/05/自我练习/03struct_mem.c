#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct foo
{
	char *p;
	int a;
};
int main()
{
	#if 0
	struct foo *pfoo;//定义了一个结构体指针
	//pfoo野指针
	pfoo=(struct foo*)malloc(sizeof(struct foo));//
	//pfoo=(struct foo*)calloc(1,sizeof(struct foo));
	//
	if(pfoo==NULL)
	{
	printf("%s,%s,%d\n",__func__,__FILE__,__LINE__);
	return 0;
	}
	pfoo->a=100;
	pfoo->p=(char*)malloc(sizeof("hello"));
	pfoo->p="hello";//
	//strcpy(pfoo->p,"world");//段错误:字符串常量在ro_data区域；
	printf("pfoo->a=%d\n",pfoo->a);
	printf("pfoo->a=%d,pfoo->p=%s\n",pfoo->a,pfoo->p);
	//strcpy(pfoo->p,"world");//段错误：虽然给pfoo分配了空间，但是指向的空间不明确也就是野指针；
	//printf("pfoo->p=%s\n",pfoo->p);
	free(pfoo);
	#endif
	struct foo f1={"hello",100};
	struct foo f2=f1;
	printf("f2.a=%d,f2.p=%s\n",f2.a,f2.p);
	/*int arr[5]={1,2,3,4,5};
	int brr[5]=arr;//invalid initializer
	*///数组之间不能直接赋值；
	/*if(f1==f2){
	printf("f2.a=%d\n",f2.a);
	*///结构体可以进行整体赋值，但不能整体进行比较。结构体和结构体实体无法比较，结构体指针可以比较。

	return 0;
}
