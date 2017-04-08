#include<stdio.h>
struct foo
{
	char *p;
	int a;
};
int main(int argc,char const *argv[])
{
	struct foo foo = {"hello",100};
	struct foo foo1 = {.a = 88};
	struct foo foo2 = {a:66};
	struct foo *pfoo;
	pfoo=&foo;
	pfoo->a=66;//->指针运算符；->之前必须是结构体或联合体的指针；
	printf("foo.a=%d\n",foo.a);//.结构体和联合体中的运算符，.之前必须结构体或联合体类型的变量；
	char a=88;
	foo.a=100;
	printf("foo.a=%d\n",foo.a);
	(&foo)->a=101;//->运算符的优先级高于&
	printf("foo.a=%d\n",foo.a);
	
	foo.p = &a;
	printf("foo.a=%d,foo.p=%s\n",foo.a,foo.p);//char a=88;定义一个变量，并且将其地址赋值给foo.p;
	printf("foo1.a=%d\n",foo1.a);
	printf("foo2.a=%d\n",foo2.a);
	return 0;
}
/*输出结果为：
foo.a=66
foo.a=100
foo.a=101
foo.a=101,foo.p=X0�q�
foo1.a=88
foo2.a=66
*/
