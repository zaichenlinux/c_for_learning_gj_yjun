

#include <stdio.h>
//  foo 标签
struct  foo    
{
	char *p;
	int a;
};

int main(int argc, char const *argv[])
{
	struct foo  foo = {"hello", 100};
	struct foo  foo1 = {.a = 88};  //.成员 = xxx
	//对结构体成员声明时候赋值,推荐该方式赋值
	struct foo  foo2 = {  a:  66 };//:成员= xx

	struct foo *pfoo;  //结构体指针
	pfoo = &foo; //
	//->指针运算符, ->之前必须是结构体或者联合体的指针.
	pfoo->a = 66;  //(*pfoo).a  
	printf("%d\n", foo.a);
	char a  = 88;
//. 结构体和联合体中运算符
//. 之前的变量必须是结构体或者联合体类型的变量
	foo.a = 100;   //  &foo->a  取结构体成员a的地址 
					//(&foo)->a 
	foo.p =  &a;

	/*
	printf(" %d,  %s\n", foo.a ,   foo.p);
	printf("%d\n", foo1.a);
	printf("%d\n",foo2.a );
	return 0;
	*/
}
