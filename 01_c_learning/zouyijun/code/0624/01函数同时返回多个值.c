#include <stdio.h>

// 定义一个函数，同时"返回"两个变量的 和与差

struct result {
	int sum; // 和
	int sub; // 差
};

void get_value(int a, int b, struct result *r)
{
	r->sum = a + b;
	r->sub = a - b;
}

int get_value2(int a, int b, int *p)
{
	*p = a - b;
	return a + b;	
}

int get_value3(int a, int b, int (*p)(int, int), int *c)
{
	*c = p(a, b);
	return a + b;
}

int call_back(int a, int b)
{
	return a - b;
}

int main()
{
	int a = 3, b = 5;
	struct result r;
	get_value(a, b, &r);
	printf("%d + %d = %d\n", a, b, r.sum);
	printf("%d - %d = %d\n", a, b, r.sub);

	int c;
	printf("%d + %d = %d\n", a, b, get_value2(a, b, &c));
	printf("%d - %d = %d\n", a, b, c);

	int d;
	printf("%d + %d = %d\n", a, b, get_value3(a, b, call_back, &d));
	printf("%d - %d = %d\n", a, b, d);


	return 0;
}
