/*
内联函数:
关键字inline
内联函数不会像普通函数在调用时候开辟一个新的栈空间,结束的时候销毁该栈空间.而是将函数内的代码直接粘贴到函数调用的地方.


要想成为真正的内联函数要满足
1.该函数必须要有inline和static两个关键字同时修饰
2.编译的时候必须要有优化
gcc -O3  1~3优化级别
3.函数内部的代码行数一般不能过多,通常不超过10行
4.函数内部最好不要存在循环,等复杂逻辑,更不要出现函数的调用

*/

 static inline void test(int a, int b)
{
	//printf("hello world\n");
	//读-->改-->写
}

int main(int argc, char const *argv[])
{
	test(3, 4);

	return 0;
}