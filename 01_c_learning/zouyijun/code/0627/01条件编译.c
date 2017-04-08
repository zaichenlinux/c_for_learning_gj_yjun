#include <stdio.h>

#if 1
void test()
{
	printf("%s被调用\n", __func__);
}
#endif

#define PI 3.14
void compiler1()
{
	double area; // 计算面积

	//cplusplus C++内置的宏

	//#define CIRCLE 1
	#define SQUARE 2	

	#if CIRCLE
	printf("请输入圆半径：");
	int radius;
	scanf("%d", &radius);
	area = PI * radius * radius;
	printf("圆面积是：%f\n", area);
	#elif SQUARE
	printf("请输入正方形的边长：");
	int a;
	scanf("%d", &a);
	area = a * a;
	printf("正方形面积是：%f\n", area);
	#else
		printf("无法计算\n");
	#endif
}

int main()
{
	compiler1();
	return 0;
}
